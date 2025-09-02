//
// Created by Collei on 25-4-29.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <qcontainerfwd.h>
#include <QRect>
#include <QVector>
#include <QObject>
#include <QPainter>
#include <QPainterPath>
#include <QPolygon>
#include <QLineEdit>
#include <QMouseEvent>

class Graphics : public QObject
{
    Q_OBJECT
public:
    explicit Graphics(QObject *parent = nullptr):QObject(parent), m_position(2, 2), m_borderColor(Qt::black), m_filledColor(Qt::transparent), m_borderWidth(2), m_borderStyle(Qt::SolidLine), m_width(0), m_height(0), m_isVerticalMirrored(false), m_isHorizontalMirrored(false) {
    }
    Graphics(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr): QObject(parent), m_position(position), m_width(width), m_height(height), m_isVerticalMirrored(false), m_isHorizontalMirrored(false) ,m_borderColor(lineColor), m_filledColor(bgColor) {

    }
    Graphics(const Graphics& other, QObject *parent = nullptr) :
        QObject(other.parent()),
        m_position(other.m_position),
        m_borderColor(other.m_borderColor),
        m_filledColor(other.m_filledColor),
        m_borderWidth(other.m_borderWidth),
        m_borderStyle(other.m_borderStyle),
        m_width(other.m_width),
        m_height(other.m_height),
        m_isVerticalMirrored(other.m_isVerticalMirrored),
        m_isHorizontalMirrored(other.m_isHorizontalMirrored)
    {
    }
    ~Graphics() override = default;
    virtual void paint(QPainter *painter) = 0;

    virtual void setPosition(const QPoint &position) {m_position = position;}
    [[nodiscard]] QPoint position() const{return m_position;}

    // 设置和获取颜色
    void setBorderColor(const QColor &borderColor) {m_borderColor = borderColor;}
    void setBorderWidth(const int &borderWidth) {m_borderWidth = borderWidth;}
    void setFilledColor(const QColor &filledColor) {m_filledColor = filledColor;}
    void setBorderStyle(const Qt::PenStyle borderStyle) {m_borderStyle = borderStyle;};
    void setSize(int width, int height) {m_width = width; m_height = height;}
    void setVerticalMirrored(bool mirrored) {m_isVerticalMirrored = mirrored;}
    void setHorizontalMirrored(bool mirrored) {m_isHorizontalMirrored = mirrored;}

    [[nodiscard]] QColor borderColor() const{return m_borderColor;}
    [[nodiscard]] int borderWidth() const{return m_borderWidth;}
    [[nodiscard]] QColor filledColor() const{return m_filledColor;}
    [[nodiscard]] Qt::PenStyle borderStyle() const{return m_borderStyle;}
    [[nodiscard]] int width() const{return m_width;}
    [[nodiscard]] int height() const{return m_height;}
    [[nodiscard]] bool isVerticalMirrored() const {return m_isVerticalMirrored;}
    [[nodiscard]] bool isHorizontalMirrored() const {return m_isHorizontalMirrored;}

protected:
    QPoint m_position;
    //QVector<QPoint> points;
    int m_width;    //基类宽度，用于调节位置
    int m_height;   //基类高度，用于调节位置
    bool m_isVerticalMirrored;   //垂直镜像
    bool m_isHorizontalMirrored; //水平镜像

    QColor m_borderColor;
    QColor m_filledColor;
    int m_borderWidth;
    Qt::PenStyle m_borderStyle;
};

class Line : public Graphics{
    Q_OBJECT
public:
    explicit Line( QObject *parent = nullptr):Graphics(parent)  {

    }
    explicit Line(const QPoint &position, const int width, const int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {

    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);
        
        QPointF startPoint = m_position;
        QPointF endPoint = m_position + QPointF(m_width, m_height);
        
        if (m_isHorizontalMirrored) {
            startPoint.setX(m_position.x() + m_width);
            endPoint.setX(m_position.x());
        }
        
        if (m_isVerticalMirrored) {
            startPoint.setY(m_position.y() + m_height);
            endPoint.setY(m_position.y());
        }
        
        painter->drawLine(startPoint, endPoint);
        painter->restore();
    }
};

