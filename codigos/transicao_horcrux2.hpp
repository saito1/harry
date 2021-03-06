#ifndef TRANSICAO_HORCRUX2_HPP
#define TRANSICAO_HORCRUX2_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ItensGanhar.hpp"
#include "Nodetype.hpp"

using namespace std;

class transicao_horcrux2{
public:
    void MostrarHorcrux(sf::RenderWindow& window, ItensGanhar* destruidos);
};


void transicao_horcrux2::MostrarHorcrux(sf::RenderWindow & renderWindow, ItensGanhar* destruidos)
{
    float i, j;
    Nodetype *Paux;
    sf::Texture imagem;
    if (imagem.loadFromFile("imagens/transicao2.jpg") != true)
        return;
    
    sf::Sprite sprite;
    sprite.setTexture(imagem);
    renderWindow.draw(sprite);
    
    
    if (destruidos->QuantidadeElementos() > 0)
        Paux = destruidos->PegaElementoN(1);
    
    else
        Paux = NULL;
    
    i = 0;
    j = 0;
    
    while (Paux != NULL)
    {
        if(Paux->get_id() % 2 != 0)
        {
            Paux->set_posicao(80 + i, 110);
            i += 100;
        }
        else
        {
            Paux->set_posicao(80 + j, 220);
            j += 100;
        }
        Paux->desenhar(renderWindow); 
        Paux = Paux->get_next();
    }

    renderWindow.display();
    
    sf::Clock clock;
    
    while (true)
    {
        if (clock.getElapsedTime().asSeconds() > 3)
        {
            return;
        }
    }
}


#endif /* transicao_horcrux2_hpp */
