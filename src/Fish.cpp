#include"Fish.h"
constexpr auto MonsterSpeed = 50.f;

Fish::Fish(sf::Vector2f v1)
    :Monster(v1, Resources::instance().animationData(Resources::Fish), Direction::Right, m_sprite)
{

}

void Fish::update(sf::Time delta)
{
    if (!is_dead)
    {
        if (m_jump)
        {
            if (this->getPosition().y <= 250)
            {
                m_jump = false;
                m_fall = true;
            }
            else
            {
                m_sprite.move(toVector(Direction::Up) * delta.asSeconds() * MonsterSpeed);
                m_animation.update(delta);
                //  update(delta);
              //  m_sprite.move(toVector(Direction::Up) * delta.asSeconds() * (MonsterSpeed * 4));
                // direction(sf::Keyboard::Up);
            }
        }
        if (m_fall)
        {
            if (this->getPosition().y >= 750)
            {
                m_jump = true;
                m_fall = false;
            }
            else
            {


                m_sprite.move(toVector(Direction::Down) * delta.asSeconds() * (MonsterSpeed * 2));
            }

        }
    }
    else
    {
        
        m_dir = Direction::Dead;
        m_animation.direction(m_dir);
        if (this->getPosition().y <= 800)
        {
            m_sprite.move(toVector(Direction::Down) * delta.asSeconds() * (MonsterSpeed * 2));

        }
    }

    /*
    if (!is_dead)
    {
        prevPos = this->getPosition();
        if (m_aiTime.getElapsedTime().asSeconds() >= 3)
        {
            m_aiTime.restart();

            if (rand() % 2 == 0)
            {
                m_dir = static_cast<Direction>(Direction::Right);
            }
            else
            {
                m_dir = static_cast<Direction>(Direction::Left);

            }
            m_animation.direction(m_dir);
        }
        m_sprite.move(toVector(m_dir) * delta.asSeconds() * MonsterSpeed);
        m_animation.update(delta);
    }
    if (is_dead)
    {
        m_dir = Direction::Dead;
        m_animation.direction(m_dir);
        /*
        if (rand() % 2 == 0)
        {
            m_sprite.move(toVector(Direction::Right) * delta.asSeconds() * MonsterSpeed);
        }
        else
        {
            m_sprite.move(toVector(Direction::Left) * delta.asSeconds() * MonsterSpeed);
        }
        */



}
