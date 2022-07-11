#include "Game/menu-state.hpp"
#include "Game/state.hpp"

Menu_State:: Menu_State(sf::RenderWindow *window) : State(window)
{
  
    
    this->background.setSize(sf::Vector2f((float)window->getSize().x, (float)window->getSize().y));
    this->background.setFillColor(sf::Color::White);
    if(!this->font.loadFromFile("resources/adumu.ttf"))
    {
        std::cout<<"Error loading font \n";
    }
    this->background.setSize(static_cast<float>(this->window->getSize().x),static_cast<float>(this->window->getSize().y));
    
    if(!this->texture.loadFromFile("resources/menu_test.gif"))
    {
        std::cout<<"Erro loading texture"<<std::endl;
    }
    this->background.setTexture(&this->texture);
}

Menu_State::~Menu_State()
{   
    std::cout<<"Estado de jogo deletado"<<std::endl;
}

void Menu_State::end_state()
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

void Menu_State::init_Fonts()
{
    if(!this->font.loadFromFile("resources/adumu.ttf")){
        std::cout<<"Error loading font \n";
    }
}