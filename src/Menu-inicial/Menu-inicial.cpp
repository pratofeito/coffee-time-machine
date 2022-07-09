#include "menu-inicial/menu-inicial.hpp"

//contrutor
Menu::Menu(){
    winclose = new sf::RectangleShape();
    Window = new sf::RenderWindow();
    font = new sf::Font();
    image = new sf::Texture(); 
    bg = new sf::Sprite();
    event = new sf::Event();
}


//destrutor
Menu::~Menu(){
    delete winclose;
    delete winclose;
    delete font;
    delete image;
    delete bg;
    delete event;
    delete Window;
}

//coisas da tela /possibilidade de fazer uma classe filha so para mecher com ela futuramente
void Menu::set_values(){
    Window->create(sf::VideoMode(1360,768),"MenuDoJogotest",sf::Style::Titlebar |sf::Style::Close);
    Window->setPosition(sf::Vector2i(0,0));
    std::cout << "CHEGUEI AQUI!!" << std::endl;
   
    posicao=0;
    pressed = theselect = false;

    font->loadFromFile("/resources/menu-resources/Adumu.ttf");
    image->loadFromFile("/resources/menu-resources/4.png");
    
    
    bg->setTexture(*image);


    options = {"New game","Options","quit"};
    
    //preencher com as cordenadas das opções
    //coords = {{0,0,0},{0,0,0},{0,0,0}}
    //tamanho da fontes
    //sizes;
}


//oq vai acontecer ao mexer no menu?
void Menu::loop_events(){
    sf::Event event;
    while(Window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            Window->close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            //pos tem que ir ate 3 por causa do numeros de opções do menu incial
            if( posicao < 3){
                posicao++;
                pressed = true;
                texts[posicao].setOutlineThickness(3);
                texts[posicao - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(posicao > 1){
                posicao--;
                pressed = true;
                texts[posicao].setOutlineThickness(3);
                texts[posicao + 1].setOutlineThickness(0);
                pressed = false;
                theselect= false;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && (!theselect)){
                theselect = true;
                std::cout<<"pos: "<<posicao<<std::endl;
                if(posicao==3){
                    Window->close();
                }
            }
        }
    }
}


/*objetivos quando escolher alguma opção fazer da barulhinho 
  fazer tocar uma musica durante o menu 
  ter a seleções de opções *falta testar
  
  
*/

void Menu::draw_menu(){
    Window->close();
    Window->draw(*bg);
    Window->display();
}

void Menu::run_menu(){
    while(Window->isOpen()){
        loop_events();
        draw_menu();
    }
}