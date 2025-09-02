//
// Created by Collei on 25-5-10.
//

#ifndef GRAPHICSFACTORY_H
#define GRAPHICSFACTORY_H
#include "config.h"
#include "graphics.h"
#include "../CanvasFrame//textframe.h"

class GraphicsFactory {
public:
    virtual ~GraphicsFactory() = default;
    virtual std::unique_ptr<Graphics> createGraphics(QWidget *parent) = 0;
};

class BasicFactory : public GraphicsFactory {
public:
    std::unique_ptr<Graphics> createGraphics(QWidget *parent) override {
        switch (ActionConfig::getInstance().currentType()) {
            case ActionType::Pen: {
                return std::make_unique<Pen>(parent);
            }
            case ActionType::Line: {
                return std::make_unique<Line>(parent);
            }
            case ActionType::Circle: {
                return std::make_unique<Circle>(parent);
            }
            case ActionType::Rectangle: {
                return std::make_unique<Rectangle>(parent);
            }/*case ActionType::RoundedRectangle: {
                return std::make_unique<Circle>(QPoint(15, 15) ,parent);
            }*/
            case ActionType::Triangle: {
                return std::make_unique<Triangle>(parent);
            }
            case ActionType::Diamond: {
                return std::make_unique<Diamond>(parent);
            }
            case ActionType::RightTriangle: {
                return std::make_unique<RightTriangle>(parent);
            }
            case ActionType::Pentagon: {
                return std::make_unique<Pentagon>(parent);
            }
            case ActionType::Hexagon: {
                return std::make_unique<Hexagon>(parent);
            }
            case ActionType::Pentagram: {
                return std::make_unique<Pentagram>(parent);
            }
            default:break;
        }
        return {};
    }
};

class CopyFactory{
public:
    std::unique_ptr<Graphics> createGraphics(const ActionType type, Graphics* graphics, QWidget *parent) {
        switch (type) {
            case ActionType::Pen: {
                return std::make_unique<Pen>(graphics);
            }
            case ActionType::Line: {
                return std::make_unique<Line>(graphics);
            }
            case ActionType::Circle: {
                return std::make_unique<Circle>(graphics);
            }
            case ActionType::Rectangle: {
                return std::make_unique<Rectangle>(graphics);
            }/*case ActionType::RoundedRectangle: {
                return std::make_unique<Circle>(QPoint(15, 15) ,parent);
            }*/
            case ActionType::Triangle: {
                return std::make_unique<Triangle>(graphics);
            }
            case ActionType::Diamond: {
                return std::make_unique<Diamond>(graphics);
            }
            case ActionType::RightTriangle: {
                return std::make_unique<RightTriangle>(graphics);
            }
            case ActionType::Pentagon: {
                return std::make_unique<Pentagon>(graphics);
            }
            case ActionType::Hexagon: {
                return std::make_unique<Hexagon>(graphics);
            }
            case ActionType::Pentagram: {
                return std::make_unique<Pentagram>(graphics);
            }
            default:break;
        }
        return {};
    }
};

class TextFactory{
public:
    std::unique_ptr<TextFrame> createText(QWidget *parent) {
        return std::make_unique<TextFrame>(parent);
    }
};

#endif //GRAPHICSFACTORY_H
