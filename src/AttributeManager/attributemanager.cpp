//
// Created by Collei on 25-5-20.
//

#include <QColorDialog>
#include "borderstylecombobox.h"
#include "attributemanager.h"

#include <QToolButton>

AttributeManager::AttributeManager(const CanvasData& canvasData, QWidget* parent) : QObject(parent), m_canvasData(canvasData) {
}

AttributeManager::~AttributeManager() {
    RegeditSettings::getInstance().setCanvasData(m_canvasData);
}

void AttributeManager::setupUi(QFrame *canvasWidthFrame,
        QSpinBox *canvasWidthSpinBox,
        QFrame *canvasHeightFrame,
        QSpinBox *canvasHeightSpinBox,
        QFrame *zoomRatioFrame,
        QSpinBox *zoomRatioSpinBox,
        QFrame *canvasColorFrame,
        QPushButton *canvasColorPushButton,
        QFrame *borderWidthFrame,
        QSpinBox *borderWidthSpinBox,
        QFrame *borderColorFrame,
        QPushButton *borderColorPushButton,
        QFrame *filledColorFrame,
        QPushButton *filledColorPushButton,
        QFrame *borderStyleFrame,
        QComboBox* borderStyleComboBox,
        QFrame* textColorFrame,
        QPushButton* textColorBtn,
        QFrame *fontFrame,
        QFontComboBox* fontComboBox,
        QFrame *textSettingFrame,
        QToolButton* boldBtn,
        QToolButton* italicBtn,
        QToolButton* underlineBtn,
        QComboBox* fontSizeComboBox,
        QFrame *posFrame,
        QPushButton *upBtn,
        QPushButton *downBtn,
        QPushButton *topBtn,
        QPushButton *bottomBtn
        ) {
    this->m_pCanvasWidthFrame = canvasWidthFrame;
    this->m_pCanvasWidthSpinBox = canvasWidthSpinBox;
    this->m_pCanvasWidthSpinBox->setValue(m_canvasData.m_canvasWidth);
    this->m_pCanvasHeightFrame = canvasHeightFrame;
    this->m_pCanvasHeightSpinBox = canvasHeightSpinBox;
    this->m_pCanvasHeightSpinBox->setValue(m_canvasData.m_canvasHeight);
    this->m_pZoomRatioFrame = zoomRatioFrame;
    this->m_pZoomRatioSpinBox = zoomRatioSpinBox;
    this->m_pZoomRatioSpinBox->setValue(static_cast<int>(m_canvasData.m_zoomRatio * 100));
    this->m_pCanvasColorFrame = canvasColorFrame;
    this->m_pCanvasColorPushButton = canvasColorPushButton;
    this->m_pCanvasColorPushButton->setStyleSheet(QString("background-color: %1").arg(m_canvasData.m_canvasColor.name()));

    this->m_pBorderWidthFrame = borderWidthFrame;
    this->m_pBorderWidthSpinBox = borderWidthSpinBox;
    this->m_pBorderColorFrame = borderColorFrame;
    this->m_pBorderColorPushButton = borderColorPushButton;
    this->m_pFilledColorFrame = filledColorFrame;
    this->m_pFilledColorPushButton = filledColorPushButton;
    this->m_pBorderStyleFrame = borderStyleFrame;
    this->m_pBorderStyleComboBox = borderStyleComboBox;
    this->m_pPosFrame = posFrame;
    this->m_pUpBtn = upBtn;
    this->m_pDownBtn = downBtn;
    this->m_pTopBtn = topBtn;
    this->m_pBottomBtn = bottomBtn;

    this->m_pTextColorFrame = textColorFrame;
    this->m_pTextColorBtn = textColorBtn;
    this->m_pFontFrame = fontFrame;
    this->m_pFontComboBox = fontComboBox;
    this->m_pTextSettingFrame = textSettingFrame;
    this->m_pBoldBtn = boldBtn;
    this->m_pItalicBtn = italicBtn;
    this->m_pUnderlineBtn = underlineBtn;
    this->m_pFontSizeComboBox = fontSizeComboBox;

    m_pBorderStyleComboBox->setGeometry(5, 30, 80, 38);
    m_pBorderStyleComboBox->setItemDelegate(new LineStyleDelegate(m_pBorderStyleComboBox));

    for (int i = 0;i < BorderStyleConfig::getInstance().amount(); ++i) {
        m_pBorderStyleComboBox->addItem("");
        m_pBorderStyleComboBox->setItemData(i, static_cast<int>(BorderStyleConfig::getInstance().getPenStyles(i)), Qt::UserRole);
    }
    m_pBorderStyleComboBox->show();

    m_pBorderColorFrame->hide();
    m_pFilledColorFrame->hide();
    m_pBorderWidthFrame->hide();
    m_pBorderStyleFrame->hide();
    m_pPosFrame->hide();

    connect(m_pCanvasWidthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &AttributeManager::onCanvasWidthChanged);
    connect(m_pCanvasHeightSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &AttributeManager::onCanvasHeightChanged);
    connect(m_pZoomRatioSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &AttributeManager::onZoomRatioChanged);
    connect(m_pCanvasColorPushButton, &QPushButton::clicked, this, &AttributeManager::onCanvasColorBtnClicked);

    connect(m_pBorderColorPushButton, &QPushButton::clicked, this, &AttributeManager::onBorderColorBtnClicked);
    connect(m_pFilledColorPushButton, &QPushButton::clicked, this, &AttributeManager::onFilledColorBtnClicked);
    connect(m_pBorderWidthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &AttributeManager::onBorderWidthChanged);
    connect(m_pBorderStyleComboBox, QOverload<int>::of(&BorderStyleComboBox::currentIndexChanged), this, &AttributeManager::onBorderStyleComboBoxChanged);
    connect(m_pUpBtn, &QPushButton::clicked, this, &AttributeManager::onUpBtnClicked);
    connect(m_pDownBtn, &QPushButton::clicked, this, &AttributeManager::onDownBtnClicked);
    connect(m_pTopBtn, &QPushButton::clicked, this, &AttributeManager::onTopBtnClicked);
    connect(m_pBottomBtn, &QPushButton::clicked, this, &AttributeManager::onBottomBtnClicked);

    connect(m_pTextColorBtn, &QPushButton::clicked, this, &AttributeManager::onTextColorBtnClicked);
    connect(m_pFontComboBox, &QFontComboBox::currentFontChanged, this, &AttributeManager::onFontComboBoxChanged);
    connect(m_pBoldBtn, &QToolButton::toggled, this, &AttributeManager::onBoldBtnToggled);
    connect(m_pItalicBtn, &QToolButton::toggled, this, &AttributeManager::onItalicBtnToggled);
    connect(m_pUnderlineBtn, &QToolButton::toggled, this, &AttributeManager::onUnderlineBtnToggled);
    connect(m_pFontSizeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AttributeManager::onFontSizeComboBoxChanged);
}

