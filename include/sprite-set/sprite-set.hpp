/**
 * @file sprite-set.hpp
 * @author mateuskrause
 * @brief Definições da classe SpriteSet
 * @version 0.1
 * @date 2022-07-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SPRITE_HANDLER_HPP
#define SPRITE_HANDLER_HPP

#define TILE_SIZE 32

#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>

/**
 * @brief Gera um vetor de sprites por um arquivo tileset
 * 
 */
class SpriteSet
{
protected:
    
    int tileset_width, tileset_height;
    sf::Texture texture;
    std::vector<sf::IntRect> texture_map;

    /**
     * @brief Remove todos os elementos (que são alocados dinamicamente)
     * e os deleta
     * 
     */
    void clear_sprites_map();

public:

    /**
     * @brief Constrói um novo objeto do tipo SpriteSet
     * 
     * @param tileset_dir String informando o diretório do arquivo de imagem (.png)
     */
    SpriteSet(std::string tileset_dir);

    /**
     * @brief Destrói o objeto do tipo SpriteSet
     * 
     */
    virtual ~SpriteSet();

    /**
     * @brief Vetor de sprites que armazena as sprites obtidas
     * no arquivo.
     * 
     */
    std::vector<sf::Sprite *> sprites_map;
};

#endif
