#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "instances/dialogue/dialogue_tree.hpp"
#include "instances/sound/sound.hpp"

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
    sf::Text m_text;
    sf::Font font;

    Barulho barulho;

    sf::SoundBuffer m_buffer;
    sf::Sound m_sound;
    std::string m_string;
    sf::Clock m_timer;
    float m_offset;

    std::ifstream teste;

    bool pode = false;

public:
    TipoNo *root;
    dialogueTree arvore;

    std::size_t m_itr;
    std::size_t currItem = 0;

    Dialogue();
    Dialogue(std::string myfile);
    ~Dialogue();

    void create_tree(std::string myfile);

    void write();

    void setString(std::string s);

    void reset();

    void dialogue_draw(sf::RenderTarget *target);

    void setPode(bool boolean);

    bool getPode();

    void uptade_event_dialogue(sf::Event gato);

    void show_dialogue(bool please);
};

#endif