void AttributeManager::onCanvasWidthChanged(const int width) {
    m_canvasData.m_canvasWidth = width;
    emit canvasDataChanged(m_canvasData);
}
void AttributeManager::onCanvasHeightChanged(const int height) {
    m_canvasData.m_canvasHeight = height;
    emit canvasDataChanged(m_canvasData);
}
void AttributeManager::onZoomRatioChanged(const int ratio) {
    m_canvasData.m_zoomRatio = ratio / 100.0;
    emit canvasDataChanged(m_canvasData);
}

void AttributeManager::onCanvasColorBtnClicked() {
    QColor newColor = QColorDialog::getColor(m_canvasData.m_canvasColor, dynamic_cast<QWidget *>(parent()), "选择颜色");
    if (newColor.isValid() && newColor != m_canvasData.m_canvasColor) {
        dynamic_cast<QPushButton*>(sender())->setStyleSheet(QString("background-color: %1").arg(newColor.name()));
        m_canvasData.m_canvasColor = newColor;
        emit canvasDataChanged(m_canvasData);
    }
}

void AttributeManager::onBorderColorBtnClicked() {
    QColor newColor = QColorDialog::getColor(m_graphicsData.m_borderColor, dynamic_cast<QWidget *>(parent()), "选择颜色");
    if (newColor.isValid() && newColor != m_graphicsData.m_borderColor) {
        dynamic_cast<QPushButton*>(sender())->setStyleSheet(QString("background-color: %1").arg(newColor.name()));
        m_graphicsData.m_borderColor = newColor;
        emit graphicsDataChanged(m_graphicsData);
    }
}
void AttributeManager::onFilledColorBtnClicked() {
    QColor newColor = QColorDialog::getColor(m_graphicsData.m_filledColor, dynamic_cast<QWidget *>(parent()), "选择颜色");
    if (newColor.isValid() && newColor != m_graphicsData.m_filledColor) {
        dynamic_cast<QPushButton*>(sender())->setStyleSheet(QString("background-color: %1").arg(newColor.name()));
        m_graphicsData.m_filledColor = newColor;
        emit graphicsDataChanged(m_graphicsData);
    }
}
void AttributeManager::onBorderWidthChanged(const int width) {
    m_graphicsData.m_borderWidth = width;
    emit graphicsDataChanged(m_graphicsData);
}
void AttributeManager::onBorderStyleComboBoxChanged(int index) {
    QVariant data = m_pBorderStyleComboBox->itemData(index, Qt::UserRole);
    if (data.isValid()) {
        Qt::PenStyle style = static_cast<Qt::PenStyle>(data.toInt());
        m_graphicsData.m_borderStyle = style;
        emit graphicsDataChanged(m_graphicsData);
    }
}
void  AttributeManager::onUpBtnClicked() {
    emit upDownChanged(true);
}
void  AttributeManager::onDownBtnClicked() {
    emit upDownChanged(false);
}
void  AttributeManager::onTopBtnClicked() {
    emit topBottomChanged(true);
}
void  AttributeManager::onBottomBtnClicked() {
    emit topBottomChanged(false);
}

