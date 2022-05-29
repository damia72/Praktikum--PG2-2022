#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

#include "Level.h"
/**
 * @brief The AbstractUI class is a pure virtual class
 */

class AbstractUI
{
public:
    AbstractUI();
    virtual void draw(Level*) = 0;// = 0 <=> pure virtual methode
};

#endif // ABSTRACTUI_H
