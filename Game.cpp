#include "Game.hpp"
#include "config.h"
#include "Bullet.hpp"
#include "vector"
#include "cstdlib"
#include "ctime"
#include "Enemy.hpp"
#include "iostream"
#include "Enemy/Friendly.hpp"
#include "Enemy/Dangerous.hpp"

#include <SFML/Graphics.hpp>

void Game::inputs()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            isRunning = false;
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            {isMovingLeft = true;}
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            {isMovingRight = true;}
        // else {
        //     isMovingLeft = false;
        //     isMovingRight = false;
        // }
        else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
            {isMovingLeft = false;}
        else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
            {isMovingRight = false;}

        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            shoot();
    }
}
void Game::init()
{
    //initialize the window
    window.create(sf::VideoMode(WIN_W,WIN_H) , appName , sf::Style::Default);
    window.setFramerateLimit(FPS_LIMIT);

    //initialize the player
    player.init();

    //initialize texts
    scoHealFont.loadFromFile("Resources/Fonts/tarrget.otf");

    scoreText.setFont(scoHealFont);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setCharacterSize(25);
    scoreText.setString("Score :");

    healthText.setFont(scoHealFont);
    healthText.setFillColor(sf::Color::White);
    healthText.setCharacterSize(25);
    healthText.setString("Health :");

    healthText.setPosition(2 , 610);
    scoreText.setPosition(2 , 670);

    healthbar.setSize(sf::Vector2f(20 * health , 30));
    healthbar.setPosition(2 , 640);
    healthbar.setFillColor(sf::Color::Green);

}
void Game::run()
{
    sf::Time dt;

    inputs();
    dt = clock.restart();
    update(dt.asSeconds());
    render();
}
void Game::update(float dt)
{
    //handle player movements
    if(isMovingLeft)
        player.moveDir(dt , "left");
    if(isMovingRight)
        player.moveDir(dt , "right");
    
    totalTime += dt;
    if(totalTime >= SPAWN_TIME)
        spawnEnemy();
   
    // update the enemies
    for(int i = 0 ; i < enemies.size() ; i++)
    {
        Enemy* enemy = enemies[i];
        // std::cout << i << std::endl;
        enemy -> update(dt);

        if (enemy -> getYpos() > 600.f)
        {
            if(enemy -> getType() == "friendly")
                health -= 1;
        
            enemies.erase (enemies.begin() + i);
            delete(enemy);
        }
        // check bullet collision with objects ------------------------------------------
        for(int j = 0 ; j < bullets.size() ; j++)
        {
            Bullet* bullet = bullets[j];
            if(enemy->getSprite().getGlobalBounds().intersects(bullet->getSprite().getGlobalBounds()))
            {
                if (enemy->getType() == "friendly")
                {
                    // score
                    score++;
                    enemies.erase (enemies.begin() + i);
                    delete(enemy);
                    bullets.erase (bullets.begin() + j);
                    delete(bullet);
                }
                else
                {
                    //reduce health
                    health--;
                    // std::cout << "Ouch" << std::endl;
                    enemies.erase (enemies.begin() + i);
                    delete(enemy);
                    bullets.erase (bullets.begin() + j);
                    delete(bullet);
                }
                
            }
            if(enemy->getSprite().getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
            {
                if (enemy->getType() == "dangerous")
                {
                    // score
                    score += 2;
                    enemies.erase (enemies.begin() + i);
                    delete(enemy);
                }
                else
                {
                    //reduce health
                    health -= 2;
                    // std::cout << "Ouch" << std::endl;
                    enemies.erase (enemies.begin() + i);
                    delete(enemy);
                }
                
            }
             // collision ends -----------------------------------------------------
        }
        // std::cout << score << std::endl << health << std::endl << "---------------------------------------\n";
    }
    
    // update the bullets
    for(int i = 0 ; i < bullets.size() ; i++)
    {
        Bullet* bullet = bullets[i];
        // std::cout << i << std::endl;
        bullet -> update(dt);

        if (bullet -> getYpos() < -5.f)
        {
            bullets.erase (bullets.begin() + i);
            delete(bullet);
        }
    }
    healthText.setString("Health : " + std::to_string(health));
    scoreText.setString("Score : " + std::to_string(score));
    healthbar.setSize(sf::Vector2f(12 * health , 30));

    //change color of healthbar for each health possiblity
    if(health > 12)
    {
        healthbar.setFillColor(sf::Color::Green);
    }
    else if(health > 5)
    {
        healthbar.setFillColor(sf::Color::Yellow);
    }
    else
    {
        healthbar.setFillColor(sf::Color::Red);
    }
}
void Game::render()
{
    window.clear(sf::Color::Black);

    for (Bullet* bullet: bullets)
    {
        window.draw(bullet -> getSprite());
    }

    for (Enemy* enemy: enemies)
    {
        window.draw(enemy -> getSprite());
    }

    window.draw(player.getSprite());
    window.draw(scoreText);
    window.draw(healthText);
    window.draw(healthbar);
    window.display();
}
void Game::shoot()
{
    Bullet* bullet = new Bullet();
    bullet -> init(player.getPlayerCenter());
    bullets.push_back(bullet);      
}
void Game::spawnEnemy()
{
    Enemy *enemy;
    srand((unsigned) time(0));
    unsigned int randLoc = (rand() % 2); // 0 for friendly 1 for dangerous
    if(randLoc == 0)
    {
        FriendlyEnemy *en = new FriendlyEnemy((rand() % 16) * 50 , -50.f) ; // = new FriendlyEnemy();
        enemy = en;
        enemy -> init();
        enemies.push_back(enemy);
    }
    if(randLoc == 1)
    {
        DangerousEnemy *en = new DangerousEnemy((rand() % 16) * 50 , -50.f) ; //= new DangerousEnemy();
        enemy = en;
        enemy -> init();
        enemies.push_back(enemy);
    }  
    totalTime = 0;      
}