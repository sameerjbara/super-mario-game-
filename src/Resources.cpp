#include "Resources.h"

#include "Direction.h"

#include <stdexcept>

namespace
{
AnimationData monsterData()
{
    const auto size = sf::Vector2i(40, 40);
  //  const auto initSpace = sf::Vector2i(70, 2);
    const auto initSpace = sf::Vector2i(1, 2);

    const auto middleSpace = sf::Vector2i(0, 10);

    auto monster = AnimationData {};
    auto currentStart = initSpace;

    auto nextStart = [&]()
    {
        currentStart += middleSpace;
        currentStart.y += size.y;
        return currentStart;
    };

    monster.m_data[Direction::Right].emplace_back(currentStart, size);
    monster.m_data[Direction::Right].emplace_back(nextStart(), size);
    monster.m_data[Direction::Right].emplace_back(nextStart(), size);
    monster.m_data[Direction::Dead].emplace_back(nextStart(), size);
    monster.m_data[Direction::Dead].emplace_back(nextStart(), size);
    monster.m_data[Direction::Dead].emplace_back(nextStart(), size);
    monster.m_data[Direction::Left].emplace_back(nextStart(), size);
    monster.m_data[Direction::Left].emplace_back(nextStart(), size);
    monster.m_data[Direction::Left].emplace_back(nextStart(), size);
    /*
    monster.m_data[Direction::Up].emplace_back(nextStart(), size);
    monster.m_data[Direction::Up].emplace_back(nextStart(), size);
    monster.m_data[Direction::Up].emplace_back(nextStart(), size);
    monster.m_data[Direction::Stay].emplace_back(nextStart(), size);
    monster.m_data[Direction::Stay].emplace_back(nextStart(), size);
    monster.m_data[Direction::Stay].emplace_back(nextStart(), size);
    */

    return monster;
}
AnimationData mushroomData()
{
    const auto size = sf::Vector2i(40, 40);
    //  const auto initSpace = sf::Vector2i(70, 2);
    const auto initSpace = sf::Vector2i(70, 2);

    const auto middleSpace = sf::Vector2i(0, 10);

    auto mushroom = AnimationData{};
    auto currentStart = initSpace;

    auto nextStart = [&]()
    {
        currentStart += middleSpace;
        currentStart.y += size.y;
        return currentStart;
    };

    mushroom.m_data[Direction::Right].emplace_back(currentStart, size);
    mushroom.m_data[Direction::Right].emplace_back(nextStart(), size);
    mushroom.m_data[Direction::Right].emplace_back(nextStart(), size);
    mushroom.m_data[Direction::Dead].emplace_back(nextStart(), size);
    mushroom.m_data[Direction::Dead].emplace_back(nextStart(), size);
    mushroom.m_data[Direction::Dead].emplace_back(nextStart(), size);
    mushroom.m_data[Direction::Left].emplace_back(nextStart(), size);
    mushroom.m_data[Direction::Left].emplace_back(nextStart(), size);
    mushroom.m_data[Direction::Left].emplace_back(nextStart(), size);
   


    return mushroom;
}
AnimationData fishData()
{
    const auto size = sf::Vector2i(40, 40);
    //  const auto initSpace = sf::Vector2i(70, 2);
    const auto initSpace = sf::Vector2i(140, 2);

    const auto middleSpace = sf::Vector2i(0, 10);

    auto fish = AnimationData{};
    auto currentStart = initSpace;

    auto nextStart = [&]()
    {
        currentStart += middleSpace;
        currentStart.y += size.y;
        return currentStart;
    };

    fish.m_data[Direction::Right].emplace_back(currentStart, size);
    fish.m_data[Direction::Right].emplace_back(nextStart(), size);
    fish.m_data[Direction::Right].emplace_back(nextStart(), size);
    fish.m_data[Direction::Dead].emplace_back(nextStart(), size);
    fish.m_data[Direction::Dead].emplace_back(nextStart(), size);
    fish.m_data[Direction::Dead].emplace_back(nextStart(), size);
    fish.m_data[Direction::Left].emplace_back(nextStart(), size);
    fish.m_data[Direction::Left].emplace_back(nextStart(), size);
    fish.m_data[Direction::Left].emplace_back(nextStart(), size);
    fish.m_data[Direction::Up].emplace_back(nextStart(), size);
    fish.m_data[Direction::Up].emplace_back(nextStart(), size);
    fish.m_data[Direction::Up].emplace_back(nextStart(), size);
    fish.m_data[Direction::Stay].emplace_back(nextStart(), size);
    fish.m_data[Direction::Stay].emplace_back(nextStart(), size);
    fish.m_data[Direction::Stay].emplace_back(nextStart(), size);


    return fish;
}
AnimationData playerData()
{
    const auto size = sf::Vector2i(40, 40);
    const auto initSpace = sf::Vector2i(900, 2);
    const auto middleSpace = sf::Vector2i(0, 10);

    auto player = AnimationData {};
    auto currentStart = initSpace;

    auto nextStart = [&]()
    {
        currentStart += middleSpace;
        currentStart.y += size.y;
        return currentStart;
    };

    player.m_data[Direction::Right].emplace_back(currentStart, size);
    player.m_data[Direction::Right].emplace_back(nextStart(), size);
    player.m_data[Direction::Right].emplace_back(nextStart(), size);
    player.m_data[Direction::Down].emplace_back(nextStart(), size);
    player.m_data[Direction::Down].emplace_back(nextStart(), size);
    player.m_data[Direction::Down].emplace_back(nextStart(), size);
    player.m_data[Direction::Left].emplace_back(nextStart(), size);
    player.m_data[Direction::Left].emplace_back(nextStart(), size);
    player.m_data[Direction::Left].emplace_back(nextStart(), size);
    player.m_data[Direction::Up].emplace_back(nextStart(), size);
    player.m_data[Direction::Up].emplace_back(nextStart(), size);
    player.m_data[Direction::Up].emplace_back(nextStart(), size);

    return player;
}
}

