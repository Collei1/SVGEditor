//
// Created by Collei on 25-4-28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), m_pActionGroup(new QActionGroup(this)), m_pMenuManager(new MenuManager(this)),
    m_pAttributeManager(new AttributeManager(CanvasData(RegeditSettings::getInstance().canvasWidth(), RegeditSettings::getInstance().canvasHeight(), RegeditSettings::getInstance().canvasZoom(), RegeditSettings::getInstance().canvasColor()), this)){
    ui->setupUi(this);
    initUI();
    initActions();
    initConnections();
}

void MainWindow::initUI() {
    this->setGeometry(RegeditSettings::getInstance().windowGeometry());

    m_pCanvasFrame = new CanvasFrame();
    m_pScene = new QGraphicsScene(ui->scrollAreaWidgetContents);
    QGraphicsProxyWidget* proxy = m_pScene->addWidget(m_pCanvasFrame);
    proxy->setAcceptHoverEvents(true);
    proxy->setAcceptedMouseButtons(Qt::AllButtons);
    proxy->setFlag(QGraphicsItem::ItemIsFocusable);
    m_pGraphicsView = new QGraphicsView(m_pScene, ui->scrollAreaWidgetContents);
    ui->gridLayout->addWidget(m_pGraphicsView, 0, 0, 1, 1);
    double scale = RegeditSettings::getInstance().canvasZoom();
    m_pGraphicsView->scale(scale, scale);
    ui->scrollAreaWidgetContents->adjustSize();

    /*m_pCanvasFrame = new CanvasFrame(ui->scrollAreaWidgetContents);
    ui->gridLayout->addWidget(m_pCanvasFrame, 0, 0, 1, 1);*/

    m_pBorderStyleComboBox = new BorderStyleComboBox(ui->borderStyleFrame);
    ui->textColorFrame->move(ui->borderColorFrame->pos());
    ui->textColorFrame->hide();
    ui->fontFrame->move(ui->borderWidthFrame->pos());
    ui->fontFrame->hide();
    ui->textSettingFrame->move(ui->filledColorFrame->pos());
    ui->textSettingFrame->hide();
    m_pMenuManager->setupUI(ui->newAction, ui->openAction, ui->saveAction, ui->exportAction);
    m_pAttributeManager->setupUi(ui->canvasWidthFrame,
        ui->canvasWidthSpinBox,
        ui->canvasHeightFrame,
        ui->canvasHeightSpinBox,
        ui->zoomRatioFrame,
        ui->zoomRatioSpinBox,
        ui->canvasColorFrame,
        ui->canvasColorPushButton,
        ui->borderWidthFrame,
        ui->borderWidthSpinBox,
        ui->borderColorFrame,
        ui->borderColorPushButton,
        ui->filledColorFrame,
        ui->filledColorPushButton,
        ui->borderStyleFrame,
        m_pBorderStyleComboBox,
        ui->textColorFrame,
        ui->textColorBtn,
        ui->fontFrame,
        ui->fontComboBox,
        ui->textSettingFrame,
        ui->boldBtn,
        ui->italicBtn,
        ui->underrlineBtn,
        ui->fontSizeComboBox,
        ui->posFrame,
        ui->upBtn,
        ui->downBtn,
        ui->topBtn,
        ui->bottomBtn);
}

void MainWindow::initActions() {
    ui->arrowAction->setChecked(true);
    QList<QAction*> actions{ui->arrowAction, ui->penAction, ui->lineAction, ui->circleAction, ui->triangleAction, ui->rightTriangleAction, ui->rectangleAction, ui->pentagonAction, ui->hexagonAction, ui->pentagramAction, ui->diamondAction, ui->textAction, ui->zoomAction};
    int index = 0;
    for (const auto& action : actions) {
        action->setCheckable(true);
        action->setData(index);
        m_pActionGroup->addAction(action);
        ++index;
    }
}

