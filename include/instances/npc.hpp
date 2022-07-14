/**
 * @file npc.hpp
 * @author brisabn, heitoeu
 * @brief Definição da classe Npc
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
 * @brief Cria uma classe Npc que é filha de Instance 
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
     * @brief Constroi o objeto do tipo Npc
     * 
     * @param name Parametro do objeto Npc do tipo string
     * @param x Parametro do objeto Npc do tipo int 
     * @param y Parametro do objeto Npc do tipo int
     * @param script Parametro do objeto Npc do tipo string
     */
    Npc(std::string name, int x, int y, std::string script);
    
    /**
     * @brief Destroi o objeto do tipo Npc
     * 
     */
    virtual ~Npc();

    /**
     * @brief Retorna true ou false de acordo com a interação
     * 
     * @return true 
     * @return false 
     */
    bool instance_interact() override;
    
    /**
     * @brief Desenha o objeto Instance para o destino de renderização
     * 
     * @param target Parametro do tipo ponteiro de RenderTarget da classe Instance 
     */
    void instance_draw(sf::RenderTarget *target) override;
    
    /**
     * @brief Atualiza a insntancia 
     * 
     * @param delta_time parametro passado pelo metodo instance_update
     */
    void instance_update(const float &delta_time) override;

    /**
     * @brief Retorna a variavel npc_dialogue
     * 
     * @return Dialogue* 
     */
    Dialogue *get_npc_dialogue();
};

#endif