/**
 * @file background.hpp
 * @author mateuskrause
 * @brief Definições da classe Background, derivada de SpriteSet
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

/**
 * @brief Extende as funcionalidades de SpriteSet, sendo possível além de ler
 * um tileset, lê um arquivo csv de mapeamento para cada posição e desenha essa sequência
 * partindo de uma determinada posição
 *
 */
class Background : public SpriteSet
{

private:
    std::ifstream sprites_index_file;
    std::vector<int> sprites_index;

public:
    /**
     * @brief Constrói um novo objeto do tipo Background
     *
     * @param tileset_dir String informando o diretório do arquivo de imagem (.png)
     * @param positionset_dir String informando o diretório do arquivo de mapeamento (.csv)
     * @param position Vetor de posição informando o ponto inicial para começar o desenho
     */
    Background(std::string tileset_dir, std::string positionset_dir, sf::Vector2i position);

    /**
     * @brief Desenha na tela todos os pedaços do Background
     *
     * @param window Referência para a janela da aplicação
     */
    void draw(sf::RenderWindow *window);
};

#endif