//
// Created by Collei on 25-5-24.
//

#ifndef DELGRAPHICSCOMMAND_H
#define DELGRAPHICSCOMMAND_H
#include "../CanvasFrame/canvasframe.h"
#include "command.h"
class DelGraphicsCommand : public Command {
public:
    DelGraphicsCommand(CanvasFrame* canvas, GraphicsFrame* frame)
        : m_canvas(canvas), m_frame(frame), m_index(-1) {}

    void undo() override {
        if (m_frame && m_canvas) {
            m_canvas->addFrame(m_frame, m_index);
        }
    }
    void redo() override {
        if (m_frame && m_canvas) {
            m_index = m_canvas->removeFrame(m_frame);
        }
    }
    [[nodiscard]] GraphicsFrame* frame() const { return m_frame; }
private:
    CanvasFrame* m_canvas;
    GraphicsFrame* m_frame;
    int m_index; // 记录原来的位置
};


#endif //DELGRAPHICSCOMMAND_H
