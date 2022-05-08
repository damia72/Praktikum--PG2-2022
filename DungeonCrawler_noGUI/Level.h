#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <vector>

class Tile;
class Character;

class Level
{
public:

    /**
     * @brief Standard constructor
     * creates a map 4x4 and a pair of Portals for testing purpose
     */
    Level();

    /**
     * @brief Destructor of class Level
     *
     * all the dynamic Resources (Tiles, Character, etc.) which are created
     * will be rightly destroyed
     */
    ~Level();

    /**
     * @brief getTile
     * @param row
     * @param col
     * @return
     */
    Tile* getTile( int row, int col );

    const Tile* getTile( int row, int col ) const;// const version of Tile* getTile

    /**
     * @brief placeCharacter initialises Level:
     * puts the Character on the Tile object at the given coordinates
     */
    void placeCharacter( Character *c, int row, int col );

private:
    std::vector<std::vector<Tile*>> listTiles;//Array aus Kacheln
    std::vector<Character*> listCharacter;//Array aus Figuren
    const int hight;// Höhe des Levels
    const int width;//Breite des Levels
};

#endif // LEVEL_H
