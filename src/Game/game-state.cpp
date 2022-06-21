#include "Game/game-state.hpp"

Game_state::Game_state(sf::RenderWindow *window) : State(window)
{
}

Game_state::~Game_state()
{
}

void Game_state::update(const float &delta_time)
{
    std::cout << "Estou em Game State !!!" << std::endl;
}

void Game_state::draw(sf::RenderTarget *target)
{
}

void Game_state::end_state()
{
}