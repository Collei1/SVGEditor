//
// Created by Collei on 25-4-28.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QActionGroup>
#include <QGraphicsView>
#include <QSvgGenerator>
#include "ui_mainwindow.h"
#include "../CanvasFrame/canvasframe.h"
#include "../AttributeManager/attributemanager.h"
#include "../AttributeManager/borderstylecombobox.h"
#include "../MenuManager/menumanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void initUI();
    void initActions();
    void initConnections();

public slots:
    void onCanvasDataChanged(const CanvasData& canvasData);
    void onExportSvg(const QString& filename);

private:
    Ui::MainWindow *ui;
    BorderStyleComboBox* m_pBorderStyleComboBox{};
    CanvasFrame* m_pCanvasFrame{};
    QGraphicsScene* m_pScene{};
    QGraphicsView* m_pGraphicsView{};
    QActionGroup *m_pActionGroup;
    MenuManager* m_pMenuManager{};
    AttributeManager *m_pAttributeManager{};
};


#endif //MAINWINDOW_H
