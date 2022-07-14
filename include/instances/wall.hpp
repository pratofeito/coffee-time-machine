/**
 * @file wall.hpp
 * @author heitoeu
 * @brief Definição da classe Wall
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
 * @brief Cria uma classe Wall que é filha de Instance
 * 
 */
class Wall : public Instance
{
private:
    sf::RectangleShape hit_box;
    Collision *wall_collision;

public:

    /**
     * @brief Constrói um novo objeto wall
     * 
     * @param x 
     * @param y 
     */
    Wall(int x, int y);

    /**
     * @brief Destrói um novo objeto Wall
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
     * @brief Desenha o objeto Instance para o destino de renderização
     * 
     * @param target 
     */
    void instance_draw(sf::RenderTarget *target) override;

    /**
     * @brief Atualiza o objeto Instance 
     * 
     * @param delta_time 
     */
    void instance_update(const float &delta_time) override;
};
#endif
