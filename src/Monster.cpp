#include "Monster.h"
#include "Player.h"
#include "Resources.h"

constexpr auto MonsterSpeed = 90.f;
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
Monster::Monster(sf::Vector2f v1, const AnimationData& data, Direction dir, sf::Sprite& sprite)
    :m_animation(data, dir, sprite)
{
    m_sprite.setPosition(v1);
}
FloatRect Monster::getGlobalBound2() const
{
    return m_animation.getGlobalBound1();
}
void Monster::collision(Player& otherobj)
{
    if (this->getPosition().y > otherobj.getPosition().y)
    {
        is_dead = true;
      
    }
}
void Monster::collision(Wall& otherobj)
{
    if (this->getPosition().y < otherobj.getPosition().y)
    {
        m_fall = false;
        this->setPosition(prevPos);

    }
    else
    {
        setPosition(prevPos);
    }

}
void Monster::collision(Object& otherobj)
{
    otherobj.collision(*this);

}

void Monster::collision(Block& otherobj)
{
    if (this->getPosition().y < otherobj.getPosition().y)
    {
        m_fall = false;
        this->setPosition(prevPos);

    }
    else
    {


        setPosition(prevPos);
    }

}

bool Monster::checkIfDeleted()
{
    return m_deleted;
}

void Monster::direction(sf::Keyboard::Key key)
{
    if (auto dir = toDirection(key))
    {
        m_dir = *dir;
        m_animation.direction(*dir);
    }
}


