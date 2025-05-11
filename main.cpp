#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Aula 2 de SFML");
    sf::CircleShape bolinha(30.f);
    bolinha.setFillColor(sf::Color::White);
    bolinha.setOrigin(bolinha.getRadius(), bolinha.getRadius()); // Define a origem no centro
    bolinha.setPosition(400, 300); // Posição inicial no centro da janela

    // Variáveis de velocidade nos eixos X e Y
    float velocidadeX = 0.5f;
    float velocidadeY = 0.5f;

    sf::SoundBuffer somBolinha;
    if (!somBolinha.loadFromFile("pongblip.wav")) {
            std::cerr << "Erro ao carregar o som de quique.\n";
            return -1;
        }

    sf::Sound quique;
    quique.setBuffer(somBolinha);
    quique.setVolume(40.0f); // Define um volume para o som
    int quantiQuiques = 0;


    while (window.isOpen()) {
        sf::Event evento;
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Atualiza a posição da bolinha
        sf::Vector2f posicao = bolinha.getPosition();
        posicao.x += velocidadeX;
        posicao.y += velocidadeY;
        bolinha.setPosition(posicao);

        bool quicou = false;

        // Verifica as colisões com as bordas da janela (eixo X)
        if (posicao.x + bolinha.getRadius() > window.getSize().x || posicao.x - bolinha.getRadius() < 0) {
            velocidadeX = -velocidadeX; // Inverte a direção no eixo X
            if (!quicou) {
            	quique.play();
                quicou = true;
                quantiQuiques++;
            }
        }

        // Verifica as colisões com as bordas da janela (eixo Y)
        if (posicao.y + bolinha.getRadius() > window.getSize().y || posicao.y - bolinha.getRadius() < 0) {
            velocidadeY = -velocidadeY; // Inverte a direção no eixo Y
            if (!quicou) {
            	quique.play();
            	quicou = true;
            	quantiQuiques++;
            }
        }

        if (quantiQuiques > 20) {
        	quique.setPitch(70.f);
        }

        window.clear(sf::Color::Blue);
        window.draw(bolinha);
        window.display();
    }

    return 0;
}
