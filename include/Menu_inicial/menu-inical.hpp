#ifndef MENU_INICIAL_H
#define MENU_INCIAL_H

#include "game-state.hpp"
#include "state.hpp"
#include <iostream>


class Menu{
    private:
        //posicao do menu
        bool pressed,theselect;
        int posicao;
        sf::Font * font;
        sf::Texture * image;
        sf::Sprite * bg;
        sf::Event * _event;

        sf::Vector2i pos_mouse;
        sf::Vector2f mouse_coord;
        std::vector<sf::Text> texts;
        std::vector<std::size_t> sizes;
    
    protected:
        
        //valores para cada objeto
        void set_values();
        //eventos dos cliques do mouse quando pressionar alguma tecla durante o menu
        void loop_events();
        //desenhos da tela
        void draw_all();
    public:
        menu();
        ~menu();

};



#endif