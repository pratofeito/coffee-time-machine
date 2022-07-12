#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <iostream>

#include "SFML/Graphics.hpp"
#include "state.hpp"
#include "game-state.hpp"
#include "buttons.hpp"


class Menu_State: public State{
    private:
        sf::Texture texture;
        sf::RectangleShape background;
        sf::Font font;

        std::map<std::string, Button*> buttons;
        
        

        Button* gamestate_btn;
        
    public:
        Menu_State(sf::RenderWindow *window);
        virtual ~Menu_State();


        void update_kb(const float &delta_time) override;
        void update(const float &delta_time) override;
        void draw(sf::RenderTarget *target= nullptr) override;
        void updateButtons();
        void drawButtons(sf::RenderTarget *target= nullptr);
        void end_state() override;
};

#endif 
