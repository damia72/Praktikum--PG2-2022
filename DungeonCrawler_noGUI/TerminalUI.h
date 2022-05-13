#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "AbstractUI.h"

class TerminalUI : public AbstractUI
{
public:
    TerminalUI();
    ~TerminalUI(){};
    void draw(Level* level) override;
};

#endif // TERMINALUI_H
