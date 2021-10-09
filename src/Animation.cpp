#include "Animation.h"

#include "Resources.h"

const auto AnimationTime = sf::seconds(0.2f);

Animation::Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite)
    : m_data(data), m_dir(dir), m_sprite(sprite)
{
    m_sprite.setTexture(Resources::instance().texture());
    m_sprite.setScale(1.5, 1.5);

    update();
}

void Animation::direction(Direction dir)
{
    if (m_dir == dir )
    {
        return;
    }

    m_dir = dir;
    update();
}

void Animation::update(sf::Time delta)
{
    m_elapsed += delta;
    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        ++m_index;
        m_index %= m_data.m_data.find(m_dir)->second.size();
        update();
    }
}

FloatRect Animation::getGlobalBound1() const
{
    return m_sprite.getGlobalBounds();
}

void Animation::update()
{
    if (m_dir != Direction::Up&& m_dir != Direction::Down)
    {
        m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
    }
}
