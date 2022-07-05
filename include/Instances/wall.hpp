
#ifndef WALL_H
#define WALL_H

#include "collision.hpp"

class Wall : public Instance
{
private:
    sf::RectangleShape hit_box;

public:
    Wall(int x, int y);
    virtual ~Wall() {}

    void instance_draw(sf::RenderTarget *target) override;
    void instance_update(const float &delta_time) override;
};
#endif
