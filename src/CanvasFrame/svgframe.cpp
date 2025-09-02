//
// Created by Collei on 25-5-23.
//

#include "svgframe.h"

SvgFrame::SvgFrame(const QString &svgPath, QWidget *parent)
        : QFrame(parent), renderer(new QSvgRenderer(svgPath, this)) {

    if (renderer->isValid()) {
        QSize svgSize = parent->size();
        setFixedSize(svgSize);
    }
}
SvgFrame::~SvgFrame() = default;

void SvgFrame::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    renderer->render(&painter, contentsRect());
    renderer->setAspectRatioMode(Qt::KeepAspectRatio);
}