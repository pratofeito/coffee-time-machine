#ifndef MENU_INICIAL_H
#define MENU_INCIAL_H

#include <iostream>

#include "Game/game-state.hpp"
#include "Game/state.hpp"


class Menu{
    private:
        //posicao do menu
        bool pressed;
        bool theselect;
        int posicao;
        sf::Font * font;
        sf::Texture * image;
        sf::Sprite * bg;
        sf::Event * Event;

        sf::Vector2i pos_mouse;
        sf::Vector2f mouse_coord;
        std::vector<sf::Text> texts;
        std::vector<std::size_t> sizes;
        std::vector<const char *>options;

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
