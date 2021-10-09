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
#include <optional>

#include <SFML/Graphics.hpp>

class Monster :public DynamicObject
{
public:
    Monster(sf::Vector2f v1, const AnimationData& data, Direction dir, sf::Sprite& sprite);
    virtual FloatRect getGlobalBound2() const;
	virtual void collision(Player& otherobj);
	virtual void collision(Wall& otherobj);
	virtual void collision(Object& otherobj);
	virtual void collision(Block& otherobj);
	virtual void collision(MysteryBlock& otherobj) {};
	virtual void collision(Coin& otherobj) {};
	virtual void collision(Pipe& otherobj) {};
	virtual void collision(Monster& otherobj) {};
	bool checkIfDeleted();
	void direction(sf::Keyboard::Key key);

	bool is_dead = false;


protected:
    Animation m_animation;
    sf::Clock m_aiTime;
	bool m_deleted = false;
	bool m_fall = false;


};
