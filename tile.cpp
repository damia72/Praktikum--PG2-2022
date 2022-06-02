#include "tile.h"
#include "portal.h"
#include <iostream>
using namespace std;
Tile::Tile(int rowinput, int collumninput)
{
    pointerOnCharacter = nullptr;
    row = rowinput;
    collumn = collumninput;
}

const std::string &Tile::getTexture() const
{
    if(hasCharacter()){
        return getPointerOnCharacter()->getTexture();
    }else{
        return texture;
    }
}

Character *Tile::getPointerOnCharacter() const
{
    return pointerOnCharacter;
}

void Tile::setPointerOnCharacter(Character *newPointerOnCharacter)
{
    pointerOnCharacter = newPointerOnCharacter;
}

bool Tile::hasCharacter() const
{
    if(pointerOnCharacter == nullptr){
        return false;
    }else{
        return true;
    }
}

bool Tile::moveTo(Tile *destTile, Character *who)
{
    if(who == nullptr){
        cout << "Cannot move Character: Character is not on Tile";
        return false;
    }
    if(destTile == nullptr){
        cout << "Cannot move Character: Tile does not exist";
        return false;
    }
    if(destTile->onLeave(destTile, who) == nullptr){
        cout << "Cannot leave This Tile!\n";
        return false;
    }
    if(destTile->onEnter(this, who) == nullptr){
        cout << "Cannot enter the new Tile!\n";
        return false;
    }else if (destTile->getTexture() == "O"){
         dynamic_cast<Portal*>(destTile)->getPointerToTheOtherPortal()->setPointerOnCharacter(pointerOnCharacter);
        who->setPointerOnTile(dynamic_cast<Portal*>(destTile)->getPointerToTheOtherPortal());
        pointerOnCharacter = nullptr;
        return true;
    }else{
        destTile->setPointerOnCharacter(pointerOnCharacter);
        who->setPointerOnTile(destTile);
        pointerOnCharacter = nullptr;
        return true;
    }
    return false;
}

int Tile::getRow() const
{
    return row;
}

int Tile::getCollumn() const
{
    return collumn;
}

Tile *Tile::onLeave(Tile *desTile, Character *who)
{
    return this;
}


