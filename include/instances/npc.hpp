#ifndef NPC_H
#define NPC_H

#include "collision/collision.hpp"
#include "instances/instance.hpp"
#include "dialogue/dialogue.hpp"
#include "instances/player.hpp"

class Npc : public Instance
{
private:
    // Atributes
    std::string name;
    Dialogue *npc_dialogue;

    // Collision
    sf::RectangleShape hit_box;

public:
    Collision *npc_collision;

    Npc(std::string name, int x, int y, std::string script);
    virtual ~Npc();

    bool instance_interact() override;
    void instance_draw(sf::RenderTarget *target) override;
    void instance_update(const float &delta_time) override;

    Dialogue *get_npc_dialogue();
};

#endif