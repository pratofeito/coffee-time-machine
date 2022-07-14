/**
 * @file instance.hpp
 * @author heitoreu
 * @brief Definições da classe instance
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
 * @brief Cria uma classe Instance 
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
     * @brief Constrói o objeto do tipo Instance 
     * 
     * @param x Parametros do construtor do objeto Instance
     * @param y Parametros do construtor do objeto Instance
     */
    Instance(int x, int y);
    
    /**
     * @brief Destrói o objeto Instance 
     * 
     */
    virtual ~Instance();
    sf::Vector2i virtual_position;
    sf::Vector2f projected_position;

    /**
     * @brief Retorna se é true ou false de acordo com  a interação
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
     * @brief Desenha o objeto Instance para o destino de renderização
     * 
     * @param target 
     */
    virtual void instance_draw(sf::RenderTarget *target) = 0;
    
    /**
     * @brief Atualiza o objeto Instance
     * 
     * @param delta_time 
     */
    virtual void instance_update(const float &delta_time) = 0;
    
    /**
     * @brief Metodo bool que retorna interact_status 
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
