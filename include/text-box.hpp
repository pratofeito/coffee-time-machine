#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <SFML/Graphics.hpp>

class text_box
{
private:
    sf::Font font;
    sf::Text text;

public:
    text_box();
    ~text_box();
};

#endif