#include "instances/dialogue/dialogue.hpp"

Dialogue::Dialogue()
{
}

Dialogue::Dialogue(std::string myfile)
{
    create_tree(myfile);

    if (!font.loadFromFile("resources/pixel.ttf"))
        std::cout << "Error loading font\n";

    this->m_text.setCharacterSize(27);
    this->m_text.setFont(font);
    this->m_text.setOrigin(sf::Vector2f(0.f, 0.f));
    this->m_text.setFillColor(sf::Color::Black);
    this->m_text.setPosition(110, 450);

    this->box.setSize(sf::Vector2f(600.f, 110.f));
    this->box.setOrigin(sf::Vector2f(0.f, 0.f));
    this->box.setFillColor(sf::Color::White);
    this->box.setPosition(100, 450);

    barulho.define_sound("resources/typing2.wav");
}

Dialogue::~Dialogue()
{
}

void Dialogue::create_tree(std::string myfile)
{
    teste = std::ifstream(myfile);
    std::string myline;
    std::vector<std::string> leia;

    if (teste.is_open())
    {
        while (teste)
        {
            std::getline(teste, myline);

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

    root = arvore.CreateNode(leia[0]);
    root->esq = arvore.CreateNode(leia[1]);
    root->esq->esq = arvore.CreateNode(leia[2]);
    root->dir = arvore.CreateNode(leia[3]);
    root->dir->esq = arvore.CreateNode(leia[4]);
    root->dir->dir = arvore.CreateNode(leia[5]);
}

void Dialogue::write()
{
    if (this->m_timer.getElapsedTime().asSeconds() > .03f && this->m_itr < this->m_string.size())
    {
        this->m_timer.restart();
        this->m_itr++;

        barulho.play_sound();
    }
    this->m_text.setString(m_string.substr(0, this->m_itr));
}

void Dialogue::reset()
{
    this->m_timer.restart();
    this->m_itr = 0;
};

void Dialogue::setString(std::string s)
{
    this->m_string = s;
}

void Dialogue::dialogue_draw(sf::RenderTarget *target)
{
    target->draw(this->box);
    target->draw(this->m_text);
    write();
}

void Dialogue::setPode(bool boolean)
{
    this->pode = boolean;
}

bool Dialogue::getPode()
{
    return pode;
}

void Dialogue::uptade_event_dialogue(sf::Event gato)
{
    if (gato.type == sf::Event::KeyPressed)
    {
        if (gato.key.code == sf::Keyboard::Space)
        {
            setPode(true);
            this->setString(root->item);
            reset();
        }

        if (gato.key.code == sf::Keyboard::Right)
        {
            if (root->dir != NULL && root != NULL)
            {
                setPode(true);

                this->setString(root->dir->item);
                reset();

                root = root->dir;
            }
            else
                setPode(false);
        }

        if (gato.key.code == sf::Keyboard::Left)
        {
            if (root->esq != NULL && root != NULL)
            {
                setPode(true);
                setString(root->esq->item);
                reset();

                root = root->esq;
            }
            else
                setPode(false);
        }
    }
}