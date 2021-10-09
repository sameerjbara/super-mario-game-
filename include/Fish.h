#pragma once

#include "Direction.h"
#include "Animation.h"
#pragma once

#include "Direction.h"
#include "Animation.h"
#include"DynamicObject.h"
#include "Player.h"
#include "Wall.h"
#include "Block.h"
#include "MysteryBlock.h"
#include "Coin.h"
#include "Pipe.h"
#include <iostream>
#include "Monster.h"

#include <SFML/Graphics.hpp>

class Fish : public Monster
{
public:
	Fish(sf::Vector2f v1);
	virtual void update(sf::Time delta);

	bool m_fall = false;
	bool m_jump = true;

private:

};
