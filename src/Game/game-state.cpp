#include "Game/game-state.hpp"

Game_state::Game_state(sf::RenderWindow *window) : State(window)
{
}

Game_state::~Game_state()
{
    std::cout << "Estado de jogo deletado" << std::endl;
}

void Game_state::update(const float &delta_time)
{
    this->update_kb(delta_time);
    this->player.instance_update(delta_time);
}

void Game_state::draw(sf::RenderTarget *target)
{
    this->player.instance_draw(this->window);
}

void Game_state::update_kb(const float &delta_time)
{
    this->kb_check_for_quit();
}

void Game_state::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}