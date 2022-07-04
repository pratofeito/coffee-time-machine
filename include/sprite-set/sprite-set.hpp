/**
 * @file sprite-set.hpp
 * @author pinguim
 * @brief o objetivo dessa classe é ler um arquivo de imagem de um tileset e preencher
 * um vetor com cada uma das sprites nesse arquivo.
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

class SpriteSet {

    protected:

        int tileset_width, tileset_height;
        sf::Texture texture;
        std::vector<sf::IntRect> texture_map;

        void clear_sprites_map();

        SpriteSet(std::string tileset_dir);
        virtual ~SpriteSet();

    public:

        std::vector<sf::Sprite*> sprites_map;

};

#endif