#ifndef ENDING_STATE_H
#define ENDING_STATE_H

#include "game/state.hpp"

class EndingState : public State
{
protected:
    // Elementos de Game
    Wall *wall;
    sf::Event sfml_event;

public:
    EndingState(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~EndingState();

    void update(const float &delta_time) override;
    void update_inputs(const float &delta_time) override;
    void update_events(sf::Event event) override;

    void draw(sf::RenderTarget *target = nullptr) override;

    void end_state() override;
};

#endif