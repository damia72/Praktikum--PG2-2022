#include "floor.h"

Floor::Floor(int rowinput, int collumninput) : Tile(rowinput, collumninput)
{
    texture = ".";
}

Tile *Floor::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