void AttributeManager::onTextColorBtnClicked() {
    QColor newColor = QColorDialog::getColor(m_textData.m_textColor, dynamic_cast<QWidget *>(parent()), "选择颜色");
    if (newColor.isValid() && newColor != m_textData.m_textColor) {
        dynamic_cast<QPushButton*>(sender())->setStyleSheet(QString("background-color: %1").arg(newColor.name()));
        m_textData.m_textColor = newColor;
        emit textDataChanged(m_textData);
    }
}
void AttributeManager::onFontComboBoxChanged(const QFont &font) {
    if (font != m_textData.m_font) {
        m_textData.m_font = font;
        emit textDataChanged(m_textData);
    }
}
void AttributeManager::onBoldBtnToggled(bool checked) {
    m_textData.m_bold = checked;
    emit textDataChanged(m_textData);
}
void AttributeManager::onItalicBtnToggled(bool checked) {
    m_textData.m_italic = checked;
    emit textDataChanged(m_textData);
}
void AttributeManager::onUnderlineBtnToggled(bool checked) {
    m_textData.m_underline = checked;
    emit textDataChanged(m_textData);
}
void AttributeManager::onFontSizeComboBoxChanged(int index) {
    int size = FontSizeConfig::getInstance().getFontSize(index);
    if (size != m_textData.m_size) {
        m_textData.m_size = size;
        emit textDataChanged(m_textData);
    }
}

void AttributeManager::onFrameChecked(const AttributeType &type, const GraphicsData &data) {
    this->m_graphicsData = data;
    m_pTextColorFrame->hide();
    m_pFontFrame->hide();
    m_pTextSettingFrame->hide();
    switch (type) {
        case AttributeType::Base: {
            m_pBorderColorFrame->hide();
            m_pFilledColorFrame->hide();
            m_pBorderWidthFrame->hide();
            m_pBorderStyleFrame->hide();
            m_pPosFrame->hide();
            break;
        }
        case AttributeType::Line: {
            m_pPosFrame->show();
            m_pBorderColorFrame->show();
            m_pBorderColorPushButton->setStyleSheet(QString("background-color: %1").arg(data.m_borderColor.name()));
            m_pFilledColorFrame->hide();
            m_pBorderWidthFrame->show();
            m_pBorderWidthSpinBox->setValue(data.m_borderWidth);
            m_pBorderStyleFrame->show();
            m_pBorderStyleComboBox->setCurrentIndex(BorderStyleConfig::getInstance().getIndex(data.m_borderStyle));
            break;
        }
        case AttributeType::Flat: {
            m_pPosFrame->show();
            m_pBorderColorFrame->show();
            m_pBorderColorPushButton->setStyleSheet(QString("background-color: %1").arg(data.m_borderColor.name()));
            m_pFilledColorFrame->show();
            m_pFilledColorPushButton->setStyleSheet(QString("background-color: %1").arg(data.m_filledColor.name()));
            m_pBorderWidthFrame->show();
            m_pBorderWidthSpinBox->setValue(data.m_borderWidth);
            m_pBorderStyleFrame->show();
            m_pBorderStyleComboBox->setCurrentIndex(BorderStyleConfig::getInstance().getIndex(data.m_borderStyle));
            break;
        }
        case AttributeType::Text: {
            m_pPosFrame->show();
            m_pBorderColorFrame->show();
            m_pBorderColorPushButton->setStyleSheet(QString("background-color: %1").arg(data.m_borderColor.name()));
            m_pFilledColorFrame->hide();
            m_pBorderWidthFrame->hide();
            m_pBorderStyleFrame->hide();
            break;
        }
        default: {
            m_pPosFrame->hide();
            m_pBorderWidthFrame->hide();
            m_pBorderStyleFrame->hide();
            m_pBorderColorFrame->hide();
            m_pFilledColorFrame->hide();
            break;
        }
    }
}

void AttributeManager::onTextChecked(const TextData &data) {
    this->m_textData = data;
    m_pTextColorFrame->show();
    m_pFontFrame->show();
    m_pPosFrame->show();
    m_pTextSettingFrame->show();
    m_pBorderColorFrame->hide();
    m_pFilledColorFrame->hide();
    m_pBorderWidthFrame->hide();
    m_pBorderStyleFrame->hide();

    m_pTextColorBtn->setStyleSheet(QString("background-color: %1").arg(data.m_textColor.name()));
    m_pFontComboBox->setCurrentFont(data.m_font);
    m_pFontSizeComboBox->setCurrentIndex(FontSizeConfig::getInstance().getIndex(data.m_size));
    m_pBoldBtn->setChecked(data.m_bold);
    m_pItalicBtn->setChecked(data.m_italic);
    m_pUnderlineBtn->setChecked(data.m_underline);
}

void AttributeManager::onZoomBtnClicked(bool isEnlarge) {
    if (isEnlarge) {
        m_canvasData.m_zoomRatio += 0.2;
        m_pZoomRatioSpinBox->setValue(m_pZoomRatioSpinBox->value() + 20);
    }else {
        m_canvasData.m_zoomRatio -= 0.2;
        m_pZoomRatioSpinBox->setValue(m_pZoomRatioSpinBox->value() - 20);
    }
    emit canvasDataChanged(m_canvasData);
}

