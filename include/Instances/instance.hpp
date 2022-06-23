#ifndef INSTANCE_H
#define INSTANCE_H

#include <map>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>

#include <SFML/Graphics.hpp>

class Instance
{
private:
protected:
    sf::RectangleShape colision_mask;
    float speed;

public:
    Instance();
    ~Instance();

    virtual void instance_move(const float delta_time, const float x, const float y);

    virtual void instance_draw(sf::RenderTarget *target);
    virtual void instance_update(const float &delta_time);
};

#endif