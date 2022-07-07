#include "game/game.hpp"

Game::Game()
{
    this->initialize_window();
    this->initialize_states();

    // criação do mapa
    map_bg = new Background("resources/bricks.png", "resources/map.csv", sf::Vector2i(0, 0));   

    this->initialize_sfml_events();
}

Game::~Game()
{

    // deleto o background do mapa criado no início
    delete map_bg;

    delete this->window;
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
    std::cout << "Aplicacao finalizada" << std::endl;
}

// Private
void Game::initialize_window()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    this->window = new sf::RenderWindow(sf::VideoMode(800, 640), "RPG", sf::Style::Close, settings);
    this->window->setFramerateLimit(30);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initialize_states()
{
    this->states.push(new Game_state(this->window));
}

void Game::initialize_sfml_events()
{
}

// Public

void Game::update_delta_time()
{
    this->delta_time = this->delta_time_clock.restart().asSeconds();

#ifdef LINUX
    system("clear");
#else
    system("cls");
#endif

    // std::cout << this->delta_time << std::endl;
}

void Game::update_sfml_events()
{
    while (this->window->pollEvent(this->sfml_event))
    {
        if (sfml_event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::draw_guidelines() {
    sf::RectangleShape vertical_line;
    sf::RectangleShape horizontal_line;

    vertical_line.setSize(sf::Vector2f(1, WINDOW_HEIGHT));
    horizontal_line.setSize(sf::Vector2f(WINDOW_WIDTH, 1));

    sf::Color ct (244, 125, 66, 100);
    vertical_line.setFillColor(ct);
    horizontal_line.setFillColor(ct);

    for (int i = 1; i < (WINDOW_WIDTH / TILE_SIZE); i++) {
        vertical_line.setPosition(TILE_SIZE * i, 0);
        horizontal_line.setPosition(0, TILE_SIZE * i);
        window->draw(vertical_line);
        window->draw(horizontal_line);
    }
}

void Game::update()
{
    this->update_sfml_events();

    if (!this->states.empty())
    {
        this->states.top()->update(this->delta_time);
        // State quit
        if (this->states.top()->get_quit_state())
        {
            this->states.top()->end_state();
            delete this->states.top();
            this->states.pop();
        }
    }
    // Application quit
    if (this->states.empty())
    {
        this->window->close();
    }
}

void Game::draw()
{
    // Double Buffering

    this->window->clear(sf::Color::Black);
    
    
    map_bg->draw(window);

    this->draw_guidelines();

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
