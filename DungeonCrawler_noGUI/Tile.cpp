#include "Tile.h"

Tile::Tile()
    :row(), column()
{

}

std::string Tile::getTexture()
{

}

bool Tile::hasCharacter()
{
    if (character != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }

}

Tile* Tile::onLeave(Tile *destTile, Character *who)
{
    return this;
}

Tile* Tile::onEnter(Tile *fromTile, Character *who)
{
    if (texture == ".") // return "this" if on Floor "."
        return this;

    if (texture == "#")// return "nullptr" if on Wall
        return nullptr;

    return .; // return the pointer to the connected Portal if on Portal
}

bool Tile::moveTo(Tile *destTile, Character *who)
{

}
