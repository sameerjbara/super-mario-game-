#include "Wall.h"
#include "Player.h"
#include <iostream>

Wall::~Wall()
{

}
void Wall::collision(Player& otherobj)
{
	otherobj.collision(*this);

}
void Wall::collision(Monster& otherobj)
{
	otherobj.collision(*this);

}
char Wall::getType()
{
	return '#';
}

