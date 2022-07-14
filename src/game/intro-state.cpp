#include "game/intro-state.hpp"

IntroState::IntroState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    wall = new Wall(4, 4);
    intro = new Intro("resources/dialogues/intro.txt");
}

IntroState::~IntroState()
{
    delete wall;
    delete intro;
    std::cout << "Estado de jogo deletado" << std::endl;
}

void IntroState::update(const float &delta_time)
{
    if (intro->get_next_state() == true)
    {
        quit_state = true;
    }
    //  this->update_inputs(delta_time);
    // this->player->instance_update(delta_time);
    // carrot->instance_update(delta_time);
}

void IntroState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }
    this->wall->instance_draw(target);
    this->intro->intro_draw(target);
}

void IntroState::update_inputs(const float &delta_time)
{
    this->kb_check_for_quit();
}

void IntroState::update_events(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        intro->uptade_event_intro(event);
    }
}

void IntroState::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
    // this->states->push(new GameState(this->window, this->states));
}