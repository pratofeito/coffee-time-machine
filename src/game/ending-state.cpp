#include "Game/ending-state.hpp"

Ending_state::Ending_state(sf::RenderWindow *window) : State(window)
{
    wall = new Wall(5, 5);
}

Ending_state::~Ending_state()
{
    delete wall;
    std::cout << "Estado de jogo deletado" << std::endl;
}

void Ending_state::update(const float &delta_time)
{
    //
}

void Ending_state::draw(sf::RenderTarget *target)
{
    this->wall->instance_draw(target);
}

void Ending_state::update_inputs(const float &delta_time)
{
    this->kb_check_for_quit();
}

void Ending_state::update_events(sf::Event event)
{
}

void Ending_state::end_state()
{
    std::cout << "Ending_state game state!!!" << std::endl;
}