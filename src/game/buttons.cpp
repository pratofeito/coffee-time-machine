#include "game/buttons.hpp"

Button::Button(float x, float y, float width, float height,
               sf::Font *font, std::string text, sf::Color idle_color,
               sf::Color hover_color, sf::Color active_color)
{
    this->button_state = BTN_IDLE;

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    // arrumar erro aqui depois

    this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
                           this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f);

    this->idle_color = idle_color;
    this->hover_color = hover_color;
    this->active_color = active_color;

    this->shape.setFillColor(this->idle_color);
}

Button::~Button()
{
}

const bool Button::isPressed() const
{
    if (this->button_state == BTN_PRESSED)
    {
        return true;
    }
    return false;
}

void Button::draw(sf::RenderTarget *target)
{
    target->draw(this->shape);
    target->draw(this->text);
}

void Button::update(const sf::Vector2f mousePos)
{
    this->button_state = BTN_IDLE;

    if (this->shape.getGlobalBounds().contains(mousePos))
    {
        this->button_state = BTN_HAVER;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->button_state = BTN_PRESSED;
        }
    }

    switch (this->button_state)
    {
    case BTN_IDLE:
        this->shape.setFillColor(this->idle_color);
        break;

    case BTN_HAVER:
        this->shape.setFillColor(this->hover_color);
        break;

    case BTN_PRESSED:
        this->shape.setFillColor(this->active_color);
        break;

    default:
        this->shape.setFillColor(sf::Color::Red);
        break;
    }
}