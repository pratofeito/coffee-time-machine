#include "game/state.hpp"

State::State(sf::RenderWindow *window, std::stack<State *> *states)
{
    this->window = window;
    this->states = states;
    this->quit_state = false;
}

State::~State() {}

void State::kb_check_for_quit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        // this->quit_state = true;
    }
}

bool State::get_quit_state()
{
    return this->quit_state;
}

void State::updateMousePositions()
{
    this->mouse_position_screen = sf::Mouse::getPosition();
    this->mouse_position_window = sf::Mouse::getPosition(*this->window);
    this->mouse_position_view = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}