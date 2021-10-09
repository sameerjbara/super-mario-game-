#pragma once

#include "Direction.h"
#include "AnimationData.h"
#include "Object.h"
#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite);
    void direction(Direction dir);
    void update(sf::Time delta);

    FloatRect getGlobalBound1()const;

private:
    void update();
    const AnimationData& m_data;
    sf::Time m_elapsed = {};
    Direction m_dir = Direction::Up;
    int m_index = 0;
    sf::Sprite& m_sprite;
};
