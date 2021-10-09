#pragma once
#include "Resources.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const int NUM_OF_BUTTONS = 3;

class Menu
{
public:
	//---------- c-tor / d-tor ---------------
	Menu();
	Menu(float height,
		float width);
	void buildMenu();

	~Menu();
	void startMenu();

	//---------handel menu ----------------
	void run();
	void events();
	//void highlight();


	//---------- get --------------------
	int getselecteditem() const { return m_selectedButton; }

	//------------ set ---------------
	void setsize(float width,
		float hefight);

	//---------- draw ----------------
	void drawButoons();
	void draw();
	void creatwindow();
	void moveup();
	void movedown();
	bool closed = false;


private:
	float m_width;         //window size
	float m_hegiht;		  //window size

	int m_selectedButton;     //check wich button pressed
	sf::RectangleShape m_background;
	sf::RectangleShape m_background1;

	sf::Text m_Menu[NUM_OF_BUTTONS];     //vector of buttons
	sf::RenderWindow m_MenuWindow;
	sf::RenderWindow m_MenuWindow1;
	sf::Music m_music;



};