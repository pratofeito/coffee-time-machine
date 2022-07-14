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
    //sf::Sprite sprite;
    bool interact_status;
    int looking;
    int instance_state;

    enum directions
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    enum states
    {
        MOVING,
        INTERACTING,
        NOTHING
    };

public:
    Instance(int x, int y);
    virtual ~Instance();
    sf::Vector2i virtual_position;
    sf::Vector2f projected_position;

    virtual bool instance_interact() = 0;
    virtual void instance_interact(std::map<const std::string, bool> &bag) {}
    virtual void instance_interact(int &_player_state) {}
    virtual void instance_draw(sf::RenderTarget *target) = 0;
    virtual void instance_update(const float &delta_time) = 0;
    virtual bool get_interact_status();

    // Checar o tipo da instancia
    template <typename Base, typename T>
    inline bool instanceof (const T *ptr)
    {
        return dynamic_cast<const Base *>(ptr) != nullptr;
    }
};

#endif
