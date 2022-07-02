#ifndef WALL_H
#define WALL_H

#include "instance.hpp"

class Wall : public Instance
{
private:
public:
    Wall();
    ~Wall();
    virtual void instance_draw(sf::RenderTarget *target) override;
    virtual void instance_update(const float &delta_time) override;
};

#endif