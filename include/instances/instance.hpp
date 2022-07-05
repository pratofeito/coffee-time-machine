#ifndef INSTANCE_H
#define INSTANCE_H

#define GRID_SIZE 32.f

#include <map>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>

#include <SFML/Graphics.hpp>
#include "collision/collision.hpp"

class Instance
{
protected:
    sf::Texture *texture;
    sf::Sprite sprite;

public:
    Instance(int x, int y);
    ~Instance();
    sf::Vector2i virtual_position;

    virtual void instance_draw(sf::RenderTarget *target) = 0;
    virtual void instance_update(const float &delta_time) = 0;
};

#endif