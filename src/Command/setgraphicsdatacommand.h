//
// Created by Collei on 25-5-24.
//

#ifndef SETGRAPHICSDATACOMMAND_H
#define SETGRAPHICSDATACOMMAND_H

#include "../CanvasFrame/graphicsframe.h"
#include "command.h"
#include "../Graphics/config.h"

class SetGraphicsDataCommand : public Command {
public:
    SetGraphicsDataCommand(GraphicsFrame* frame, const GraphicsData& oldData, const GraphicsData& newData)
        : m_frame(frame), m_oldData(oldData), m_newData(newData) {}

    void undo() override {
        if (m_frame) m_frame->setGraphicsData(m_oldData);
    }
    void redo() override {
        if (m_frame) m_frame->setGraphicsData(m_newData);
    }
private:
    GraphicsFrame* m_frame;
    GraphicsData m_oldData;
    GraphicsData m_newData;
};

#endif //SETGRAPHICSDATACOMMAND_H
