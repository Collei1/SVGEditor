//
// Created by Collei on 25-5-24.
//

#ifndef ADDTEXTCOMMMAND_H
#define ADDTEXTCOMMMAND_H
#include "command.h"
#include "../CanvasFrame/canvasframe.h"
class AddTextCommand : public Command {
    CanvasFrame* m_pCanvas;
    TextFrame* m_pText;
public:
    AddTextCommand(CanvasFrame* canvas, TextFrame* text) : m_pCanvas(canvas), m_pText(text) {}
    void undo() override { m_pCanvas->removeText(m_pText); }
    void redo() override { m_pCanvas->addText(m_pText, -1); }
    [[nodiscard]] TextFrame* text() const { return m_pText; }
};

#endif //ADDTEXTCOMMMAND_H
