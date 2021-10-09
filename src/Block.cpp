#include "Block.h"
#include "Player.h"
#include <iostream>

Block::~Block()
{

}

void Block::collision(Player& otherobj)
{
	otherobj.collision(*this);

}


void Block::collision(Monster& otherobj)
{
	otherobj.collision(*this);

}

char Block::getType()
{
	return '^';
}

