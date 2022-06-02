#include <iostream>
#ifndef CHARACTER_H
#define CHARACTER_H
class Tile;

class Character
{
public:
    Character(Tile* startingPosition);
    Tile *getPointerOnTile() const;
    void setPointerOnTile(Tile *newPointerOnTile);

    const std::string &getTexture() const;

private:
    Tile* pointerOnTile;
    std::string texture;
};

#endif // CHARACTER_H
