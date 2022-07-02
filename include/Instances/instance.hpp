#ifndef INSTANCE_H
#define INSTANCE_H

#include <map>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>

#include <SFML/Graphics.hpp>

#define GRID_SIZE 32.f

class Instance
{
protected:
    sf::Texture *texture;
    sf::Sprite sprite;
    sf::RectangleShape colision_mask;

public:
    Instance();
    ~Instance();

    virtual void instance_draw(sf::RenderTarget *target) = 0;
    virtual void instance_update(const float &delta_time) = 0;
};

#endif