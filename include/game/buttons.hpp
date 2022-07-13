/**
 * @file buttons.hpp
 * @author Minipato
 * @brief Definições de classe Buttons
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#ifndef BUTTONS_H
#define BUTTONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

/**
 * @brief define estado dos botões
 * 
 */

enum button_states
{
    BTN_IDLE = 0,
    BTN_HAVER,
    BTN_PRESSED
};

/**
 * @brief define botões no menu-state
 * 
 */

class Button
{
private:
    short unsigned button_state;
    sf::RectangleShape shape;
    sf::Font *font;
    sf::Text text;

    sf::Color idle_color;
    sf::Color hover_color;
    sf::Color active_color;

public:
    /**
     * @brief Controi um novo objeto do tipo button
     * 
     * @param x Parametro para definir posição do objeto no eixo X
     * @param y Parametro para definir posição do objeito no eixo Y
     * @param width Parametro para definir a largura do objeto 
     * @param height Parametro para definir a altura do objeto
     * @param font Parametro de button para passar a fonte de text
     * @param text Parametro de button para passar as palavras de botões
     * @param idle_color Parametro que deixa objeto com cor
     * @param hover_color Parametro que deixa objeto com foco
     * @param active_color Parametro de button para ativar a cor
     */
    Button(float x, float y, float width, float height, sf::Font *font, std::string text, sf::Color idle_color, sf::Color hover_color, sf::Color active_color);
    
    /**
     * @brief Destroi o objeto button
     * 
     */
    ~Button();
    
    /**
     * @brief Desenha o objeto para destino de rederização 
     * 
     * @param target Ponteiro de um objeto do tipo RenderTarget para renderizar para onde ele vai apontar
     */
    void draw(sf::RenderTarget *target);
    
    /**
     * @brief Atualiza a posição do Mouse 
     * 
     * @param mouse_pos É um vetor de que define a posição do mouse 
     */
    void update(sf::Vector2f mouse_pos);

    /**
     * @brief Verifica se button é pressionado 
     *
     */
    const bool isPressed() const;
};

#endif