class Circle : public Graphics{
    Q_OBJECT
public:
    explicit Circle( QObject *parent = nullptr):Graphics(parent)  {
    }
    explicit Circle(const QPoint &position, const int width, const int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {
    }
    explicit Circle(const Graphics& other, QObject *parent = nullptr) :Graphics(other, parent){

    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);
        painter->drawEllipse(QPoint(m_position.x() + m_width / 2, m_position.y() + m_height / 2), m_width / 2, m_height / 2);
        painter->restore();
    }
};

class Rectangle : public Graphics {
    Q_OBJECT
public:
    explicit Rectangle( QObject *parent = nullptr):Graphics(parent)  {

    }
    explicit Rectangle(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {

    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);
        
        // 镜像处理
        QTransform transform;
        transform.translate(m_position.x() + m_width / 2, m_position.y() + m_height / 2);
        
        if (m_isHorizontalMirrored) {
            transform.scale(-1, 1);
        }
        
        if (m_isVerticalMirrored) {
            transform.scale(1, -1);
        }
        
        transform.translate(-(m_position.x() + m_width / 2), -(m_position.y() + m_height / 2));
        painter->setTransform(transform);
        
        painter->drawRect(QRect(m_position, QSize(m_width, m_height)));
        painter->restore();
    }
};

class RoundedRectangle : public Graphics {
    Q_OBJECT
public:
    explicit RoundedRectangle( QObject *parent = nullptr):Graphics(parent)  {

    }
    explicit RoundedRectangle(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {

    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);
        
        // 镜像处理
        QTransform transform;
        transform.translate(m_position.x() + m_width / 2, m_position.y() + m_height / 2);
        
        if (m_isHorizontalMirrored) {
            transform.scale(-1, 1);
        }
        
        if (m_isVerticalMirrored) {
            transform.scale(1, -1);
        }
        
        transform.translate(-(m_position.x() + m_width / 2), -(m_position.y() + m_height / 2));
        painter->setTransform(transform);
        
        painter->drawRoundedRect(QRect(m_position, QSize(m_width, m_height)), 5, 5);
        painter->restore();
    }
};

class Triangle : public Graphics {
    Q_OBJECT
public:
    explicit Triangle( QObject *parent = nullptr):Graphics(parent)  {

    }
    explicit Triangle(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {

    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);

        QPoint top(m_position.x() + m_width / 2, m_position.y());
        QPoint bottomLeft(m_position.x(), m_position.y() + m_height);
        QPoint bottomRight(m_position.x() + m_width, m_position.y() + m_height);
        
        // 应用镜像变换
        if (m_isHorizontalMirrored) {
            top.setX(m_position.x() + m_width - (top.x() - m_position.x()));
            bottomLeft.setX(m_position.x() + m_width - (bottomLeft.x() - m_position.x()));
            bottomRight.setX(m_position.x() + m_width - (bottomRight.x() - m_position.x()));
        }
        
        if (m_isVerticalMirrored) {
            top.setY(m_position.y() + m_height - (top.y() - m_position.y()));
            bottomLeft.setY(m_position.y() + m_height - (bottomLeft.y() - m_position.y()));
            bottomRight.setY(m_position.y() + m_height - (bottomRight.y() - m_position.y()));
        }

        QPolygon triangle;
        triangle << top << bottomLeft << bottomRight;
        painter->drawPolygon(triangle);
        painter->restore();
    }
};

