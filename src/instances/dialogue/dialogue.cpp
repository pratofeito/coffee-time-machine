#include "instances/dialogue/dialogue.hpp"

Dialogue::Dialogue()
{
}

Dialogue::Dialogue(std::string myfile)
{
    create_tree(myfile);

    if (!font.loadFromFile("resources/pixel.ttf"))
        std::cout << "Error loading font\n";
    // colocar esse coisa de erro para outros abridores de arquivo!!!
    // Exception aqui

    this->text.setCharacterSize(25);
    this->text.setFont(font);
    this->text.setOrigin(sf::Vector2f(0.f, 0.f));
    this->text.setFillColor(sf::Color::Black);
    this->text.setPosition(105, 405);

    this->box.setSize(sf::Vector2f(600.f, 100.f));
    this->box.setOrigin(sf::Vector2f(0.f, 0.f));
    this->box.setFillColor(sf::Color::White);
    this->box.setPosition(100, 400);

    // this->interact = true;

    audio_sound.define_sound("resources/typing2.wav", 50.f);
}

Dialogue::~Dialogue()
{
}

void Dialogue::create_tree(std::string myfile)
{
    text_file = std::ifstream(myfile);
    std::string myline;
    std::vector<std::string> leia;

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
            leia.push_back(myline);
        }
    }

    root = tree.CreateNode(leia[0]);
    root->left = tree.CreateNode(leia[1]);
    root->left->left = tree.CreateNode(leia[2]);
    root->right = tree.CreateNode(leia[3]);
    root->right->left = tree.CreateNode(leia[4]);
    root->right->right = tree.CreateNode(leia[5]);
}

void Dialogue::write()
{
    if (this->timer.getElapsedTime().asSeconds() > .025f && this->itr < this->phrase.size())
    {
        this->timer.restart();
        this->itr++;

        audio_sound.play_sound();
    }
    this->text.setString(phrase.substr(0, this->itr));
}

void Dialogue::reset()
{
    this->timer.restart();
    this->itr = 0;
};

void Dialogue::set_string(std::string s)
{
    this->phrase = s;
}

void Dialogue::dialogue_draw(sf::RenderTarget *target)
{
    if (show == true && Pode == true) //&& interact == false)
    {
        write();
        target->draw(this->box);
        target->draw(this->text);
    }
}

void Dialogue::set_show(bool boolean)
{
    this->show = boolean;
}

bool Dialogue::get_show()
{
    return show;
}

void Dialogue::uptade_event_dialogue(sf::Event event)
{
    if (Pode == true)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            set_show(true);
            this->set_string(root->data);
            reset();
        }

        if (event.key.code == sf::Keyboard::M)
        {
            if (root->right != NULL && root != NULL)
            {
                set_show(true);
                this->set_string(root->right->data);
                reset();
                root = root->right;
            }
            else
            {
                set_show(false);
                Pode = false;
            }
        }

        if (event.key.code == sf::Keyboard::B)
        {
            if (root->left != NULL && root != NULL)
            {
                set_show(true);
                set_string(root->left->data);
                reset();
                root = root->left;
            }
            else
            {
                set_show(false);
                Pode = false;
            }
        }
    }
}