#pragma once

#include "AnimationData.h"

#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

class Resources
{
public:
    enum Objects
    {
        Monster,
        Player,
        Mushroom,
        Fish,
        Max,

    };

    //new
    static Resources& instance();
    const sf::Texture& getWall() const;
    const sf::Texture& getBlock() const;
    const sf::Texture& getPipe() const;
    const sf::Texture& getCoin() const;
    const sf::Texture& getMysteryBlock() const;
    const sf::Texture& getShell() const;
    const sf::Texture& getMysteryBlockUpdated() const;

    
    const sf::Texture& getBack() const;
    void loadfont();
    const sf::Font& getfont() const;
    const sf::Texture& getMenuBack() const;
    const sf::Texture& getHelpMenu() const;



    const sf::SoundBuffer& getGameOverTune()const;
    const sf::SoundBuffer& getMarioDieTune()const;
    const sf::SoundBuffer& getCoinTune()const;
    const sf::SoundBuffer& getKillTune()const;
    const sf::SoundBuffer& getJumpTune()const;
    const sf::SoundBuffer& getbreakTune()const;


    void loadresources();
    void loadtextures();
    void loadSounds();

  //  const sf::Texture& getBackround() const;

    Resources(const Resources&) = delete;
    Resources& operator=(const Resources&) = delete;

    const sf::Texture& texture() const { return m_texture; }
    const AnimationData& animationData(Objects object) { return m_data[object]; }

private:
    Resources();



    std::vector<sf::Texture> m_textures;		               //game figures textures
    sf::Font m_font;

    sf::Texture m_texture;
    sf::Texture m_backgorund;
    std::vector<AnimationData> m_data;
    std::vector<sf::SoundBuffer> m_soundefects;

};
