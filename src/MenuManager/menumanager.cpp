//
// Created by Collei on 25-5-22.
//

#include "menumanager.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>

MenuManager::MenuManager(QObject *parent) : QObject(parent) {

}

MenuManager::~MenuManager() = default;

void MenuManager::setupUI(QAction *newAction, QAction *openAction, QAction *saveAction, QAction *exportAction) {
    this->m_pNewAction = newAction;
    this->m_pOpenAction = openAction;
    this->m_pSaveAction = saveAction;
    this->m_pExportAction = exportAction;

    connect(m_pNewAction, &QAction::triggered, this, &MenuManager::onNewActionTriggered);
    connect(m_pOpenAction, &QAction::triggered, this, &MenuManager::onOpenActionTriggered);
    connect(m_pSaveAction, &QAction::triggered, this, &MenuManager::onSaveActionTriggered);
    connect(m_pExportAction, &QAction::triggered, this, &MenuManager::onExportActionTriggered);
}

void MenuManager::onNewActionTriggered() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(dynamic_cast<QWidget *>(parent()), "新建文件", "是否新建文件？这将清除画布内容。",QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        m_currentFilePath.clear();
        emit clearCanvas();
    }
}

void MenuManager::onOpenActionTriggered() {
    QString filePath = QFileDialog::getOpenFileName(
        nullptr,
        "选择 SVG 文件",
        QDir::homePath(),
        "SVG 文件 (*.svg *.svgz)"
    );
    if (filePath.isEmpty()) {
        return;
    }
    m_currentFilePath = filePath;
    emit loadSvgFrame(filePath);
}

void MenuManager::onSaveActionTriggered() {
    if (m_currentFilePath.isEmpty()) {
        onExportActionTriggered();
    } else {
        emit exportSvg(m_currentFilePath);
    }
}

void MenuManager::onExportActionTriggered() {
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);// 获取默认保存路径（用户文档目录）
    QString filename = QFileDialog::getSaveFileName(
        dynamic_cast<QWidget *>(parent()),
        QObject::tr("Export as SVG"),
        defaultPath + "/untitled.svg",
        QObject::tr("SVG Files (*.svg)")
    );
    if (filename.isEmpty()) {
        return;
    }
    if (!filename.endsWith(".svg", Qt::CaseInsensitive)) {
        filename += ".svg";
    }
    m_currentFilePath = filename;
    emit exportSvg(filename);
}



