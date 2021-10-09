#include"DynamicObject.h"

DynamicObject::DynamicObject()

{
}


void DynamicObject::draw(sf::RenderTarget& target) const
{
	target.draw(m_sprite);

}

sf::Vector2f DynamicObject::getPosition() const
{
	return m_sprite.getPosition();

}
void DynamicObject::setPosition(sf::Vector2f v)
{
	m_sprite.setPosition(v);
}
