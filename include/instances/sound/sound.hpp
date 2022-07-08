#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>

#include <iostream>
#include <fstream>

#include <ctime>
#include <cstdlib>
#include <stack>

class Barulho
{
    // usar singleton? como?
private:
    sf::Music music;

    sf::SoundBuffer buffer;
    sf::Sound sound;

    std::ifstream teste;

protected:
public:
    Barulho();
    // Sound(std::string myfile);
    ~Barulho();

    void define_music(std::string myfile);
    void play_music();

    void define_sound(std::string myfile);
    void play_sound();
};

#endif
