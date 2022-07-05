#ifndef PLAYER_H
#define PLAYER_H

#include "instance.hpp"
#include "wall.hpp"
#include "supported-keys.hpp"

class Player : public Instance
{
private:
    // Movimentação
    const float move_speed = 150.f / GRID_SIZE;
    float velh, velv;
    bool is_moving;
    std::string direction;

    int next_tile_x;
    int next_tile_y;
    float x, y;

    // Controles

public:
    Player();
    ~Player();

    void player_move(const float delta_time);
    void player_inputs();

    enum states
    {
        idle,
        walking
    };

    virtual void instance_draw(sf::RenderTarget *target) override;
    virtual void instance_update(const float &delta_time) override;
};

#endif