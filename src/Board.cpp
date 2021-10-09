#include "Board.h"
#include "Player.h"
#include "Monster.h"
#include "Turtle.h"
#include"Mushroom.h"
#include "Resources.h"
#include "DebugUtils.h"
#include"Board.h"



Board::Board() :
    m_player(), m_window(sf::RenderWindow(sf::VideoMode(1500, 800), "SFML Animation")), gameClock(sf::Clock()),
    m_data("Score:            Lives:           ", m_font, 40)
{

    m_music.openFromFile("raed.wav");
    m_music.setLoop(true);
    m_music.play();
    m_music.setVolume(5);

    m_file.open("Board.txt");
    background.setTexture(&Resources::instance().getBack());
    background.setSize(Vector2f(1500,800));
    
    background.setPosition(0, 0);

    m_font.loadFromFile("font.TTF");
    m_data.setFillColor(sf::Color::White);
    m_data.setPosition(10, 10);

   for (size_t i = 0; i < 2; i++) {
       m_data1.push_back(std::make_unique<sf::Text>());
       m_data1[i]->setFont(m_font);
       m_data1[i]->setCharacterSize(40);
       m_data1[i]->setFillColor(sf::Color::White);
       m_data1[i]->setPosition((float)(130 + i * 220), 10);
   }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Board::draw(sf::RenderWindow& window)
{
    m_window.draw(background);
    m_window.draw(m_data);
    m_window.draw(*m_data1[0]);
    m_window.draw(*m_data1[1]);
    for (int i = 0; i < m_boardPtr.size(); i++)
    {
        if (!m_boardPtr[i]->m_isEaten)
        {
            m_boardPtr[i]->draw(window);
        }
    }
    m_player->draw(window);
    for (int i = 0; i < m_monsters.size(); i++)
    {
        m_monsters[i]->draw(window);
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Board::move(sf::Time d)
{

    for (int i = 0; i < m_monsters.size(); i++)
    {
        m_monsters[i]->update(d);
    }
    m_player->move(d);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Board::moveView()
{
    int g1, g2;
    
    m_boardView = m_window.getView();
    if (m_player->getPosition().x - m_boardView.getCenter().x > 250)
    {
        g1 = m_boardView.getCenter().x;
        m_boardView.move({ 1, 0 });
        m_window.setView(m_boardView);
        g2 = m_boardView.getCenter().x;
        background.setPosition(background.getPosition().x + g2 - g1, background.getPosition().y);
        m_data.setPosition(m_data.getPosition().x +( g2 - g1), m_data.getPosition().y);
        for (size_t i = 0; i < 2; i++) {
        
            m_data1[i]->setPosition((float)(m_data1[i]->getPosition().x+g2-g1), m_data1[i]->getPosition().y);
        }
        

    }
    else if (m_player->getPosition().x - m_boardView.getCenter().x < 250 && m_boardView.getCenter().x >750)
    {
        g1 = m_boardView.getCenter().x;
        m_boardView.move({ -1, 0 });
        m_window.setView(m_boardView);
        g2 = m_boardView.getCenter().x;
        background.setPosition(background.getPosition().x + g2 - g1, background.getPosition().y);
        m_data.setPosition(m_data.getPosition().x + (g2 - g1), m_data.getPosition().y);
        for (size_t i = 0; i < 2; i++) {

            m_data1[i]->setPosition((float)(m_data1[i]->getPosition().x + g2 - g1), m_data1[i]->getPosition().y);
        }


    }
    else if (m_boardView.getCenter().y-m_player->getPosition().y > 100 )//up
    {
        g1 = m_boardView.getCenter().y;
        m_boardView.move({ 0, -1 });
        m_window.setView(m_boardView);
        g2 = m_boardView.getCenter().y;
        background.setPosition(background.getPosition().x, background.getPosition().y + g2 - g1);
        m_data.setPosition(m_data.getPosition().x,m_data.getPosition().y + (g2 - g1));
        for (size_t i = 0; i < 2; i++) {

            m_data1[i]->setPosition((float)(m_data1[i]->getPosition().x ), m_data1[i]->getPosition().y + g2 - g1);
        }


    }

    else if (m_boardView.getCenter().y - m_player->getPosition().y < 100 && m_boardView.getCenter().y <400)//down
    {
        g1 = m_boardView.getCenter().y;
        m_boardView.move({ 0, 1 });
        m_window.setView(m_boardView);
        g2 = m_boardView.getCenter().y;
        background.setPosition(background.getPosition().x, background.getPosition().y + g2 - g1);
        m_data.setPosition(m_data.getPosition().x, m_data.getPosition().y + (g2 - g1));
        for (size_t i = 0; i < 2; i++) {

            m_data1[i]->setPosition((float)(m_data1[i]->getPosition().x), m_data1[i]->getPosition().y + g2 - g1);
        }

    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Board::collide()
{
    
    for (int i = 0; i < m_boardPtr.size(); i++)
    {
        if (  (m_boardPtr[i]->getPosition().x - m_player->getPosition().x < 49) &&(m_boardPtr[i]->getPosition().x - m_player->getPosition().x >0) 
            || m_player->getPosition().x - m_boardPtr[i]->getPosition().x <40)
        {
            if (m_player->getGlobalBound2().intersects(m_boardPtr[i]->getGlobalBound()))//bl3ks
            {
                 {
                    m_player->collision(*m_boardPtr[i]);

                    if (m_boardPtr[i]->m_isEaten)
                    {
                        m_boardPtr.erase(m_boardPtr.begin() + i);
                    }
                 }
            }
        }
    }
    
    for (int i = 0; i < m_monsters.size(); i++)
    {
        for (int j = 0; j < m_boardPtr.size(); j++)
        {
            if (m_monsters[i]->getGlobalBound2().intersects(m_boardPtr[j]->getGlobalBound()))//bl3ks
            {
                m_monsters[i]->collision(*m_boardPtr[j]);
            }
        }
    }
    for (int i = 0; i < m_monsters.size(); i++)
    {
        if (m_player->getGlobalBound2().intersects(m_monsters[i]->getGlobalBound2()))
        {
            if (m_player)
                m_player->collision(*m_monsters[i]);

        }

    }
   
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Board::run()
{
    int g1 = 0;
    srand(static_cast<unsigned>(time(nullptr)));
    loadmatrix();
    loadlevel();
    while (m_window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }
        else
        {
            m_window.clear();
            m_data1[0]->setString(std::to_string(m_player->getCoins()));
            m_data1[1]->setString(std::to_string(m_player->getLive()));
            if (auto debugSpriteSheet = 0)
            {
                displayAll(m_window, Resources::instance().animationData(Resources::Player));
                draw(m_window);

            }
            else
            {
                draw(m_window);
            }
            m_delta = gameClock.restart();

            move(m_delta);
            moveView();
            collide();
            for (int i = 0; i < m_monsters.size(); i++)
            {
                if (m_monsters[i]->checkIfDeleted())
                {
                    m_monsters.erase(m_monsters.begin() + i);

                }
            }
            m_window.display();
         
            if (m_player->getLive() == 0||m_player->getPosition().x>=10500)
            {
                m_music.setLoop(false);
                m_music.pause();
                m_window.close();
                Menu m;
                m.run();
            }
            
        }
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Board::loadmatrix()
{

    if (m_file.eof())
        return false;

    m_file >> m_row >> m_col;
    m_col++;                                             //leave some space for toolbar

    m_matrix.resize(m_row);                              //allocate memory
    for (size_t i = 0; i < m_row; i++)
    {
        m_matrix[i].resize(m_col);
    }

    char c = m_file.get();

    while (!m_file.eof())
    {
        for (size_t i = 0; i < m_row; i++)
        {
            for (size_t j = 0; j < m_col; j++)
            {
                m_matrix[i][j] = m_file.get();
            }
        }
        m_file.get();
        break;
    }

    return true;

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Board::loadlevel()
{
    char c;

    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            c = charTofigure(m_matrix[i][j]);

            switch (c)
            {
            case CharPlayer:
                m_player = std::make_unique<Player>(sf::Vector2f(j * 50, i * 50));
                break;

            case CharWALL:
            {
                m_boardPtr.push_back(std::make_unique <Wall>(Resources::instance().getWall(), sf::Vector2f(j * 50, i * 50), 70));
                break;
            }
            case CharBlock:
            {
                m_boardPtr.push_back(std::make_unique <Block>(Resources::instance().getBlock(), sf::Vector2f(j * 50, i * 50), 65));
                break;
            }
            case CharPipe:
            {
                m_boardPtr.push_back(std::make_unique <Pipe>(Resources::instance().getPipe(), sf::Vector2f(j * 50, i * 50), 65));
                break;
            }
            case CharCoin:
            {
                m_boardPtr.push_back(std::make_unique <Coin>(Resources::instance().getCoin(), sf::Vector2f(j * 50, i * 50), 45));
                break;
            }
            case CharMysteryBlock:
            {
                m_boardPtr.push_back(std::make_unique <MysteryBlock>(Resources::instance().getMysteryBlock(), sf::Vector2f(j * 50, i * 50), 65));
                break;
            }

            case CharMONSTER:
                m_monsters.push_back(std::make_unique<Turtle>(sf::Vector2f(j * 50, i * 50)));
                break;


            case CharMushroom:
                m_monsters.push_back(std::make_unique<Mushroom>(sf::Vector2f(j * 50, i * 50)));

                break;

            case CharFish:
                m_monsters.push_back(std::make_unique<Fish>(sf::Vector2f(j * 50, i * 50)));

                break;
                
            case ' ':
                break;
            }

        }
    }
}
