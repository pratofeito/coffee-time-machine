#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "game/state.hpp"
class Game_state : public State
{
private:
    // Elementos de Game
    Player *player;
    Wall *wall;
    Npc *npc_leandro;
    Npc *npc_edinho;
    Timer *timer;

    Item *carrot;
    Item *carrot2;

public:
    Game_state(sf::RenderWindow *window);
    virtual ~Game_state();

    void update(const float &delta_time) override;
    void update_inputs(const float &delta_time) override;
    void update_events(sf::Event event) override;

    void draw(sf::RenderTarget *target = nullptr) override;

    void end_state() override;
};

#endif