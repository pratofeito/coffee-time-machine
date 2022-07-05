#ifndef PLAYER_H
#define PLAYER_H

#include "instance.hpp"
#include "collision.hpp"

class Player : public Instance
{
private:
    sf::RectangleShape hit_box;
    // Movimentação
    bool is_moving;
    int looking;
    sf::Vector2i next_tile;
    float move_time = 0.3;
    float elapsed_time;

    sf::Vector2i move_dir;
    // Controles

public:
    Player(int x, int y);
    virtual ~Player();

    void player_move(const float delta_time);
    void check_inputs();

    enum directions
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