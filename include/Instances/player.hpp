#ifndef PLAYER_H
#define PLAYER_H

#include "instance.hpp"
#include "wall.hpp"

class Player : public Instance
{
private:
    const float move_speed = 100.f / GRID_SIZE;

    bool move[4]; // direções possíveis
    bool walking;
    bool can_up, can_down, can_left, can_right;

    int next_tile_x;
    int next_tile_y;

    float x, y;

public:
    Player();
    ~Player();

    void player_move(const float delta_time);
    void player_inputs();
    void player_col(const std::vector<Wall> colisions);

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