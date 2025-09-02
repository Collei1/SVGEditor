//
// Created by Collei on 25-5-20.
//

#ifndef ACTIONCONFIG_H
#define ACTIONCONFIG_H
#include "graphics.h"

enum class ActionType{
    Arrow,
    Pen,
    Line,
    Circle,
    Triangle,
    RightTriangle,
    Rectangle,
    Pentagon,
    Hexagon,
    //Octagon,
    Pentagram,
    Diamond,
    Text,
    Zoom,
};

enum class AttributeType {
    Base,
    Line,
    Flat,
    Text
};

struct CanvasData {
    CanvasData(const int canvasWidth, const int canvasHeight, const double zoomRatio, const QColor& canvasColor) {
        this->m_canvasWidth = canvasWidth;
        this->m_canvasHeight = canvasHeight;
        this->m_zoomRatio = zoomRatio;
        this->m_canvasColor = canvasColor;
    }
    int m_canvasWidth;
    int m_canvasHeight;
    double m_zoomRatio;
    QColor m_canvasColor;
};

struct GraphicsData {
    explicit GraphicsData()= default;
    explicit GraphicsData(Graphics* graphics) {
        this->m_borderWidth = graphics->borderWidth();
        this->m_borderStyle = graphics->borderStyle();
        this->m_borderColor = graphics->borderColor();
        this->m_filledColor = graphics->filledColor();
    }
    int m_borderWidth = 0;
    Qt::PenStyle m_borderStyle{};
    QColor m_borderColor{};
    QColor m_filledColor{};
};

struct TextData {
    QColor m_textColor;
    QFont m_font;
    int m_size;
    bool m_bold;
    bool m_italic;
    bool m_underline;
    explicit TextData() {
        m_textColor = Qt::black;
        QFont font("微软雅黑");
        m_size = 13;
        m_bold = false;
        m_italic = false;
        m_underline = false;
    };
};

static AttributeType getAttributeType(const ActionType type) {
    switch (type) {
        case ActionType::Arrow:
        case ActionType::Zoom:
            return AttributeType::Base;
        case ActionType::Pen:
        case ActionType::Line:
            return AttributeType::Line;
        case ActionType::Text:
            return AttributeType::Text;
        case ActionType::Circle:
        case ActionType::Triangle:
        case ActionType::RightTriangle:
        case ActionType::Rectangle:
        case ActionType::Pentagon:
        case ActionType::Hexagon:
        case ActionType::Pentagram:
        case ActionType::Diamond:
            return AttributeType::Flat;
        default:
            return AttributeType::Base;
    }
}
static QString getShapeName(const ActionType type) {
    switch (type) {
        case ActionType::Circle: {
            return "圆形";
        }
        case ActionType::Rectangle: {
            return "矩形";
        }
            /*case ActionType::RoundedRectangle: {
                return "圆角矩形";
            }*/
        case ActionType::Triangle: {
            return "三角形";
        }
        case ActionType::Diamond: {
            return "菱形";
        }
            case ActionType::RightTriangle: {
                return "直角三角形";
            }
        case ActionType::Pentagon: {
            return "五边形";
        }
        case ActionType::Hexagon: {
            return "六边形";
        }
        case ActionType::Pentagram: {
            return "五角星";
        }
        default:break;
    }
    return {};
}

class ActionConfig {//单例模式管理ActionConfig
public:
    static ActionConfig& getInstance() {
        static ActionConfig instance;
        return instance;
    }

    ActionType getType(const int key) const {
        const auto it = m_actionConfig.find(key);
        if (it != m_actionConfig.end()) {
            return it->second;
        }
    }

    ActionType currentType() const {return m_currentType;}
    void setCurrentType(ActionType type) {
        m_currentType = type;
    }

private:
    ActionConfig(): m_currentType(ActionType::Arrow){
        m_actionConfig.insert({0, ActionType::Arrow});
        m_actionConfig.insert({1, ActionType::Pen});
        m_actionConfig.insert({2, ActionType::Line});
        m_actionConfig.insert({3, ActionType::Circle});
        m_actionConfig.insert({4, ActionType::Triangle});
        m_actionConfig.insert({5, ActionType::RightTriangle});
        m_actionConfig.insert({6, ActionType::Rectangle});
        m_actionConfig.insert({7, ActionType::Pentagon});
        m_actionConfig.insert({8, ActionType::Hexagon});
        m_actionConfig.insert({9, ActionType::Pentagram});
        m_actionConfig.insert({10, ActionType::Diamond});
        m_actionConfig.insert({11, ActionType::Text});
        m_actionConfig.insert({12, ActionType::Zoom});
    }
    ~ActionConfig() = default;
    ActionConfig(const ActionConfig&) = delete;
    ActionConfig& operator=(const ActionConfig&) = delete;
    std::unordered_map<int, ActionType> m_actionConfig;
    ActionType m_currentType;
};


class BorderStyleConfig {//单例模式管理BorderStyleConfig
public:
    static BorderStyleConfig& getInstance() {
        static BorderStyleConfig instance;
        return instance;
    }
    Qt::PenStyle getPenStyles(const int i) const {
        return m_borderStyles[i];
    }
    int getIndex(const Qt::PenStyle key) const {
        const auto it = m_borderStyleConfig.find(key);
        if (it != m_borderStyleConfig.end()) {
            return it->second;
        }
    }
    size_t amount() const {
        return m_borderStyles.size();
    }

private:
    BorderStyleConfig() {
        for (int i = 0; i < m_borderStyles.size(); ++i) {
            m_borderStyleConfig.insert({m_borderStyles[i], i});
        }
    }
    ~BorderStyleConfig() = default;
    BorderStyleConfig(const BorderStyleConfig&) = delete;
    BorderStyleConfig& operator=(const BorderStyleConfig&) = delete;

    QList<Qt::PenStyle> m_borderStyles = {
        Qt::SolidLine,
        Qt::DashLine,
        Qt::DotLine,
        Qt::DashDotLine,
        Qt::DashDotDotLine
    };
    std::unordered_map<Qt::PenStyle, int> m_borderStyleConfig;
};

class FontSizeConfig {
public:
    static FontSizeConfig& getInstance() {
        static FontSizeConfig instance;
        return instance;
    }
    int getFontSize(const int i) const {
        return m_fontSizes[i];
    }
    int getIndex(const int key) const {
        const auto it = m_fontSizeConfig.find(key);
        if (it != m_fontSizeConfig.end()) {
            return it->second;
        }
    }

private:
    FontSizeConfig() {
        for (int i = 0; i < m_fontSizes.size(); ++i) {
            m_fontSizeConfig.insert({m_fontSizes[i], i});
        }
    }
    ~FontSizeConfig() = default;
    FontSizeConfig(const FontSizeConfig&) = delete;
    FontSizeConfig& operator=(const FontSizeConfig&) = delete;

    QList<int> m_fontSizes = {
        12, 13, 14, 15, 16, 17, 18, 20, 24, 32, 40, 64
    };
    std::unordered_map<int, int> m_fontSizeConfig;
};


#endif //ACTIONCONFIG_H