void MainWindow::initConnections() {
    connect(m_pActionGroup, &QActionGroup::triggered, this, [this](const QAction *action) {
            const int data = action->data().toInt();
            ActionConfig::getInstance().setCurrentType(ActionConfig::getInstance().getType(data));
            m_pCanvasFrame->changeCursor();
        });
    connect(m_pAttributeManager, &AttributeManager::canvasDataChanged, this, &MainWindow::onCanvasDataChanged);
    connect(m_pAttributeManager, &AttributeManager::graphicsDataChanged, m_pCanvasFrame, &CanvasFrame::onGraphicsDataChanged);
    connect(m_pAttributeManager, &AttributeManager::textDataChanged, m_pCanvasFrame, &CanvasFrame::onTextDataChanged);
    connect(m_pAttributeManager, &AttributeManager::upDownChanged, m_pCanvasFrame, &CanvasFrame::onUpDownChanged);
    connect(m_pAttributeManager, &AttributeManager::topBottomChanged, m_pCanvasFrame, &CanvasFrame::onTopBottomChanged);
    connect(m_pCanvasFrame, &CanvasFrame::changeToArrow, this, [=] {
            ui->arrowAction->setChecked(true);
        });
    connect(m_pCanvasFrame, &CanvasFrame::frameChecked, m_pAttributeManager, &AttributeManager::onFrameChecked);
    connect(m_pCanvasFrame, &CanvasFrame::textChecked, m_pAttributeManager, &AttributeManager::onTextChecked);
    connect(m_pCanvasFrame, &CanvasFrame::zoomBtnClicked, m_pAttributeManager, &AttributeManager::onZoomBtnClicked);

    connect(m_pMenuManager, &MenuManager::clearCanvas, m_pCanvasFrame, &CanvasFrame::onClearAllFrames);
    connect(m_pMenuManager, &MenuManager::loadSvgFrame, m_pCanvasFrame, &CanvasFrame::onLoadSvgFrame);
    connect(m_pMenuManager, &MenuManager::exportSvg, this, &MainWindow::onExportSvg);
}

void MainWindow::onExportSvg(const QString& filename) {
    QSvgGenerator generator;
    generator.setFileName(filename);

    // 使用场景的原始大小，不考虑任何变换
    QRectF sceneRect = m_pScene->itemsBoundingRect(); // 获取所有项的边界矩形
    generator.setSize(sceneRect.size().toSize());
    generator.setViewBox(sceneRect);

    generator.setTitle(QObject::tr("Scene Export"));
    generator.setDescription(QObject::tr("SVG file exported from QGraphicsScene"));

    QPainter painter;
    if (!painter.begin(&generator)) {
        QMessageBox::warning(this,
                           QObject::tr("Export Error"),
                           QObject::tr("Failed to create SVG file."));
        return;
    }

    painter.setTransform(QTransform());
    m_pScene->render(&painter, sceneRect, sceneRect);

    painter.end();

    QMessageBox::information(this,
                           QObject::tr("Export Successful"),
                           QObject::tr("Scene has been exported to:\n%1").arg(filename));
}

void MainWindow::onCanvasDataChanged(const CanvasData& canvasData) {
    if (m_pCanvasFrame) {
        m_pCanvasFrame->setMinimumSize(canvasData.m_canvasWidth, canvasData.m_canvasHeight);
        m_pCanvasFrame->resize(canvasData.m_canvasWidth, canvasData.m_canvasHeight);
        m_pCanvasFrame->move((m_pScene->width() - m_pCanvasFrame->width()) / 2,(m_pScene->height() - m_pCanvasFrame->height()) / 2);
        m_pCanvasFrame->setStyleSheet(QString("background-color: %1").arg(canvasData.m_canvasColor.name()));

        m_pGraphicsView->resize(ui->scrollArea->width(), ui->scrollArea->height());
        const qreal scale = canvasData.m_zoomRatio;
        m_pGraphicsView->resetTransform(); // 重置之前的缩放
        m_pGraphicsView->scale(scale, scale);
        ui->scrollAreaWidgetContents->adjustSize();
    }
}

MainWindow::~MainWindow() {
    delete ui;
    RegeditSettings::getInstance().setWindowGeometry(geometry());
}
