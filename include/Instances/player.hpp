#ifndef PLAYER_H
#define PLAYER_H

#include "instance.hpp"

class Player : public Instance
{
private:
    const float move_speed = 100.f / GRID_SIZE;
    bool move[4]; // direções possíveis
    bool walking;
    int next_tile;
    float x, y;

public:
    Player();
    ~Player();

    void player_move(const float delta_time);
    void player_inputs();

    enum MOVE
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    virtual void instance_draw(sf::RenderTarget *target) override;
    virtual void instance_update(const float &delta_time) override;
};

#endif