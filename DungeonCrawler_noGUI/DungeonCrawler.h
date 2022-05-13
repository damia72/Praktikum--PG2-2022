#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H


#include <TerminalUI.h>
#include<windows.h>


class DungeonCrawler
{
public:
    AbstractUI* abstractUI;
    TerminalUI* terminalUI;
    Level* currentLevel;
    DungeonCrawler();
    void play();
};

#endif // DUNGEONCRAWLER_H
