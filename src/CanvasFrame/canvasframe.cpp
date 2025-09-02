//
// Created by Collei on 25-5-2.
//
#include <QSvgRenderer>
#include <iomanip>
#include <QApplication>
#include <QShortcut>
#include "canvasframe.h"
#include "../Command/addgraphicscommand.h"
#include "../Command/addtextcommand.h"
#include "../Command/setgeometrycommand.h"
#include "../Command/delgraphicscommand.h"
#include "../Command/deltextcommand.h"
#include "../Command/movetextcommand.h"
#include "../Command/setgraphicsdatacommand.h"
#include "../Command/settextdatacommand.h"
#include "../Command/settextcontentcommand.h"
#include "svgframe.h"
#include "../RegeditSettings/regeditsettings.h"

CanvasFrame::CanvasFrame(QWidget *parent): QFrame(parent), m_pTextFactory(new TextFactory()), m_pCopyFactory(new CopyFactory()), m_pOverlay(new OverlayWidget(this)), copyAmount(0) {
    QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    setSizePolicy(sizePolicy);
    setMinimumSize(QSize(RegeditSettings::getInstance().canvasWidth(), RegeditSettings::getInstance().canvasHeight()));
    resize(RegeditSettings::getInstance().canvasWidth(), RegeditSettings::getInstance().canvasHeight());
    setStyleSheet(QString::fromUtf8("background-color: %1").arg(RegeditSettings::getInstance().canvasColor().name()));
    setFrameShape(NoFrame);
    setFrameShadow(Raised);
    setFocusPolicy(Qt::StrongFocus);

    m_pOverlay->setAttribute(Qt::WA_TransparentForMouseEvents);
    connect(m_pOverlay, &OverlayWidget::graphicsFinished, this, &CanvasFrame::onGraphicsFinished);
    m_pOverlay->setGeometry(0, 0, width(), height());
    m_pOverlay->setStyleSheet("background:transparent;");
    m_pOverlay->raise();
    m_pOverlay->show();

    // 复制快捷键 (Ctrl+C)
    QShortcut *copyShortcut = new QShortcut(QKeySequence::Copy, this);
    copyShortcut->setContext(Qt::ApplicationShortcut);  // 全局生效
    connect(copyShortcut, &QShortcut::activated, this, &CanvasFrame::handleCopy);

    // 粘贴快捷键 (Ctrl+V)
    QShortcut *pasteShortcut = new QShortcut(QKeySequence::Paste, this);
    pasteShortcut->setContext(Qt::ApplicationShortcut);
    connect(pasteShortcut, &QShortcut::activated, this, &CanvasFrame::handlePaste);

    // 全选快捷键 (Ctrl+A)
    QShortcut *selectAllShortcut = new QShortcut(QKeySequence::SelectAll, this);
    selectAllShortcut->setContext(Qt::ApplicationShortcut);
    connect(selectAllShortcut, &QShortcut::activated, this, &CanvasFrame::handleSelectAll);

    // 撤销快捷键 (Ctrl+Z)
    QShortcut *undoShortcut = new QShortcut(QKeySequence::Undo, this);
    undoShortcut->setContext(Qt::ApplicationShortcut);
    connect(undoShortcut, &QShortcut::activated, this, &CanvasFrame::handleUndo);

    // 重做快捷键 (Ctrl+Y)
    QShortcut *redoShortcut = new QShortcut(QKeySequence::Redo, this);
    redoShortcut->setContext(Qt::ApplicationShortcut);
    connect(redoShortcut, &QShortcut::activated, this, &CanvasFrame::handleRedo);
}

CanvasFrame::~CanvasFrame() {
    delete m_pTextFactory;
    delete m_pCopyFactory;
}

void CanvasFrame::setTransform(const QTransform &transform) {
    m_transform = transform;
    update();
}

