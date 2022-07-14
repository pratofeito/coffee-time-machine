/**
 * @file timer.hpp
 * @author your name (you@domain.com)
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

protected:
public:
    
    /**
     * @brief Contró um objeto do tipo Timer
     * 
     */
    Timer();
    
    /**
     * @brief Destroi o objeto Timer
     * 
     */
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