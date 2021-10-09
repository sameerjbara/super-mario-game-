#include "MysteryBlock.h"

#include <iostream>

MysteryBlock::~MysteryBlock()
{
	//temp.release();
}

void MysteryBlock::collision(Player& otherobj)
{
	m_figure.setTexture(&Resources::instance().getMysteryBlockUpdated());
	otherobj.collision(*this);
	updated = true;

	//temp = std::make_unique<Coin>(sf::Vector2f(this->getPosition().x, this->getPosition().y + 50));
	
	
	//std::make_unique<Mushroom>(sf::Vector2f(j * 50, i * 50))
	/*
	rand 1/2
	
	if 1
	dont hide 1
	
	if 2
	same 

	
	
	
	
	
	
	
	*/

}



char MysteryBlock::getType()
{
	return '#';
}


