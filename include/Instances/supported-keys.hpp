#ifndef SUPPORTED_KEYS_H
#define SUPPORTED_KEYS_H

#include "instance.hpp"
class Supported_keys
{
private:
public:
    Supported_keys(/* args */);
    ~Supported_keys();

    void update_keys()
    {
        bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    }
};

#endif