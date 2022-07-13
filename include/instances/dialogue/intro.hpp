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

namespace sf
{
    class RenderTarget;
}

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

    Intro();
    Intro(std::string myfile);
    ~Intro();

    void write();
    void imagine();

    void set_string(std::string s);
    void set_image(sf::RectangleShape r);

    void image_sequence();
    void text_sequence(std::string myfile);

    void reset();
    void intro_draw(sf::RenderTarget *target);
    void uptade_event_intro(sf::Event event);

    bool get_next_state();
};

#endif