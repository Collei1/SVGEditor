//
// Created by Collei on 25-5-22.
//

#ifndef MENUMANAGER_H
#define MENUMANAGER_H
#include <QAction>
#include <QObject>


class MenuManager :public QObject{
    Q_OBJECT
public:
    explicit MenuManager(QObject *parent = nullptr);
    ~MenuManager() override;
    void setupUI(QAction* newAction, QAction* openAction, QAction* saveAction, QAction* exportAction);

    signals:
    void clearCanvas();
    void loadSvgFrame(const QString &svgPath);
    void exportSvg(const QString& filename);

public slots:
    void onNewActionTriggered();
    void onOpenActionTriggered();
    void onSaveActionTriggered();
    void onExportActionTriggered();

private:
    QAction *m_pNewAction{};
    QAction *m_pOpenAction{};
    QAction *m_pSaveAction{};
    QAction *m_pExportAction{};

    QString m_currentFilePath{};
};



#endif //MENUMANAGER_H
