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
#include <map>

class Instance
{
protected:
    sf::Texture *texture;
    sf::Sprite sprite;

public:
    Instance(int x, int y);
    virtual ~Instance();
    sf::Vector2i virtual_position;

    virtual void instance_desinteract() = 0;
    virtual void instance_interact() = 0;
    virtual void instance_interact(std::map<const std::string, bool> &bag) {}
    virtual void instance_draw(sf::RenderTarget *target) = 0;
    virtual void instance_update(const float &delta_time) = 0;

    // Checar o tipo da instancia
    template <typename Base, typename T>
    inline bool instanceof (const T *ptr)
    {
        return dynamic_cast<const Base *>(ptr) != nullptr;
    }
};

#endif