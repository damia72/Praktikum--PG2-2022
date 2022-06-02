#include "dungeoncrawler.h"
#include "level.h"
#include <iostream>
using namespace std;
DungeonCrawler::DungeonCrawler()
{
    playGame();
}

DungeonCrawler::~DungeonCrawler()
{
    delete level;
}


Tile *DungeonCrawler::whereIsCharacter(Character *who)
{
    return who->getPointerOnTile();
}

void DungeonCrawler::moveCharacter(int direction)
{
    bool moveSucess;
    //schaut wo der Charakter steht:
    int collumn = level->getCharacters()[0]->getPointerOnTile()->getCollumn();
    int row = level->getCharacters()[0]->getPointerOnTile()->getRow();
    switch (direction){
    //schaut nach wo charakter 0 steht und bewegt sich von dieser kachel aus
    //unten links:
    case 1: moveSucess = level->getCharacters()[0]->getPointerOnTile()
                ->moveTo(level->getTileVector()[row+1][collumn-1], level->getCharacters()[0]); break;
    //unten:
    case 2: moveSucess = level->getCharacters()[0]->getPointerOnTile()
                ->moveTo(level->getTileVector()[row+1][collumn+0], level->getCharacters()[0]); break;
    //unten rechts:
    case 3: moveSucess = level->getCharacters()[0]->getPointerOnTile()
                ->moveTo(level->getTileVector()[row+1][collumn+1], level->getCharacters()[0]); break;
    //links:
    case 4: moveSucess = level->getCharacters()[0]->getPointerOnTile()
                ->moveTo(level->getTileVector()[row][collumn-1], level->getCharacters()[0]); break;
    //stehen bleiben:
    case 5: moveSucess = level->getCharacters()[0]->getPointerOnTile()
                ->moveTo(level->getTileVector()[row+0][collumn+0], level->getCharacters()[0]); break;
    //rechts:
    case 6: moveSucess = level->getCharacters()[0]->getPointerOnTile()
                ->moveTo(level->getTileVector()[row][collumn+1], level->getCharacters()[0]); break;
    //oben links:
    case 7: moveSucess = level->getCharacters()[0]->getPointerOnTile()
                ->moveTo(level->getTileVector()[row-1][collumn-1], level->getCharacters()[0]); break;
    //oben:
    case 8: moveSucess = level->getCharacters()[0]->getPointerOnTile()
                ->moveTo(level->getTileVector()[row-1][collumn], level->getCharacters()[0]); break;
    //oben rechts
    case 9: moveSucess = level->getCharacters()[0]->getPointerOnTile()
                ->moveTo(level->getTileVector()[row-1][collumn+1], level->getCharacters()[0]); break;
    default: moveSucess = false; break;
    }
    if(!moveSucess){
        cout << "Bewegung war nicht erfolgreich\n";
    }
}

void DungeonCrawler::playGame()
{
    int direction = -1;
    generateLevel();
    do{
        UI.draw(level);
        direction = UI.computeDirection();
        if(direction == 0){
            break;
        }
        moveCharacter(direction);
    }while (direction != 0);
    cout << "Tschüss \n";
}

void DungeonCrawler::generateLevel()
{
    //Level generieren anhand eines strings
    level = new Level("##########e" //# Wall
                      "#.......O#e" //. Floor
                      "#........#e" //1: spawnpoint von einem character
                      "#######.##e"
                      "#........#e"
                      "#O.......#e" //O Portal
                      "##########e");//e ende einer spalte
};
