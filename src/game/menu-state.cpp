#include "game/menu-state.hpp"
#include "game/state.hpp"

Menu_state::Menu_state(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    // Inicializando Background
    this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x),
                                          static_cast<float>(this->window->getSize().y)));

    // Carregando arquivo de texturas
    if (!this->bg_texture.loadFromFile("resources/menu_test.gif"))
    {
        std::cout << "Erro loading texture" << std::endl;
    }
    this->background.setTexture(&this->bg_texture);

    // Carregando fontes

    if (!this->font.loadFromFile("resources/Adumu.ttf"))
    {
        std::cout << "Error loading font \n";
    }

    // Inicializando botões

    this->buttons["GAME_STATE"] = new Button(200, 300, 130, 50, &this->font, "New Game", sf::Color(10, 10, 10, 100), sf::Color(20, 20, 20, 200), sf::Color(40, 40, 40, 144));
    this->buttons["OPTIONS"] = new Button(400, 300, 130, 50, &this->font, "Options", sf::Color(10, 10, 10, 100), sf::Color(20, 20, 20, 200), sf::Color(40, 40, 40, 144));
    this->buttons["EXIT_STATE"] = new Button(600, 300, 130, 50, &this->font, "Quit", sf::Color(10, 10, 10, 100), sf::Color(20, 20, 20, 200), sf::Color(40, 40, 40, 144));
}

Menu_state::~Menu_state()
{
    auto it = this->buttons.begin();
    for (it = this->buttons.begin(); it != this->buttons.end(); it++)
    {
        delete it->second;
    }
}

void Menu_state::end_state()
{
    std::cout << "Ending menu state!!!" << std::endl;
}

void Menu_state::update(const float &delta_time)
{
    this->updateMousePositions();
    this->update_kb(delta_time);

    this->updateButtons();
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        this->quit_state = true;
    }
}

void Menu_state::update_kb(const float &delta_time)
{
    this->kb_check_for_quit();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
    }
}

void Menu_state::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }
    target->draw(this->background);
    this->drawButtons(target);
    // std::cout << "ATIZAP" << std::endl;
}

void Menu_state::updateButtons()
{
    for (auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

    // Começar o jogo
    if (this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->states));
    }

    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        window->clear();
        end_state();
        // quit = true
    }
}

void Menu_state::drawButtons(sf::RenderTarget *target)
{
    for (auto &it : this->buttons)
    {
        it.second->draw(target);
    }
    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        window->clear();
        end_state();
    }
}