#include "enemy.h"


int Enemy::getLvl()
{
    return level;
}

string Enemy::getName()
{
    return name;
}


Enemy::Enemy(int elvl)
{
    level = elvl;
    name = "Evil Being of Evil";
}
