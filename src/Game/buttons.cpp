#include "Game/buttons.hpp"

Button::Button(float x,float y,float width,float height,sf::Font* font,std::string text,sf::Color idleColor,sf::Color haverColor,sf::Color activeColor){
    
    this->buttonState = BTN_IDLE;
    
    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width,height));
   
   
    this->font=font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    //arrumar erro aqui depois

    this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width /2.f) - this->text.getGlobalBounds().width/2.f , this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height/2.f);

    this->idle_Color = idleColor;
    this->haver_Color = haverColor;
    this->active_Color= activeColor;

    this->shape.setFillColor(this->idle_Color);
}


Button::~Button()
{

}

const bool Button::isPressed() const
{
    if(this->buttonState == BTN_PRESSED)
    {
        return true;
    }
    return false;
}

void Button::draw(sf::RenderTarget * target)
{
    target->draw(this->shape);
    target->draw(this->text);
}

void Button::update(const sf::Vector2f mousePos)
{
    this->buttonState = BTN_IDLE;

    
    if(this->shape.getGlobalBounds().contains(mousePos))
    {
       this->buttonState = BTN_HAVER; 
       if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
       {
        this->buttonState = BTN_PRESSED;
       }
    }

    switch (this->buttonState)
    {
    case BTN_IDLE:
        this->shape.setFillColor(this->idle_Color);
        break;
    
    case BTN_HAVER:
        this->shape.setFillColor(this->haver_Color);
        break;
    
    case BTN_PRESSED:
        this->shape.setFillColor(this->active_Color);
        break;
    
    default:
    this->shape.setFillColor(sf::Color::Red);
        break;
    }

}