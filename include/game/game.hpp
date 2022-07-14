#ifndef GAME_H
#define GAME_H

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 544
#define WINDOW_SCALING 1.25
#define TILE_SIZE 32

#include "game-state.hpp"
#include "menu-state.hpp"
#include "intro-state.hpp"
#include "ending-state.hpp"
#include "sprite-set/background.hpp"

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

    std::map<std::string, int>supportedKeys;

    void initialize_window();
    void initialize_states();
    void initialize_sfml_events();
    void draw_guidelines();

    Background *map_bg;

public:
    Game();
    virtual ~Game();

    void update_delta_time();
    void update_sfml_events();
    void update();

    void draw();

    void run();
};

#endif