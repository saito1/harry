#include "tela_inicial.h"

void Tela_Inicial::Mostrar(sf::RenderWindow & renderWindow)
{
    sf::Texture imagem;
    if (imagem.loadFromFile("imagens/inicial.jpg") != true)
        return;
    
    sf::Sprite sprite;
    sprite.setTexture(imagem);
    
    renderWindow.draw(sprite);
    renderWindow.display();
    
    sf::Event evnt;
    while (true)
    {
        while (renderWindow.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::EventType::MouseButtonPressed || evnt.type == sf::Event::EventType::Closed)
                return;
        }
        
    }
}