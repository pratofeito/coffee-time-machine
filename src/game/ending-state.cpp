#include "game/ending-state.hpp"
#include "game/menu-state.hpp"

EndingState::EndingState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    wall = new Wall(5, 5);
    intro = new Intro("resources/dialogues/intro.txt");
}

EndingState::~EndingState()
{
    delete wall;
    std::cout << "Estado de jogo deletado" << std::endl;
}

void EndingState::update(const float &delta_time)
{
    if (intro->get_next_state() == true)
    {
        this->states->push(new Menu_state(this->window, this->states));
    }
}

void EndingState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    };
    this->wall->instance_draw(target);
    this->intro->intro_draw(target);
}

void EndingState::update_inputs(const float &delta_time)
{
    this->kb_check_for_quit();
}

void EndingState::update_events(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        intro->uptade_event_intro(event);
    }
}

void EndingState::end_state()
{
    std::cout << "EndingState game state!!!" << std::endl;
}
