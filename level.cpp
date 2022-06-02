#include "level.h"
#include <vector>
using namespace std;
Level::Level(std::string levelInput)
{
    //höhe und breite des Levels bestimmen
    //breite mit anzahl der sachen die nicht e sind
    int width = 0;
    while(true){
        if(levelInput[width]!= 'e')
        {
            width = ++width;

        }else{
            levelWidth = width;
            break;
        }
    }

    int count = 0;
    int ecount = 0;
    while(true){
        if(levelInput[count]=='e'){
            ++ecount;
            ++count;
        }else {
            ++count;
        }if(levelInput[count] == '\0'){
            levelHeight = ecount;
            break;
        }
    }
    //TileVektor des Levels wird erstellt:
    int stringCount = 0;
    for (int i = 0; i < levelHeight; i++){
        TileVector.push_back(std::vector<Tile*>());
        for (int j = 0; j < levelWidth; j++){
            TileVector[i].push_back(nullptr);
            if(levelInput[stringCount]=='e'){
                j--;
                stringCount++;
                continue;
            }
            if(levelInput[stringCount]=='#'){
                TileVector[i][j] = new Wall(i,j);
            }
            if(levelInput[stringCount]=='.'){
                TileVector[i][j] = new Floor(i,j);
            }
            if(levelInput[stringCount]=='O'){
                static int portalcount = 0;
                static Portal* pointerToPortal = nullptr;
                static int rememberI = i;
                static int rememberJ = j;
                if(portalcount%2==0){
                    TileVector[i][j] = new Portal(i,j,nullptr);
                    pointerToPortal = dynamic_cast<Portal*>(TileVector[i][j]);
                    rememberI = i;
                    rememberJ = j;
                    portalcount++;
                }else{
                    TileVector[i][j] = new Portal(i,j,pointerToPortal);
                    dynamic_cast<Portal*>(TileVector[rememberI][rememberJ])
                            ->activatePortal(dynamic_cast<Portal*>(TileVector[i][j]));
                    portalcount++;
                }
            }
            stringCount = ++stringCount;
        }
    }
    //Character 0 wird gesetzt
    Characters.push_back(new Character(TileVector[1][1]));
    TileVector[1][1]->setPointerOnCharacter(Characters[0]);
}

Level::~Level()
{
    delete Characters[0];
    for(int i = 0; i < levelHeight; i++){
        for(int j = 0; j < levelWidth; j++){
            delete TileVector[i][j];
        }
    }
}

int Level::getLevelWidth() const
{
    return levelWidth;
}

int Level::getLevelHeight() const
{
    return levelHeight;
}

const std::vector<std::vector<Tile *> > &Level::getTileVector() const
{
    return TileVector;
}

const std::vector<Character *> &Level::getCharacters() const
{
    return Characters;
}
