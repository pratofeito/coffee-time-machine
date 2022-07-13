#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "game/state.hpp"
class IntroState : public State
{
private:
    // Elementos de Game
    Wall *wall;
    Intro *intro;

public:
    IntroState(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~IntroState();

    void update(const float &delta_time) override;
    void update_inputs(const float &delta_time) override;
    void update_events(sf::Event event) override;

    void draw(sf::RenderTarget *target = nullptr) override;

    void end_state() override;
};

#endif