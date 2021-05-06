#include "Player.hpp"
#include "SFML/Graphics.hpp"
#include "playerConf.h"

void Player::init()
{
    player.setPointCount(10);
    // define player points
    player.setPoint(0 , sf::Vector2f(0 , 30));
    player.setPoint(1 , sf::Vector2f(25 , 20));
    player.setPoint(2 , sf::Vector2f(50 , 30));
    player.setPoint(3 , sf::Vector2f(40 , 15));
    player.setPoint(4 , sf::Vector2f(45 , 0));
    player.setPoint(5 , sf::Vector2f(30 , 10));
    player.setPoint(6 , sf::Vector2f(25 , 0));
    player.setPoint(7 , sf::Vector2f(20 , 10));
    player.setPoint(8 , sf::Vector2f(5 , 0));
    player.setPoint(9 , sf::Vector2f(10 , 15));

    //set player color
    if(pColor == "blue"){
        player.setFillColor(sf::Color::Blue);}
    else if(pColor == "green"){
        player.setFillColor(sf::Color::Green);}
    else if(pColor == "yellow"){
        player.setFillColor(sf::Color::Yellow);}
    else if (pColor == "white"){
        player.setFillColor(sf::Color::White);}
    else {player.setFillColor(sf::Color::White);}

    player.setPosition(sf::Vector2f(pPoseX - pSizeX, pPoseY - pSizeY));
}
void Player::moveDir(float dt , std::string direction)
{
    update();
    if (!isCollision)
    {
        if(direction == "left")
            player.move(-speed  * dt * MULTIPLIER , 0);
        if(direction == "right")
            player.move(speed  * dt * MULTIPLIER , 0);
    }
    isCollision = false;
}

void Player::update()
{   
    // check the collision of player and screen
    if(player.getPosition().x > pPoseX * 2 - pSizeX) // right collision
    {
        isCollision = true;
        player.setPosition(pPoseX * 2 - pSizeX , pPoseY - pSizeY);
    }

    if(player.getPosition().x < 0) //left collision
    {
        isCollision = true;
        player.setPosition(0, pPoseY - pSizeY);
    }
}