#pragma once
#include "string"
#include "SFML/Graphics.hpp"

class Player
{
public:
    Player() {};
    ~Player() {};

    // void setColor(std::string pC)
    // {
    //     pColor = pC;
    // }

    void init();
    sf::ConvexShape getSprite()
    {
        // std::cout << player.getPosition().x + 25 << std::endl;
        return player;
    }
    void moveDir(float dt , std::string direction);
    float getPlayerCenter()
    {   
        return player.getPosition().x + 25;
    }

private:
    sf::ConvexShape player;
    std::string pColor = "blue";

    bool isCollision = false;

    void update();
};