#include "dialogue/intro.hpp"

Intro::Intro()
{
}

Intro::Intro(std::string myfile)
{
    text_sequence(myfile);
    image_sequence();

    if (!font.loadFromFile("resources/fonts/pixel.ttf"))
        std::cout << "Error loading font\n";
    // colocar esse coisa de erro para outros abridores de arquivo!!!
    // Exception aqui

    this->text.setCharacterSize(30);
    this->text.setFont(font);
    this->text.setOrigin(sf::Vector2f(0.f, 0.f));
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(110, 400);

    this->box1.setSize(sf::Vector2f(800.f, 544.f));
    this->box1.setOrigin(sf::Vector2f(0.f, 0.f));
    this->box1.setFillColor(sf::Color::Black);
    this->box1.setPosition(0, 0);

    // audio_music.define_music("resources/gris.ogg", 20.f);
    audio_sound.define_sound("resources/audio/typing.wav", 10.f);
}

Intro::~Intro()
{
}

void Intro::text_sequence(std::string myfile)
{
    text_file = std::ifstream(myfile);
    std::string myline;

    if (text_file.is_open())
    {
        while (text_file)
        {
            std::getline(text_file, myline);

            // identifica quebra de linha no arquivo
            size_t start_pos = 0;
            while ((start_pos = myline.find("\\n", start_pos)) != std::string::npos)
            {
                myline.replace(start_pos, 2, "\n");
                start_pos += 1;
            }
            description.push_back(myline);
        }
    }
}

void Intro::write()
{
    if (this->timer.getElapsedTime().asSeconds() > .025f && this->itr < this->phrase.size())
    {
        this->timer.restart();
        this->itr++;

        audio_sound.play_sound();
    }
    this->text.setString(phrase.substr(0, this->itr));
}

void Intro::set_string(std::string s)
{
    this->phrase = s;
}

void Intro::image_sequence()
{
    sf::RectangleShape rec1, rec2, rec3;

    rec1.setSize(sf::Vector2f(600.f, 300.f));
    rec1.setOrigin(sf::Vector2f(0.f, 0.f));
    rec1.setFillColor(sf::Color::Yellow);
    rec1.setPosition(100, 90);
    image.push_back(rec1);

    rec2.setSize(sf::Vector2f(600.f, 300.f));
    rec2.setOrigin(sf::Vector2f(0.f, 0.f));
    rec2.setFillColor(sf::Color::Blue);
    rec2.setPosition(100, 90);
    image.push_back(rec2);

    rec3.setSize(sf::Vector2f(600.f, 300.f));
    rec3.setOrigin(sf::Vector2f(0.f, 0.f));
    rec3.setFillColor(sf::Color::Red);
    rec3.setPosition(100, 90);
    image.push_back(rec3);
}

void Intro::imagine()
{
    this->box = caixa;
}

void Intro::set_image(sf::RectangleShape r)
{
    this->caixa = r;
}

void Intro::reset()
{
    this->timer.restart();
    this->itr = 0;
};

void Intro::intro_draw(sf::RenderTarget *target)
{
    audio_music.play_music();

    target->draw(this->box1);

    if (show == true)
    {
        imagine();
        write();
        target->draw(this->text);
        target->draw(this->box);
    }
}

void Intro::uptade_event_intro(sf::Event event)
{
    if (event.key.code == sf::Keyboard::Right)
    {
        if (curr < description.size() - 1)
        {
            show = true;
            set_string(description[curr]);
            set_image(image[curr]);
            reset();
            curr++;
        }
        else
        {
            next_state = true;
            show = false;
        }
    }
}

bool Intro::get_next_state()
{
    return next_state;
}