#ifndef STATE_H
#define STATE_H

#include <stack>
#include <map>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>

// Classe Abstrata
class State
{
private:
    sf::RenderWindow *window;
    std::vector<sf::Texture> textures;
    bool quit_state;

public:
    State(sf::RenderWindow *window);
    virtual ~State();

    // Serão definidos pelos states especializados
    virtual void update(const float &delta_time) = 0;
    virtual void update_kb(const float &delta_time) = 0;

    virtual void draw(sf::RenderTarget *target = nullptr) = 0;

    virtual void end_state() = 0;
    virtual void kb_check_for_quit();

    // Getters
    bool get_quit_state();
};

#endif