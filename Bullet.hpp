#pragma once
#include "SFML/Graphics.hpp"

class Bullet
{
public:
    Bullet() {};
    ~Bullet() {};

    void init(float positionX);
    void update(float dt);
    bool isCollision = false;
    bool isOnTarget = false;

    float getYpos()
    {
        return m_posY;
    }

    sf::CircleShape getSprite()
    {
        return bullet;
    }

private:
    int m_posX;
    int m_posY = 680;

    sf::CircleShape bullet;

};