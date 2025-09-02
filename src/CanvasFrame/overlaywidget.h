//
// Created by Collei on 25-5-16.
//

#ifndef OVERLAYWIDGET_H
#define OVERLAYWIDGET_H
#include <QPainter>
#include <QWidget>
#include "../Graphics/graphics.h"
#include "../Graphics/graphicsfactory.h"
#include "../Graphics/config.h"

class OverlayWidget : public QWidget {
    Q_OBJECT
public:
    explicit OverlayWidget(QWidget *parent = nullptr);
    ~OverlayWidget() override;
    std::unique_ptr<Graphics> getGraphics();
    void setStartPoint(QPoint point);

    signals:
    void graphicsFinished();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint m_startPoint;
    QPoint m_endPoint;
    bool m_isDrawing = false;
    bool m_isConstructed = false;

    std::unique_ptr<Graphics> m_pGraphics;
    BasicFactory *m_pBasicFactory{};
};


#endif //OVERLAYWIDGET_H
