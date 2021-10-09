#pragma once

#include "StaticObject.h"
#include "Player.h"
#include "Wall.h"
#include "Monster.h"
#include "Pipe.h"
#include "MysteryBlock.h"
#include "Coin.h"
class Wall :public StaticObject
{
public:
	using StaticObject::StaticObject;

	virtual ~Wall();
	virtual void collision(Player& otherobj) ;
	virtual void collision(Wall& otherobj) {};
	virtual void collision(Object& otherobj) {};
	virtual void collision(Block& otherobj) {};
	virtual void collision(MysteryBlock& otherobj) {};
	virtual void collision(Coin& otherobj) {};
	virtual void collision(Pipe& otherobj) {};
	virtual void collision(Monster& otherobj);
	virtual char getType();



};