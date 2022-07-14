/**
 * @file dialogue.hpp
 * @author brisabn
 * @brief Definições da classe dialogue
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef DIALOGUE_HPP
#define DIALOGUE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "instances/dialogue/dialogue_tree.hpp"
#include "instances/audio/audio.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <fstream>

/**
 * @brief Cria uma organização para evitar conflitos de nomes de variaveis
 * 
 */

namespace sf
{
    class RenderTarget;
}


/**
 * @brief Cria uma classe Dialogue
 * 
 */

class Dialogue
{
protected:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;

    Audio audio_sound;

    std::string phrase;
    sf::Clock timer;

    std::ifstream text_file;

    bool show_dialogue = false;

public:
    bool interacted;
    bool on_going;
    bool given;

    Node *root;
    DialogueTree tree;

    std::size_t itr;
    
    /**
     * @brief Constrói o objeto de Dialogue
     * 
     */
    Dialogue();

    /**
     * @brief Controi um novo objeto de Dialogue
     * 
     * @param myfile 
     */
    Dialogue(std::string myfile);

    /**
     * @brief Destrói o objeto Dialogue
     * 
     */
    ~Dialogue();

    /**
     * @brief Cria um objeto create_tree
     * 
     * @param myfile parametro atribuido em create_tree
     */
    void create_tree(std::string myfile);
    
    /**
     * @brief 
     * 
     */
    void write();

    /**
     * @brief Faz a atribuição entre a variavel phrase  e o parametro s
     * 
     * @param s Parametro passado pelo metodo set_string
     */
    void set_string(std::string s);
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool get_on_going();

    /**
     * @brief Faz a atribuição entre variavel given e o parametro given
     * 
     * @param given Parametro do metodo set_given
     */
    void set_given(bool given);

    /**
     * @brief Reinicia o tempo
     * 
     */
    void reset();

    /**
     * @brief Desenha o objeto Dialogue para o destino de renderização
     * 
     * @param target 
     */
    void dialogue_draw(sf::RenderTarget *target);
    
    /**
     * @brief Atualiza o eventos do objeto Dialogue
     * 
     * @param z retorna true caso seja pressionado
     * @param x retorna true caso seja pressionado
     * @param space retorna true caso seja pressionado 
     */
    void update_event_dialogue(bool z, bool x, bool space);
};

#endif