//
// Created by Collei on 25-5-22.
//

#ifndef TEXTFRAME_H
#define TEXTFRAME_H

#include <QLineEdit>
#include <QColor>
#include <QKeyEvent>
#include "../Graphics/config.h"

class TextFrame : public QLineEdit
{
    Q_OBJECT
public:
    explicit TextFrame(QWidget* parent = nullptr);
    TextFrame(const TextFrame& other);
    void edit();
    void check();
    void uncheck();
    //void setTextColor(const QColor &textColor);
    //[[nodiscard]] QColor textColor() const { return m_textColor; }
    void setTextData(const TextData &textData);
    [[nodiscard]] TextData getTextData() const;

    signals:
        void clicked();
        void moveFinished(QPoint oldPosition, QPoint newPosition);
        void textContentChanged(const QString &oldText, const QString &newText);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void focusOutEvent(QFocusEvent* event) override;

private:
    void adjustSizeToText();

    QPointF m_startPoint;
    QPoint m_oldPosition;
    bool m_isDragging = false;
    bool m_isChecked = false;

    TextData m_textData;
    QString m_oldText{};
};

#endif // TEXTFRAME_H
