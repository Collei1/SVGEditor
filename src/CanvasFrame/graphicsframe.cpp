//
// Created by Collei on 25-5-2.
//

#include "graphicsframe.h"
#include <QMouseEvent>

GraphicsFrame::GraphicsFrame(const ActionType type, std::unique_ptr<Graphics> graphics, QWidget *parent) :
    QFrame(parent), m_actionType(type), m_pGraphics(std::move(graphics)){
    m_pGraphics->setParent(this);
    setStyleSheet(QString::fromUtf8("background:transparent;border:none;"));
    m_pGraphics->setPosition(QPoint(2,2));
    m_pGraphics->setFilledColor(Qt::white);
    resize(m_pGraphics->width() + 4, m_pGraphics->height() + 4);
    setFrameShape(NoFrame);
    setFrameShadow(Raised);
    setMouseTracking(true);
    uncheck();
}
void GraphicsFrame::check() {
    setFocus();
    m_isChecked = true;
    setStyleSheet(QString::fromUtf8("border:2px solid blue;background:transparent;"));
}

void GraphicsFrame::uncheck(){
    clearFocus();
    m_isChecked = false;
    setStyleSheet(QString::fromUtf8("border:none;background:transparent;"));
}

void GraphicsFrame::setSize(QPoint startPoint, QPoint endPoint) {
    int newWidth = endPoint.x() - startPoint.x();
    int newHeight = endPoint.y() - startPoint.y();
    QPoint newPos = startPoint;

    bool horizontalMirrored = false;
    if (newWidth < 0) {
        newWidth = -newWidth;
        newPos.setX(newPos.x() - newWidth);
        horizontalMirrored = true;
    }
    bool verticalMirrored = false;
    if (newHeight < 0) {
        newHeight = -newHeight;
        newPos.setY(newPos.y() - newHeight);
        verticalMirrored = true;
    }
    m_pGraphics->setHorizontalMirrored(horizontalMirrored);
    m_pGraphics->setVerticalMirrored(verticalMirrored);

    m_pGraphics->setSize(width() - 4, height() - 4);
    setGeometry(newPos.x(), newPos.y(), newWidth, newHeight);
}

void GraphicsFrame::setGraphicsData(const GraphicsData& graphicsData) {
    m_pGraphics->setBorderColor(graphicsData.m_borderColor);
    m_pGraphics->setFilledColor(graphicsData.m_filledColor);
    m_pGraphics->setBorderWidth(graphicsData.m_borderWidth);
    m_pGraphics->setBorderStyle(graphicsData.m_borderStyle);
    update();
}

ActionType GraphicsFrame::getActionType() const {
    return m_actionType;
}

GraphicsData GraphicsFrame::getGraphicsData() const {
    return GraphicsData(m_pGraphics.get());
}

void GraphicsFrame::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    m_pGraphics->setSize(width() - 4, height() - 4);
    m_pGraphics->paint(&painter);
}

void GraphicsFrame::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        m_startPoint = event->globalPosition();
        if (m_isChecked) {
            m_startGeometry = geometry();
            m_oldGeometry = m_startGeometry;
            if (m_resizeEdges != Qt::Edges()) {
                m_isResizing = true;
            } else {
                m_isDragging = true;
            }
        }else {
            QFrame::mousePressEvent(event);
        }
    }
}

