#include "game/game-state.hpp"

Game_state::Game_state(sf::RenderWindow *window) : State(window)
{
    player = new Player(0, 0);
    wall = new Wall(4, 6);
    npc_leandro = new Npc("Leandro", 8, 8);
}

Game_state::~Game_state()
{
    delete player;
    delete wall;
    delete npc_leandro;
    std::cout << "Estado de jogo deletado" << std::endl;
}

void Game_state::update(const float &delta_time)
{
    this->update_inputs(delta_time);
    this->player->instance_update(delta_time);
}

void Game_state::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }
    this->player->instance_draw(target);
    this->wall->instance_draw(target);
    this->npc_leandro->instance_draw(target);
}

void Game_state::update_inputs(const float &delta_time)
{
    this->kb_check_for_quit();
}

void Game_state::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}