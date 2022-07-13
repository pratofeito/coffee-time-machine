#ifndef BUTTONS_H
#define BUTTONS_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "SFML\system.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"


enum button_states{BTN_IDLE = 0, BTN_HAVER,BTN_PRESSED};

class Button{
    private:
        short unsigned buttonState;
        sf::RectangleShape shape;
        sf::Font* font;
        sf::Text text;

        sf::Color idle_Color;
        sf::Color haver_Color;
        sf::Color active_Color;





    public:
        Button(float x,float y,float width,float height,sf::Font* font,std::string text,sf::Color idle_Color,sf::Color haver_Color,sf::Color active_Color);
        ~Button();
        void draw(sf::RenderTarget* target);
        void update(sf::Vector2f mousePos);
        const bool isPressed() const;
};  

#endif