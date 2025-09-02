//
// Created by Collei on 25-5-24.
//

#ifndef SETGEOMETRYCOMMAND_H
#define SETGEOMETRYCOMMAND_H
#include "command.h"
#include "../CanvasFrame/canvasframe.h"
class SetGeometryCommand : public Command {
public:
    SetGeometryCommand(GraphicsFrame* frame, const QRect& oldGeometry, const QRect& newGeometry)
        : m_pFrame(frame), m_oldGeometry(oldGeometry), m_newGeometry(newGeometry) {}

    void undo() override {
        if (m_pFrame) {
            m_pFrame->setGeometry(m_oldGeometry);
        }
    }

    void redo() override {
        if (m_pFrame) {
            m_pFrame->setGeometry(m_newGeometry);
        }
    }

private:
    GraphicsFrame* m_pFrame;
    QRect m_oldGeometry;
    QRect m_newGeometry;
};

#endif //SETGEOMETRYCOMMAND_H
