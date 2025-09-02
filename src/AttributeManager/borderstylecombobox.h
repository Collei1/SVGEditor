// LineStyleDelegate.h

#ifndef LINESTYLEDELEGATE_H
#define LINESTYLEDELEGATE_H

#include <QComboBox>
#include <QPainter>
#include <QStyledItemDelegate>

class LineStyleDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit LineStyleDelegate(QObject* parent = nullptr);
    void paint(QPainter* painter, const QStyleOptionViewItem& option,
               const QModelIndex& index) const override;
};

class BorderStyleComboBox : public QComboBox {
    Q_OBJECT
public:
    explicit BorderStyleComboBox(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    LineStyleDelegate* m_delegate;
};

#endif // LINESTYLEDELEGATE_H
