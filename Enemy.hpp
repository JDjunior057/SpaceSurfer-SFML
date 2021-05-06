#pragma once
#include "SFML/Graphics.hpp"
#include "string"

class Enemy
{
protected:
    float xPos;
    float yPos;

    sf::CircleShape enemy;
public:
    Enemy(float x = 0 , float y = 0) {
        xPos = x;
        yPos = y;
    };
    ~Enemy() {};
    virtual void init()
    {
        // polymorphism
    };
    void update(float dt);
    virtual std::string getType() 
    {
        // polymorphism
    };  
    sf::CircleShape getSprite()
    {
        return enemy;
    }
    float getYpos();
};