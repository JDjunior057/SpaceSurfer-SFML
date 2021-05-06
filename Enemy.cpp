#include "Enemy.hpp"
#include "enemyConf.h"

void Enemy::update(float dt)
{
    enemy.move(0 , eSpeed * dt * fps);
}

float Enemy::getYpos()
{
    return yPos;
}
