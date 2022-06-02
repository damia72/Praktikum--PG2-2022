#include "terminalui.h"
#include <iostream>
using namespace std;
TerminalUI::TerminalUI()
{

}
int TerminalUI::computeDirection()
{
    //Bewegungrichtung wird ermittelt:
    int direction = -1;
    while(!(direction >= 0 && direction < 10 && direction != 5)){
    cout << "Geben sie die Bewegungsrichtung (1-4, 6-9) ein oder 0 zum Beenden: \n";
    cin >> direction;
    //Falls der Input falsch ist:
    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore();
    }
    if(direction < 0 || direction > 9 || direction == 5){
        cout << "Falsche eingabe \n";
    }
    }

    return direction;
}

void TerminalUI::draw(Level* level)
{
    std::cout << std::endl;
    for(unsigned int i = 0; i<level->getLevelHeight(); i++){
        for (unsigned int j = 0; j<level->getLevelWidth();j++){
                std::cout << level->getTileVector()[i][j]->getTexture();
        }
        std::cout << std::endl;
    }
}
