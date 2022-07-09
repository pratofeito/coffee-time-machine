#include "menu-inicial/menu-inicial.hpp"

Main_Menu_State::Main_Menu_State(sf::RenderWindow* window,std::map<std::string, int>* supportedKeys)
{
    this->initkeybinds();
    
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::White);

}

Main_Menu_State::~Main_Menu_State()
{

}

void Main_Menu_State::endState()
{

}

void Main_Menu_State::updateInput(const float& dt)
{
    this->checkForQuit();
}

void Main_Menu_State::update(const float& dt)
{

}

void Main_Menu_State::render(sf::RenderTarget* target)
{
    if(!target){
        target= this->window;
    }
    target->draw(this->background);

}

void Main_Menu_State::initkeybinds(){
    
}
