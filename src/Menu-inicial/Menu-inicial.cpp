
#include "menu-inicial/menu-inicial.hpp"

Menu_State::Menu_State(sf::RenderWindow* window)
{
  
    
    this->background.setSize(sf::Vector2f((float)window->getSize().x, (float)window->getSize().y));
    this->background.setFillColor(sf::Color::White);

}

Menu_State::~Menu_State()
{
   std::cout<<"Estado de jogo deletado"<<std::endl;
}

void Menu_State::endState()
{
    std::cout<<"Ending menu state!!!"<< std::endl;
}

void Menu_State::update(const float& delta_time)
{
    this->update_kb(delta_time);
}

void Menu_State::update_kb(const float& delta_time)
{
    this->kb_check_for_quit();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {

    }
}

void Menu_State::draw(sf::RenderTarget* target)
{
    if(!target){
        target= this->window;
    }
    target->draw(this->background);

}

void Menu_State::initkeybinds()
{
    
}
