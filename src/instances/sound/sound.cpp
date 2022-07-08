#include "instances/sound/sound.hpp"

Barulho::Barulho()
{
}

Barulho::~Barulho()
{
}

void Barulho::define_music(std::string myfile)
{
    teste = std::ifstream(myfile);
    this->music.openFromFile(myfile);
    this->music.setVolume(50.f);
}

void Barulho::play_music()
{
    if (music.getStatus() == sf::Music::Stopped)
    {
        music.play();
    }
}

void Barulho::define_sound(std::string myfile)
{
    teste = std::ifstream(myfile);
    this->buffer.loadFromFile(myfile);
    this->sound.setBuffer(buffer);
    this->sound.setVolume(50.f);
}

void Barulho::play_sound()
{
    if (sound.getStatus() == sf::Sound::Stopped)
    {
        sound.play();
    }
}