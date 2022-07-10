#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <iostream>

#include "SFML/Graphics.hpp"
#include "state.hpp"
#include "game-state.hpp"


class Menu_State: public State{
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
