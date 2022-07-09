#ifndef PLAYER_H
#define PLAYER_H

#include "instance.hpp"
#include "collision/collision.hpp"
#include <map>

class Player : public Instance
{
private:
    // Atributos

    // Movimentação
    sf::RectangleShape hit_box;
    int player_state;
    int looking;
    enum directions
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    enum states
    {
        MOVING,
        INTERACTING,
        NOTHING
    };

    sf::Vector2i next_tile;
    float move_time = 0.3;
    float elapsed_time;
    sf::Vector2i move_dir;
    int y_direction, x_direction;

    // Controles
    // Movimento
    bool arrow_up, arrow_down, arrow_left, arrow_right;
    // Iteração
    bool accept_key, deny_key;

public:
    bool okay;
    // Atributos
    std::map<const std::string, bool> bag;

    // Métodos
    Player(int x, int y);
    Collision *player_colision;
    virtual ~Player();

    void player_move(const float delta_time);
    void player_interact();
    void check_inputs();

    void uptade_event_player(sf::Event event);
    void keyboard_step();

    virtual void instance_desinteract() override;
    virtual void instance_interact() override;
    virtual void instance_draw(sf::RenderTarget *target) override;
    virtual void instance_update(const float &delta_time) override;
};

#endif