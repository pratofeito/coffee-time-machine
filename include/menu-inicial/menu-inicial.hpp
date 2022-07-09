#ifndef MENU_INICIAL_H
#define MENU_INCIAL_H

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Game/game-state.hpp"
#include "Game/state.hpp"
#include "Game/game.hpp"


class Main_Menu_State{
    private:
        sf::RectangleShape background;
        
        
        void initkeybinds();

    public:
        Main_Menu_State(sf::RenderWindow* window,std::map<std::string, int>* supportedKeys);
        virtual ~Main_Menu_State();

        void endState();

        void updateInput(const float& dt);
        void update(const float& dt);
        void render(sf::RenderTarget* target=NULL);
};

#endif 