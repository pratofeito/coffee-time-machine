/**
 * @file ending-state.hpp
 * @author brisabn
 * @brief Definições da classe EndingState
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef ENDING_STATE_H
#define ENDING_STATE_H

#include "game/state.hpp"

/**
 * @brief Define um estado de Ending_states, que extende as funcionalidades de States
 * 
 */

class EndingState : public State
{
protected:
    // Elementos de Game
    Wall *wall;
    sf::Event sfml_event;

public:
    /**
     * @brief Constrói um novo objeto do tipo EndingState filha de State
     * 
     * @param window Ponteiro de RenderWindow para o objeto a ser adicionado no caso de mudança de Estado
     * @param states 
     */
    EndingState(sf::RenderWindow *window, std::stack<State *> *states);
    
    /**
     * @brief Destroi o objeto EndingState
     * 
     */
    virtual ~EndingState();


    /**
     * @brief
     * 
     * @param delta_time 
     */
    void update(const float &delta_time) override;
    
    /**
     * @brief Atualiza os estado dos inputs
     * 
     * @param delta_time 
     */
    void update_inputs(const float &delta_time) override;
    
    /**
     * @brief Atualiza os estados dos eventos 
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
     * @brief Printa quando altera o estado de jogo para EndingState
     * 
     */
    void end_state() override;
};

#endif