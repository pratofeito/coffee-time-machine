#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Definição de algumas constantes para o exemplo
    const float pi = 3.14159f;
    const int gameWidth = 800;
    const int gameHeight = 600;
    float ballRadius = 10.f;

    // Cria a janela da aplicação
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "Exemplo Inicial", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    // Carraga os sons que serão utilizados
    sf::SoundBuffer ballSoundBuffer;
    if (!ballSoundBuffer.loadFromFile("resources/ball.wav"))
        return EXIT_FAILURE;
    sf::Sound ballSound(ballSoundBuffer);

    // Cria a bolinha
    sf::CircleShape ball;
    ball.setRadius(ballRadius - 3);
    ball.setOutlineThickness(3);
    ball.setOutlineColor(sf::Color::White);
    ball.setFillColor(sf::Color::Magenta);
    ball.setOrigin(ballRadius / 2, ballRadius / 2);

    // Carrega a fonte para os textos
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;

    // Inicia a mensagem de pause
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(170.f, 150.f);
    pauseMessage.setFillColor(sf::Color::White);
    pauseMessage.setString("Template!\nPressione espaco");

    // Define algumas propriedades dos elementos
    sf::Clock AITimer;
    const sf::Time AITime   = sf::seconds(0.1f);
    const float ballSpeed   = 400.f;
    float ballAngle         = 0.f; // to be changed later

    sf::Clock clock;
    bool isPlaying = false;

    while (window.isOpen())
    {
        // Lida com os eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Janela fechada ou tecla esc pressionada: exit
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }

            // Tecla de espaço pressioanda: play
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                // Eventos executados uma vez antes do jogo iniciar
                if (!isPlaying)
                {
                    // Começa o jogo
                    isPlaying = true;
                    clock.restart();

                    // Reseta a posição da bolinha
                    ball.setPosition(gameWidth / 2, gameHeight / 2);

                    // Reseta o ângulo da bolinha
                    do
                    {
                        // Confirma que o ângulo inicial da bolinha não é muito vertical
                        ballAngle = (std::rand() % 360) * 2 * pi / 360;
                    }
                    while (std::abs(std::cos(ballAngle)) < 0.7f);

                    // Toca o som no início do jogo
                    ballSound.play();

                }
            }
        }

        // Loop principal  do jogo
        if (isPlaying)
        {
            float deltaTime = clock.restart().asSeconds();


            // Move a bolinha
            float factor = ballSpeed * deltaTime;
            ball.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);

            // Checa as colisões da bolinha com as bordas da janela
            if (ball.getPosition().x - ballRadius < 0.f)
            {
                ballSound.play();
                ballAngle = -ballAngle + pi;
                ball.setPosition(ballRadius + 0.1f, ball.getPosition().y);
            }
            if (ball.getPosition().x + ballRadius > gameWidth)
            {
                ballSound.play();
                ballAngle = -ballAngle + pi;
                ball.setPosition(gameWidth - ballRadius - 0.1f, ball.getPosition().y);
            }
            if (ball.getPosition().y - ballRadius < 0.f)
            {
                ballSound.play();
                ballAngle = -ballAngle;
                ball.setPosition(ball.getPosition().x, ballRadius + 0.1f);
            }
            if (ball.getPosition().y + ballRadius > gameHeight)
            {
                ballSound.play();
                ballAngle = -ballAngle;
                ball.setPosition(ball.getPosition().x, gameHeight - ballRadius - 0.1f);
            }

        }

        // Limpa a janela
        window.clear(sf::Color::Black);

        if (isPlaying)
        {
            // Desenha a bolinha
            window.draw(ball);
        }
        else
        {
            // Desenha mensagem de pause
            window.draw(pauseMessage);
        }

        // Mostra as coisas na tela
        window.display();
    }

    return EXIT_SUCCESS;
}

