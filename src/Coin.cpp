#include "Coin.h"

#include <iostream>

Coin::~Coin()
{

}

void Coin::collision(Player& otherobj)
{
	m_isEaten = true;
	otherobj.collision(*this);


}

char Coin::getType()
{
	return '#';
}



