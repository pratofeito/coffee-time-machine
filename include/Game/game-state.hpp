#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Game/state.hpp"
class Game_state : public State
{
private:
    // Elementos de Game
    Player player;
    std::vector<Wall> walls;
    Wall wall;

public:
    Game_state(sf::RenderWindow *window);
    virtual ~Game_state();

    void update(const float &delta_time) override;
    void update_inputs(const float &delta_time) override;
    void draw(sf::RenderTarget *target = nullptr) override;

    void end_state() override;
};

#endif