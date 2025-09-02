// LineStyleDelegate.cpp

#include "borderstylecombobox.h"

LineStyleDelegate::LineStyleDelegate(QObject* parent)
    : QStyledItemDelegate(parent) {}

void LineStyleDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,
                               const QModelIndex& index) const {
    painter->save();

    bool selected = option.state & QStyle::State_Selected;
    QRect rect = option.rect;

    // 填充背景
    QColor bgColor = selected ? option.palette.highlight().color() : option.palette.base().color();
    painter->fillRect(rect, bgColor);

    // 获取线条样式
    QVariant value = index.data(Qt::UserRole);
    if (!value.isValid()) {
        painter->restore();
        QStyledItemDelegate::paint(painter, option, index);  // fallback
        return;
    }

    Qt::PenStyle style = static_cast<Qt::PenStyle>(value.toInt());
    QPen pen(QColor(0, 111, 255), 2, style);
    painter->setPen(pen);
    int y = rect.center().y();
    int margin = 10;
    painter->drawLine(rect.left() + margin, y, rect.right() - margin, y);

    painter->restore();
}

BorderStyleComboBox::BorderStyleComboBox(QWidget* parent)
    : QComboBox(parent), m_delegate(new LineStyleDelegate(this)) {}

void BorderStyleComboBox::paintEvent(QPaintEvent* event) {
    QStyleOptionComboBox opt;
    initStyleOption(&opt);

    QPainter painter(this);
    // 绘制 combo 框边框等
    style()->drawComplexControl(QStyle::CC_ComboBox, &opt, &painter, this);

    // 获取当前 index
    QModelIndex idx = model()->index(currentIndex(), modelColumn(), rootModelIndex());
    if (!idx.isValid()) return;

    // 获取 item 区域
    QRect displayRect = style()->subControlRect(QStyle::CC_ComboBox, &opt,
                                                QStyle::SC_ComboBoxEditField, this);
    QStyleOptionViewItem itemOpt;
    itemOpt.rect = displayRect;
    itemOpt.palette = opt.palette;
    itemOpt.state = QStyle::State_Enabled | QStyle::State_Active;
    if (hasFocus())
        itemOpt.state |= QStyle::State_HasFocus;

    m_delegate->paint(&painter, itemOpt, idx);
}
