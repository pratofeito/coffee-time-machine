#ifndef ENDING_STATE_H
#define ENDING_STATE_H

#include "Game/state.hpp"

class Ending_state : public State
{
protected:
    // Elementos de Game
    Wall *wall;
    sf::Event sfml_event;

public:
    Ending_state(sf::RenderWindow *window);
    virtual ~Ending_state();

    void update(const float &delta_time) override;
    void update_inputs(const float &delta_time) override;
    void update_events(sf::Event event) override;

    void draw(sf::RenderTarget *target = nullptr) override;

    void end_state() override;
};

#endif