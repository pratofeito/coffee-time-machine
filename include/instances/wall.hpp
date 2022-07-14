/**
 * @file wall.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef WALL_H
#define WALL_H

#include "collision/collision.hpp"
#include "instances/instance.hpp"

/**
 * @brief 
 * 
 */
class Wall : public Instance
{
private:
    sf::RectangleShape hit_box;
    Collision *wall_collision;

public:

    /**
     * @brief Construct a new Wall object
     * 
     * @param x 
     * @param y 
     */
    Wall(int x, int y);

    /**
     * @brief Destroy the Wall object
     * 
     */
    virtual ~Wall();

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool instance_interact() override;

    /**
     * @brief 
     * 
     * @param target 
     */
    void instance_draw(sf::RenderTarget *target) override;

    /**
     * @brief 
     * 
     * @param delta_time 
     */
    void instance_update(const float &delta_time) override;
};
#endif
