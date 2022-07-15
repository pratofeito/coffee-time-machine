/**
 * @file game.hpp
 * @author heitoeu
 * @brief Definições da classe Game
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GAME_H
#define GAME_H

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 544
#define WINDOW_SCALING 1.25
#define TILE_SIZE 32

#include "game-state.hpp"
#include "credits-state.hpp"
#include "menu-state.hpp"
#include "intro-state.hpp"
#include "ending-state.hpp"

/**
 * @brief Classe que constroi Game 
 * 
 */

class Game
{
private:
    sf::RenderWindow *window;
    sf::Event sfml_event;

    sf::Clock delta_time_clock;
    float delta_time;

    // Stack funciona exatamente igual a Stack estudada seguindo LIFO
    // Empilhar os estados de jogo para facilitar a mudança entre os estados
    std::stack<State *> states;

    std::map<std::string, int> supportedKeys;

    /**
     * @brief Inicializa a tela 
     * 
     */
    void initialize_window();
    
    /**
     * @brief Inicializa os estados 
     * 
     */
    void initialize_states();
    
    /**
     * @brief Inicializa os eventos
     * 
     */
    void initialize_sfml_events();
    
    /**
     * @brief 
     * 
     */
    void draw_guidelines();

public:
    /**
     * @brief Constrói o objeto Game 
     * 
     */
    Game();
    
    /**
     * @brief Destrói o objeto Game
     * 
     */
    virtual ~Game();

    /**
     * @brief 
     * 
     */
    void update_delta_time();
    
    /**
     * @brief Atualiza o evento do objeto Game
     * 
     */
    void update_sfml_events();
    
    /**
     * @brief Atualiza o estado do objeto Game
     * 
     */
    void update();

    /**
     * @brief Desenha na tela 
     * 
     */
    void draw();

    /**
     * @brief Inicia o loop principal
     * 
     */
    void run();
};

#endif