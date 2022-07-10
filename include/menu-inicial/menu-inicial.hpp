#ifndef MENU_INICIAL_H
#define MENU_INCIAL_H

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Game/game-state.hpp"
#include "Game/state.hpp"
#include "Game/game.hpp"


class Menu_State :public State{
    private:
        sf::RectangleShape background;
        
        
        void initkeybinds();

    public:
        Menu_State(sf::RenderWindow *window);
        virtual ~Menu_State();

    
        void update_kb(const float &delta_time) override;
        void update(const float &delta_time) override;
        void draw(sf::RenderTarget *target= nullptr) override;

        void end_state() override;
};

#endif 
