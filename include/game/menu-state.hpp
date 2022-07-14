/**
 * @file menu-state.hpp
 * @author Minipato
 * @brief Definições da classe Menu_state
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game-state.hpp"
#include "buttons.hpp"
#include "game.hpp"

/**
 * @brief Define um estado de menu inicial, que extende as funcionalidades de States
 * 
 */

class Menu_state : public State
{
private:
    sf::Texture bg_texture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button *> buttons;

public:
    /**
     * @brief Constrói um novo objeto do tipo Menu_state que herda alguns metodos de states 
     * 
     * @param window Ponteiro de RenderWindow para o objeto a ser adiconado no caso de mudança de Estado
     * @param states 
     */
    Menu_state(sf::RenderWindow *window, std::stack<State *> *states);
    
    /**
     * @brief Destrói o objeto do tipo Menu_state
     * 
     */
    virtual ~Menu_state();

    /**
     * @brief 
     * 
     * @param delta_time 
     */
    void update_kb(const float &delta_time);

    /**
     * @brief 
     * 
     * @param delta_time 
     */
    void update(const float &delta_time) override;
    
    /**
     * @brief Desenha Menu_state para o destino de renderização
     * 
     * @param target 
     */
    void draw(sf::RenderTarget *target = nullptr) override;
    
    /**
     * @brief Atualiza o state de jogo de acordo com escolha do objeto button
     * 
     */
    void updateButtons();
    
    /**
     * @brief Desenha Button em Menu_state
     * 
     * @param target 
     */
    void drawButtons(sf::RenderTarget *target = nullptr);
    
    /**
     * @brief Printa quando termina o estado de menu 
     * 
     */
    void end_state() override;
};

#endif