//
// Created by Collei on 25-5-24.
//

#ifndef SETTEXTCONTENTCOMMAND_H
#define SETTEXTCONTENTCOMMAND_H
#include "../CanvasFrame/textframe.h"
#include "command.h"

class SetTextContentCommand : public Command {
public:
    SetTextContentCommand(TextFrame* frame, const QString& oldText, const QString& newText)
        : m_frame(frame), m_oldText(oldText), m_newText(newText) {}

    void undo() override {
        if (m_frame) m_frame->setText(m_oldText);
    }
    void redo() override {
        if (m_frame) m_frame->setText(m_newText);
    }
private:
    TextFrame* m_frame;
    QString m_oldText;
    QString m_newText;
};

#endif //SETTEXTCONTENTCOMMAND_H