void GraphicsFrame::mouseMoveEvent(QMouseEvent *event){
    if (m_isChecked) {
        if (!m_isDragging && !m_isResizing) {
            Qt::Edges edges;
            if (m_actionType == ActionType::Pen) {
                edges = Qt::Edges();
            }else {
                edges = getEdgesAt(event->pos());
            }
            m_resizeEdges = edges;
            if (edges != Qt::Edges()) {
                this->setCursor(getResizeCursor(edges));
            } else {
                this->setCursor(Qt::SizeAllCursor);
            }
        }
        if (event->buttons() == Qt::LeftButton) {
            QPointF globalPos = event->globalPosition();
            QPointF delta = globalPos - m_startPoint;
            if (m_isResizing) {
                QRect newGeometry = m_startGeometry;
                bool horizontalFlipped = false;
                bool verticalFlipped = false;

                if (m_resizeEdges & Qt::TopEdge) {
                    newGeometry.setTop(m_startGeometry.top() + delta.y());
                    if (newGeometry.top() > newGeometry.bottom()) {
                        m_resizeEdges = (m_resizeEdges & ~Qt::TopEdge) | Qt::BottomEdge;
                        newGeometry.setTop(m_startGeometry.bottom());
                        m_startPoint.setY(globalPos.y());
                        m_startGeometry = newGeometry;
                        verticalFlipped = true;
                    }
                }
                if (m_resizeEdges & Qt::BottomEdge) {
                    newGeometry.setBottom(m_startGeometry.bottom() + delta.y());
                    if (newGeometry.bottom() < newGeometry.top()) {
                        m_resizeEdges = (m_resizeEdges & ~Qt::BottomEdge) | Qt::TopEdge;
                        newGeometry.setBottom(m_startGeometry.top());
                        m_startPoint.setY(globalPos.y());
                        m_startGeometry = newGeometry;
                        verticalFlipped = true;
                    }
                }
                if (m_resizeEdges & Qt::LeftEdge) {
                    newGeometry.setLeft(m_startGeometry.left() + delta.x());
                    if (newGeometry.left() > newGeometry.right()) {
                        m_resizeEdges = (m_resizeEdges & ~Qt::LeftEdge) | Qt::RightEdge;
                        newGeometry.setLeft(m_startGeometry.right());
                        m_startPoint.setX(globalPos.x());
                        m_startGeometry = newGeometry;
                        horizontalFlipped = true;
                    }
                }
                if (m_resizeEdges & Qt::RightEdge) {
                    newGeometry.setRight(m_startGeometry.right() + delta.x());
                    if (newGeometry.right() < newGeometry.left()) {
                        m_resizeEdges = (m_resizeEdges & ~Qt::RightEdge) | Qt::LeftEdge;
                        newGeometry.setRight(m_startGeometry.left());
                        m_startPoint.setX(globalPos.x());
                        m_startGeometry = newGeometry;
                        horizontalFlipped = true;
                    }
                }

                // 更新图形的镜像状态
                if (horizontalFlipped) {
                    m_pGraphics->setHorizontalMirrored(!m_pGraphics->isHorizontalMirrored());
                }
                if (verticalFlipped) {
                    m_pGraphics->setVerticalMirrored(!m_pGraphics->isVerticalMirrored());
                }
                
                // 确保框架不会超出父窗口边界
                if (parentWidget()) {
                    QRect parentRect = parentWidget()->rect();
                    newGeometry = newGeometry.intersected(parentRect);
                }
                setGeometry(newGeometry);
                setCursor(getResizeCursor(m_resizeEdges));
            }
            else if (m_isDragging) {
                move(pos() + delta.toPoint());
                m_startPoint = globalPos;
            }
        }
        //event->accept();
    }else {
        QFrame::mouseMoveEvent(event);
    }
}

void GraphicsFrame::mouseReleaseEvent(QMouseEvent *event)
{
    if (ActionConfig::getInstance().currentType() == ActionType::Zoom) {
        QFrame::mousePressEvent(event);
        return;
    }
    if (event->button() == Qt::LeftButton) {
        if (m_isChecked) {
            m_isDragging = false;
            m_isResizing = false;
            emit setGeometryFinished(m_oldGeometry, geometry());
        }else {
            if (m_startPoint == event->globalPosition()) {
                emit clicked();
                check();
                m_resizeEdges = Qt::Edges();
                setCursor(Qt::SizeAllCursor);
            }else {
                QFrame::mouseReleaseEvent(event);
            }
        }
    }
}

void GraphicsFrame::enterEvent(QEnterEvent*event)
{
    if (m_isChecked) {
        setCursor(Qt::SizeAllCursor);
        QFrame::enterEvent(event);
    }
}
void GraphicsFrame::leaveEvent(QEvent *event)
{
    unsetCursor();
    QFrame::leaveEvent(event);
}