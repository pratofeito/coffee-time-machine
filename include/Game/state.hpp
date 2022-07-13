#ifndef STATE_H
#define STATE_H

#include "Instances/instance.hpp"

// Classe Abstrata
class State
{
private:
protected:
    std::stack<State *> *states;
    sf::RenderWindow *window;
    std::vector<sf::Texture> textures;
    bool quit_state = false;

    sf::Vector2i mousePosSreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

public:
    State(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~State();

    // Serão definidos pelos states especializados
    virtual void update(const float &delta_time) = 0;
    virtual void update_kb(const float &delta_time) = 0;

    virtual void draw(sf::RenderTarget *target = nullptr) = 0;

    virtual void updateMousePositions();

    virtual void end_state() = 0;
    virtual void kb_check_for_quit();

    // Getters
    bool get_quit_state();
};

#endif