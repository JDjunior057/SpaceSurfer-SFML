#include "Bullet.hpp"
#include "bulConf.h"
#include "iostream"

void Bullet::init(float positionX)
{
    m_posX = positionX;

    if(bColor == "white")
        {bullet.setFillColor(sf::Color::White);}
    else 
        {bullet.setFillColor(sf::Color::Yellow);}
    
    bullet.setRadius(2.5f);
}

void Bullet::update(float dt)
{
    m_posY -= bSpeed * dt * FPS;
    bullet.setPosition(m_posX , m_posY);
    // std::cout << m_posY << std::endl;
}