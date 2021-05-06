#pragma once
#include "SFML/Graphics.hpp"
#include "../Enemy.hpp"

class FriendlyEnemy : public Enemy
{
public:
    FriendlyEnemy(float x , float y) : Enemy(x,y){};
    ~FriendlyEnemy() {};

    void init();
    std::string getType() 
    {
       return "friendly";
    }; 
};