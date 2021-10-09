#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Player;
class Block;
class Wall;
class Pipe;
class Coin;
class MysteryBlock;
class Monster;
class Turtle;
class Mushroom;
class Fish;


using sf::Texture;
using sf::Vector2f;
using sf::RectangleShape;
using sf::RenderWindow;
using sf::FloatRect;


class Object
{
public:

	Object();
	virtual ~Object();


	virtual void collision(Player& otherobj) = 0;
	virtual void collision(Wall& otherobj) = 0;
	virtual void collision(Object& otherobj) = 0;
	virtual void collision(Block& otherobj) = 0;
	virtual void collision(MysteryBlock& otherobj) = 0;
	virtual void collision(Coin& otherobj) = 0;
	virtual void collision(Pipe& otherobj) = 0;
	virtual void collision(Monster& otherobj) = 0;





	FloatRect getGlobalBound()const;
	sf::RectangleShape getFigure();


protected:
	sf::RectangleShape m_figure;


};