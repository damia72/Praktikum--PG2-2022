#include "TerminalUI.h"


void TerminalUI::draw(Level *level) {
    for(int i{}; i < numRows; i++)
    {
        for(int z{}; z < numColumns; z++)
        {
            std::cout << level->getTile(i, z)->getCharacterTexture();
        }
        std::cout << std::endl;
    }
}
