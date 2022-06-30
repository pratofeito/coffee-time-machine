#include "Game/state.hpp"

State::State(sf::RenderWindow *window)
{
    this->window = window;
}
State::~State() {}

void State::kb_check_for_quit()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->quit_state = true;
    }
}

bool State::get_quit_state()
{
    return this->quit_state;
}