void CanvasFrame::onGraphicsFinished() {
    std::unique_ptr<Graphics> newGraphics = m_pOverlay->getGraphics();
    const QPoint position = newGraphics->position();
    GraphicsFrame *newFrame = new GraphicsFrame(ActionConfig::getInstance().currentType(), std::move(newGraphics), this);
    newFrame->move(position - QPoint(2, 2));

    Command* cmd = new AddGraphicsCommand(this, newFrame);
    cmd->redo();
    m_undoStack.push(cmd);
    clearRedoStack();
    newFrame->check();
    m_checkedFrames.insert(newFrame);
    emit frameChecked(getAttributeType(newFrame->getActionType()), GraphicsData(newFrame->getGraphics()));
}

void CanvasFrame::clearChecked() {
    for (const auto frame : m_checkedFrames) {
        frame->uncheck();
        frame->unsetCursor();
    }
    for (const auto& text : m_checkedTexts) {
        text->uncheck();
        text->unsetCursor();
    }
    m_checkedFrames.clear();
    m_checkedTexts.clear();
}

void CanvasFrame::onLoadSvgFrame(const QString &svgPath) {
    if (m_pSvgFrame != nullptr) {
        m_pSvgFrame->deleteLater();
    }
    m_pSvgFrame = new SvgFrame(svgPath, this);
    m_pSvgFrame->show();
    m_pSvgFrame->lower();
    m_pOverlay->raise();
}
void CanvasFrame::addFrame(GraphicsFrame* frame, int index) {
    if (index < 0 || index > m_totalFrames.size()) index = m_totalFrames.size();
    m_totalFrames.insert(index, frame);

    connect(frame, &GraphicsFrame::clicked, this, &CanvasFrame::onFrameClicked);
    connect(frame, &GraphicsFrame::setGeometryFinished, this, &CanvasFrame::onSetGeometryFinished);
    m_pOverlay->raise();
    frame->setParent(this);
    frame->show();
}
int CanvasFrame::removeFrame(GraphicsFrame* frame) {
    frame->uncheck();
    frame->unsetCursor();
    int index = m_totalFrames.indexOf(frame);
    if (index != -1) {
        m_totalFrames.removeAt(index);
        frame->hide();
    }
    return index;
}

void CanvasFrame::addText(TextFrame* text, int index) {
    if (index < 0 || index > m_totalTexts.size()) index = m_totalTexts.size();
    m_totalTexts.insert(index, text);
    connect(text, &TextFrame::clicked, this, &CanvasFrame::onTextClicked);
    connect(text, &TextFrame::moveFinished, this, &CanvasFrame::onTextMoveFinished);
    connect(text, &TextFrame::textContentChanged, this, &CanvasFrame::onTextContentChanged);
    m_pOverlay->raise();
    text->setParent(this);
    text->show();
}
int CanvasFrame::removeText(TextFrame* text) {
    text->uncheck();
    text->unsetCursor();
    int index = m_totalTexts.indexOf(text);
    if (index != -1) {
        m_totalTexts.removeAt(index);
        text->hide();
    }
    return index;
}

