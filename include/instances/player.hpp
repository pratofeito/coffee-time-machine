#ifndef PLAYER_H
#define PLAYER_H

#include "instance.hpp"
#include "collision/collision.hpp"

class Player : public Instance
{
private:
    sf::RectangleShape hit_box;
    // Movimentação
    bool is_moving;
    int looking;
    enum directions
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    sf::Vector2i next_tile;
    float move_time = 0.3;
    float elapsed_time;
    sf::Vector2i move_dir;
    int y_direction, x_directon;

    // Controles
    // Movimento
    bool arrow_up, arrow_down, arrow_left, arrow_right;
    // Iteração
    bool accept_key, deny_key;

public:
    Player(int x, int y);
    Collision *player_colision;
    virtual ~Player();

    void player_move(const float delta_time);
    void player_interact();
    void check_inputs();
    void keyboard_step();

    virtual void instance_interact() override;
    virtual void instance_draw(sf::RenderTarget *target) override;
    virtual void instance_update(const float &delta_time) override;
};

#endif