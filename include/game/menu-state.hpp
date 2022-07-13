#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "game-state.hpp"
#include "buttons.hpp"
#include "game.hpp"

class Menu_state : public State
{
private:
    sf::Texture bg_texture;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button *> buttons;

public:
    Menu_state(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~Menu_state();

    void update_kb(const float &delta_time);
    void update(const float &delta_time) override;
    void draw(sf::RenderTarget *target = nullptr) override;
    void updateButtons();
    void drawButtons(sf::RenderTarget *target = nullptr);
    void end_state() override;
};

#endif