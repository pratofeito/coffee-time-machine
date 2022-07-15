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
#include "dialogue/dialogue.hpp"

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
    int i, x, y;

    sf::Texture *spr_texture;
    sf::Sprite *spr_item;

    sf::Texture *spr_texture_icon;
    sf::Sprite *spr_item_icon;


public:
    bool given;
    sf::RectangleShape carrot_sprite;

    /**
     * @brief Constrói novo objeto do tipo item
     * 
     * @param name nome do item
     * @param x posição x virtual na tela
     * @param y posição y virtual na tela
     * @param i 
     * @param spr_dir diretório da sprite do item
     * @param spr_dir_icon diretório da sprite do ícone do item
     */
    Item(std::string name, int x, int y, int i, std::string spr_dir, std::string spr_dir_icon);
    virtual ~Item();
    
    /**
     * @brief Obtem o objeto carregado
     * 
     * @return true 
     * @return false 
     */
    bool get_holding();

    /**
     * @brief Define objeto dado
     * 
     * @param given_item valor a ser atribuido a given
     */
    void set_given(bool given_item);

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
     * @brief Desenha o objeto Instance para o destino de renderização
     * 
     * @param target variavel do tipo ponteiro de RenderTarget do metodo instance_draw
     */
    virtual void instance_draw(sf::RenderTarget *target) override;
    
    /**
     * @brief Atualiza o objeto Instance
     * 
     * @param delta_time 
     */
    virtual void instance_update(const float &delta_time) override;
};

#endif