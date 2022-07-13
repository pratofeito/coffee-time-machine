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

    // this->first_interaction = true;
    this->on_going = true;
    this->given = false;
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
    root->left->right = tree.CreateNode(leia[3]);
    root->right = tree.CreateNode(leia[4]);
    root->right->left = tree.CreateNode(leia[5]);
    root->right->right = tree.CreateNode(leia[6]);
}

bool Dialogue::get_on_going()
{
    return on_going;
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
    if (show_dialogue == true && interacted == true)
    {
        write();
        target->draw(this->box);
        target->draw(this->text);
    }
}
void Dialogue::set_given(bool given)
{
    this->given = given;
}

void Dialogue::update_event_dialogue(bool z, bool x, bool space)
{
    given = true;

    if ((first_interaction == true) && ((z == true) || (x == true)))
    {
        on_going = true;
        show_dialogue = true;
        set_string(root->data);
        reset();
        first_interaction = false;
        z = false;
        x = false;
        on_going = false;
    }

    if ((z == true) && (x == false))
    {
        on_going = true;
        if (root->left != NULL && root != NULL)
        {
            show_dialogue = true;
            set_string(root->left->data);
            reset();
            root = root->left;
            z = false;
            x = false;
            space = false;
        }
        else
        {
            show_dialogue = false;
            interacted = false;
            on_going = false;
            first_interaction = true;
            z = false;
            x = false;
            space = false;
        }
    }

    if ((x == true) && (z == false))
    {
        on_going = true;

        if (root->right != NULL && root != NULL)
        {
            show_dialogue = true;
            set_string(root->right->data);
            reset();
            root = root->right;
            z = false;
            x = false;
            space = false;
        }
        else
        {
            show_dialogue = false;
            interacted = false;
            on_going = false;
            first_interaction = true;
            x = false;
            z = false;
            space = false;
        }
    }
}