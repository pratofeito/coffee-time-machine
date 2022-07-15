#include "hud/timer.hpp"

Timer::Timer(int tempo)
{
    this->tempo_total = tempo;
    if (!font.loadFromFile("resources/fonts/VT323.ttf"))
        std::cout << "Error loading font\n";

    this->m_text.setCharacterSize(45);
    this->m_text.setFont(font);
    this->m_text.setFillColor(sf::Color::White);
    this->m_text.setPosition(700, 15);
}
Timer::~Timer()
{
}

int Timer::timer_update()
{

    int tempo = tempo_total - (int)m_clock.getElapsedTime().asSeconds();
    int min = tempo / 60;

    std::stringstream ss;
    if (tempo_total - m_clock.getElapsedTime().asSeconds() > 0)
    {

        ss << int(min % 60) << ":" << int(tempo % 60);
        // ss << 15 - (int)m_clock.getElapsedTime().asSeconds();
    }

    if (tempo_total - m_clock.getElapsedTime().asSeconds() < 5)
        this->m_text.setFillColor(sf::Color::Red);

    m_text.setString(ss.str());

    return tempo_total - (int)m_clock.getElapsedTime().asSeconds();
}

void Timer::hud_draw(sf::RenderTarget *target)
{
    timer_update();
    target->draw(this->m_text);
}