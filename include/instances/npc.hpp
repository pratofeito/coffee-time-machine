/**
 * @file npc.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef NPC_H
#define NPC_H

#include "collision/collision.hpp"
#include "instances/instance.hpp"
#include "instances/dialogue/dialogue.hpp"
#include "instances/player.hpp"


/**
 * @brief 
 * 
 */
class Npc : public Instance
{
private:
    // Atributes
    std::string name;
    Dialogue *npc_dialogue;

    // Collision
    sf::RectangleShape hit_box;

public:
    Collision *npc_collision;


    /**
     * @brief Construct a new Npc object
     * 
     * @param name 
     * @param x 
     * @param y 
     * @param script 
     */
    Npc(std::string name, int x, int y, std::string script);
    
    /**
     * @brief Destroy the Npc object
     * 
     */
    virtual ~Npc();

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

    /**
     * @brief Get the npc dialogue object
     * 
     * @return Dialogue* 
     */
    Dialogue *get_npc_dialogue();
};

#endif