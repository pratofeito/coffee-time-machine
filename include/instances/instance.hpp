/**
 * @file instance.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


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

/**
 * @brief 
 * 
 */
class Instance
{
protected:
    sf::Texture *texture;
    //sf::Sprite sprite;
    bool interact_status;

public:
    /**
     * @brief Construct a new Instance object
     * 
     * @param x 
     * @param y 
     */
    Instance(int x, int y);
    
    /**
     * @brief Destroy the Instance object
     * 
     */
    virtual ~Instance();
    sf::Vector2i virtual_position;
    sf::Vector2f projected_position;

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool instance_interact() = 0;
    
    /**
     * @brief 
     * 
     * @param bag 
     */
    virtual void instance_interact(std::map<const std::string, bool> &bag) {}
    
    /**
     * @brief 
     * 
     * @param _player_state 
     */
    virtual void instance_interact(int &_player_state) {}
    
    /**
     * @brief 
     * 
     * @param target 
     */
    virtual void instance_draw(sf::RenderTarget *target) = 0;
    
    /**
     * @brief 
     * 
     * @param delta_time 
     */
    virtual void instance_update(const float &delta_time) = 0;
    
    /**
     * @brief Get the interact status object
     * 
     * @return true 
     * @return false 
     */
    virtual bool get_interact_status();

    // Checar o tipo da instancia
    template <typename Base, typename T>
    inline bool instanceof (const T *ptr)
    {
        return dynamic_cast<const Base *>(ptr) != nullptr;
    }
};

#endif
