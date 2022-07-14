#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "dialogue/dialogue_tree.hpp"
#include "audio/audio.hpp"

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

    bool show_dialogue = false;

public:
    bool interacted;
    // comando de deixar ele parado é on_going
    bool on_going = false;
    bool given;
    bool first_interaction = true;

    Node *root;
    DialogueTree tree;

    std::size_t itr;

    Dialogue();
    Dialogue(std::string myfile);
    ~Dialogue();

    void create_tree(std::string myfile);
    void write();
    void set_string(std::string s);
    bool get_on_going();

    void reset();
    void dialogue_draw(sf::RenderTarget *target);
    void update_event_dialogue(bool z, bool x, bool given);
};

#endif