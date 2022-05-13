#include "Level.h"

Level::Level()
    :hight(4), width(4)
{
    //a pair of Portals are still be created
    for(int i = 0; i < numRows; i ++ ) {
        for(int z = 0; z < numColumns; z++){
           this->stage[i][z] = new Floor(this, i, z);
        }
    }
    delete stage[1][1];
    delete stage[3][3];
    this->stage[1][1] = new Portal(this, 1, 1, nullptr);

    Portal* newPort = dynamic_cast<Portal*>(this->stage[1][1]);

    this->stage[1][1]= newPort;
    this->stage[3][3] = new Portal(this, 3, 3, newPort);
    Portal* newPort2 = dynamic_cast<Portal*>(this->stage[3][3]);
    newPort2->connectPortal(newPort);
    this->stage[3][3] = newPort2;
}

Level::~Level()
{
    for(unsigned int i{}; i < listCharacters.size(); i++) {
        delete listCharacters.at(i);
    }
    for(int row{}; row< numRows; ++row ) {
        for(int col{}; col < numColumns ; ++col) {
            delete stage[row][col];
        }
    }
}

Tile* Level::getTile(int row, int col)
{
    return stage[row][col];
}

const Tile* Level::getTile(int row, int col) const
{
    return stage[row][col];
}

void Level::placeCharacter(Character *c, int row, int col)
{
    /** Just like linked list
     *  Character must know on which Tile he is standing on
     *  (currentTile of Character should be assigned with the given Tile)
     *  and
     *  Tile must know which Character is standing on it
     *  (character of Tile - here is a element in Level:
     *  std::array<std::array<Tile*, numRows>, numColumns> stage;
     *
     *  IN Character there is a "currentTile" Attribute
     *  IN Tile there is a "character" Attribute
     */
    c->currentTile = stage[row][col];
    stage[row][col]->character = c;
}

