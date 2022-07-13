#include "game/ending-state.hpp"

EndingState::EndingState(sf::RenderWindow *window) : State(window)
{
    wall = new Wall(5, 5);
}

EndingState::~EndingState()
{
    delete wall;
    std::cout << "Estado de jogo deletado" << std::endl;
}

void EndingState::update(const float &delta_time)
{
    //
}

void EndingState::draw(sf::RenderTarget *target)
{
    this->wall->instance_draw(target);
}

void EndingState::update_inputs(const float &delta_time)
{
    this->kb_check_for_quit();
}

void EndingState::update_events(sf::Event event)
{
}

void EndingState::end_state()
{
    std::cout << "EndingState game state!!!" << std::endl;
}
