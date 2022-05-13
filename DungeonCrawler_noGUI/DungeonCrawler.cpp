#include "DungeonCrawler.h"

DungeonCrawler::DungeonCrawler()
{
    currentLevel = new Level;
    abstractUI = new TerminalUI;
}
void DungeonCrawler::play() {
    Character* char1 = new Character;
    this->currentLevel->placeCharacter(char1, 1, 3);
    while(true) {
        this->terminalUI->draw(this->currentLevel);
        this->currentLevel->listCharacters.at(0)->move();
    }
}
