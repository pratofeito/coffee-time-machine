#ifndef NPC_H
#define NPC_H

#include "collision/collision.hpp"
#include "instances/instance.hpp"

class Npc : public Instance
{
private:
    std::string name;
    sf::RectangleShape hit_box;
    Collision *npc_collision;

public:
    Npc(std::string name, int x, int y);
    virtual ~Npc();

    void instance_interact() override;
    void instance_draw(sf::RenderTarget *target) override;
    void instance_update(const float &delta_time) override;
};

#endif