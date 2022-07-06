#include "menu-incial.hpp"


Menu::menu(){
    font = new sf::Font();
    image = new sf::Texture(); 
    sprite = new sf::bg();
    __event = new sf::event();
}



Menu::~menu(){
    delete font;
    delete Texture;
    delete bg;
    delete __event;
}


void Menu::set_values(){
    posicao=0;
    pressed = theselect = false;
    
    pos_mouse{0,0};
    mouse_coord{0,0};
    
     
}

