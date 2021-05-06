#include "Enemy/Dangerous.hpp"

void DangerousEnemy::init() 
{
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(xPos , yPos);
    enemy.setRadius(25);
}
