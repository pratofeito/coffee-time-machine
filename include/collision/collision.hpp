/**
 * @file collision.hpp
 * @author heitoeu
 * @brief Definições da classe Collision
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef COLLISION_H
#define COLLISION_H

#include "instances/instance.hpp"
#include <list>

/**
 * @brief Define uma colisão e torna elementos colidíveis
 *
 */
class Collision
{
private:

    /**
     * @brief Vetor estático que armazena todos os objetos colidíveis
     *
     */
    static std::list<Instance *> collidable;
    Instance *collidable_instance;

public:
    /**
     * @brief Constrói um novo objeto do tipo Collision
     *
     * @param new_object Ponteiro de instância para o objeto a ser adicionado colidível
     */
    Collision(Instance *new_object);
    
    /**
     * @brief Destrói o objeto do tipo Collision
     *
     */
    virtual ~Collision();
    
    virtual void disable_collision();

    /**
     * @brief Verifica se há uma colisão
     *
     * @param position Vetor posição que se quer verificar a colisão
     * @return Instance* Elemento que possui colisão que está na coordenada informada
     */
    Instance *get_collision(sf::Vector2i position);
};

#endif
