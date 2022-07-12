#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
#include <string>

#include <ctime>

class Timer
{
private:
    sf::Clock m_clock;
    sf::Text m_text;
    sf::Font font;

protected:
public:
    Timer();
    ~Timer();

    void hud_draw(sf::RenderTarget *target);
    int timer_update();
};

#endif