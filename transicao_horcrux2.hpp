//
//  transicao_horcrux2.hpp
//  HarryApp
//
//  Created by Renata Sarmet Smiderle Mendes on 22/06/17.
//  Copyright © 2017 Renata Sarmet Smiderle Mendes. All rights reserved.
//

#ifndef TRANSICAO_HORCRUX2_HPP
#define TRANSICAO_HORCRUX2_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"
#include "ItensGanhar.hpp"
#include "Nodetype.hpp"

using namespace std;

class transicao_horcrux2{
public:
    void MostrarHorcrux(sf::RenderWindow& window, ItensGanhar* destruidos);
};


void transicao_horcrux2::MostrarHorcrux(sf::RenderWindow & renderWindow, ItensGanhar* destruidos)
{
    
    
    cout << endl << endl << "TO AQUI NO TRANSICAO E TENHO " << endl << endl;
    destruidos->ExibeLista();
    
    int i, j;
    Nodetype *Paux;
    sf::Texture imagem;
    if (imagem.loadFromFile(resourcePath() + "transicao2.jpg") != true)
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
        if(Paux->get_id() % 2 == 0)
        {
            Paux->set_posicao(125 + i, 145);
            i += 100;
        }
        else
        {
            Paux->set_posicao(125 + j, 265);
            j += 100;
        }
        Paux->desenhar(renderWindow); 
        cout << endl << " ERA PRA EU TER DESENHADO " << Paux->get_info() << endl;
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