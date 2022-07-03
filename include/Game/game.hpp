#ifndef GAME_H
#define GAME_H

#include "game-state.hpp"
#include "Map/map.hpp"

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

    Map map;

    void initialize_window();
    void initialize_states();
    void initialize_sfml_events();

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