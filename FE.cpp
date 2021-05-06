#include "Enemy/Friendly.hpp"

void FriendlyEnemy::init() 
{
    enemy.setFillColor(sf::Color::Cyan);
    enemy.setPosition(xPos , yPos);
    enemy.setRadius(25);
}