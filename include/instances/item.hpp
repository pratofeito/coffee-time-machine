/**
 * @file item.hpp
 * @author heitoeu
 * @brief definição da classe Item
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
 * @brief Cria uma classe Item que é filha de Instance
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
     * @brief Constroi um objeto do tipo Item
     * 
     * @param name 
     * @param x 
     * @param y 
     * @param i 
     */
    Item(std::string name, int x, int y, int i);
    
    /**
     * @brief Destrói o objeto do Item 
     * 
     */
    virtual ~Item();
    
    /**
     * @brief Obtem o objeto carregado
     * 
     * @return true 
     * @return false 
     */
    bool get_holding();

    /**
     * @brief Define o Lugar onde Item está
     * 
     * @param aqui 
     */
    void set_given(bool aqui);

    /**
     * @brief Obtem o nome do objeto
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