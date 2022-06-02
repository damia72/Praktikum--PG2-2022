#include "character.h"

Character::Character(Tile *startingPosition)
{
    pointerOnTile = startingPosition;
    texture = "@";
}

Tile *Character::getPointerOnTile() const
{
    return pointerOnTile;
}

void Character::setPointerOnTile(Tile *newPointerOnTile)
{
    pointerOnTile = newPointerOnTile;
}

const std::string &Character::getTexture() const
{
    return texture;
}
