#include "Player.h"

#include "Resources.h"
#include <iostream>

#include <optional>
constexpr auto PlayerSpeed = 1.4f;

namespace
{
    std::optional<Direction> toDirection(sf::Keyboard::Key key)
    {
        switch (key)
        {
        case sf::Keyboard::Left:
            return Direction::Left;
        case sf::Keyboard::Right:
            return Direction::Right;
        case sf::Keyboard::Up:
            return Direction::Up;
        case sf::Keyboard::Down:
            return Direction::Down;
        case sf::Keyboard::Space:
            return Direction::Stay;
       
     
        default:
            return {};
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Player::Player(sf::Vector2f v1)
    : m_animation(Resources::instance().animationData(Resources::Player), Direction::Right, m_sprite)
{
    m_sprite.setPosition(v1);
    m_sprite.setScale(1.3, 1.3);
    m_lives = 3;
    m_coins = 0;
    startPos = v1;
    
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::update(sf::Time delta)
{
    if (m_dir == Direction::Stay)
    {
        m_sprite.move(this->getPosition());
    }
    if (m_dir == Direction::Down)
    {
      
        m_sprite.move(toVector(m_dir) * (.25f));
        
    }
    if (m_dir == Direction::Up)
    {
        m_sprite.move(toVector(m_dir) * (2.0f));
    }
    else
    {
        m_sprite.move(toVector(m_dir) * (PlayerSpeed));
    }

    m_animation.update(delta);
    int c = 0;
    if (m_dir == Direction::Up)
    {
        m_fall = true;
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::direction(sf::Keyboard::Key key)
{
    if (auto dir = toDirection(key))
    {
        m_dir = *dir;
        m_animation.direction(*dir);
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::move(sf::Time d)
{
    if (this->getPosition().y > 750)
    {
        m_sound.setBuffer(Resources::instance().getMarioDieTune());
        m_sound.play();
        this->setPosition(startPos);
        m_lives--;
    }
    else
    {
        prevPos = this->getPosition();
        if (m_jump)
        {
            if (m_jumpPos - this->getPosition().y >= 150)
            {
                m_jump = false;
            }
            else
            {
                update(d);
                direction(sf::Keyboard::Up);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                update(d);
                m_fall = true;
                direction(sf::Keyboard::Left);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                update(d);
                m_fall = true;
                direction(sf::Keyboard::Right);
            }

            
        }
        else if (m_fall)
        {
            
            update(d);
            direction(sf::Keyboard::Down);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                update(d);
                m_fall = true;
                direction(sf::Keyboard::Left);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                update(d);
                m_fall = true;
                direction(sf::Keyboard::Right);
            }
            
        }
       
        else
        {


            if (!m_jump)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    if (!m_jump)
                    {
                        m_jump = true;
                        m_sound.setBuffer(Resources::instance().getJumpTune());
                        m_sound.play();
                        m_jumpPos = this->getPosition().y;
                    }
                    update(d);
                    direction(sf::Keyboard::Up);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    update(d);
                    direction(sf::Keyboard::Down);

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    update(d);
                    m_fall = true;
                    direction(sf::Keyboard::Left);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    update(d);
                    m_fall = true;
                    direction(sf::Keyboard::Right);
                }
                else
                {
                    return;
                }
            }
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::fall(sf::Time d)
{
        m_sprite.move(toVector(m_dir) * .00041f);
        m_animation.update(d);
        m_dir = Direction::Down;
        m_animation.direction(Direction::Down);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::collision(Wall& otherobj)
{
    if (this->getPosition().y < otherobj.getPosition().y)
    {
        m_fall = false;
        this->setPosition(prevPos);

    }
    else
    {
        m_jump = false;
        m_fall = true;
        setPosition(prevPos);

    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::collision(Object& otherobj)
{
    otherobj.collision(*this);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::collision(Block& otherobj)
{
   //std::cout << this->getPosition().x << "  " << this->getPosition().y << "player"<<std::endl;
   // std::cout << otherobj.getPosition().x << "  " << otherobj.getPosition().y <<"block"<< std::endl;

    if (this->getPosition().y < otherobj.getPosition().y)
    {
       // if (this->getPosition().x - otherobj.getPosition().x < 40 || this->getPosition().x - otherobj.getPosition().x >-50)

     //  if( (otherobj.getPosition().x - this->getPosition().x < 49 ))//&& otherobj.getPosition().x - this->getPosition().x < 50 >0) || (this->getPosition().x - otherobj.getPosition().x < 50&& this->getPosition().x - otherobj.getPosition().x < 50>0))
         {
           m_fall = false;
            this->setPosition(prevPos);

         }
    }
    else
    {
        m_jump = false;
        m_fall = true;
        setPosition(prevPos);

    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::collision(MysteryBlock& otherobj)
{
    if (this->getPosition().y < otherobj.getPosition().y)
    {
        m_fall = false;
        this->setPosition(prevPos);

    }
    else
    {
        if (!otherobj.updated)
        {
            m_sound.setBuffer(Resources::instance().getbreakTune());
            m_sound.play();
            int r = rand() % 2;
            if (r == 0)
            {
                m_lives++;
            }
            else if (r == 1)
            {
                m_coins++;
            }
            
          //  otherobj.updated = true;
        }
        m_jump = false;
        m_fall = true;
        setPosition(prevPos);

    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::collision(Coin& otherobj)
{
    m_sound.setBuffer(Resources::instance().getCoinTune());
	m_sound.play();
    m_coins++;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Player::collision(Monster& otherobj)
{
    otherobj.collision(*this);

    if (this->getPosition().y < otherobj.getPosition().y)
    {
        m_sound.setBuffer(Resources::instance().getKillTune());
        m_sound.play();
        otherobj.is_dead = true;
        m_jump = true;
    }
    else
    {
        if (!otherobj.is_dead)
        {
            m_sound.setBuffer(Resources::instance().getMarioDieTune());
            m_sound.play();
            m_lives--;
            this->setPosition(startPos);
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
FloatRect Player::getGlobalBound2() const
{
    return m_animation.getGlobalBound1();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int Player::getLive()
{
    return m_lives;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int Player::getCoins()
{
    return m_coins;
}