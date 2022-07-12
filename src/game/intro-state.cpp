#include "game/intro-state.hpp"

Intro_state::Intro_state(sf::RenderWindow *window) : State(window)
{
    wall = new Wall(4, 4);
    intro = new Intro("resources/intro.txt");
}

Intro_state::~Intro_state()
{
    delete wall;
    delete intro;
    std::cout << "Estado de jogo deletado" << std::endl;
}

void Intro_state::update(const float &delta_time)
{
    if (intro->get_next_state() == true)
    {
        quit_state = true;
    }
    //  this->update_inputs(delta_time);
    // this->player->instance_update(delta_time);
    // carrot->instance_update(delta_time);
}

void Intro_state::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }
    this->wall->instance_draw(target);
    this->intro->intro_draw(target);
}

void Intro_state::update_inputs(const float &delta_time)
{
    this->kb_check_for_quit();
}

void Intro_state::update_events(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        intro->uptade_event_intro(event);
    }
}

void Intro_state::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}