class Diamond : public Graphics {
    Q_OBJECT
public:
    explicit Diamond( QObject *parent = nullptr):Graphics(parent)  {

    }
    explicit Diamond(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {

    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);
        
        QPoint top(m_position.x() + m_width / 2, m_position.y());
        QPoint right(m_position.x() + m_width , m_position.y() + m_height / 2);
        QPoint bottom(m_position.x() + m_width / 2, m_position.y() + m_height);
        QPoint left(m_position.x(), m_position.y() + m_height / 2);

        if (m_isHorizontalMirrored) {
            top.setX(m_position.x() + m_width - (top.x() - m_position.x()));
            right.setX(m_position.x() + m_width - (right.x() - m_position.x()));
            bottom.setX(m_position.x() + m_width - (bottom.x() - m_position.x()));
            left.setX(m_position.x() + m_width - (left.x() - m_position.x()));
        }
        
        if (m_isVerticalMirrored) {
            top.setY(m_position.y() + m_height - (top.y() - m_position.y()));
            right.setY(m_position.y() + m_height - (right.y() - m_position.y()));
            bottom.setY(m_position.y() + m_height - (bottom.y() - m_position.y()));
            left.setY(m_position.y() + m_height - (left.y() - m_position.y()));
        }
        
        QPolygon diamond;
        diamond << top << right << bottom << left;
        painter->drawPolygon(diamond);
        painter->restore();
    }
};

class RightTriangle : public Graphics {
    Q_OBJECT
public:
    explicit RightTriangle( QObject *parent = nullptr):Graphics(parent)  {

    }
    explicit RightTriangle(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {

    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);
        
        QPoint top(m_position.x(), m_position.y());
        QPoint right(m_position.x() + m_width , m_position.y() + m_height);
        QPoint vertex(m_position.x(), m_position.y() + m_height);
        
        // 应用镜像变换
        if (m_isHorizontalMirrored) {
            top.setX(m_position.x() + m_width - (top.x() - m_position.x()));
            right.setX(m_position.x() + m_width - (right.x() - m_position.x()));
            vertex.setX(m_position.x() + m_width - (vertex.x() - m_position.x()));
        }
        
        if (m_isVerticalMirrored) {
            top.setY(m_position.y() + m_height - (top.y() - m_position.y()));
            right.setY(m_position.y() + m_height - (right.y() - m_position.y()));
            vertex.setY(m_position.y() + m_height - (vertex.y() - m_position.y()));
        }

        QPolygon rightTriangle;
        rightTriangle << top << right << vertex;
        painter->drawPolygon(rightTriangle);
        painter->restore();
    }
};

class Pentagon : public Graphics {
    Q_OBJECT
public:
    explicit Pentagon( QObject *parent = nullptr):Graphics(parent)  {

    }
    explicit Pentagon(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {

    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);
        
        // 镜像处理
        QTransform transform;
        transform.translate(m_position.x() + m_width / 2, m_position.y() + m_height / 2);
        
        if (m_isHorizontalMirrored) {
            transform.scale(-1, 1);
        }
        
        if (m_isVerticalMirrored) {
            transform.scale(1, -1);
        }
        
        transform.translate(-(m_position.x() + m_width / 2), -(m_position.y() + m_height / 2));
        painter->setTransform(transform);
        
        QPointF top(m_position.x() + m_width / 2, m_position.y());
        double ratioH = (1 - std::cos(0.4 * M_PI)) / (1 + std::cos(0.2 * M_PI));
        double ratioW = 0.5 - std::sin(0.2 * M_PI) / (2 * std::sin(0.4 * M_PI));
        QPointF left(m_position.x(), m_position.y() + m_height * ratioH);
        QPointF right(m_position.x() + m_width, m_position.y() + m_height * ratioH);
        QPointF bottomLeft(m_position.x() + m_width * ratioW, m_position.y() + m_height);
        QPointF bottomRight(m_position.x() + m_width * (1 - ratioW), m_position.y() + m_height);
        QVector<QPointF> points{top, left,  bottomLeft, bottomRight, right};
        QPolygonF pentagon(points);
        painter->drawPolygon(pentagon);
        painter->restore();
    }
};

