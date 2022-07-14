/**
 * @file state.hpp
 * @author heitoeu
 * @brief Definições da classe state
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STATE_H
#define STATE_H

#include "instances/player.hpp"
#include "instances/wall.hpp"
#include "instances/npc.hpp"
#include "instances/audio/audio.hpp"
#include "instances/dialogue/dialogue_tree.hpp"
#include "instances/dialogue/dialogue.hpp"
#include "instances/dialogue/intro.hpp"
#include "instances/item.hpp"
#include "hud/timer.hpp"

/**
 * @brief 
 * 
 */

// Classe Abstrata
class State
{
private:
protected:
    std::stack<State *> *states;
    sf::RenderWindow *window;
    std::vector<sf::Texture> textures;
    bool quit_state = false;

    sf::Vector2i mouse_position_screen;
    sf::Vector2i mouse_position_window;
    sf::Vector2f mouse_position_view;

public:
    /**
     * @brief Constroi um novo objeto do tipo State
     * 
     * @param window Ponteiro de RenderWindow para o objeto a ser adicionado no caso de mudança de estado
     * @param states 
     */
    State(sf::RenderWindow *window, std::stack<State *> *states);
    
    /**
     * @brief Destrói o objeto State
     * 
     */
    virtual ~State();

    /**
     * @brief Serão definidos pelos states especializados
     * 
     * @param delta_time 
     */
    virtual void update(const float &delta_time) = 0;
    
    /**
     * @brief Atualiza os inputs do objeto States
     * 
     * @param delta_time 
     */
    virtual void update_inputs(const float &delta_time) {}

    /**
     * @brief Atualiza os estados dos eventos 
     * 
     * @param event 
     */
    virtual void update_events(sf::Event event) {}

    /**
     * @brief Desenha o objeto para o destino de renderização
     * 
     * @param target 
     */
    virtual void draw(sf::RenderTarget *target = nullptr) = 0;

    /**
     * @brief Atualiza a posição do mouse 
     * 
     */
    virtual void updateMousePositions();

    /**
     * @brief Printa quando altera o estado de jogo
     * 
     */
    virtual void end_state() = 0;
    
    /**
     * @brief 
     * 
     */
    virtual void kb_check_for_quit();

    /**
     * @brief Verifica se saida do objeto e retorna falso ou verdadeiro 
     * 
     * @return true 
     * @return false 
     */
    bool get_quit_state();
};

#endif