#pragma once

#include "Direction.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include "DynamicObject.h"
#include "Block.h"
#include "Wall.h"
#include "Monster.h"
#include "Pipe.h"
#include "MysteryBlock.h"
#include "Coin.h"



class Player :public DynamicObject
{
public:

    Player(sf::Vector2f v1);
    virtual void update(sf::Time delta);
    void direction(sf::Keyboard::Key key);
    void move(sf::Time d);
    void fall(sf::Time d);


    virtual void collision(Player& otherobj) {};
    virtual void collision(Wall& otherobj) ;
    virtual void collision(Object& otherobj) ;
    virtual void collision(Block& otherobj) ;
    virtual void collision(MysteryBlock& otherobj);
    virtual void collision(Coin& otherobj) ;
    virtual void collision(Pipe& otherobj) {};
    virtual void collision(Monster& otherobj);
    FloatRect getGlobalBound2()const;

    int getLive();
    int getCoins();
   
    
    
private:
    Vector2f startPos;
    sf::Sound m_sound;
    bool m_fall = true;
    bool m_jump = false;
    Animation m_animation;
    int m_jumpPos = 0;
    int m_lives;
    int m_coins;
};

