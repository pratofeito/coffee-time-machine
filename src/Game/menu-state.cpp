#include "Game/menu-state.hpp"
#include "Game/state.hpp"

Menu_State:: Menu_State(sf::RenderWindow *window) : State(window)
{
  
    
    this->background.setSize(sf::Vector2f((float)window->getSize().x, (float)window->getSize().y));
    this->background.setFillColor(sf::Color::White);
    
    //carregando fontes
    
    if(!this->font.loadFromFile("resources/adumu.ttf"))
    {
        std::cout<<"Error loading font \n";
    }
    this->background.setSize(static_cast<float>(this->window->getSize().x),static_cast<float>(this->window->getSize().y));
    

    //carregando arquivo de texturas
    if(!this->texture.loadFromFile("resources/menu_test.gif"))
    {
        std::cout<<"Erro loading texture"<<std::endl;
    }
    this->background.setTexture(&this->texture);
    //inicializando botões
    
    this->buttons["GAME_STATE"] = new Button(200,300,130,50,&this->font,"New Game" ,sf::Color(10,10,10,100),sf::Color(20,20,20,200),(40,40,40,400));
    this->buttons["OPTIONS"] = new Button(400,300,130,50,&this->font,"Options", sf::color(10,10,10,10,100),sf::color(20,20,20,200),(40,40,40,400)); 
    this->buttons["EXIT_STATE"] = new Button(600,300,130,50,&this->font,"Quit" ,sf::Color(10,10,10,100),sf::Color(20,20,20,200),(40,40,40,400));
 
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

    sf::Text mouseText;

    //remover later
    //mouseText.setPosition(this->mousePosView.x, this->mousePosView.y-50);
    //mouseText.setFont(this->font);
    //mouseText.setCharactersize(12);
    //mouseText.setString(this->mousePosView);
    //std::stringsteam string_steam;
    //string_steam<< this->mousePosView.x<<""<<this->mousePosView.y<<std::endl;
   //mouseTExt.setstring(string_steam.str());

    //target->draw(mouseText);
}

