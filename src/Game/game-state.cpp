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
    this->update_inputs(delta_time);
    walls.push_back(this->wall);
    this->player.instance_update(delta_time);
    this->player.player_col(walls);
}

void Game_state::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }

    this->player.instance_draw(this->window);
    for (auto i : walls)
    {
        i.instance_draw(this->window);
    }
}

void Game_state::update_inputs(const float &delta_time)
{
    this->kb_check_for_quit();
}

void Game_state::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}