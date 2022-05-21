#include "Level.h"

Level::Level()
{
    for(int row{}; row < numRows; ++row ) {
        for(int col = 0; col < numColumns; ++col){
           stage[row][col] = new Floor(this, row, col);
        }
    }

    for(int row = 0; row < numRows; ++row ) {
        for(int col = 0; col < numColumns; ++col){
            if (row == 0 || row == numRows-1)
            {
                stage[row][col] = new Wall(this, row, col);
            }
            if (row >= 1 && row <= numColumns)
            {
                stage[row][0] = new Wall(this, row, col);
                stage[row][numColumns-1] = new Wall(this, row, col);
            }
            std::cout << std::endl;
        }
    }

    //a pair of Portals are still be created
    // Character's position should also be initialised here too
}

Level::~Level()
{
    for(unsigned int i{}; i < listCharacters.size(); i++) {
        delete listCharacters.at(i);
    }
    for(int row{}; row < numRows; ++row ) {
        for(int col{}; col < numColumns ; ++col) {
            delete stage[row][col];
        }
    }
}

Level::Level( const Level& level )
{

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

    //c->level = this;
    Tile* temp = stage[row][col];
    c->setTile(temp);
    //c->setTile(this->getTile(row,col));
    temp->setCharacter(c);
    listCharacters.push_back(c);
}

