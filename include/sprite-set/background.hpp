/**
 * @file background.hpp
 * @author pinguim
 * @brief essa classe extende as funcionalidades de SpriteSet, sendo possível além de ler
 * um tileset, lê um arquivo csv de mapeamento para cada posição e desenha essa sequencia
 * partindo de uma determinada posição
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <fstream>
#include "sprite-set/sprite-set.hpp"

class Background : public SpriteSet {

    private:

        std::ifstream sprites_index_file;
        std::vector<int> sprites_index;

    public:

        void draw(sf::RenderWindow *window);
        Background(std::string tileset_dir, std::string positionset_dir, sf::Vector2i position);

};

#endif