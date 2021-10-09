#include "StaticObject.h"

StaticObject::~StaticObject()
{

}

StaticObject::StaticObject(const Texture& texture, const Vector2f position, const float size)
{
	m_figure.setTexture(&texture);
	m_figure.setSize(sf::Vector2f(size, size));
	m_figure.setPosition(position);
	m_figure.setScale(0.8f, 0.8f);

}

void StaticObject::draw(RenderWindow& window)
{
	window.draw(m_figure);
}

sf::Vector2f StaticObject::getPosition() const
{
	
	return m_figure.getPosition();

}
void StaticObject::setPosition(sf::Vector2f v)
{
	m_figure.setPosition(v);
}