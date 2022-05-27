#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "AbstractUI.h"
#include "Level.h"
class TerminalUI : virtual public AbstractUI
{
public:
    TerminalUI();
    void draw(Level* level) override;
};

#endif // TERMINALUI_H
