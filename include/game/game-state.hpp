/**
 * @file game-state.hpp
 * @author heitoeu
 * @brief define um estado de jogo
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "game/state.hpp"


/**
 * @brief Define um estado de Game_states, que extende as funcionalidades de States
 * 
 */
class GameState : public State
{
private:
    // Elementos de Game
    Player *player;
    Wall *wall;
    Npc *npc_leandro;
    Npc *npc_edinho;
    Npc *npc_edinho2;
    Timer *timer;

    Item *carrot;
    // Item *carrot2;

public:
    
    /**
     * @brief Constrói um objeto do tipo Game_state
     * 
     * @param window 
     * @param states 
     */
    GameState(sf::RenderWindow *window, std::stack<State *> *states);
    /**
     * @brief Destroi o objeto Game_state
     * 
     */
    virtual ~GameState();

    /**
     * @brief Atualiza o objeto Game_state
     * 
     * @param delta_time 
     */
    void update(const float &delta_time) override;
    
    /**
     * @brief Atualiza os inputs do objeto Game_state
     * 
     * @param delta_time 
     */
    void update_inputs(const float &delta_time) override;
    
    /**
     * @brief Atualiza os eventos do objeto Game_states
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
     * @brief Printa quando acaba o estado de Game_state
     * 
     */
    void end_state() override;
};

#endif