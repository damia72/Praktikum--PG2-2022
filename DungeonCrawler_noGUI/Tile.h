#ifndef TILE_H
#define TILE_H

#include <iostream>

class Character;
class Tile
{
public:
    explicit Tile();
    virtual ~Tile();

    /**
     * @brief getTexture prints out the Tiles on the console(Terminal)
     * @return
     */
    std::string getTexture();

    /**
     * @brief hasCharacter
     * @return true if Character is on the tile,
     * else returns false
     */
    bool hasCharacter();

    /**
     * @brief moveTo implements the movement of Character "who"
     * from a tile to another tile
     * (eventhough it is a bool method, its main function is to implement the movement)
     *
     * @param destTile is the destination to which the current tile (this) will move to
     *
     * @param who is Character "who"
     * @return true if the movement is successful
     */
    bool moveTo(Tile* destTile, Character* who);

    /**
     * @brief onEnter implements what should happen when entering a tile
     * @param fromTile is the starting tile (The movement is started there)
     * and "this" is the destination tile( Die Kachel die versucht wird zu betreten)
     *
     * @return
     * "nullptr" if the current tile can not be entered (nicht betretbar - not walkable)
     * "this" (the current tile - destination tile) if it is enterable
     *
     *
     */
    Tile* onEnter(Tile* fromTile, Character* who);

    /**
     * @brief
     * onLeave implements what should happen when leaving (beim Verlassen) a tile
     *
     * @param destTile is the destination tile (The movement is arrived there)
     * "this" is the starting Tile (Auch hier ist die Kachel, welche verlassen wird, this)
     *
     * @return
     * "nullptr" if the current tile can not be left (nicht verlassbar - not leftable)
     * "this" (the current tile - starting Tile) if it is leftable
     *
     */
    Tile* onLeave(Tile* destTile, Character* who);

    //getter and setter
    Character* getCharacter()
    {
        return character;
    }

protected:
    /**
     * @brief texture is a string to save which kind of
     * texture (Floor ".", Wall "#" or Portal"O" )
     * In the ohne GUI version it will be used to
     * print out a particular Zeichnen for each type of Tile
     */
    std::string texture;

    /**
     * @brief character is a pointer to the Character (Spielfigur)
     * if there is no Character --> = nullptr
     * Through this pointer, the Tile can know which Character are standing on it
     * (The Character also has a Tile* => he knows on which tile he is standing on)
     */
    Character* character;

    /**
     * @brief row & column are position of Tile on the Level (which one?)
     * These two are constant values and will not change over the lifetime of a Tile object
     */
    const double row;
    const double column;
};

/**
 * @brief The Floor class is a normal, walkable(betretbar) floor tile
 */
class Floor : virtual public Tile
{

};

/**
 * @brief The Wall class is the not stepable tile
 */
class Wall : virtual public Tile
{

};

/**
 * @brief The Portal class works like wormhole
 */
class Portal : virtual public Tile
{

};
#endif // TILE_H
