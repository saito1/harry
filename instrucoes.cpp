//
//  instrucoes.cpp
//  HarryApp
//
//  Created by Renata Sarmet Smiderle Mendes on 22/06/17.
//  Copyright © 2017 Renata Sarmet Smiderle Mendes. All rights reserved.
//

#include "instrucoes.h"

Instrucoes::instrucoes_opcoes Instrucoes::Mostrar(sf::RenderWindow& window)
{
    //Carrega a imagem do menu de um arquivo
    sf::Texture imagem;
    imagem.loadFromFile("imagens/instrucoes.jpg");
    
    sf::Sprite sprite;
    sprite.setTexture(imagem);
    
    std::string aux2 = std::to_string(get_k());
    aux2 = "imagens/tutorial" + aux2 + ".jpg";

    imagem_tutorial.loadFromFile(aux2);
    tutorial.setTexture(imagem_tutorial);
    tutorial.setOrigin(0, 0);
    tutorial.setPosition(165, 195);
    
    //Areas clicaveis
    
    //coordenadas do botao JOGAR
    Item_Instrucoes botao_jogar;
    botao_jogar.rect.top = 675;
    botao_jogar.rect.height = 745;
    botao_jogar.rect.left = 595;
    botao_jogar.rect.width = 750;
    botao_jogar.action = Jogar;
    
    //coordenadas do botao PROXIMO
    Item_Instrucoes botao_proximo;
    botao_proximo.rect.top = 595;
    botao_proximo.rect.height = 630;
    botao_proximo.rect.left = 710;
    botao_proximo.rect.width = 815;
    botao_proximo.action = Proximo;
    
    //coordenadas do botao ANTERIOR
    Item_Instrucoes botao_anterior;
    botao_anterior.rect.top = 600;
    botao_anterior.rect.height = 630;
    botao_anterior.rect.left = 200;
    botao_anterior.rect.width = 300;
    botao_anterior.action = Anterior;
    
    //Coordenadas do botao VOLTAR
    Item_Instrucoes botao_menu;
    botao_menu.rect.top = 680;
    botao_menu.rect.height = 750;
    botao_menu.rect.left = 260;
    botao_menu.rect.width = 395;
    botao_menu.action = Menu;
    
    itens_instrucao.push_back(botao_jogar);
    itens_instrucao.push_back(botao_menu);
	itens_instrucao.push_back(botao_proximo);
	itens_instrucao.push_back(botao_anterior);
    
    window.draw(sprite);
    window.draw(tutorial);
    window.display();
    
    return obter_resposta_instrucao(window);
}

void Instrucoes::set_k(int j)
{
    if((j >= 1) && (j < QUANT_INSTRUCOES))
        k = j;
}

void Instrucoes::proximo_k()
{
    if(k<QUANT_INSTRUCOES)
        k = k + 1;
}

void Instrucoes::anterior_k()
{
    if(k>1)
        k = k - 1;
}

int Instrucoes::get_k() const
{
    return k;
}

Instrucoes::instrucoes_opcoes Instrucoes::clique(int x, int y)
{
    std::list<Item_Instrucoes>::iterator it;
    
    for (it = itens_instrucao.begin(); it != itens_instrucao.end(); it++)
    {
        sf::Rect<int> item_da_instrucao = (*it).rect;
        if (item_da_instrucao.top < y && item_da_instrucao.height > y && item_da_instrucao.left < x && item_da_instrucao.width > x)
            return (*it).action;
    }
    
    return Nada;
}

Instrucoes::instrucoes_opcoes Instrucoes::obter_resposta_instrucao(sf::RenderWindow& window)
{
    sf::Event evento_instrucao;
    
    while (1 != 0)
    {
        while (window.pollEvent(evento_instrucao))
        {
            if (evento_instrucao.type == sf::Event::MouseButtonPressed)
                return clique(int(evento_instrucao.mouseButton.x), int(evento_instrucao.mouseButton.y));
            if (evento_instrucao.type == sf::Event::Closed)
                return Sair;
        }
    }
}