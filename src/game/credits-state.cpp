#include "game/credits-state.hpp"
#include "game/menu-state.hpp"

CreditsState::CreditsState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    if (!font.loadFromFile("resources/fonts/pixel.ttf"))
        std::cout << "Error loading font\n";
    // colocar esse coisa de erro para outros abridores de arquivo!!!
    // Exception aqui

    this->text.setCharacterSize(30);
    this->text.setFont(font);
    this->text.setOrigin(sf::Vector2f(0.f, 0.f));
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(40, 40);

    this->text.setString("Credits \n\nBrisa Nascimento \nHeitor dos Santos \nLucas Augusto \nMateus Krause \nMusic: Loyalty Freak Music");
}

CreditsState::~CreditsState()
{
    std::cout << "Estado de jogo deletado" << std::endl;
}

void CreditsState::update(const float &delta_time)
{
    sf::Event event;
    this->update_events(event);
}

void CreditsState::draw(sf::RenderTarget *target)
{
    target->draw(text);
}

void CreditsState::update_inputs(const float &delta_time)
{
}

void CreditsState::update_events(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::S)
        {
            quit_state = true;
            // this->states->push(new Menu_state(this->window, this->states));
        }
    }
}

void CreditsState::end_state()
{
    std::cout << "CreditsState game state!!!" << std::endl;
}
