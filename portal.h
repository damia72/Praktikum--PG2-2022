#include <tile.h>
#ifndef PORTAL_H
#define PORTAL_H
class Portal : public Tile
{
public:
    Portal(int rowinput, int collumninput, Portal* pointerToTheOtherPortalInput);
    const std::string &getTexture() const;
    Tile* onEnter(Tile* fromTile, Character* who);
    void activatePortal( Portal* pointerToTheOtherPortalInput);
    Portal *getPointerToTheOtherPortal() const;
private:
    Portal* pointerToTheOtherPortal;
    bool isPortalActive;
};

#endif // PORTAL_H
