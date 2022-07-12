#ifndef NPC_H
#define NPC_H

#include "collision/collision.hpp"
#include "instances/instance.hpp"
#include "instances/dialogue/dialogue.hpp"
#include "instances/player.hpp"

class Npc : public Instance
{
private:
    // Atributes
    std::string name;
    Dialogue *npc_dialogue;

    // Collision
    sf::RectangleShape hit_box;
    Collision *npc_collision;

public:
    Npc(std::string name, int x, int y, std::string script);
    virtual ~Npc();

    void instance_interact() override;
    void instance_draw(sf::RenderTarget *target) override;
    void instance_update(const float &delta_time) override;

    Dialogue *get_npc_dialogue();
};

#endif