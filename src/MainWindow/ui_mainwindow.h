/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *arrowAction;
    QAction *penAction;
    QAction *lineAction;
    QAction *circleAction;
    QAction *rectangleAction;
    QAction *pentagonAction;
    QAction *hexagonAction;
    QAction *pentagramAction;
    QAction *textAction;
    QAction *zoomAction;
    QAction *triangleAction;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *exportAction;
    QAction *diamondAction;
    QAction *rightTriangleAction;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QWidget *attributeWidget;
    QLabel *label;
    QFrame *canvasWidthFrame;
    QLabel *label_2;
    QSpinBox *canvasWidthSpinBox;
    QFrame *canvasHeightFrame;
    QLabel *label_3;
    QSpinBox *canvasHeightSpinBox;
    QFrame *zoomRatioFrame;
    QLabel *label_4;
    QSpinBox *zoomRatioSpinBox;
    QFrame *canvasColorFrame;
    QLabel *label_5;
    QPushButton *canvasColorPushButton;
    QFrame *borderWidthFrame;
    QLabel *label_6;
    QSpinBox *borderWidthSpinBox;
    QFrame *borderColorFrame;
    QLabel *label_8;
    QPushButton *borderColorPushButton;
    QFrame *filledColorFrame;
    QLabel *label_9;
    QPushButton *filledColorPushButton;
    QFrame *borderStyleFrame;
    QLabel *label_7;
    QFrame *fontFrame;
    QLabel *label_10;
    QFontComboBox *fontComboBox;
    QFrame *textSettingFrame;
    QLabel *label_11;
    QToolButton *boldBtn;
    QToolButton *italicBtn;
    QToolButton *underrlineBtn;
    QComboBox *fontSizeComboBox;
    QFrame *textColorFrame;
    QLabel *label_12;
    QPushButton *textColorBtn;
    QFrame *posFrame;
    QPushButton *upBtn;
    QPushButton *topBtn;
    QPushButton *downBtn;
    QPushButton *bottomBtn;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        MainWindow->setMinimumSize(QSize(500, 300));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/resources/favicon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 47, 47);\n"
