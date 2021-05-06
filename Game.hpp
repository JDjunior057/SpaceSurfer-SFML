#pragma once
#include "SFML/Graphics.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Enemy/Friendly.hpp"
#include "Enemy/Dangerous.hpp"
#include "vector"

class Game
{
public:
    Game() {};
    ~Game() {};

    bool isRunning = true;
    void run();
    void init();

    std::vector<Bullet*> bullets;
    std::vector<Enemy*> enemies;

private:
    sf::RenderWindow window;
    sf::Clock clock;
    float totalTime = 0;

    int score = 0;
    int prevScore = 0;
    int health = 20;

    Player player;
    bool isMovingLeft = false;
    bool isMovingRight = false;

    //methods
    void inputs();
    void update(float dt);
    void render();

    void shoot();
    void spawnEnemy();
    bool spawnDangerous = true;

    //texts
    sf::Font scoHealFont; // font for score and health
    // sf::Font tutorialFont;
    // sf::Font gameFont;

    sf::Text scoreText;
    sf::Text healthText;
    sf::RectangleShape healthbar;
    
};