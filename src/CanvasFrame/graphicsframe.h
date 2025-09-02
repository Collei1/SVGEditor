//
// Created by Collei on 25-5-2.
//

#ifndef GRAPHICSFRAME_H
#define GRAPHICSFRAME_H
#include <QFrame>
#include "../Graphics/config.h"
#include "../Graphics/graphics.h"

class GraphicsFrame : public QFrame{
    Q_OBJECT
public:
    explicit GraphicsFrame(ActionType type, std::unique_ptr<Graphics> graphics, QWidget *parent = nullptr);
    ~GraphicsFrame() override = default;

    void check();
    void uncheck();
    void setSize(QPoint startPoint, QPoint endPoint);
    void setGraphicsData(const GraphicsData& graphicsData);

    [[nodiscard]] ActionType getActionType() const;
    [[nodiscard]] Graphics* getGraphics() const { return m_pGraphics.get(); }
    [[nodiscard]] GraphicsData getGraphicsData() const;

    signals:
    void clicked();
    void setGeometryFinished(QRect oldGeometry, QRect newGeometry);
    public slots:
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    ActionType m_actionType;
    std::unique_ptr<Graphics> m_pGraphics;
    bool m_isChecked = false;
    QPointF m_startPoint;
    bool m_isDragging = false;
    int m_resizeMargin = 5;
    bool m_isResizing = false;
    Qt::Edges m_resizeEdges;
    QRect m_startGeometry;
    QRect m_oldGeometry;

    [[nodiscard]] Qt::Edges getEdgesAt(const QPoint &pos) const {
        Qt::Edges edges;
        if (pos.x() <= m_resizeMargin)
            edges |= Qt::LeftEdge;
        if (pos.x() >= width() - m_resizeMargin)
            edges |= Qt::RightEdge;
        if (pos.y() <= m_resizeMargin)
            edges |= Qt::TopEdge;
        if (pos.y() >= height() - m_resizeMargin)
            edges |= Qt::BottomEdge;
        return edges;
    }

    [[nodiscard]] QCursor getResizeCursor(Qt::Edges edges) const {
        if ((edges & Qt::LeftEdge && edges & Qt::TopEdge) ||
            (edges & Qt::RightEdge && edges & Qt::BottomEdge))
            return Qt::SizeFDiagCursor;
        if ((edges & Qt::RightEdge && edges & Qt::TopEdge) ||
            (edges & Qt::LeftEdge && edges & Qt::BottomEdge))
            return Qt::SizeBDiagCursor;
        if (edges & Qt::LeftEdge || edges & Qt::RightEdge)
            return Qt::SizeHorCursor;
        if (edges & Qt::TopEdge || edges & Qt::BottomEdge)
            return Qt::SizeVerCursor;
        return Qt::ArrowCursor;
    }
};

#endif //GRAPHICSFRAME_H