class Hexagon : public Graphics {
    Q_OBJECT
public:
    explicit Hexagon( QObject *parent = nullptr):Graphics(parent)  {

    }
    explicit Hexagon(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {

    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);
        
        // 镜像处理
        QTransform transform;
        transform.translate(m_position.x() + m_width / 2, m_position.y() + m_height / 2);
        
        if (m_isHorizontalMirrored) {
            transform.scale(-1, 1);
        }
        
        if (m_isVerticalMirrored) {
            transform.scale(1, -1);
        }
        
        transform.translate(-(m_position.x() + m_width / 2), -(m_position.y() + m_height / 2));
        painter->setTransform(transform);
        
        QPoint topLeft(m_position.x() + m_width / 4, m_position.y());
        QPoint topRight(m_position.x() + m_width * 3 / 4, m_position.y());
        QPoint left(m_position.x(), m_position.y() + m_height / 2);
        QPoint right(m_position.x() + m_width, m_position.y() + m_height / 2);
        QPoint bottomLeft(m_position.x() + m_width / 4, m_position.y() +  m_height);
        QPoint bottomright(m_position.x() + m_width * 3 / 4, m_position.y() + m_height);
        QPolygon hexagon;
        hexagon << topLeft << left << bottomLeft << bottomright << right <<topRight;
        painter->drawPolygon(hexagon);
        painter->restore();
    }
};

class Pentagram : public Graphics {
    Q_OBJECT
public:
    explicit Pentagram( QObject *parent = nullptr):Graphics(parent)  {

    }
    explicit Pentagram(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr):Graphics(position, width, height, lineColor, bgColor, parent )  {

    }
    QPointF getIntersection(QPointF p1, QPointF p2, QPointF p3, QPointF p4) {
        double x1 = p1.x(), y1 = p1.y();
        double x2 = p2.x(), y2 = p2.y();
        double x3 = p3.x(), y3 = p3.y();
        double x4 = p4.x(), y4 = p4.y();
        double denom = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4);
        double px = ((x1*y2 - y1*x2)*(x3 - x4) - (x1 - x2)*(x3*y4 - y3*x4)) / denom;
        double py = ((x1*y2 - y1*x2)*(y3 - y4) - (y1 - y2)*(x3*y4 - y3*x4)) / denom;
        return QPointF(px, py);
    }

    QVector<QPointF> computeStretchedStar() {
        QPointF top(m_position.x() + m_width / 2, m_position.y());
        double ratioH = (1 - std::cos(0.4 * M_PI)) / (1 + std::cos(0.2 * M_PI));
        double ratioW = 0.5 - std::sin(0.2 * M_PI) / (2 * std::sin(0.4 * M_PI));
        QPointF left(m_position.x(), m_position.y() + m_height * ratioH);
        QPointF right(m_position.x() + m_width, m_position.y() + m_height * ratioH);
        QPointF bottomLeft(m_position.x() + m_width * ratioW, m_position.y() + m_height);
        QPointF bottomRight(m_position.x() + m_width * (1 - ratioW), m_position.y() + m_height);
        QVector<QPointF> outsidePoints{top, left,  bottomLeft, bottomRight, right};
        QVector<QPointF> insidePoints;
        for (int i = 0; i < outsidePoints.size(); ++i) {
            insidePoints.push_back(getIntersection(outsidePoints[(i + 4) % 5], outsidePoints[(i + 1) % 5], outsidePoints[(i ) % 5], outsidePoints[(i + 2) % 5]));
        }
        QVector<QPointF> totalPoints;
        auto outPoint = outsidePoints.begin();
        auto inPoint = insidePoints.begin();
        while (outPoint != outsidePoints.end()) {
            totalPoints.push_back(*outPoint);
            totalPoints.push_back(*inPoint);
            ++outPoint;
            ++inPoint;
        }
        return totalPoints;
    }
    void paint(QPainter *painter) override {
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->setBrush(m_filledColor);
        
        // 镜像处理
        QTransform transform;
        transform.translate(m_position.x() + m_width / 2, m_position.y() + m_height / 2);
        
        if (m_isHorizontalMirrored) {
            transform.scale(-1, 1);
        }
        
        if (m_isVerticalMirrored) {
            transform.scale(1, -1);
        }
        
        transform.translate(-(m_position.x() + m_width / 2), -(m_position.y() + m_height / 2));
        painter->setTransform(transform);
        
        QVector<QPointF> points = computeStretchedStar();
        QPolygonF pentagram(points);
        painter->drawPolygon(pentagram);
        painter->restore();
    }
};

