#ifndef PLAYER_H
#define PLAYER_H

#include "instance.hpp"
#include "collision/collision.hpp"
#include "item.hpp"
#include "npc.hpp"
#include <set>

class Player : public Instance
{
private:
    // Movimentação
    sf::RectangleShape hit_box;

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
    // Interação
    bool interact_key;

public:
    int player_state;
    bool z = false, x = false;
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

    virtual bool instance_interact() override;
    virtual void instance_draw(sf::RenderTarget *target) override;
    virtual void instance_update(const float &delta_time) override;
};

#endif