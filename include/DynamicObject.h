#pragma once
#include "Object.h"
#include "Direction.h"
#include"Animation.h"
#include "Resources.h"

class DynamicObject : public Object
{
public:
	DynamicObject();

	virtual void update(sf::Time delta)=0;
	virtual void draw(sf::RenderTarget& target) const;
	virtual sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f v);




protected:
	Vector2f prevPos;
	sf::Sprite m_sprite;
	Direction m_dir = Direction::Right;
};