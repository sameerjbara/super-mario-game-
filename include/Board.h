#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include"StaticObject.h"
#include <vector>
#include "Wall.h"
#include "Player.h"
#include"Monster.h"
#include"Mushroom.h"
#include "Turtle.h"
#include "Fish.h"
#include <SFML/Audio.hpp>
#include "Menu.h"



enum charTofigure
{
    CharPlayer = '@',
    CharMONSTER = '%',
    CharWALL = '#',
    CharBlock = '^',
    CharCoin = '&',
    CharPipe = '*',
    CharMysteryBlock = '!',
    CharMushroom = '+',
    CharFish = '=',


};
class Board
{
public:


    Board();
    void run();
   

private:
    bool loadmatrix();
    void loadlevel();
    void draw(sf::RenderWindow& window);
    void move(sf::Time d);
    void moveView();
    void collide();
    
    int m_row;
    int m_col;

    std::fstream m_file;
  
    std::vector<std::vector<char>>  m_matrix;
    std::vector<std::unique_ptr <StaticObject>> m_boardPtr;
    std::vector<std::unique_ptr <Monster>> m_monsters;
    std::vector<std::unique_ptr<sf::Text>> m_data1;
    std::unique_ptr <Player> m_player;


    sf::Text m_data;
    sf::Font m_font;
    sf::Music m_music;



    sf::RectangleShape background;
    sf::View m_boardView;
    sf::Time m_delta;
    sf::RenderWindow m_window;
    sf::Clock gameClock;

};
