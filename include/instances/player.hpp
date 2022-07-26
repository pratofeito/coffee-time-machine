/**
 * @file player.hpp
 * @author heitoeu
 * @brief Definição da classe player.
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <set>
#include "instance.hpp"
#include "collision/collision.hpp"
#include "item.hpp"
#include "npc.hpp"
#include "sprite-set/sprite-set.hpp"
#include "animation/animation.hpp"

/**
 * @brief Cria uma classe Player que é filha de Instance
 * 
 */
class Player : public Instance
{
private:
    // Movimentação
    sf::RectangleShape hit_box;

    float move_time = FRAME_TIME * 2;
    float elapsed_time;
    sf::Vector2i move_dir;
    int y_direction, x_direction;

    // Controles
    // Movimento
    bool arrow_up, arrow_down, arrow_left, arrow_right;
    // Interação
    bool interact_key;

    // sprites e animação
    sf::Sprite *player_sprite;
    Animation *player_animation;

public:
    sf::Vector2i next_tile;

    // int player_state;
    bool z = false, x = false, space = false;
    // Atributos
    std::map<const std::string, bool> bag;

    // Métodos

    /**
     * @brief Constroi um novo objeto Player
     * 
     * @param x 
     * @param y 
     */
    Player(int x, int y);
    
    Collision *player_colision;
    
    /**
     * @brief Destrói o objeto player
     * 
     */
    virtual ~Player();

    /**
     * @brief 
     * 
     * @param delta_time 
     */
    void player_move(const float delta_time);
    
    /**
     * @brief 
     * 
     */
    void player_interact();
    
    /**
     * @brief 
     * 
     */
    void check_inputs();
    int invert_looking(int looking);

    /**
     * @brief 
     * 
     * @param event 
     * @return true 
     * @return false 
     */
    bool uptade_event_player(sf::Event event);
    
    /**
     * @brief 
     * 
     */
    void keyboard_step();

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
     * @param target 
     */
    virtual void instance_draw(sf::RenderTarget *target) override;
    
    /**
     * @brief Desenha o objeto Instance para o destino de renderização
     * 
     * @param delta_time 
     */
    virtual void instance_update(const float &delta_time) override;
};

#endif
