#include "game/menu-state.hpp"
#include "game/credits-state.hpp"
#include "game/intro-state.hpp"
#include "game/state.hpp"

Menu_state::Menu_state(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{
    // Inicializando Background
    this->background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));

    // Carregando arquivo de texturas
    if (!this->bg_texture.loadFromFile("resources/sprites/menu/menu_background.png"))
    {
        std::cout << "Erro loading texture" << std::endl;
    }
    this->background.setTexture(&this->bg_texture);

    // Carregando fontes

    if (!this->font.loadFromFile("resources/fonts/pixel.ttf"))
    {
        std::cout << "Error loading font \n";
    }

    // Inicializando botões

    int vertical_pos = (WINDOW_WIDTH / 2) - (128 / 2);
    int horizontal_center = WINDOW_HEIGHT / 2;

    this->buttons["GAME_STATE"] = new Button(vertical_pos, horizontal_center - 50, 128, 32, &this->font, "NEW GAME", sf::Color(10, 10, 10, 100), sf::Color(20, 20, 20, 200), sf::Color(40, 40, 40, 144));
    this->buttons["OPTIONS"] = new Button(vertical_pos, horizontal_center, 128, 32, &this->font, "CREDITS", sf::Color(10, 10, 10, 100), sf::Color(20, 20, 20, 200), sf::Color(40, 40, 40, 144));
    this->buttons["EXIT_STATE"] = new Button(vertical_pos, horizontal_center + 50, 128, 32, &this->font, "QUIT", sf::Color(10, 10, 10, 100), sf::Color(20, 20, 20, 200), sf::Color(40, 40, 40, 144));

    menu_soundtrack = new Audio();
    menu_soundtrack->define_music("resources/audio/the_space_is_deep.ogg", 60);
    menu_soundtrack->play_music();
}

Menu_state::~Menu_state()
{
    auto it = this->buttons.begin();
    for (it = this->buttons.begin(); it != this->buttons.end(); it++)
    {
        delete it->second;
    }
    delete menu_soundtrack;
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
        it.second->update(this->mouse_position_view);
    }

    // Começar o jogo
    if (this->buttons["GAME_STATE"]->isPressed())
    {
        delete menu_soundtrack;
        this->states->push(new IntroState(this->window, this->states));
    }

    if (this->buttons["EXIT_STATE"]->isPressed())
    {
        window->clear();
        end_state();
        // quit = true
    }
    if (this->buttons["OPTIONS"]->isPressed())
    {
        this->states->push(new CreditsState(this->window, this->states));
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