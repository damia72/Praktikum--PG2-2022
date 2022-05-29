#include "Tile.h"


std::string Tile::getTexture()
{
    return texture;
}

std::string Tile::getCharacterTexture() {
    if(hasCharacter()) {
        return "X";
    }
    else return getTexture();
}

bool Tile::hasCharacter()
{   //if Character locates on Tile --> true
    // Character on Tile <=> attribue, pointer character of Tile != nullptr
    if (this->character != nullptr) {
        return true;
    }
    return false;
}

int Tile::getRow() const {
    return row;
}

int Tile::getCol() const {
    return column;
}

bool Tile::moveTo(Tile *destTile, Character *who)
{
    /**After both above-mentioned conditions are satisfied,
    *  We can set the attribute Character* of starting Tile and target Tile
    *  by doing:
    *  1. Character* attribute of destination Tile = who;
    *  2. Character* attribute of starting Tile = nullptr;
    *
    *  AGAIN: this is current Tile (actualleft)
    */

    Tile* actualleft = this->onLeave(this,who);
    if(actualleft==nullptr) return false;

    Tile* EnteredTile = destTile->onEnter(actualleft,who);
    if(EnteredTile == nullptr) return false;

    actualleft->setCharacter(nullptr);
    EnteredTile->setCharacter(who);//großer Unterschied: destTile->setCharacter();
    who->setTile(EnteredTile);//update Tile* in Character
    return true;
/************************************************************
    if (onLeave(destTile, who) != nullptr) {
        //save the result from onLeave - the actual left Tile
        Tile* actualleft = onLeave(destTile,who);

        //result from onLeave used in onEnter as Parameter
        //if (onEnter(actualleft, who) != nullptr) {
        if (destTile->onEnter(actualleft, who) != nullptr) {

            destTile->character = who;
            this->character = nullptr;

            //update Tile* in Character
            who->currentTile = destTile;


//            destTile->character->characterTexture = who->characterTexture;
//            destTile->character->level = who->level;
            return true;

        }
        else {
            std::cout << "can not enter this Tile!" << std::endl;
            return false;
        }
    }
    std::cout << "can not leave this Tile" << std::endl;
    return false;
******************************************************************/
}

/**
 * Floor onLeave & onEnter implementation
 */
Tile* Floor::onEnter(Tile *fromTile, Character *who)
{
     // return "this" if on Floor "."
        return this;

}

Tile* Floor::onLeave(Tile *destTile, Character *who)
{
    return this;
}

/**
 * Wall onLeave & onEnter  implementation
 */
Tile* Wall::onEnter(Tile *fromTile, Character *who)
{
    // return "nullptr" if on Wall
    return nullptr;

}

Tile* Wall::onLeave(Tile *destTile, Character *who)
{
    return this;
}

/**
 * Portal onLeave & onEnter implementation
 */
Tile* Portal::onEnter(Tile *fromTile, Character *who)
{
    return connectedPortal; // return the pointer to the connected Portal if on Portal

}

void Portal::setConnectedPortal(Portal *newConnectedPortal)
{
    connectedPortal = newConnectedPortal;
}

Tile* Portal::onLeave(Tile *destTile, Character *who)
{
    return this;
}


