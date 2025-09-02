//
// Created by Collei on 25-5-24.
//

#ifndef ADDGRAPHICSCOMMAND_H
#define ADDGRAPHICSCOMMAND_H
#include "command.h"
#include "../CanvasFrame/canvasframe.h"
class AddGraphicsCommand : public Command {
    CanvasFrame* m_pCanvas;
    GraphicsFrame* m_pFrame;
public:
    AddGraphicsCommand(CanvasFrame* canvas, GraphicsFrame* frame) : m_pCanvas(canvas), m_pFrame(frame) {}
    void undo() override { m_pCanvas->removeFrame(m_pFrame); }
    void redo() override { m_pCanvas->addFrame(m_pFrame, -1); }
    [[nodiscard]] GraphicsFrame* frame() const { return m_pFrame; }
};


#endif //ADDGRAPHICSCOMMAND_H
