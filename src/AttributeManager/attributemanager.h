//
// Created by Collei on 25-5-20.
//

#ifndef ATTRIBUTEMANAGE_H
#define ATTRIBUTEMANAGE_H
#include <QComboBox>
#include <QFontComboBox>
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <QSpinBox>
#include "../Graphics/config.h"
#include "../RegeditSettings/regeditsettings.h"

class AttributeManager : public QObject{
    Q_OBJECT
public:
    explicit AttributeManager(const CanvasData& canvasData, QWidget* parent = nullptr);
    ~AttributeManager() override;

    void setupUi(QFrame *canvasWidthFrame,
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
        );

    signals:
    void canvasDataChanged(const CanvasData& canvasData);
    void graphicsDataChanged(const GraphicsData& graphicsData);
    void textDataChanged(const TextData& textData);
    void upDownChanged(bool isUp);
    void topBottomChanged(bool isTop);

public slots:
    void onCanvasWidthChanged(int width);
    void onCanvasHeightChanged(int height);
    void onZoomRatioChanged(int ratio);
    void onCanvasColorBtnClicked();

    void onBorderColorBtnClicked();
    void onFilledColorBtnClicked();
    void onBorderWidthChanged(int width);
    void onBorderStyleComboBoxChanged(int index);
    void  onUpBtnClicked();
    void  onDownBtnClicked();
    void  onTopBtnClicked();
    void  onBottomBtnClicked();

    void onTextColorBtnClicked();
    void onFontComboBoxChanged(const QFont &font);
    void onBoldBtnToggled(bool checked);
    void onItalicBtnToggled(bool checked);
    void onUnderlineBtnToggled(bool checked);
    void onFontSizeComboBoxChanged(int index);

    void onFrameChecked(const AttributeType &type, const GraphicsData &data);
    void onTextChecked(const TextData &data);
    void onZoomBtnClicked(bool isEnlarge);

private:
    CanvasData m_canvasData;
    GraphicsData m_graphicsData;
    TextData m_textData;

    QFrame *m_pCanvasWidthFrame{};
    QSpinBox *m_pCanvasWidthSpinBox{};
    QFrame *m_pCanvasHeightFrame{};
    QSpinBox *m_pCanvasHeightSpinBox{};
    QFrame *m_pZoomRatioFrame{};
    QSpinBox *m_pZoomRatioSpinBox{};
    QFrame *m_pCanvasColorFrame{};
    QPushButton *m_pCanvasColorPushButton{};

    QFrame *m_pBorderWidthFrame{};
    QSpinBox *m_pBorderWidthSpinBox{};
    QFrame *m_pBorderColorFrame{};
    QPushButton *m_pBorderColorPushButton{};
    QFrame *m_pFilledColorFrame{};
    QPushButton *m_pFilledColorPushButton{};
    QFrame *m_pBorderStyleFrame{};
    QComboBox* m_pBorderStyleComboBox{};

    QFrame* m_pTextColorFrame{};
    QPushButton* m_pTextColorBtn{};
    QFrame *m_pFontFrame{};
    QFontComboBox* m_pFontComboBox{};
    QFrame *m_pTextSettingFrame{};
    QToolButton* m_pBoldBtn{};
    QToolButton* m_pItalicBtn{};
    QToolButton* m_pUnderlineBtn{};
    QComboBox* m_pFontSizeComboBox{};
    QFrame *m_pPosFrame{};
    QPushButton *m_pUpBtn{};
    QPushButton *m_pDownBtn{};
    QPushButton *m_pTopBtn{};
    QPushButton *m_pBottomBtn{};
};



#endif //ATTRIBUTEMANAGE_H
