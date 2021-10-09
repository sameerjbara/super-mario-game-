#pragma once

#include <SFML/Graphics.hpp>

enum class Direction
{
    Up,
    Down,
    Right,
    Left,
    Stay,
    Max,
    Dead,
};

Direction opposite(Direction dir);
sf::Vector2f toVector(Direction dir);
