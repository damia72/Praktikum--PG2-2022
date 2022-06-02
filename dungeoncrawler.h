#include <character.h>
#include <tile.h>
#include <terminalui.h>
#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H


class DungeonCrawler
{
public:
    DungeonCrawler();
    ~DungeonCrawler();
private:
    Tile* whereIsCharacter(Character* who);
    TerminalUI UI;
    void computeDestinationTile(int direction, Level* level);
    void moveCharacter(int direction);
    void playGame();
    void generateLevel();
    Level* level;
};

#endif // DUNGEONCRAWLER_H
