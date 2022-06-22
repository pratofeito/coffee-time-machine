#include "Game/game-state.hpp"

Game_state::Game_state(sf::RenderWindow *window) : State(window)
{
}

Game_state::~Game_state()
{
}

void Game_state::update(const float &delta_time)
{
    this->update_kb(delta_time);
    std::cout << "Estou em Game State !!!" << std::endl;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "A" << std::endl;
    }
}

void Game_state::draw(sf::RenderTarget *target)
{
}

void Game_state::update_kb(const float &delta_time)
{
    this->kb_check_for_quit();
}

void Game_state::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}