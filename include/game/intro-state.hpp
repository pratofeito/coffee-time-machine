#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "game/state.hpp"
class Intro_state : public State
{
private:
    // Elementos de Game
    Wall *wall;
    Intro *intro;

public:
    Intro_state(sf::RenderWindow *window);
    virtual ~Intro_state();

    void update(const float &delta_time) override;
    void update_inputs(const float &delta_time) override;
    void update_events(sf::Event event) override;

    void draw(sf::RenderTarget *target = nullptr) override;

    void end_state() override;
};

#endif