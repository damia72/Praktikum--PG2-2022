#include <level.h>
#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H


class AbstractUI
{
public:
    AbstractUI();
protected:
    virtual void draw(Level* level) = 0;
};

#endif // ABSTRACTUI_H