class Pen : public Graphics {
    Q_OBJECT
public:
    explicit Pen(QObject *parent = nullptr) : Graphics(parent), m_minX(INT_MAX), m_minY(INT_MAX), m_maxX(INT_MIN), m_maxY(INT_MIN) {
    }
    
    explicit Pen(const QPoint &position, int width, int height, const QColor &lineColor, const QColor &bgColor, QObject *parent = nullptr)
        : Graphics(position, width, height, lineColor, bgColor, parent), m_minX(INT_MAX), m_minY(INT_MAX), m_maxX(INT_MIN), m_maxY(INT_MIN) {
    }
    
    void addPoint(const QPoint &point) {
        m_points.append(point);

        if (m_points.size() == 1) {
            // 第一个点直接 moveTo
            m_path.moveTo(point);
            m_position = point;
            m_minX = m_maxX = point.x();
            m_minY = m_maxY = point.y();
        } else if (m_points.size() == 2) {
            const QPoint &p0 = m_points[0];
            const QPoint &p1 = m_points[1];
            QPointF mid((p0.x() + p1.x()) / 2.0, (p0.y() + p1.y()) / 2.0);
            m_path.lineTo(mid);  // 为后续 quadTo 做准备
        } else {
            const QPoint &pLast = m_points[m_points.size() - 2];
            const QPoint &pCurr = m_points[m_points.size() - 1];
            QPointF mid((pLast.x() + pCurr.x()) / 2.0, (pLast.y() + pCurr.y()) / 2.0);
            m_path.quadTo(pLast, mid);
        }
        m_minX = qMin(m_minX, point.x());
        m_minY = qMin(m_minY, point.y());
        m_maxX = qMax(m_maxX, point.x());
        m_maxY = qMax(m_maxY, point.y());
        updateBounds();
    }

    void paint(QPainter *painter)  override{
        if (m_points.isEmpty()) {
            return;
        }
        painter->save();
        painter->setPen(QPen(m_borderColor, m_borderWidth, m_borderStyle));
        painter->drawPath(m_path);
        painter->restore();
    }

    void setPosition(const QPoint &newPosition) override {
        for (int i = 0; i < m_points.size(); ++i) {
            m_points[i].setX(m_points[i].x() - m_position.x() + newPosition.x());
            m_points[i].setY(m_points[i].y() - m_position.y() + newPosition.y());
        }
        m_position = newPosition;
        m_path.clear();
        m_path.moveTo(m_points.front());
        for (int i = 1; i < m_points.size() - 1; ++i) {
            QPointF ctrl = m_points[i];
            QPointF mid = (m_points[i] + m_points[i + 1]) / 2.0;
            m_path.quadTo(ctrl, mid);
        }
        m_path.lineTo(m_points.last());
    }
    
private:
    void updateBounds() {
        m_width = m_maxX - m_minX + 2;
        m_height = m_maxY - m_minY + 2;
        m_position = QPoint(m_minX, m_minY);
    }
    
    QPainterPath m_path;
    QVector<QPoint> m_points;
    int m_minX, m_minY;
    int m_maxX, m_maxY;
};

#endif //GRAPHICS_H
