/**
 * @file item.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ITEM_H
#define ITEM_H

#include "collision/collision.hpp"
#include "instances/dialogue/dialogue.hpp"

/**
 * @brief 
 * 
 */

class Item : public Instance
{
private:
    std::string item_name;
    Collision *item_collision;
    sf::RectangleShape hit_box;
    // Substituir pro icone que vai ser desenhado
    // sf::RectangleShape carrot_sprite;

    Dialogue item_dialogue;
    bool holding_item;
    int i;

public:
    bool given;
    sf::RectangleShape carrot_sprite;

    /**
     * @brief Construct a new Item object
     * 
     * @param name 
     * @param x 
     * @param y 
     * @param i 
     */
    Item(std::string name, int x, int y, int i);
    
    /**
     * @brief Destroy the Item object
     * 
     */
    virtual ~Item();
    
    /**
     * @brief Get the holding object
     * 
     * @return true 
     * @return false 
     */
    bool get_holding();

    /**
     * @brief Set the given object
     * 
     * @param aqui 
     */
    void set_given(bool aqui);

    /**
     * @brief Get the name object
     * 
     * @return std::string 
     */
    std::string get_name();

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool instance_interact() override;
    
    /**
     * @brief 
     * 
     * @param bag 
     */
    virtual void instance_interact(std::map<const std::string, bool> &bag) override;
    
    /**
     * @brief 
     * 
     * @param target 
     */
    virtual void instance_draw(sf::RenderTarget *target) override;
    
    /**
     * @brief 
     * 
     * @param delta_time 
     */
    virtual void instance_update(const float &delta_time) override;
};

#endif