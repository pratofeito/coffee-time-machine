#ifndef STATE_H
#define STATE_H

#include "instances/player.hpp"
#include "instances/wall.hpp"
#include "instances/npc.hpp"
#include "audio/audio.hpp"
#include "dialogue/dialogue_tree.hpp"
#include "dialogue/dialogue.hpp"
#include "dialogue/intro.hpp"
#include "instances/item.hpp"
#include "hud/timer.hpp"

// Classe Abstrata
class State
{
private:
protected:
    std::stack<State *> *states;
    sf::RenderWindow *window;
    std::vector<sf::Texture> textures;
    bool quit_state = false;

    sf::Vector2i mouse_position_screen;
    sf::Vector2i mouse_position_window;
    sf::Vector2f mouse_position_view;

public:
    State(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~State();

    // Serão definidos pelos states especializados
    virtual void update(const float &delta_time) = 0;
    virtual void update_inputs(const float &delta_time) {}

    virtual void update_events(sf::Event event) {}

    virtual void draw(sf::RenderTarget *target = nullptr) = 0;

    virtual void updateMousePositions();

    virtual void end_state() = 0;
    virtual void kb_check_for_quit();

    // Getters
    bool get_quit_state();
};

#endif