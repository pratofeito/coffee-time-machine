/**
 * @file game-state.hpp
 * @author your name (you@domain.com)
 * @brief 
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
     * @brief Construct a new Game State object
     * 
     * @param window 
     * @param states 
     */
    GameState(sf::RenderWindow *window, std::stack<State *> *states);
    /**
     * @brief Destroy the Game State object
     * 
     */
    virtual ~GameState();

    /**
     * @brief 
     * 
     * @param delta_time 
     */
    void update(const float &delta_time) override;
    
    /**
     * @brief 
     * 
     * @param delta_time 
     */
    void update_inputs(const float &delta_time) override;
    
    /**
     * @brief 
     * 
     * @param event 
     */
    void update_events(sf::Event event) override;

    /**
     * @brief 
     * 
     * @param target 
     */
    void draw(sf::RenderTarget *target = nullptr) override;

    /**
     * @brief 
     * 
     */
    void end_state() override;
};

#endif