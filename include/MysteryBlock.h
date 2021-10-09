#pragma once

#include "StaticObject.h"
#include "Player.h"
#include "Wall.h"
#include "Monster.h"
#include "Pipe.h"
#include "MysteryBlock.h"
#include "Coin.h"

class MysteryBlock :public StaticObject
{
public:
	using StaticObject::StaticObject;

	virtual ~MysteryBlock();

	virtual void collision(Player& otherobj);
	virtual void collision(Wall& otherobj) {};
	virtual void collision(Object& otherobj) {};
	virtual void collision(Block& otherobj) {};
	virtual void collision(MysteryBlock& otherobj) {};
	virtual void collision(Coin& otherobj) {};
	virtual void collision(Pipe& otherobj) {};
	virtual void collision(Monster& otherobj) {};

	bool updated = false;
	virtual char getType();

private:
	//std::unique_ptr <Mushroom> timp;
	//std::unique_ptr< Coin> temp;
	//auto temp1;
};