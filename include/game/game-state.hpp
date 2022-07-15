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
#include "sprite-set/background.hpp"
#include "audio/audio.hpp"
#include "game/game-state.hpp"


/**
 * @brief Define um estado de Game_states, que extende as funcionalidades de States
 * 
 */
class GameState : public State
{
private:
    enum directions
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    enum states_player
    {
        MOVING,
        INTERACTING,
        NOTHING
    };

    // Background
    Background *map_floor;
    Background *map_chairs;
    Background *map_tables;
    Background *map_obj;

    // Elementos de Game
    Player *player;

    // Blue
    Npc *npc_blue;
    Npc *npc_blue_clone;

    // Pink
    Npc *npc_pink;
    Npc *npc_pink_clone;
    // Cian
    Npc *npc_cyan;
    Npc *npc_cyan_clone;
    // Yellow
    Npc *npc_yellow;
    Npc *npc_yellow_clone;

    // Jitsi
    Npc *npc_jitsi_intro;
    Npc *npc_jitsi_complete;

    std::vector<Wall *> walls;
    std::ifstream walls_file;

    Timer *timer;

    Item *coffee;
    Item *chocolate;
    Item *penguin;
    Item *camera;

    void generate_walls(std::string walls_dir);

    // audio
    Audio *game_soundtrack;

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
     * @brief Inicia os npcs com suas configurações
     * 
     */
    void init_npcs();

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
