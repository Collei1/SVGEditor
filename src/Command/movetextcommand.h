//
// Created by Collei on 25-5-24.
//

#ifndef MOVETEXTCOMMAND_H
#define MOVETEXTCOMMAND_H
#include "command.h"
#include "../CanvasFrame/canvasframe.h"
class MoveTextCommand : public Command {
public:
    MoveTextCommand(TextFrame* text, const QPoint& oldPosition, const QPoint& newPosition)
        : m_pText(text), m_oldPosition(oldPosition), m_newPosition(newPosition) {}

    void undo() override {
        if (m_pText) {
            m_pText->move(m_oldPosition);
        }
    }

    void redo() override {
        if (m_pText) {
            m_pText->move(m_newPosition);
        }
    }

private:
    TextFrame* m_pText;
    QPoint m_oldPosition;
    QPoint m_newPosition;
};


#endif //MOVETEXTCOMMAND_H
