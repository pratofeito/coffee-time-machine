/**
 * @file intro.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef INTRO_HPP
#define INTRO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "instances/audio/audio.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <vector>

/**
 * @brief 
 * 
 */

namespace sf
{
    class RenderTarget;
}

/**
 * @brief 
 * 
 */

class Intro
{
protected:
    sf::RectangleShape box;
    sf::RectangleShape box1;
    sf::RectangleShape caixa;

    sf::Text text;
    sf::Font font;

    Audio audio_sound;
    Audio audio_music;

    // falta setar uma musiquinha
    std::string phrase;
    sf::Clock timer;

    std::ifstream text_file;
    std::vector<std::string> description;
    std::vector<sf::RectangleShape> image;

    bool show = false;
    bool next_state = false;
    std::size_t curr = 0;

public:
    std::size_t itr;

    /**
     * @brief Construct a new Intro object
     * 
     */
    Intro();

    /**
     * @brief Construct a new Intro object
     * 
     * @param myfile 
     */
    Intro(std::string myfile);
    
    /**
     * @brief Destroy the Intro object
     * 
     */
    ~Intro();

    /**
     * @brief 
     * 
     */
    void write();

    /**
     * @brief 
     * 
     */
    void imagine();


    /**
     * @brief Set the string object
     * 
     * @param s 
     */
    void set_string(std::string s);
    
    /**
     * @brief Set the image object
     * 
     * @param r 
     */
    void set_image(sf::RectangleShape r);

    /**
     * @brief 
     * 
     */
    void image_sequence();
    
    /**
     * @brief 
     * 
     * @param myfile 
     */
    void text_sequence(std::string myfile);

    
    /**
     * @brief 
     * 
     */
    void reset();
    
    /**
     * @brief 
     * 
     * @param target 
     */
    void intro_draw(sf::RenderTarget *target);
    
    /**
     * @brief 
     * 
     * @param event 
     */
    void uptade_event_intro(sf::Event event);

    /**
     * @brief Get the next state object
     * 
     * @return true 
     * @return false 
     */
    bool get_next_state();
};

#endif