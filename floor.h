#include "tile.h"
#ifndef FLOOR_H
#define FLOOR_H


class Floor : public Tile
{
public:
    Floor(int rowinput, int collumninput);
    Tile* onEnter(Tile* fromTile, Character* who) override;
};

#endif // FLOOR_H
