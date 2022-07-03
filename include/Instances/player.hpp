#ifndef PLAYER_H
#define PLAYER_H

#include "instance.hpp"
#include "wall.hpp"

class Player : public Instance
{
private:
    // Movimentação e Colisão
    const float move_speed = 150.f / GRID_SIZE;
    bool move[4]; // Direções possíveis
    bool walking;
    bool can_up, can_down, can_left, can_right; // Colisão
    std::string direction;

    int next_tile_x;
    int next_tile_y;
    float x, y;

    bool interagiu = false;

public:
    Player();
    ~Player();

    void player_move(const float delta_time);
    void player_inputs();
    void player_col(const std::vector<Wall> colisions);
    void player_interact(const Wall interactable);

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