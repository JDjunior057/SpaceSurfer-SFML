#pragma once
#include "SFML/Graphics.hpp"
#include "../Enemy.hpp"

class DangerousEnemy : public Enemy{
public:
    DangerousEnemy(float x , float y) : Enemy(x , y) {};
    ~DangerousEnemy() {};

    void init();
    std::string getType() 
    {
       return "dangerous";
    };
};