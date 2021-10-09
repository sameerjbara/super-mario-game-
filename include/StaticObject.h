#pragma once
#include "Object.h"
#include<SFML/Graphics.hpp>

using sf::Texture;
using sf::Vector2f;


class StaticObject : public Object
{
public:
	using Object::Object;
	virtual ~StaticObject();
	StaticObject(const Texture& texture,const Vector2f position,const float size);
	virtual sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f v);
	void draw(RenderWindow& window);
	virtual char getType()=0;

	bool isExists = false;
	bool m_isEaten = false;
	bool hide = false;

};