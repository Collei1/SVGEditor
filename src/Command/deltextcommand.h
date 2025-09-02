//
// Created by Collei on 25-5-24.
//

#ifndef DELTEXTGRAPHICSCOMMAND_H
#define DELTEXTGRAPHICSCOMMAND_H
#include "../CanvasFrame/canvasframe.h"
#include "command.h"
class DelTextCommand : public Command {
public:
    DelTextCommand(CanvasFrame* canvas, TextFrame* text)
        : m_canvas(canvas), m_text(text), m_index(-1) {}

    void undo() override {
        if (m_text && m_canvas) {
            m_canvas->addText(m_text, m_index);
        }
    }
    void redo() override {
        if (m_text && m_canvas) {
            m_index = m_canvas->removeText(m_text);
        }
    }
    [[nodiscard]] TextFrame* text() const { return m_text; }
private:
    CanvasFrame* m_canvas;
    TextFrame* m_text;
    int m_index;
};


#endif //DELTEXTGRAPHICSCOMMAND_H
