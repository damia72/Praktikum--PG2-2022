#include "wall.h"

#include <wall.h>

Wall::Wall(int rowinput, int collumninput) : Tile(rowinput, collumninput)
{
    texture = "#";
}

Tile *Wall::onEnter(Tile *fromTile, Character *who)
{
    return nullptr;
}

