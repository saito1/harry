//
//  instrucoes.hpp
//  HarryApp
//
//  Created by Renata Sarmet Smiderle Mendes on 22/06/17.
//  Copyright © 2017 Renata Sarmet Smiderle Mendes. All rights reserved.
//

#ifndef INSTRUCOES_H
#define INSTRUCOES_H

#include <stdio.h>

#define QUANT_INSTRUCOES 12

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
 
#include <list>

class Instrucoes
{
public:
    enum instrucoes_opcoes { Nada, Menu, Jogar , Sair, Proximo, Anterior};
    
    struct Item_Instrucoes
    {
    public:
        sf::Rect<int> rect;
        instrucoes_opcoes action;
    };
    
    instrucoes_opcoes Mostrar(sf::RenderWindow& window);
    
    void set_k(int j);
    void proximo_k();
    void anterior_k();
    int get_k() const;
    
private:
    instrucoes_opcoes obter_resposta_instrucao(sf::RenderWindow& window);
    instrucoes_opcoes clique(int x, int y);
    std::list<Item_Instrucoes> itens_instrucao;
    
    sf::Sprite tutorial;
    sf::Texture imagem_tutorial;
    std::string nome_arquivo;
    bool carregou;
    int k;
};
#endif // !instrucoes_h
