
#ifndef WALL_H
#define WALL_H

#include "collision/collision.hpp"
#include "instances/instance.hpp"

class Wall : public Instance
{
private:
    sf::RectangleShape hit_box;
    Collision *wall_collision;

public:
    Wall(int x, int y);
    virtual ~Wall();

    bool instance_interact() override;
    void instance_draw(sf::RenderTarget *target) override;
    void instance_update(const float &delta_time) override;
};
#endif
