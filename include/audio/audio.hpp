/**
 * @file audio.hpp
 * @author brisabn
 * @brief Definições da classe Audio
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
 * @brief cria uma classe Audio
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
     * @brief Constrói o objeto do tipo Audio
     * 
     */
    Audio();

    /**
     * @brief Destrói o objeto Audio
     * 
     */
    ~Audio();

    /**
     * @brief Define a musica do tipo Audio
     * 
     * @param myfile nome do ficheiro de audio
     * @param volume Parametro que pega o valor float para alterar intesidade da musica do objeto Audio
     */
    void define_music(std::string myfile, float volume);
    
    /**
     * @brief Toca a musica do objeto Audio
     * 
     */
    void play_music();

    /**
     * @brief Define a som do tipo Audio 
     * 
     * @param myfile 
     * @param volume Parametro que pega um valor float para alterar a intesidade do som do objeto Audio
     */
    void define_sound(std::string myfile, float volume);
    
    /**
     * @brief Toca o som do objeto Audio
     * 
     */
    void play_sound();
};

#endif
