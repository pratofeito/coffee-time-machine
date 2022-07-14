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
     * @brief cria um objeto create_tree
     * 
     * @param myfile 
     */
    void create_tree(std::string myfile);
    
    /**
     * @brief 
     * 
     */
    void write();

    /**
     * @brief Set the string object
     * 
     * @param s 
     */
    void set_string(std::string s);
    
    /**
     * @brief Get the on going object
     * 
     * @return true 
     * @return false 
     */
    bool get_on_going();

    /**
     * @brief Set the given object
     * 
     * @param given 
     */
    void set_given(bool given);

    /**
     * @brief 
     * 
     */
    void reset();

    /**
     * @brief 
     * 
     * @param target 
     */
    void dialogue_draw(sf::RenderTarget *target);
    
    /**
     * @brief 
     * 
     * @param z 
     * @param x 
     * @param space 
     */
    void update_event_dialogue(bool z, bool x, bool space);
};

#endif