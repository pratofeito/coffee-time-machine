#include "Game/game.hpp"

Game::Game()
{
    this->initialize_window();
    this->initialize_states();
    // this->initialize_sfml_events();
}

Game::~Game()
{
    delete this->window;
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

// Private
void Game::initialize_window()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "RPG", sf::Style::Default, settings);
    this->window->setFramerateLimit(30);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initialize_states()
{
    this->states.push(new Game_state(this->window));
}

void initialize_sfml_events()
{
    // Sfml events
}

// Public

void Game::update_delta_time()
{
    this->delta_time = this->delta_time_clock.restart().asSeconds();

    system("cls");
    std::cout << this->delta_time << std::endl;
}

void Game::update_sfml_events()
{
    while (this->window->pollEvent(this->sfml_event))
    {
        if (sfml_event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->update_sfml_events();
    if (!this->states.empty())
    {
        this->states.top()->update(this->delta_time);
    }
}

void Game::draw()
{
    // Double Buffering

    this->window->clear(sf::Color::White);

    if (!this->states.empty())
    {
        this->states.top()->draw(this->window);
    }

    this->window->display();
}

void Game::run()
{
    // Loop Principal
    while (this->window->isOpen())
    {
        this->update_delta_time();

        // Atualiza os eventos e desenha na tela
        this->update();
        this->draw();
    }
}