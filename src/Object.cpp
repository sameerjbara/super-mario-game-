#include "Object.h"

Object::Object()
{
}
Object::~Object()
{
}

FloatRect Object::getGlobalBound() const
{
	return m_figure.getGlobalBounds();
}

sf::RectangleShape Object::getFigure()
{
	return m_figure;
}




