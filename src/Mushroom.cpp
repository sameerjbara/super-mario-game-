#include"Mushroom.h"

constexpr auto MonsterSpeed = 50.f;

Mushroom::Mushroom(sf::Vector2f v1)
    :Monster(v1, Resources::instance().animationData(Resources::Mushroom), Direction::Right, m_sprite)
{

}

void Mushroom::update(sf::Time delta)
{

    if (!is_dead)
    {
        prevPos = this->getPosition();
        if (m_fall)
        {
            m_sprite.move(toVector(Direction::Down) * delta.asSeconds() * (MonsterSpeed * 2));

        }
        else
        {


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
            m_fall = true;
        }
        
    }
    if (is_dead)
    {
        m_deleted = true;
        //m_dir = Direction::Dead;
        //m_animation.direction(m_dir);
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


}
