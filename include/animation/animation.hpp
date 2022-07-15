/**
 * @file animation.hpp
 * @author mateuskrause
 * @brief Definições da classe Animation
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ANIMATION_CPP
#define ANIMATION_CPP

#include <map>
#include "sprite-set/sprite-set.hpp"
#include "instances/instance.hpp"

#define FRAME_TIME 0.2

/**
 * @brief Gerencia a animação de cada isntância, recebendo como configuração um estado e direção, junto com o caminho
 * para algum arquivo de texturas. quando chamado update() utiliza dessas informações para percorrer uma animação, desenhando
 * a sprite correta para cada estágio
 *
 */
class Animation
{

private:
    const int NO_DIRECTION = -1;
    Instance *instance;
    SpriteSet *sprite_vec;
    sf::Sprite current_sprite;
    float delta_time;
    float animation_time;
    int past_state;
    int index;
    bool has_config;

    /**
     * @brief Map qua armazena ponteiros para SpriteSet com uma chave sendo os estados
     * configurados
     *
     */
    std::map<std::vector<int>, SpriteSet *> sprites_collection;

public:
    /**
     * @brief Constrói um novo objeto do tipo Animation
     *
     * @param instance Instância que terá animação. Necessária para se obter dados relevantes
     * ao posicionamento
     */
    Animation(Instance *instance);

    /**
     * @brief Destrói o objeto do tipo Animation
     *
     */
    virtual ~Animation();

    /**
     * @brief Cria um novo estado de animação
     *
     * @param state Inteiro com um "estado"
     * @param tileset_dir Diretório para um tileset relacionado ao estado informado
     */
    void new_state(int state, std::string tileset_dir);

    /**
     * @brief Cria um novo estado de animação
     *
     * @param state Inteiro com um "estado"
     * @param direction Direção que a instância está posicionada
     * @param tileset_dir Diretório para um tileset relacionado ao estado informado
     */
    void new_state(int state, int direction, std::string tileset_dir);

    /**
     * @brief Atualiza a Sprite de animação
     *
     * @param player_state Estado atual da instância
     * @param looking Direção que a instância está posicionada
     * @param delta_time Variação do tempo desde o último frame
     */
    void update(int player_state, int looking, float delta_time);

    /**
     * @brief Obtém um ponteiro de objeto do tipo Sprite
     *
     * @return sf::Sprite* Sprite atualizada referente à instância
     */
    sf::Sprite *get_sprite();
};

#endif