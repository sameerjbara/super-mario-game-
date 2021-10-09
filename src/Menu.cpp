#include <iostream>
#include "Menu.h"

const int height = 800;
const int width = 1500;

Menu::Menu()
{

	m_selectedButton = 0;
	buildMenu();
	creatwindow();
	m_MenuWindow.setSize(sf::Vector2u(width, height));
	m_background.setSize(sf::Vector2f(width, height));
	m_background.setTexture(&Resources::instance().getMenuBack());

	m_music.openFromFile("menuSound.wav");
	m_music.setLoop(true);
	m_music.play();
	m_music.setVolume(5);

}



Menu::Menu(float width, float height)
	:m_width(width), m_hegiht(height)
{
	//Resources::instance().getfont()
		Resources::instance().loadresources();
	m_selectedButton = 0;
	creatwindow();
	buildMenu();
	m_background.setSize(sf::Vector2f(width, height));
	m_background.setTexture(&Resources::instance().getMenuBack());


}

Menu::~Menu()
{
}

void Menu::startMenu()
{
}

void Menu::drawButoons()
{
	for (size_t i = 0; i < NUM_OF_BUTTONS; i++)
	{
		m_MenuWindow.draw(m_Menu[i]);
	}
}

void Menu::creatwindow()
{
	m_MenuWindow.create(sf::VideoMode(width, height), "menu");
	
}

void Menu::draw()
{

	m_MenuWindow.clear();

	m_MenuWindow.draw(m_background);

	drawButoons();

	m_MenuWindow.display();
}

void Menu::setsize(float width, float hefight)
{
	m_width = width;
	m_hegiht = hefight;
}

void Menu::buildMenu()
{
	m_Menu[0].setFont(Resources::instance().getfont());
	m_Menu[0].setFillColor(sf::Color::White);
	m_Menu[0].setString("play Game");
	m_Menu[0].setPosition(sf::Vector2f(250, 310));
	m_Menu[0].setScale(sf::Vector2f(1.3,1.3));

	m_Menu[1].setFont(Resources::instance().getfont());
	m_Menu[1].setFillColor(sf::Color::White);
	m_Menu[1].setString("Help");
	m_Menu[1].setPosition(sf::Vector2f(250, 370 ));//width / 2 - 30
	m_Menu[1].setScale(sf::Vector2f(1.3, 1.3));

	m_Menu[2].setFont(Resources::instance().getfont());
	m_Menu[2].setFillColor(sf::Color::White);
	m_Menu[2].setString("Exit");
	m_Menu[2].setPosition(sf::Vector2f(250, 430));
	m_Menu[2].setScale(sf::Vector2f(1.3, 1.3));




}

void Menu::events()
{
	sf::Event menuevent;

	while (m_MenuWindow.pollEvent(menuevent))
	{

		switch (menuevent.type)
		{
		case sf::Event::Closed:
			m_MenuWindow.close();
			break;

		case sf::Event::KeyPressed:
			switch (menuevent.key.code)
			{
			case sf::Keyboard::Up:

				moveup();

				break;
			case sf::Keyboard::Down:
				movedown();
				break;


			case sf::Keyboard::Return:
				switch (getselecteditem())
				{

				case 0:
				{

					m_music.setLoop(false);
					m_music.pause();
					Board b;
					b.run();


				}
				case 1:
				{
					sf::Event helpevent;

					m_MenuWindow1.create(sf::VideoMode(width, height), "menussss");
					m_background1.setSize(sf::Vector2f(width, height));
					m_background1.setTexture(&Resources::instance().getHelpMenu());
					while (!closed)
					{
						
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
							{
								closed = true;
								m_MenuWindow1.close();
							}
							else
							{


								m_MenuWindow1.clear();
								m_MenuWindow1.draw(m_background1);
								m_MenuWindow1.display();
							}
					}
					closed = false;
					break;
				}
				case 2:
				{
					m_music.setLoop(false);
					m_music.pause();
					m_MenuWindow.close();
					EXIT_SUCCESS;
					break;

				}
				}
			}

		}

	}

}



/*
void Menu::moveup()
{
	if (m_selectedButton - 1 >= 0)
	{
		m_Menu[m_selectedButton].setColor(sf::Color::White);
		m_selectedButton--;
		m_Menu[m_selectedButton].setColor(sf::Color::Red);
	}
}
*/
void Menu::run()
{
	while (m_MenuWindow.isOpen())
	{
		events();
		draw();
	}



}
void Menu::moveup()
{
	if (m_selectedButton - 1 >= 0)
	{
		m_Menu[m_selectedButton].setColor(sf::Color::White);
		m_selectedButton--;
		m_Menu[m_selectedButton].setColor(sf::Color::Black);
	}
}

void Menu::movedown()
{
	if (m_selectedButton + 1 < NUM_OF_BUTTONS)
	{
		m_Menu[m_selectedButton].setColor(sf::Color::White);
		m_selectedButton++;
		m_Menu[m_selectedButton].setColor(sf::Color::Black);

	}
}