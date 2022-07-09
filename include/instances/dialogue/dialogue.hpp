#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "instances/dialogue/dialogue_tree.hpp"
#include "instances/audio/audio.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <fstream>

namespace sf
{
    class RenderTarget;
}

class Dialogue
{
protected:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;

    Audio audio_sound;

    std::string phrase;
    sf::Clock timer;

    std::ifstream text_file;

    bool show = false;

public:
    bool interact;

    Node *root;
    Dialogue_Tree tree;

    std::size_t itr;

    Dialogue();
    Dialogue(std::string myfile);
    ~Dialogue();

    void create_tree(std::string myfile);
    void write();
    void set_string(std::string s);
    void reset();
    void dialogue_draw(sf::RenderTarget *target);
    void set_show(bool boolean);
    bool get_show();
    void uptade_event_dialogue(sf::Event event, bool interagiu);
};

#endif