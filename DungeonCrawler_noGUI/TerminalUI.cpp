#include "TerminalUI.h"

TerminalUI::TerminalUI()
{
}

void TerminalUI::draw(Level *level) {
    for(int row{}; row < numRows; ++row){
        for(int col{}; col < numColumns; ++col){
            std::cout << level->getTile(row, col)->getCharacterTexture();
        }
        std::cout << std::endl;
    }
}