void CanvasFrame::changeCursor() {
    QCursor newCursor;
    switch (ActionConfig::getInstance().currentType()) {
        case ActionType::Arrow: {
            newCursor = Qt::ArrowCursor;break;
        }
        case ActionType::Pen:{
            QPixmap pixmap(":/cursor/resources/pen_cursor.svg");
            QPixmap scaledPixmap = pixmap.scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            newCursor = QCursor(scaledPixmap);
            break;
        }
        case ActionType::Text:{
            newCursor = Qt::IBeamCursor;break;
        }
        case ActionType::Zoom:{
            QPixmap pixmap(":/cursor/resources/zoom_cursor.svg");
            QPixmap scaledPixmap = pixmap.scaled(25, 25, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            newCursor = QCursor(scaledPixmap);
            break;
        }
        default: {
           newCursor = Qt::CrossCursor;break;
        }
    }
    setCursor(newCursor);
}

void CanvasFrame::onFrameClicked() {
    clearChecked();
    GraphicsFrame* frame = dynamic_cast<GraphicsFrame *>(sender());
    m_checkedFrames.emplace(frame);
    ActionConfig::getInstance().setCurrentType(ActionType::Arrow);
    changeCursor();
    emit changeToArrow();
    emit frameChecked(getAttributeType(frame->getActionType()), GraphicsData(frame->getGraphics()));
}

void CanvasFrame::onTextClicked() {
    clearChecked();
    TextFrame* frame = dynamic_cast<TextFrame*>(sender());
    m_checkedTexts.emplace(frame);
    ActionConfig::getInstance().setCurrentType(ActionType::Arrow);
    changeCursor();
    emit changeToArrow();
    emit textChecked(frame->getTextData());
}

void CanvasFrame::onSetGeometryFinished(QRect oldGeometry, QRect newGeometry) {
    // 创建命令对象并压入撤销栈
    Command* cmd = new SetGeometryCommand(dynamic_cast<GraphicsFrame*>(sender()), oldGeometry, newGeometry);
    m_undoStack.push(cmd);
    clearRedoStack();
}
void CanvasFrame::onTextMoveFinished(QPoint oldPosition, QPoint newPosition) {
    Command* cmd = new MoveTextCommand(dynamic_cast<TextFrame*>(sender()), oldPosition, newPosition);
    m_undoStack.push(cmd);
    clearRedoStack();
}
void CanvasFrame::onTextContentChanged(const QString &oldText, const QString &newText) {
    Command* cmd = new SetTextContentCommand(dynamic_cast<TextFrame*>(sender()), oldText, newText);
    m_undoStack.push(cmd);
    clearRedoStack();
}

void CanvasFrame::onGraphicsDataChanged(const GraphicsData& graphicsData) {
    if (!m_checkedFrames.empty()) {
        for (const auto frame : m_checkedFrames) {
            GraphicsData oldData = frame->getGraphicsData();
            Command* cmd = new SetGraphicsDataCommand(frame, oldData, graphicsData);
            cmd->redo();
            m_undoStack.push(cmd);
            clearRedoStack();
        }
    }
}

void CanvasFrame::onTextDataChanged(const TextData& textData) {
    if (!m_checkedTexts.empty()) {
        for (const auto text : m_checkedTexts) {
            TextData oldData = text->getTextData();
            Command* cmd = new SetTextDataCommand(text, oldData, textData);
            cmd->redo();
            m_undoStack.push(cmd);
            clearRedoStack();
        }
    }
}
void CanvasFrame::onUpDownChanged(bool isUp) {
    if (m_checkedFrames.size() + m_checkedTexts.size() == 1) {
        if (m_checkedFrames.size() == 1) {
            if (isUp) {
                QList<QWidget*> siblings = this->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
                int currentIndex = siblings.indexOf((*m_checkedFrames.begin()));

                if (currentIndex < siblings.size() - 1) {
                    QWidget *nextWidget = siblings[currentIndex + 1];
                    if (nextWidget != nullptr) {
                        nextWidget->stackUnder((*m_checkedFrames.begin()));
                    }
                }
                m_pOverlay->raise();
            }else {
                QList<QWidget*> siblings = this->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
                int currentIndex = siblings.indexOf((*m_checkedFrames.begin()));

                if (currentIndex > 0) {
                    QWidget *prevWidget = siblings[currentIndex - 1];
                    if (prevWidget != nullptr) {
                        (*m_checkedFrames.begin())->stackUnder(prevWidget);
                    }
                }
                m_pOverlay->raise();
                if (m_pSvgFrame!=nullptr) {
                    m_pSvgFrame->lower();
                }
            }
        }
        if (m_checkedTexts.size() == 1) {
            if (isUp) {
                QList<QWidget*> siblings = this->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
                int currentIndex = siblings.indexOf((*m_checkedTexts.begin()));

                if (currentIndex > 0) { // 如果不是最底层
                    QWidget *prevWidget = siblings[currentIndex - 1];
                    if (prevWidget != nullptr) {
                        (*m_checkedTexts.begin())->stackUnder(prevWidget);
                    }
                }
                m_pOverlay->raise();
            }else {
                QList<QWidget*> siblings = this->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
                int currentIndex = siblings.indexOf((*m_checkedTexts.begin()));

                if (currentIndex < siblings.size() - 1) {
                    QWidget *nextWidget = siblings[currentIndex + 1];
                    if (nextWidget != nullptr) {
                        nextWidget->stackUnder((*m_checkedTexts.begin()));
                    }
                }
                if (m_pSvgFrame!=nullptr) {
                    m_pSvgFrame->lower();
                }
            }
        }
    }
}
void CanvasFrame::onTopBottomChanged(bool isTop) {
    if (m_checkedFrames.size() + m_checkedTexts.size() == 1) {
        if (m_checkedFrames.size() == 1) {
            if (isTop) {
                (*m_checkedFrames.begin())->raise();
                m_pOverlay->raise();
            }else {
                (*m_checkedFrames.begin())->lower();
                if (m_pSvgFrame!=nullptr) {
                    m_pSvgFrame->lower();
                }
            }
        }
        if (m_checkedTexts.size() == 1) {
            if (isTop) {
                (*m_checkedTexts.begin())->raise();
                m_pOverlay->raise();
            }else {
                (*m_checkedTexts.begin())->lower();
                if (m_pSvgFrame!=nullptr) {
                    m_pSvgFrame->lower();
                }
            }
        }
    }
}

void CanvasFrame::onClearAllFrames() {
    m_checkedFrames.clear();
    m_checkedTexts.clear();
    if (!m_totalFrames.empty()) {
        for (const auto frame : m_totalFrames) {
            frame->deleteLater();
        }
    }
    if (!m_totalTexts.empty()) {
        for (const auto text : m_totalTexts) {
            text->deleteLater();
        }
    }
    if (m_pSvgFrame != nullptr) {
        m_pSvgFrame->deleteLater();
        m_pSvgFrame = nullptr;

    }
    m_totalFrames.clear();
    m_totalTexts.clear();
    clearRedoStack();
    changeCursor();
}

void CanvasFrame::handleCopy() {
    if (m_checkedFrames.size() + m_checkedTexts.size() == 1) {
        copiedFrame = nullptr;
        copiedText = nullptr;
        if (m_checkedFrames.size() == 1) {
            copiedFrame = *m_checkedFrames.begin();
        }
        if (m_checkedTexts.size() == 1) {
            copiedText = *m_checkedTexts.begin();
        }
        copyAmount = 0;
    }
}

void CanvasFrame::handlePaste() {
    if (copiedFrame != nullptr) {
        ++copyAmount;
        std::unique_ptr<Graphics> newGraphics = m_pCopyFactory->createGraphics(copiedFrame->getActionType(), copiedFrame->getGraphics(), this);
        GraphicsFrame* newFrame = new GraphicsFrame(copiedFrame->getActionType(), std::move(newGraphics), this);
        newFrame->resize(copiedFrame->width(), copiedFrame->height());
        newFrame->setGraphicsData(copiedFrame->getGraphicsData());
        newFrame->move(copiedFrame->pos() + QPoint(10, 10) * copyAmount);

        Command* cmd = new AddGraphicsCommand(this, newFrame);
        cmd->redo();
        m_undoStack.push(cmd);
        clearRedoStack();
        newFrame->uncheck();
    }
    if (copiedText != nullptr) {
        ++copyAmount;
        TextFrame* newText = new TextFrame(*copiedText);
        newText->move(copiedText->pos() + QPoint(10, 10) * copyAmount);
        Command* cmd = new AddTextCommand(this, newText);
        cmd->redo();
        m_undoStack.push(cmd);
        clearRedoStack();
        newText->uncheck();
    }
}
void CanvasFrame::handleSelectAll() {
    for (const auto frame : m_totalFrames) {
        frame->check();
        m_checkedFrames.insert(frame);
    }
    for (const auto text : m_totalTexts) {
        text->check();
        m_checkedTexts.insert(text);
    }
    emit frameChecked(AttributeType::Base, GraphicsData());
}
void CanvasFrame::handleUndo() {
    if (!m_undoStack.isEmpty()) {
        Command* cmd = m_undoStack.pop();
        cmd->undo();
        m_redoStack.push(cmd);
    }
}
void CanvasFrame::handleRedo() {
    if (!m_redoStack.isEmpty()) {
        Command* cmd = m_redoStack.pop();
        cmd->redo();
        m_undoStack.push(cmd);
    }
}

void CanvasFrame::mousePressEvent(QMouseEvent *event){
    clearChecked();
    emit frameChecked(AttributeType::Base, GraphicsData());
    const ActionType actionType = ActionConfig::getInstance().currentType();
    if (actionType == ActionType::Arrow || actionType == ActionType::Zoom || actionType == ActionType::Text) {
        return;
    }
    if (m_pOverlay) {
        QMouseEvent cEvent(QEvent::MouseButtonPress, event->pos(),
                           event->button(), event->buttons(), event->modifiers());
        QCoreApplication::sendEvent(m_pOverlay, &cEvent);
    }
}
void CanvasFrame::mouseMoveEvent(QMouseEvent *event){
    const ActionType actionType = ActionConfig::getInstance().currentType();
    if (actionType == ActionType::Arrow || actionType == ActionType::Zoom || actionType == ActionType::Text) {
        return;
    }
    if (m_pOverlay) {
        QMouseEvent cEvent(QEvent::MouseMove, event->pos(),
                           event->button(), event->buttons(), event->modifiers());
        QCoreApplication::sendEvent(m_pOverlay, &cEvent);
    }
}
void CanvasFrame::mouseReleaseEvent(QMouseEvent *event){
    const ActionType actionType = ActionConfig::getInstance().currentType();
    if (actionType == ActionType::Arrow) {
        return;
    }
    if (actionType == ActionType::Zoom) {
        if (event->button() == Qt::LeftButton) {
            emit zoomBtnClicked(true);
        }else if (event->button() == Qt::RightButton) {
            emit zoomBtnClicked(false);
        }
        return;
    }
    if (actionType == ActionType::Text) {
        std::unique_ptr<TextFrame> textFrame = m_pTextFactory->createText(this);
        TextFrame* text = textFrame.release();
        text->move(event->pos());
        Command* cmd = new AddTextCommand(this, text);
        cmd->redo();
        m_undoStack.push(cmd);
        clearRedoStack();
        text->edit();
        m_checkedTexts.insert(text);
        emit textChecked(text->getTextData());
        return;
    }
    if (m_pOverlay) {
        QMouseEvent cEvent(QEvent::MouseButtonRelease, event->pos(),
                           event->button(), event->buttons(), event->modifiers());
        QCoreApplication::sendEvent(m_pOverlay, &cEvent);
    }
}

void CanvasFrame::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {
        for (auto frame : m_checkedFrames) {
            Command* cmd = new DelGraphicsCommand(this, frame);
            cmd->redo();
            m_undoStack.push(cmd);
        }
        for (auto text : m_checkedTexts) {
            Command* cmd = new DelTextCommand(this, text);
            cmd->redo();
            m_undoStack.push(cmd);
        }
        clearRedoStack();
        m_checkedFrames.clear();
        m_checkedTexts.clear();
    }
    event->ignore();
}

void CanvasFrame::paintEvent(QPaintEvent *event){
    QFrame::paintEvent(event);
    QPainter painter(this);
}

void CanvasFrame::resizeEvent(QResizeEvent *) {
    m_pOverlay->resize(size());
}

void CanvasFrame::clearUndoStack() {
    while (!m_undoStack.isEmpty()) {
        Command* cmd = m_undoStack.pop();
        if (auto addCmd = dynamic_cast<AddGraphicsCommand*>(cmd)) {
            addCmd->frame()->deleteLater();
        }
        else if (auto addCmd = dynamic_cast<AddTextCommand*>(cmd)) {
             addCmd->text()->deleteLater();
        }
        delete cmd;
    }
}
void CanvasFrame::clearRedoStack() {
    while (!m_redoStack.isEmpty()) {
        Command* cmd = m_redoStack.pop();
        if (auto addCmd = dynamic_cast<AddGraphicsCommand*>(cmd)) {
             addCmd->frame()->deleteLater();
        }
        else if (auto addCmd = dynamic_cast<AddTextCommand*>(cmd)) {
             addCmd->text()->deleteLater();
        }
        delete cmd;
    }
}

