//
// Created by Collei on 25-5-22.
//

#include "regeditsettings.h"

#include <QColor>

RegeditSettings::RegeditSettings(QObject *parent)
    : QObject(parent)
    , m_settings("HKEY_CURRENT_USER\\SOFTWARE\\SVGEditor", QSettings::NativeFormat)
{
}

void RegeditSettings::setCanvasData(const CanvasData& canvasData) {
    m_settings.setValue("CanvasWidth", canvasData.m_canvasWidth);
    m_settings.setValue("CanvasHeight", canvasData.m_canvasHeight);
    m_settings.setValue("CanvasZoom", canvasData.m_zoomRatio);
    m_settings.setValue("CanvasColor",  canvasData.m_canvasColor.name(QColor::HexArgb));
}

QRect RegeditSettings::windowGeometry() const {
    return m_settings.value("WindowGeometry", QRect(50, 50, 1200, 800)).toRect();
}

void RegeditSettings::setWindowGeometry(const QRect &geometry) {
    m_settings.setValue("WindowGeometry", geometry);
}

int RegeditSettings::canvasWidth() const {
    return m_settings.value("CanvasWidth", 800).toInt();
}
void RegeditSettings::setCanvasWidth(const int width) {
    m_settings.setValue("CanvasWidth", width);
}

int RegeditSettings::canvasHeight() const {
    return m_settings.value("CanvasHeight", 600).toInt();
}
void RegeditSettings::setCanvasHeight(const int height) {
    m_settings.setValue("CanvasHeight", height);
}

double RegeditSettings::canvasZoom() const {
    return m_settings.value("CanvasZoom", 1).toDouble();
}
void RegeditSettings::setCanvasZoom(const double zoom){
    m_settings.setValue("CanvasZoom", zoom);
}

[[nodiscard]] QColor RegeditSettings::canvasColor() const {
    return m_settings.value("CanvasColor", "#FFFFFFFF").toString();
}
void RegeditSettings::setCanvasColor(const QColor &color) {
    m_settings.setValue("CanvasColor",  color.name(QColor::HexArgb));
}
