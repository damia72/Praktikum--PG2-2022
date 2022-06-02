#include <character.h>
#include <string>
#ifndef TILE_H
#define TILE_H
class Character;
class Tile
{
public:
    Tile(int rowinput, int collumninput);
    const std::string &getTexture() const;
    Character *getPointerOnCharacter() const;
    void setPointerOnCharacter(Character *newPointerOnCharacter);
    bool hasCharacter() const;
    Tile* onLeave(Tile* desTile, Character* who);
    virtual bool moveTo(Tile* destTile, Character *who);
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;
    int getRow() const;
    int getCollumn() const;
protected:
    std::string texture;
    Character* pointerOnCharacter;
private:
    int row;
    int collumn;
};

#endif // TILE_H
