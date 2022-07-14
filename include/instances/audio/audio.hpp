/**
 * @file audio.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>

#include <iostream>
#include <fstream>

#include <ctime>
#include <cstdlib>
#include <stack>

/**
 * @brief 
 * 
 */
class Audio
{
    // usar singleton? como?
private:
    sf::Music music;

    sf::SoundBuffer buffer;
    sf::Sound sound;

    std::ifstream audio_file;

protected:
public:

    /**
     * @brief Construct a new Audio object
     * 
     */
    Audio();

    /**
     * @brief Destroy the Audio object
     * 
     */
    ~Audio();

    /**
     * @brief 
     * 
     * @param myfile 
     * @param volume 
     */
    void define_music(std::string myfile, float volume);
    
    /**
     * @brief 
     * 
     */
    void play_music();

    /**
     * @brief 
     * 
     * @param myfile 
     * @param volume 
     */
    void define_sound(std::string myfile, float volume);
    
    /**
     * @brief 
     * 
     */
    void play_sound();
};

#endif
