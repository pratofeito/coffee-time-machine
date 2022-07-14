#ifndef CREDITS_STATE_H
#define CREDITS_STATE_H

#include "game/state.hpp"

class CreditsState : public State
{
protected:
    // Elementos de Game
    sf::Text text;
    sf::Font font;

public:
    CreditsState(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~CreditsState();

    void update(const float &delta_time) override;
    void update_inputs(const float &delta_time) override;
    void update_events(sf::Event event) override;

    void draw(sf::RenderTarget *target = nullptr) override;

    void end_state() override;
};

#endif