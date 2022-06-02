#include <abstractui.h>
#ifndef TERMINALUI_H
#define TERMINALUI_H


class TerminalUI : public AbstractUI
{
public:
    TerminalUI();
    int computeDirection();
    void draw(Level* level) override;
};

#endif // TERMINALUI_H
