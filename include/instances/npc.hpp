#ifndef NPC_H
#define NPC_H

#include "collision/collision.hpp"
#include "instances/instance.hpp"
#include "dialogue/dialogue.hpp"
#include "instances/player.hpp"
#include "animation/animation.hpp"

class Npc : public Instance
{
private:
    // Atributes
    std::string name;
    Dialogue *npc_dialogue;

    // Collision
    sf::RectangleShape hit_box;

    // Sprite
    sf::Sprite *npc_sprite;

public:
    Collision *npc_collision;
    Animation *npc_animation;

    // Clone
    bool cloned = false;

    Npc(std::string name, int x, int y, std::string script);
    virtual ~Npc();

    bool instance_interact() override;
    void instance_draw(sf::RenderTarget *target) override;
    void instance_update(const float &delta_time) override;
    void set_looking(int direction);
    int get_looking();

    Dialogue *get_npc_dialogue();
};

#endif