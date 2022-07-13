#ifndef BUTTONS_H
#define BUTTONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

enum button_states
{
    BTN_IDLE = 0,
    BTN_HAVER,
    BTN_PRESSED
};

class Button
{
private:
    short unsigned button_state;
    sf::RectangleShape shape;
    sf::Font *font;
    sf::Text text;

    sf::Color idle_color;
    sf::Color hover_color;
    sf::Color active_color;

public:
    Button(float x, float y, float width, float height, sf::Font *font, std::string text, sf::Color idle_color, sf::Color hover_color, sf::Color active_color);
    ~Button();
    void draw(sf::RenderTarget *target);
    void update(sf::Vector2f mouse_pos);
    const bool isPressed() const;
};

#endif