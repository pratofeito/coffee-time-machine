#include "Game/menu-incial.hpp"

//contrutor
Menu::menu(){
    font = new sf::Font();
    image = new sf::Texture(); 
    sprite = new sf::bg();
    Event = new sf::event();
}


//destrutor
Menu::~menu(){
    delete font;
    delete Texture;
    delete bg;
    delete Event;
}

//coisas da tela /possibilidade de fazer uma classe filha so para mecher com ela futuramente
void Menu::set_values(){
    posicao=0;
    pressed = theselect = false;
    
    pos_mouse{0,0};
    mouse_coord{0,0};


    options = {"New game","Options","quit"};
    
    //preencher com as cordenadas das opções
    coords = {{0,0,0},{0,0,0},{0,0,0}}
    //tamanho da fontes
    sizes;
}


//oq vai acontecer ao mexer no menu?
void Menu::loop_events(){
    sf::Event event;
    while(window->pollEvent(__event)){
        if(event.type == sf::Event){
            window->close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            //pos tem que ir ate 4 por causa do numeros de opções do menu incial
            if( pos < 3){
                pos++;
                pressed = true;
                texts[pos].setOutlineThickness(3);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }
        if(sf::keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(pos > 1){
                pos--;
                pressed = true;
                texts[pos].setOutlineThickness(3);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect= false;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && (!theselect)){
                theselect = true;
                if(window==3){
                    window->clear;
                }
            }
        }
    }
}


void Menu::draw_all(){

}

