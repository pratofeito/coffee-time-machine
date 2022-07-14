#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "game/state.hpp"

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

    enum states
    {
        MOVING,
        INTERACTING,
        NOTHING
    };

    // Elementos de Game
    Player *player;
    Wall *wall;
    Npc *npc_leandro;
    Npc *npc_leandro2;

    Npc *npc_edinho;
    Npc *npc_edinho2;
    Timer *timer;

    Item *carrot;
    Item *carrot2;

public:
    GameState(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~GameState();

    void update(const float &delta_time) override;
    void update_inputs(const float &delta_time) override;
    void update_events(sf::Event event) override;

    void draw(sf::RenderTarget *target = nullptr) override;

    void end_state() override;
};

#endif