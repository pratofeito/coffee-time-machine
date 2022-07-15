/**
 * @file intro.hpp
 * @author brisabn
 * @brief Definições da classe intro
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

#include "audio/audio.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <vector>

/**
 * @brief Cria uma organização sematica para evitar conflitos de nome da class RenderTarget
 * 
 */

namespace sf
{
    class RenderTarget;
}

/**
 * @brief Cria uma classe do tipo Intro
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
     * @brief Constroi um  objeto do tipo Intro
     * 
     */
    Intro();

    /**
     * @brief Constroi um objeto do tipo Intro chamando parametros 
     * 
     * @param myfile Parametro do tipo string passado pelo construtor de Intro
     */
    Intro(std::string myfile);
    
    /**
     * @brief Destroi o objeto Intro
     * 
     */
    ~Intro();

    /**
     * @brief 
     * 
     */
    void write();

    /**
     * @brief Faz a atribuição entre a variavel box e a variavel caixa 
     * 
     */
    void imagine();


    /**
     * @brief Faz a atribuição entre a variavel phrase  e o parametro s
     * 
     * @param s Parametro passado pelo metodo set_string
     */
    void set_string(std::string s);
    
    /**
     * @brief Faz a atribuição entre a variavel caixa e o parametro r
     * 
     * @param r parametro do tipo RectangleShape passado pelo meotodo set_image
     */
    void set_image(sf::RectangleShape r);

    /**
     * @brief Cria um objeto do tipo RectangleShape e atribui suas informações 
     * 
     */
    void image_sequence();
    
    /**
     * @brief Cria um loop para objeto RectangleShape
     * 
     * @param myfile Parametro do tipo string passado pelo metodo text_sequence
     */
    void text_sequence(std::string myfile);

    
    /**
     * @brief Reinicia o tempo 
     * 
     */
    void reset();
    
    /**
     * @brief Desenha o objeto Intro para o destino de renderização
     * 
     * @param target 
     */
    void intro_draw(sf::RenderTarget *target);
    
    /**
     * @brief atualiza o evento do objeto intro
     * 
     * @param event variavel do tipo event passada pelo metodo update_event_intro
     */
    void uptade_event_intro(sf::Event event);

    /**
     * @brief Obtem o proximo estado do objeto
     * 
     * @return true 
     * @return false 
     */
    bool get_next_state();
};

#endif