Resources& Resources::instance()
{
    static Resources instance;
    return instance;
}

Resources::Resources()
    : m_data(Max)
{
    loadresources();

    if (!m_texture.loadFromFile("Pacman.png"))
    {
        throw std::runtime_error("Can't load file");
    }

    m_data[Player] = playerData();
    m_data[Monster] = monsterData();
    m_data[Mushroom] = mushroomData();
    m_data[Fish] = fishData();
}



const sf::Font& Resources::getfont() const
{
    return m_font;
}
const sf::Texture& Resources::getWall() const
{
    return m_textures[0];
}
const sf::Texture& Resources::getBlock() const
{
    return m_textures[1];
}

const sf::Texture& Resources::getPipe() const
{
    return m_textures[2];
}

const sf::Texture& Resources::getCoin() const
{
    return m_textures[3];
}

const sf::Texture& Resources::getMysteryBlock() const
{
    return m_textures[4];
}
const sf::Texture& Resources::getShell() const
{
    return m_textures[5];
}

const sf::Texture& Resources::getBack() const
{
    return m_textures[6];
}
const sf::Texture& Resources::getMenuBack() const
{
    return m_textures[7];
}
const sf::Texture& Resources::getHelpMenu() const
{
    return m_textures[8];
}
const sf::SoundBuffer& Resources::getGameOverTune() const
{
    return m_soundefects[3];
}
const sf::SoundBuffer& Resources::getMarioDieTune() const
{
    return m_soundefects[2];
}
const sf::Texture& Resources::getMysteryBlockUpdated() const
{
    return m_textures[9];
}
const sf::SoundBuffer& Resources::getCoinTune() const
{
    return m_soundefects[4];
}
const sf::SoundBuffer& Resources::getKillTune() const
{
    return m_soundefects[0];
}

const sf::SoundBuffer& Resources::getJumpTune() const
{
    return m_soundefects[1];
}
const sf::SoundBuffer& Resources::getbreakTune() const
{
    return m_soundefects[5];
}
void Resources::loadresources()
{

    loadtextures();
    loadfont();
    loadSounds();


}
void Resources ::loadfont()
{


    if (!m_font.loadFromFile("font.TTF"))	// if font couldn't be loaded
    {
        perror("cant load font");
        exit(EXIT_FAILURE);
    }

}
void Resources::loadtextures()
{
    m_textures.resize(10);
    m_textures[0].loadFromFile("gr.png");
    m_textures[1].loadFromFile("Block.png");
    m_textures[2].loadFromFile("pipe.png");
    m_textures[3].loadFromFile("coin.png");
    m_textures[4].loadFromFile("MysteryBlock.png");
    m_textures[5].loadFromFile("shell.png");
    m_textures[6].loadFromFile("back.jpg");
    m_textures[7].loadFromFile("newmenu.png");
    m_textures[8].loadFromFile("helpmenu.png");
    m_textures[9].loadFromFile("MysteryBlockUpdated.png");










}
void Resources::loadSounds()
{

    int NUM_OF_SOUNDS = 6;

    m_soundefects.resize(NUM_OF_SOUNDS);


    m_soundefects[0].loadFromFile("smb_kick.wav");
    m_soundefects[1].loadFromFile("smb_jump-small.wav");
    m_soundefects[2].loadFromFile("smb_mariodie.wav");
    m_soundefects[3].loadFromFile("smb_gameover.wav");
    m_soundefects[4].loadFromFile("smb_coin.wav");
    m_soundefects[5].loadFromFile("smb_breakblock.wav");






}
