//
// Created by Collei on 25-5-2.
//

#ifndef CANVASFRAME_H
#define CANVASFRAME_H

#include <QStack>
#include <unordered_set>
#include <QTransform>

#include "../Graphics/graphics.h"
#include "../Command/command.h"
#include "graphicsframe.h"
#include "overlaywidget.h"
#include "svgframe.h"

class CanvasFrame : public QFrame{
    Q_OBJECT
public:
    explicit CanvasFrame(QWidget *parent = nullptr);
    ~CanvasFrame() override;
    void changeCursor();
    void setTransform(const QTransform &transform);
    void clearChecked();
    void onLoadSvgFrame(const QString &svgPath);
    void addFrame(GraphicsFrame* frame, int index);
    int removeFrame(GraphicsFrame* frame);
    void addText(TextFrame* text, int index);
    int removeText(TextFrame* text);

    signals:
    void changeToArrow();
    void frameChecked(const AttributeType& type, const GraphicsData& data);
    void textChecked(const TextData& data);
    void zoomBtnClicked(bool isEnlarge);

public slots:
    void onGraphicsFinished();
    void onFrameClicked();
    void onTextClicked();
    void onSetGeometryFinished(QRect oldGeometry, QRect newGeometry);
    void onTextMoveFinished(QPoint oldPosition, QPoint newPosition);
    void onTextContentChanged(const QString &oldText, const QString &newText);
    void onGraphicsDataChanged(const GraphicsData& graphicsData);
    void onTextDataChanged(const TextData& textData);
    void onUpDownChanged(bool isUp);
    void onTopBottomChanged(bool isTop);
    void onClearAllFrames();

    void handleCopy();
    void handlePaste();
    void handleSelectAll();
    void handleUndo();
    void handleRedo();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QVector<GraphicsFrame*> m_totalFrames;
    QVector<TextFrame*> m_totalTexts;
    std::unordered_set<GraphicsFrame*> m_checkedFrames;
    std::unordered_set<TextFrame*> m_checkedTexts;
    //ActionType m_currentType;
    TextFactory *m_pTextFactory{};
    CopyFactory *m_pCopyFactory{};
    OverlayWidget *m_pOverlay;
    QTransform m_transform;
    GraphicsFrame* copiedFrame{};
    int copyAmount;
    TextFrame* copiedText{};
    SvgFrame* m_pSvgFrame{};

    QStack<Command*> m_undoStack;
    void clearUndoStack();
    QStack<Command*> m_redoStack;
    void clearRedoStack();
};


#endif //CANVASFRAME_H
