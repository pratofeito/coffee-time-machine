#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
#include <string>
#define TEMPO 119

#include <ctime>

class Timer
{
private:
    sf::Clock m_clock;
    sf::Text m_text;
    sf::Font font;
    int tempo_total;

protected:
public:
    Timer(int tempo);
    ~Timer();

    void hud_draw(sf::RenderTarget *target);
    int timer_update();
};

#endif