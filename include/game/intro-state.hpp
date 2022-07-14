/**
 * @file intro-state.hpp
 * @author brisabn
 * @brief Definições da classe Intro_state
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "game/state.hpp"

/**
 * @brief Define um estado de Intro_state, que extende as funcionalidades de States 
 * 
 */
class IntroState : public State
{
private:
    // Elementos de Game
    Wall *wall;
    Intro *intro;

public:

    /**
     * @brief Constrói um novo objeto do tipo Intro_state que herda alguns metodos de states
     * 
     * @param window Ponteiro de RenderWindow para o objeto a ser adicionado no caso de mudança de Estado
     * @param states 
     */
    IntroState(sf::RenderWindow *window, std::stack<State *> *states);
    
    /**
     * @brief Destrói o objeto do tipo Intro_state
     * 
     */
    virtual ~IntroState();

    /**
     * @brief Atualiza o objeto Intro_state
     * 
     * @param delta_time 
     */
    void update(const float &delta_time) override;
    
    /**
     * @brief  Atualiza os inputs do objeto Intro_state
     * 
     * @param delta_time 
     */
    void update_inputs(const float &delta_time) override;
    
    /**
     * @brief Atualiza os eventos do objeto intro_state
     * 
     * @param event 
     */
    void update_events(sf::Event event) override;

    /**
     * @brief Desenha o objeto para destino de renderização
     * 
     * @param target 
     */
    void draw(sf::RenderTarget *target = nullptr) override;

    /**
     * @brief Printa quando acaba o estado de intro
     * 
     */
    void end_state() override;
};

#endif