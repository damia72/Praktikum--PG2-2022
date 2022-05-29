#ifndef TILE_H
#define TILE_H

#include <iostream>
#include"Character.h"
class Character;
class Level;
class Tile
{
public:
    /**
     * @brief Tile
     * @param stage
     * @param r row_in
     * @param c columm_in
     */
    explicit Tile(Level* stage, int row_in, int col_in)
        :  currentLevel(stage), row(row_in), column(col_in)
    {
        character = nullptr;
    }
    virtual ~Tile(){};

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
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;

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
    virtual Tile* onLeave(Tile* destTile, Character* who)= 0;


    //getter and setter
    Character* getCharacter()
    {
        return character;
    }
    void setCharacter(Character* c)
    {
        character = c;
    }
    int getRow() const;
    int getCol() const;
    std::string getCharacterTexture();


protected:
    /**
     * @brief texture is a string to save which kind of
     * texture (Floor ".", Wall "#" or Portal"O" )
     * In the ohne GUI version it will be used to
     * print out a particular Zeichnen for each type of Tile
     */
    std::string texture;
    /**
     * @brief currentLevel shows on which Level the Character bzw. the Tile is on
     */
    Level* currentLevel;
    /**
     * @brief row & column are position of Tile on the Level (which one?)
     * These two are constant values and will not change over the lifetime of a Tile object
     */
    const int row;
    const int column;
    /**
     * @brief character is a pointer to the Character (Spielfigur)
     * if there is no Character --> = nullptr
     * Through this pointer, the Tile can know which Character are standing on it
     * (The Character also has a Tile* => he knows on which tile he is standing on)
     */
    Character* character;

};

/**
 * @brief The Floor class is a normal, walkable(betretbar) floor tile
 */
class Floor : virtual public Tile
{
public:

    Floor(Level* stage, int row, int col)
        : Tile(stage, row, col)
    {
        character = nullptr;
        currentLevel = stage;
        texture = ".";
    }
    Tile* onLeave(Tile *destTile, Character *who) override;
    Tile* onEnter(Tile* fromTile, Character* who) override;

};

/**
 * @brief The Wall class is the not stepable tile
 */
class Wall : virtual public Tile
{
public:

    Wall(Level* stage, int row, int col)
        : Tile(stage, row, col)
    {
        character = nullptr;
        currentLevel = stage;
        texture = "#";
    }
    Tile* onLeave(Tile *destTile, Character *who) override;
    Tile* onEnter(Tile* fromTile, Character* who) override;
};

/**
 * @brief The Portal class works like wormhole
 */
class Portal : virtual public Tile
{
public:
    //Portal(Level* stage,  int row, int col, Portal* port)
    Portal(Level* stage,  int row, int col)
        : Tile(stage, row, col)
    {
        //connectedPortal = port;
        character = nullptr;
        currentLevel = stage;
        texture = "O";
    }
    Tile* onLeave(Tile *destTile, Character *who) override;
    Tile* onEnter(Tile* fromTile, Character* who) override;

    void setConnectedPortal(Portal *newConnectedPortal);

private:
    Portal* connectedPortal;
};
#endif // TILE_H
