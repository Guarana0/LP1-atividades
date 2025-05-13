#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
using namespace std;


int posicaoBolaX(int menorX, int maiorX);
int posicaoBolaY(int menorY, int maiorY);

class Bola {
public:
    sf::CircleShape forma;
    sf::Color cor;
    float velocidadeX;
    float velocidadeY;

    // Construtor para inicializar a bola
    Bola(float raio, sf::Color corInicial, float velX, float velY, sf::RenderWindow& window)
        : forma(raio), cor(corInicial), velocidadeX(velX), velocidadeY(velY) {
        forma.setFillColor(cor);
        forma.setOrigin(raio, raio); // Define a origem no centro

        // Posição inicial aleatória
        float posXInicial = posicaoBolaX(raio, window.getSize().x - raio);
        float posYInicial = posicaoBolaY(raio, window.getSize().y - raio);
        forma.setPosition(posXInicial, posYInicial);
    }

    // Função para atualizar a posição da bola
    void posBola() {
        sf::Vector2f posicao = forma.getPosition();
        posicao.x += velocidadeX;
        posicao.y += velocidadeY;
        forma.setPosition(posicao);
    }

    // quando as bolas se colidem
    void colisao(const sf::RenderWindow& window) {
        sf::Vector2f posicao = forma.getPosition();
        float raio = forma.getRadius();

        if (posicao.x + raio > window.getSize().x || posicao.x - raio < 0) {
            velocidadeX = -velocidadeX;
        }
        if (posicao.y + raio > window.getSize().y || posicao.y - raio < 0) {
            velocidadeY = -velocidadeY;
        }
    }

    // Desenha a bola
    void desenhar(sf::RenderWindow& window) {
        window.draw(forma);
    }
};


// Calculo das posições da bola na tela
int posicaoBolaX(int menorX, int maiorX) {
    return rand() % (maiorX - menorX + 1) + menorX;
}

int posicaoBolaY(int menorY, int maiorY) {
    return rand() % (maiorY - menorY + 1) + menorY;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Aula 3 de SFML");
    srand(time(0)); // Inicializa a semente aleatória

    // Classe bola
    Bola bolinha(30.f, sf::Color::White, 0.5f, 0.25f, window);
    Bola bolinha2(50.f, sf::Color::Red, 0.6f, 0.3f, window);
    Bola bolinha3(10.f, sf::Color::Blue, 0.2f, 0.1f, window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        bolinha.posBola();
        bolinha.colisao(window);

        bolinha2.posBola();
        bolinha2.colisao(window);

        bolinha3.posBola();
        bolinha3.colisao(window);

        window.clear(sf::Color::Magenta);
        bolinha.desenhar(window);
        bolinha2.desenhar(window);
        bolinha3.desenhar(window);
        window.display();
    }

    return 0;
}
