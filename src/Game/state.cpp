#include "Game/state.hpp"

State::State(sf::RenderWindow *window,std::map<std::string,int>* supportedKeys,std::stack<State *>* states)
{
    this->window = window;
    this->supportedKeys=supportedKeys;
    this->states =  states;
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

void State::updateMousePositions()
{
    this->mousePosSreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}