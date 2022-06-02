#include "tile.h"
#include "floor.h"
#include "portal.h"
#include "wall.h"
#include <iostream>
#include <vector>
#ifndef LEVEL_H
#define LEVEL_H


class Level
{
public:
    Level(std::string levelInput);
    ~Level();
    int getLevelWidth() const;
    int getLevelHeight() const;

    const std::vector<std::vector<Tile *> > &getTileVector() const;

    const std::vector<Character *> &getCharacters() const;

private:
    int levelWidth;
    int levelHeight;    
    std::vector<std::vector<Tile*>> TileVector;
    std::vector<Character*> Characters;
};

#endif // LEVEL_H
