/**
 * @file timer.hpp
 * @author brisabn
 * @brief Definição da classe Timer
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
#include <string>
#define TEMPO 119

#include <ctime>

/**
 * @brief Cria uma classe Timer 
 * 
 */
class Timer
{
private:
    sf::Clock m_clock;
    sf::Text m_text;
    sf::Font font;
    int tempo_total;

protected:
public:

    /**
     * @brief Contrói um objeto do tipo tempo
     * 
     * @param tempo tempo máximo
     */
    Timer(int tempo);
    ~Timer();

    /**
     * @brief Desenha o objeto Timer para o destino de renderização 
     * 
     * @param target 
     */
    void hud_draw(sf::RenderTarget *target);
    
    /**
     * @brief Atualiza o objeto Timer
     * 
     * @return int 
     */
    int timer_update();
};

#endif