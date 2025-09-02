//
// Created by Collei on 25-5-16.
//

#include "overlaywidget.h"

#include <iostream>
#include <QFrame>
#include <QMouseEvent>

#include "graphicsframe.h"

OverlayWidget::OverlayWidget(QWidget *parent):QWidget(parent), m_pBasicFactory(new BasicFactory()) {

}

OverlayWidget::~OverlayWidget() {
    delete m_pBasicFactory;
}

std::unique_ptr<Graphics> OverlayWidget::getGraphics() {
    return std::move(m_pGraphics);
}

void OverlayWidget::setStartPoint(const QPoint point) {
    m_startPoint = point;
}

void OverlayWidget::mousePressEvent(QMouseEvent *event) {
    const ActionType actionType = ActionConfig::getInstance().currentType();
    if (actionType == ActionType::Arrow || actionType == ActionType::Zoom || actionType == ActionType::Text) {
        return;
    }
    if (event->button() == Qt::LeftButton) {
        m_startPoint = event->pos();
        m_isDrawing = true;
    }
}

void OverlayWidget::mouseMoveEvent(QMouseEvent *event){
    const ActionType actionType = ActionConfig::getInstance().currentType();
    if (actionType == ActionType::Arrow || actionType == ActionType::Zoom || actionType == ActionType::Text) {
        return;
    }
    m_endPoint = event->pos();

    if (!m_isConstructed) {// 构造新frame
        m_isConstructed = true;
        m_pGraphics = m_pBasicFactory->createGraphics(this);
        if (actionType == ActionType::Pen) {
            dynamic_cast<Pen*>(m_pGraphics.get())->addPoint(m_startPoint);
            update();
        }else {
            m_pGraphics->setPosition(m_startPoint);
        }
    }else {
        if (actionType == ActionType::Pen) {
            dynamic_cast<Pen*>(m_pGraphics.get())->addPoint(m_endPoint);
        }else {
            int newWidth = m_endPoint.x() - m_startPoint.x();
            int newHeight = m_endPoint.y() - m_startPoint.y();
            QPoint newPos = m_startPoint;

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
            m_pGraphics->setPosition(newPos);
            m_pGraphics->setSize(newWidth, newHeight);
        }
        update();
    }
}

void OverlayWidget::mouseReleaseEvent(QMouseEvent *event){
    const ActionType actionType = ActionConfig::getInstance().currentType();
    if (actionType == ActionType::Arrow || actionType == ActionType::Zoom || actionType == ActionType::Text) {
        return;
    }
    if (event->button() == Qt::LeftButton) {
        m_endPoint = event->pos();
        if (m_isConstructed) {
            if (actionType == ActionType::Pen) {
                if (!m_pGraphics) {
                    std::cerr<<"m_pGraphics is empty";
                    return;
                }
                dynamic_cast<Pen*>(m_pGraphics.get())->addPoint(m_endPoint);
                update();
            }
            emit graphicsFinished();
            m_isConstructed = false;
        }
    }
}

void OverlayWidget::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);
    QPainter painter(this);
    if (m_isConstructed) {
        m_pGraphics->paint(&painter);
    }
}