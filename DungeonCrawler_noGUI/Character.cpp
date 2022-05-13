#include "Character.h"

Character::Character()
{

}

//void Character::setTile()
//{
//    currentTile = currentTile->onEnter();
//}
void Character::moveToTile(int row, int col)
{
    if(row <= numRows-1 && col <= numColumns-1)
    {
        currentTile->moveTo(level->getTile(row, col), this);
    }
    else std::cout << "invalid movement" << std::endl;
}
int Character::move()
{
    int movingKey{};
    int row = currentTile->getRow();
    int col = currentTile->getCol();

    std::cin >> movingKey;
//    while  (std::cin)
//    {

//    }
    switch(movingKey)
    {
    case 1:
        this->moveToTile(row+1, col-1);
        break;
    case 2:
        this->moveToTile(row+1, col);
        break;
    case 3:
        this->moveToTile(row+1, col+1);
        break;
    case 4:
        this->moveToTile(row, col-1);
        break;
    case 5:
        break;
    case 6:
        this->moveToTile(row, col+1);
        break;
    case 7:
        this->moveToTile(row-1, col-1);
        break;
    case 8:
        this->moveToTile(row-1, col);
        break;
    case 9:
        this->moveToTile(row-1, col+1);
        break;
    case 0:
        return 0;
        break;
    default:
        std::cout << "Invalid Input!!" << std::endl;
        move();
        break;
    }
    return movingKey;
}



