#include "portal.h"
#include <iostream>

using namespace std;
Portal::Portal(int rowinput, int collumninput, Portal *pointerToTheOtherPortalInput) : Tile(rowinput, collumninput)
{
    texture = "O";
    pointerToTheOtherPortal = pointerToTheOtherPortalInput;
    if(pointerToTheOtherPortalInput != nullptr){
        isPortalActive = true;
    }else{
        isPortalActive = false;
    }
}

Tile *Portal::onEnter(Tile *fromTile, Character *who)
{
    if(!isPortalActive){
        cout << "Fehler: Portal ist nicht aktiv\n";
        return nullptr;
    }else{
        return pointerToTheOtherPortal;
    }
}


void Portal::activatePortal(Portal *pointerToTheOtherPortalInput)
{
    if(pointerToTheOtherPortalInput == nullptr){
        cout << "Fehler: Portal kann nicht aktiviert werden, weil es nirgendwo hinzeigt";
        return;
    }else{
        pointerToTheOtherPortal = pointerToTheOtherPortalInput;
        isPortalActive = true;
    }

}

Portal *Portal::getPointerToTheOtherPortal() const
{
    return pointerToTheOtherPortal;
}




