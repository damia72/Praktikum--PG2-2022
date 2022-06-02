#include <tile.h>
#ifndef WALL_H
#define WALL_H


class Wall : public Tile
{
public:
    Wall(int rowinput, int collumninput);
    Tile* onEnter(Tile* fromTile, Character* who) override;
};

#endif // WALL_H
