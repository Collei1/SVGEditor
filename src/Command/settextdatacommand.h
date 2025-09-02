//
// Created by Collei on 25-5-24.
//

#ifndef SETTEXTDATACOMMAND_H
#define SETTEXTDATACOMMAND_H

#include "../CanvasFrame/textframe.h"
#include "command.h"
#include "../Graphics/config.h"

class SetTextDataCommand : public Command {
public:
    SetTextDataCommand(TextFrame* frame, const TextData& oldData, const TextData& newData)
        : m_frame(frame), m_oldData(oldData), m_newData(newData) {}

    void undo() override {
        if (m_frame) m_frame->setTextData(m_oldData);
    }
    void redo() override {
        if (m_frame) m_frame->setTextData(m_newData);
    }
private:
    TextFrame* m_frame;
    TextData m_oldData;
    TextData m_newData;
};

#endif //SETTEXTDATACOMMAND_H
