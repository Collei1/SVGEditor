//
// Created by Collei on 25-5-22.
//

#ifndef REGEDITSETTINGS_H
#define REGEDITSETTINGS_H

#include <QMutex>
#include <QSettings>
#include <QRect>

#include "../Graphics/config.h"

class RegeditSettings : public QObject
{
    Q_OBJECT
public:
    static RegeditSettings& getInstance() {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        static RegeditSettings instance;
        return instance;
    }

    void setCanvasData(const CanvasData& canvasData);

    [[nodiscard]] QRect windowGeometry() const;
    void setWindowGeometry(const QRect &geometry);

    [[nodiscard]] int canvasWidth() const;
    void setCanvasWidth(int width);

    [[nodiscard]] int canvasHeight() const;
    void setCanvasHeight(int height);

    [[nodiscard]] double canvasZoom() const;
    void setCanvasZoom(double zoom);

    [[nodiscard]] QColor canvasColor() const;
    void setCanvasColor(const QColor &color);

private:
    explicit RegeditSettings(QObject *parent = nullptr);
    ~RegeditSettings() = default;
    RegeditSettings(const RegeditSettings&) = delete;
    RegeditSettings& operator=(const RegeditSettings&) = delete;

    QSettings m_settings;
};


#endif //REGEDITSETTINGS_H
