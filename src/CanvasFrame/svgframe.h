//
// Created by Collei on 25-5-23.
//

#ifndef SVGFRAME_H
#define SVGFRAME_H


#include <QFrame>
#include <QSvgRenderer>
#include <QPainter>

class SvgFrame : public QFrame {
    Q_OBJECT
public:
    explicit  SvgFrame(const QString &svgPath, QWidget *parent = nullptr);
    ~SvgFrame() override;

protected:
    void paintEvent(QPaintEvent *) override ;

private:
    QSvgRenderer *renderer;
};

#endif //SVGFRAME_H
