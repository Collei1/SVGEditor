//
// Created by Collei on 25-5-22.
//

#include "textframe.h"

#include <qcoreapplication.h>
#include <QFont>
#include <QFontMetrics>

TextFrame::TextFrame(QWidget* parent)
    : QLineEdit(parent)
{
    QFont font = m_textData.m_font;
    font.setPointSize(m_textData.m_size);
    this->setFont(font);
    setText("请输入文字");
    edit();
    adjustSizeToText();
    connect(this, &QLineEdit::textChanged, this, [this]() {
        adjustSizeToText();
    });
    setFocus();
    setFocusPolicy(Qt::StrongFocus);
}

TextFrame::TextFrame(const TextFrame& other)
    : QLineEdit(other.parentWidget()),
      m_textData(other.m_textData)
{
    QFont font = m_textData.m_font;
    font.setPointSize(m_textData.m_size);
    this->setFont(font);
    setText(other.text());
    if (other.isModified()) {
        setModified(true);
    }
    connect(this, &QLineEdit::textChanged, this, [this]() {
        adjustSizeToText();
    });
    uncheck();
    setFocusPolicy(other.focusPolicy());
    adjustSizeToText();
}

void TextFrame::edit()
{
    setCursor(Qt::IBeamCursor);
    setReadOnly(false);
    setFocus();
    selectAll();
    setStyleSheet(QString::fromUtf8("border:2px dashed blue;background:transparent;color: %1").arg(m_textData.m_textColor.name()));
}

void TextFrame::check()
{
    setReadOnly(true);
    m_isChecked = true;
    setStyleSheet(QString::fromUtf8("border:2px solid blue;background:transparent;color: %1").arg(m_textData.m_textColor.name()));
    setCursor(Qt::SizeAllCursor);
}

void TextFrame::uncheck()
{
    setReadOnly(true);
    m_isChecked = false;
    deselect();
    setStyleSheet(QString::fromUtf8("border:none;background:transparent;color: %1").arg(m_textData.m_textColor.name()));
}

void TextFrame::setTextData(const TextData &textData) {
    this->m_textData = textData;
    QFont font = m_textData.m_font;
    font.setPointSize(m_textData.m_size);
    font.setBold(m_textData.m_bold);
    font.setItalic(m_textData.m_italic);
    font.setUnderline(m_textData.m_underline);
    setStyleSheet(QString::fromUtf8("border:2px solid blue;background:transparent;color: %1").arg(m_textData.m_textColor.name()));
    setFont(font);
    adjustSizeToText();
}

TextData TextFrame::getTextData() const {
    return m_textData;
}

void TextFrame::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
        m_startPoint = event->globalPos();
        m_oldPosition = pos();
        m_isDragging = true;
        check();
    }
    QLineEdit::mousePressEvent(event);
}

void TextFrame::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton && m_isDragging) {
        QPointF globalPos = event->globalPos();
        QPointF delta = globalPos - m_startPoint;
        move(pos() + delta.toPoint());
        m_startPoint = globalPos;
    }
}

void TextFrame::mouseReleaseEvent(QMouseEvent* event)
{
    if ( m_isDragging){
        m_isDragging = false;
        emit moveFinished(m_oldPosition, pos());
    }
    QLineEdit::mouseReleaseEvent(event);
}

void TextFrame::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        check();
        adjustSizeToText();
        emit textContentChanged(m_oldText, text());
    }
    QLineEdit::keyPressEvent(event);
    QCoreApplication::sendEvent(parent(), event);
}

void TextFrame::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        edit();
        m_oldText = text();
    }
    QLineEdit::mouseDoubleClickEvent(event);
}

void TextFrame::focusOutEvent(QFocusEvent* event)
{
    uncheck();
    QLineEdit::focusOutEvent(event);
}

void TextFrame::adjustSizeToText()
{
    int textWidth = fontMetrics().horizontalAdvance(text()) + 10;
    int textHeight = m_textData.m_size * 2 + 5;
    setFixedWidth(textWidth);
    setFixedHeight(textHeight);
    if (text().isEmpty()) {
        setFixedWidth(fontMetrics().horizontalAdvance("请输入文字") + 10);
    }
}