"color: rgb(255, 255, 255);"));
        arrowAction = new QAction(MainWindow);
        arrowAction->setObjectName("arrowAction");
        arrowAction->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/normal/resources/arrow_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon1.addFile(QString::fromUtf8(":/checked/resources/arrow_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon1.addFile(QString::fromUtf8(":/hover/resources/arrow_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        arrowAction->setIcon(icon1);
        arrowAction->setMenuRole(QAction::MenuRole::NoRole);
        penAction = new QAction(MainWindow);
        penAction->setObjectName("penAction");
        penAction->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/normal/resources/pen_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon2.addFile(QString::fromUtf8(":/checked/resources/pen_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon2.addFile(QString::fromUtf8(":/hover/resources/pen_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        penAction->setIcon(icon2);
        penAction->setMenuRole(QAction::MenuRole::NoRole);
        lineAction = new QAction(MainWindow);
        lineAction->setObjectName("lineAction");
        lineAction->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/normal/resources/line_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon3.addFile(QString::fromUtf8(":/checked/resources/line_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon3.addFile(QString::fromUtf8(":/hover/resources/line_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        lineAction->setIcon(icon3);
        lineAction->setMenuRole(QAction::MenuRole::NoRole);
        circleAction = new QAction(MainWindow);
        circleAction->setObjectName("circleAction");
        circleAction->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/normal/resources/circle_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon4.addFile(QString::fromUtf8(":/checked/resources/circle_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon4.addFile(QString::fromUtf8(":/hover/resources/circle_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        circleAction->setIcon(icon4);
        circleAction->setMenuRole(QAction::MenuRole::NoRole);
        rectangleAction = new QAction(MainWindow);
        rectangleAction->setObjectName("rectangleAction");
        rectangleAction->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/normal/resources/rectangle_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon5.addFile(QString::fromUtf8(":/checked/resources/rectangle_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon5.addFile(QString::fromUtf8(":/hover/resources/rectangle_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        rectangleAction->setIcon(icon5);
        rectangleAction->setMenuRole(QAction::MenuRole::NoRole);
        pentagonAction = new QAction(MainWindow);
        pentagonAction->setObjectName("pentagonAction");
        pentagonAction->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/normal/resources/pentagon_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon6.addFile(QString::fromUtf8(":/checked/resources/pentagon_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon6.addFile(QString::fromUtf8(":/hover/resources/pentagon_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        pentagonAction->setIcon(icon6);
        pentagonAction->setMenuRole(QAction::MenuRole::NoRole);
        hexagonAction = new QAction(MainWindow);
        hexagonAction->setObjectName("hexagonAction");
        hexagonAction->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/normal/resources/hexagon_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon7.addFile(QString::fromUtf8(":/checked/resources/hexagon_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon7.addFile(QString::fromUtf8(":/hover/resources/hexagon_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        hexagonAction->setIcon(icon7);
        hexagonAction->setMenuRole(QAction::MenuRole::NoRole);
        pentagramAction = new QAction(MainWindow);
        pentagramAction->setObjectName("pentagramAction");
        pentagramAction->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/normal/resources/pentagram_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon8.addFile(QString::fromUtf8(":/checked/resources/pentagram_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon8.addFile(QString::fromUtf8(":/hover/resources/pentagram_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        pentagramAction->setIcon(icon8);
        pentagramAction->setMenuRole(QAction::MenuRole::NoRole);
        textAction = new QAction(MainWindow);
        textAction->setObjectName("textAction");
        textAction->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/normal/resources/text_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon9.addFile(QString::fromUtf8(":/checked/resources/text_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon9.addFile(QString::fromUtf8(":/hover/resources/text_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        textAction->setIcon(icon9);
        textAction->setMenuRole(QAction::MenuRole::NoRole);
        zoomAction = new QAction(MainWindow);
        zoomAction->setObjectName("zoomAction");
        zoomAction->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/normal/resources/zoom_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon10.addFile(QString::fromUtf8(":/checked/resources/zoom_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon10.addFile(QString::fromUtf8(":/hover/resources/zoom_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        zoomAction->setIcon(icon10);
        zoomAction->setMenuRole(QAction::MenuRole::NoRole);
        triangleAction = new QAction(MainWindow);
        triangleAction->setObjectName("triangleAction");
        triangleAction->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/normal/resources/triangle_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon11.addFile(QString::fromUtf8(":/checked/resources/triangle_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon11.addFile(QString::fromUtf8(":/hover/resources/triangle_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        triangleAction->setIcon(icon11);
        triangleAction->setMenuRole(QAction::MenuRole::NoRole);
        newAction = new QAction(MainWindow);
        newAction->setObjectName("newAction");
        openAction = new QAction(MainWindow);
        openAction->setObjectName("openAction");
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName("saveAction");
        exportAction = new QAction(MainWindow);
        exportAction->setObjectName("exportAction");
        diamondAction = new QAction(MainWindow);
        diamondAction->setObjectName("diamondAction");
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/normal/resources/diamond_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon12.addFile(QString::fromUtf8(":/checked/resources/diamond_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon12.addFile(QString::fromUtf8(":/hover/resources/diamond_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        diamondAction->setIcon(icon12);
        diamondAction->setMenuRole(QAction::MenuRole::NoRole);
        rightTriangleAction = new QAction(MainWindow);
        rightTriangleAction->setObjectName("rightTriangleAction");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/normal/resources/righttriangle_normal.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon13.addFile(QString::fromUtf8(":/checked/resources/righttriangle_checked.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        icon13.addFile(QString::fromUtf8(":/hover/resources/righttriangle_hover.svg"), QSize(), QIcon::Mode::Active, QIcon::State::Off);
        rightTriangleAction->setIcon(icon13);
        rightTriangleAction->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 938, 746));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        attributeWidget = new QWidget(centralwidget);
        attributeWidget->setObjectName("attributeWidget");
        attributeWidget->setMinimumSize(QSize(210, 0));
        attributeWidget->setMaximumSize(QSize(210, 16777215));
        label = new QLabel(attributeWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 71, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(11);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        canvasWidthFrame = new QFrame(attributeWidget);
        canvasWidthFrame->setObjectName("canvasWidthFrame");
        canvasWidthFrame->setGeometry(QRect(10, 30, 90, 71));
        canvasWidthFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        canvasWidthFrame->setFrameShape(QFrame::Shape::StyledPanel);
        canvasWidthFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(canvasWidthFrame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(19, 5, 61, 21));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        canvasWidthSpinBox = new QSpinBox(canvasWidthFrame);
        canvasWidthSpinBox->setObjectName("canvasWidthSpinBox");
        canvasWidthSpinBox->setGeometry(QRect(5, 30, 88, 38));
        canvasWidthSpinBox->setFont(font1);
        canvasWidthSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"	color: rgb(1, 124, 255);\n"
"	border:none;\n"
"}\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"     width: 30px;\n"
"     height: 19px;\n"
"}"));
        canvasWidthSpinBox->setFrame(true);
        canvasWidthSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        canvasWidthSpinBox->setMinimum(10);
        canvasWidthSpinBox->setMaximum(1000);
        canvasWidthSpinBox->setValue(800);
        canvasWidthSpinBox->setDisplayIntegerBase(10);
        canvasHeightFrame = new QFrame(attributeWidget);
        canvasHeightFrame->setObjectName("canvasHeightFrame");
        canvasHeightFrame->setGeometry(QRect(110, 30, 90, 71));
        canvasHeightFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        canvasHeightFrame->setFrameShape(QFrame::Shape::StyledPanel);
        canvasHeightFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(canvasHeightFrame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(19, 5, 61, 21));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        canvasHeightSpinBox = new QSpinBox(canvasHeightFrame);
        canvasHeightSpinBox->setObjectName("canvasHeightSpinBox");
        canvasHeightSpinBox->setGeometry(QRect(5, 30, 88, 38));
        canvasHeightSpinBox->setFont(font1);
        canvasHeightSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"	color: rgb(1, 124, 255);\n"
"	border:none;\n"
"}\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"     width: 30px;\n"
"     height: 19px;\n"
"}"));
        canvasHeightSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        canvasHeightSpinBox->setMinimum(10);
        canvasHeightSpinBox->setMaximum(1000);
        canvasHeightSpinBox->setValue(600);
        canvasHeightSpinBox->setDisplayIntegerBase(10);
        zoomRatioFrame = new QFrame(attributeWidget);
        zoomRatioFrame->setObjectName("zoomRatioFrame");
        zoomRatioFrame->setGeometry(QRect(10, 110, 90, 71));
        zoomRatioFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        zoomRatioFrame->setFrameShape(QFrame::Shape::StyledPanel);
        zoomRatioFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_4 = new QLabel(zoomRatioFrame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(19, 5, 61, 21));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        zoomRatioSpinBox = new QSpinBox(zoomRatioFrame);
        zoomRatioSpinBox->setObjectName("zoomRatioSpinBox");
        zoomRatioSpinBox->setGeometry(QRect(5, 30, 88, 38));
        zoomRatioSpinBox->setFont(font1);
        zoomRatioSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"	color: rgb(1, 124, 255);\n"
"	border:none;\n"
"}\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"     width: 30px;\n"
"     height: 19px;\n"
"}"));
        zoomRatioSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        zoomRatioSpinBox->setMinimum(20);
        zoomRatioSpinBox->setMaximum(400);
        zoomRatioSpinBox->setValue(100);
        zoomRatioSpinBox->setDisplayIntegerBase(10);
        canvasColorFrame = new QFrame(attributeWidget);
        canvasColorFrame->setObjectName("canvasColorFrame");
        canvasColorFrame->setGeometry(QRect(110, 110, 90, 71));
        canvasColorFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        canvasColorFrame->setFrameShape(QFrame::Shape::StyledPanel);
        canvasColorFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_5 = new QLabel(canvasColorFrame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(19, 5, 61, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        canvasColorPushButton = new QPushButton(canvasColorFrame);
        canvasColorPushButton->setObjectName("canvasColorPushButton");
        canvasColorPushButton->setGeometry(QRect(10, 35, 71, 31));
        canvasColorPushButton->setStyleSheet(QString::fromUtf8("border-radius:none;\n"
"background-color: rgb(255, 255, 255);"));
        borderWidthFrame = new QFrame(attributeWidget);
        borderWidthFrame->setObjectName("borderWidthFrame");
        borderWidthFrame->setGeometry(QRect(110, 190, 90, 71));
        borderWidthFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        borderWidthFrame->setFrameShape(QFrame::Shape::StyledPanel);
        borderWidthFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_6 = new QLabel(borderWidthFrame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(19, 5, 61, 21));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        borderWidthSpinBox = new QSpinBox(borderWidthFrame);
        borderWidthSpinBox->setObjectName("borderWidthSpinBox");
        borderWidthSpinBox->setGeometry(QRect(5, 30, 88, 38));
        borderWidthSpinBox->setFont(font1);
        borderWidthSpinBox->setStyleSheet(QString::fromUtf8("QSpinBox{\n"
"	color: rgb(1, 124, 255);\n"
"	border:none;\n"
"}\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"     width: 30px;\n"
"     height: 19px;\n"
"};"));
        borderWidthSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        borderWidthSpinBox->setMinimum(1);
        borderWidthSpinBox->setMaximum(9);
        borderWidthSpinBox->setValue(2);
        borderWidthSpinBox->setDisplayIntegerBase(10);
        borderColorFrame = new QFrame(attributeWidget);
        borderColorFrame->setObjectName("borderColorFrame");
        borderColorFrame->setGeometry(QRect(10, 190, 90, 71));
        borderColorFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        borderColorFrame->setFrameShape(QFrame::Shape::StyledPanel);
        borderColorFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_8 = new QLabel(borderColorFrame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(19, 5, 61, 21));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        borderColorPushButton = new QPushButton(borderColorFrame);
        borderColorPushButton->setObjectName("borderColorPushButton");
        borderColorPushButton->setGeometry(QRect(10, 35, 71, 31));
        borderColorPushButton->setStyleSheet(QString::fromUtf8("border-radius:none;\n"
"background-color: rgb(0, 0, 0);"));
        filledColorFrame = new QFrame(attributeWidget);
        filledColorFrame->setObjectName("filledColorFrame");
        filledColorFrame->setGeometry(QRect(10, 270, 90, 71));
        filledColorFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        filledColorFrame->setFrameShape(QFrame::Shape::StyledPanel);
        filledColorFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_9 = new QLabel(filledColorFrame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(19, 5, 61, 21));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        filledColorPushButton = new QPushButton(filledColorFrame);
        filledColorPushButton->setObjectName("filledColorPushButton");
        filledColorPushButton->setGeometry(QRect(10, 35, 71, 31));
        filledColorPushButton->setStyleSheet(QString::fromUtf8("border-radius:none;\n"
"background-color: rgb(255, 255, 255);"));
        borderStyleFrame = new QFrame(attributeWidget);
        borderStyleFrame->setObjectName("borderStyleFrame");
        borderStyleFrame->setGeometry(QRect(110, 270, 90, 71));
        borderStyleFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        borderStyleFrame->setFrameShape(QFrame::Shape::StyledPanel);
        borderStyleFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_7 = new QLabel(borderStyleFrame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(19, 5, 61, 21));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        fontFrame = new QFrame(attributeWidget);
        fontFrame->setObjectName("fontFrame");
        fontFrame->setGeometry(QRect(110, 430, 90, 71));
        fontFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        fontFrame->setFrameShape(QFrame::Shape::StyledPanel);
        fontFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_10 = new QLabel(fontFrame);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(19, 5, 61, 21));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        fontComboBox = new QFontComboBox(fontFrame);
        fontComboBox->setObjectName("fontComboBox");
        fontComboBox->setGeometry(QRect(2, 32, 85, 34));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        fontComboBox->setCurrentFont(font2);
        textSettingFrame = new QFrame(attributeWidget);
        textSettingFrame->setObjectName("textSettingFrame");
        textSettingFrame->setGeometry(QRect(10, 510, 191, 71));
        textSettingFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        textSettingFrame->setFrameShape(QFrame::Shape::StyledPanel);
        textSettingFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_11 = new QLabel(textSettingFrame);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(19, 5, 61, 21));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        boldBtn = new QToolButton(textSettingFrame);
        boldBtn->setObjectName("boldBtn");
        boldBtn->setGeometry(QRect(5, 30, 31, 31));
        QIcon icon14(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextBold));
        boldBtn->setIcon(icon14);
        boldBtn->setCheckable(true);
        italicBtn = new QToolButton(textSettingFrame);
        italicBtn->setObjectName("italicBtn");
        italicBtn->setGeometry(QRect(45, 30, 31, 31));
        QIcon icon15(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextItalic));
        italicBtn->setIcon(icon15);
        italicBtn->setCheckable(true);
        underrlineBtn = new QToolButton(textSettingFrame);
        underrlineBtn->setObjectName("underrlineBtn");
        underrlineBtn->setGeometry(QRect(85, 30, 31, 31));
        QIcon icon16(QIcon::fromTheme(QIcon::ThemeIcon::FormatTextUnderline));
        underrlineBtn->setIcon(icon16);
        underrlineBtn->setCheckable(true);
        fontSizeComboBox = new QComboBox(textSettingFrame);
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->addItem(QString());
        fontSizeComboBox->setObjectName("fontSizeComboBox");
        fontSizeComboBox->setGeometry(QRect(125, 30, 61, 32));
        fontSizeComboBox->setMaxCount(64);
        textColorFrame = new QFrame(attributeWidget);
        textColorFrame->setObjectName("textColorFrame");
        textColorFrame->setGeometry(QRect(10, 430, 90, 71));
        textColorFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        textColorFrame->setFrameShape(QFrame::Shape::StyledPanel);
        textColorFrame->setFrameShadow(QFrame::Shadow::Raised);
        label_12 = new QLabel(textColorFrame);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(19, 5, 61, 21));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        textColorBtn = new QPushButton(textColorFrame);
        textColorBtn->setObjectName("textColorBtn");
        textColorBtn->setGeometry(QRect(10, 35, 71, 31));
        textColorBtn->setStyleSheet(QString::fromUtf8("border-radius:none;\n"
"background-color: rgb(0, 0, 0);"));
        posFrame = new QFrame(attributeWidget);
        posFrame->setObjectName("posFrame");
        posFrame->setGeometry(QRect(110, 350, 90, 71));
        posFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 60);"));
        posFrame->setFrameShape(QFrame::Shape::StyledPanel);
        posFrame->setFrameShadow(QFrame::Shadow::Raised);
        upBtn = new QPushButton(posFrame);
        upBtn->setObjectName("upBtn");
        upBtn->setGeometry(QRect(2, 5, 41, 31));
        upBtn->setFont(font2);
        topBtn = new QPushButton(posFrame);
        topBtn->setObjectName("topBtn");
        topBtn->setGeometry(QRect(48, 5, 40, 31));
        topBtn->setFont(font2);
        downBtn = new QPushButton(posFrame);
        downBtn->setObjectName("downBtn");
        downBtn->setGeometry(QRect(2, 40, 40, 31));
        downBtn->setFont(font2);
        bottomBtn = new QPushButton(posFrame);
        bottomBtn->setObjectName("bottomBtn");
        bottomBtn->setGeometry(QRect(48, 40, 40, 31));
        bottomBtn->setFont(font2);

        horizontalLayout->addWidget(attributeWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 33));
        menubar->setFont(font);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"padding-left:50px;"));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu->setFont(font);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setMinimumSize(QSize(0, 0));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setMinimumSize(QSize(50, 0));
        toolBar->setMaximumSize(QSize(50, 16777215));
        toolBar->setFont(font2);
        toolBar->setStyleSheet(QString::fromUtf8("QToolBar{\n"
"	border:none;\n"
"}\n"
"QToolButton{\n"
"	margin-top:8px;\n"
"	margin-bottom:8px;\n"
"	border: none;\n"
"}\n"
"QToolButton:hover {\n"
"	border:none;\n"
"}\n"
"QToolButton:pressed {\n"
"\n"
"}\n"
"QToolButton:checked {\n"
"	border:none;\n"
"}"));
        toolBar->setAllowedAreas(Qt::ToolBarArea::LeftToolBarArea);
        MainWindow->addToolBar(Qt::ToolBarArea::LeftToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menu->addAction(newAction);
        menu->addAction(openAction);
        menu->addAction(saveAction);
        menu->addAction(exportAction);
        toolBar->addAction(arrowAction);
        toolBar->addAction(penAction);
        toolBar->addAction(lineAction);
        toolBar->addAction(circleAction);
        toolBar->addAction(triangleAction);
        toolBar->addAction(rightTriangleAction);
        toolBar->addAction(rectangleAction);
        toolBar->addAction(pentagonAction);
        toolBar->addAction(hexagonAction);
        toolBar->addAction(pentagramAction);
        toolBar->addAction(diamondAction);
        toolBar->addAction(textAction);
        toolBar->addAction(zoomAction);

        retranslateUi(MainWindow);

        fontSizeComboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SVGEditor", nullptr));
        arrowAction->setText(QCoreApplication::translate("MainWindow", "arrow", nullptr));
#if QT_CONFIG(tooltip)
        arrowAction->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\267\245\345\205\267\357\274\232\345\217\257\344\273\245\351\200\211\346\213\251\347\224\273\345\270\203\344\270\212\345\267\262\347\273\230\345\210\266\347\232\204\345\233\276\345\275\242\357\274\214\346\226\271\344\276\277\350\277\233\350\241\214\347\247\273\345\212\250\343\200\201\347\274\226\350\276\221\347\255\211\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(tooltip)
        penAction->setText(QCoreApplication::translate("MainWindow", "pen", nullptr));
#if QT_CONFIG(tooltip)
        penAction->setToolTip(QCoreApplication::translate("MainWindow", "\350\207\252\347\224\261\347\272\277\347\273\230\345\210\266\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\350\207\252\347\224\261\347\273\230\345\210\266\347\272\277\346\235\241\357\274\214\350\267\237\351\232\217\351\274\240\346\240\207\347\247\273\345\212\250\350\275\250\350\277\271\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        lineAction->setText(QCoreApplication::translate("MainWindow", "line", nullptr));
#if QT_CONFIG(tooltip)
        lineAction->setToolTip(QCoreApplication::translate("MainWindow", "\347\233\264\347\272\277\347\273\230\345\210\266\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\347\273\230\345\210\266\347\233\264\347\272\277\357\274\214\346\214\211\344\275\217\351\274\240\346\240\207\345\267\246\351\224\256\346\213\226\345\212\250\345\215\263\345\217\257\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        circleAction->setText(QCoreApplication::translate("MainWindow", "circle", nullptr));
#if QT_CONFIG(tooltip)
        circleAction->setToolTip(QCoreApplication::translate("MainWindow", "circle", nullptr));
#endif // QT_CONFIG(tooltip)
        rectangleAction->setText(QCoreApplication::translate("MainWindow", "rectangle", nullptr));
#if QT_CONFIG(tooltip)
        rectangleAction->setToolTip(QCoreApplication::translate("MainWindow", "\347\237\251\345\275\242\347\273\230\345\210\266\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\347\273\230\345\210\266\347\237\251\345\275\242\357\274\214\346\214\211\344\275\217\351\274\240\346\240\207\345\267\246\351\224\256\346\213\226\345\212\250\345\215\263\345\217\257\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        pentagonAction->setText(QCoreApplication::translate("MainWindow", "pentagon", nullptr));
#if QT_CONFIG(tooltip)
        pentagonAction->setToolTip(QCoreApplication::translate("MainWindow", "\344\272\224\350\276\271\345\275\242\347\273\230\345\210\266\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\347\273\230\345\210\266\344\272\224\350\276\271\345\275\242\357\274\214\346\214\211\344\275\217\351\274\240\346\240\207\345\267\246\351\224\256\346\213\226\345\212\250\345\215\263\345\217\257\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        hexagonAction->setText(QCoreApplication::translate("MainWindow", "hexagon", nullptr));
#if QT_CONFIG(tooltip)
        hexagonAction->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\255\350\276\271\345\275\242\347\273\230\345\210\266\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\347\273\230\345\210\266\345\205\255\350\276\271\345\275\242\357\274\214\346\214\211\344\275\217\351\274\240\346\240\207\345\267\246\351\224\256\346\213\226\345\212\250\345\215\263\345\217\257\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        pentagramAction->setText(QCoreApplication::translate("MainWindow", "pentagram", nullptr));
#if QT_CONFIG(tooltip)
        pentagramAction->setToolTip(QCoreApplication::translate("MainWindow", "\344\272\224\350\247\222\346\230\237\347\273\230\345\210\266\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\347\273\230\345\210\266\344\272\224\350\247\222\346\230\237\357\274\214\346\214\211\344\275\217\351\274\240\346\240\207\345\267\246\351\224\256\346\213\226\345\212\250\345\215\263\345\217\257\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        textAction->setText(QCoreApplication::translate("MainWindow", "text", nullptr));
#if QT_CONFIG(tooltip)
        textAction->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\207\345\255\227\347\274\226\350\276\221\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\347\274\226\350\276\221\346\226\207\345\255\227\357\274\214\346\214\211\344\270\213\351\274\240\346\240\207\345\215\263\345\217\257\346\267\273\345\212\240\346\226\207\345\255\227\350\277\233\350\241\214\347\274\226\350\276\221", nullptr));
#endif // QT_CONFIG(tooltip)
        zoomAction->setText(QCoreApplication::translate("MainWindow", "zoom", nullptr));
#if QT_CONFIG(tooltip)
        zoomAction->setToolTip(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247\347\274\251\345\260\217\357\274\232\347\202\271\345\207\273\351\274\240\346\240\207\345\267\246\351\224\256\346\224\276\345\244\247\357\274\214\347\202\271\345\207\273\351\274\240\346\240\207\345\217\263\351\224\256\347\274\251\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        triangleAction->setText(QCoreApplication::translate("MainWindow", "triangle", nullptr));
#if QT_CONFIG(tooltip)
        triangleAction->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\211\350\247\222\345\275\242\347\273\230\345\210\266\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\347\273\230\345\210\266\344\270\211\350\247\222\345\275\242\357\274\214\346\214\211\344\275\217\351\274\240\346\240\207\345\267\246\351\224\256\346\213\226\345\212\250\345\215\263\345\217\257\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        newAction->setText(QCoreApplication::translate("MainWindow", "New file", nullptr));
#if QT_CONFIG(tooltip)
        newAction->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\344\270\200\344\270\252\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        openAction->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
#if QT_CONFIG(tooltip)
        openAction->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\200\344\270\252SVG\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        saveAction->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(tooltip)
        saveAction->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        exportAction->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
#if QT_CONFIG(tooltip)
        exportAction->setToolTip(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\344\270\272SVG\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        diamondAction->setText(QCoreApplication::translate("MainWindow", "diamondAction", nullptr));
#if QT_CONFIG(tooltip)
        diamondAction->setToolTip(QCoreApplication::translate("MainWindow", "\350\217\261\345\275\242\347\273\230\345\210\266\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\347\273\230\345\210\266\350\217\261\345\275\242\357\274\214\346\214\211\344\275\217\351\274\240\346\240\207\345\267\246\351\224\256\346\213\226\345\212\250\345\215\263\345\217\257\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        rightTriangleAction->setText(QCoreApplication::translate("MainWindow", "righttriangle", nullptr));
#if QT_CONFIG(tooltip)
        rightTriangleAction->setToolTip(QCoreApplication::translate("MainWindow", "\347\233\264\350\247\222\344\270\211\350\247\222\345\275\242\347\273\230\345\210\266\357\274\232\345\234\250\347\224\273\345\270\203\344\270\212\347\273\230\345\210\266\347\233\264\350\247\222\344\270\211\350\247\222\345\275\242\357\274\214\346\214\211\344\275\217\351\274\240\346\240\207\345\267\246\351\224\256\346\213\226\345\212\250\345\215\263\345\217\257\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\224\273\345\270\203\345\256\275\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\224\273\345\270\203\351\253\230\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\274\251\346\224\276\346\257\224\344\276\213", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\224\273\345\270\203\351\242\234\350\211\262", nullptr));
        canvasColorPushButton->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\350\276\271\346\241\206\345\256\275\345\272\246", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\350\276\271\346\241\206\351\242\234\350\211\262", nullptr));
        borderColorPushButton->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\241\253\345\205\205\351\242\234\350\211\262", nullptr));
        filledColorPushButton->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\276\271\346\241\206\346\240\267\345\274\217", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\346\226\207\345\255\227\350\256\276\347\275\256", nullptr));
        boldBtn->setText(QString());
        italicBtn->setText(QString());
        underrlineBtn->setText(QString());
        fontSizeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "12px", nullptr));
        fontSizeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "13px", nullptr));
        fontSizeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "14px", nullptr));
        fontSizeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "15px", nullptr));
        fontSizeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "16px", nullptr));
        fontSizeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "17px", nullptr));
        fontSizeComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "18px", nullptr));
        fontSizeComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "20px", nullptr));
        fontSizeComboBox->setItemText(8, QCoreApplication::translate("MainWindow", "24px", nullptr));
        fontSizeComboBox->setItemText(9, QCoreApplication::translate("MainWindow", "32px", nullptr));
        fontSizeComboBox->setItemText(10, QCoreApplication::translate("MainWindow", "40px", nullptr));
        fontSizeComboBox->setItemText(11, QCoreApplication::translate("MainWindow", "64px", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
        textColorBtn->setText(QString());
        upBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\212\347\247\273", nullptr));
        topBtn->setText(QCoreApplication::translate("MainWindow", "\346\234\200\344\270\212", nullptr));
        downBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\213\347\247\273", nullptr));
        bottomBtn->setText(QCoreApplication::translate("MainWindow", "\346\234\200\344\270\213", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
