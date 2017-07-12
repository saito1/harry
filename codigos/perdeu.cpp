#include "perdeu.h"

Perdeu::perdeu Perdeu::Mostrar(sf::RenderWindow & renderWindow)
{
    sf::Texture imagem;
    imagem.loadFromFile("imagens/perdeu.jpg");
    
    sf::Sprite sprite;
    sprite.setTexture(imagem);
    
    //Coordenadas do botao JOGAR
    item_perdeu botao_jogar;
    botao_jogar.rect.top = 590;
    botao_jogar.rect.height = 640;
    botao_jogar.rect.left = 45;
    botao_jogar.rect.width = 340;
    botao_jogar.action = Jogar_Novamente;
    
    //Coordenadas do botao SAIR
    item_perdeu botao_sair;
    botao_sair.rect.top = 670;
    botao_sair.rect.height = 720;
    botao_sair.rect.left = 155;
    botao_sair.rect.width = 230;
    botao_sair.action = Sair;
    
    itens_perdeu.push_back(botao_jogar);
    itens_perdeu.push_back(botao_sair);
    
    renderWindow.draw(sprite);
    renderWindow.display();
    
    return obter_resposta_perdeu(renderWindow);
}

Perdeu::perdeu Perdeu::clique(int x, int y)
{
    std::list<item_perdeu>::iterator it;
    
    for (it = itens_perdeu.begin(); it != itens_perdeu.end(); it++)
    {
        sf::Rect<int> item_do_perdeu = (*it).rect;
        if (item_do_perdeu.top < y && item_do_perdeu.height > y && item_do_perdeu.left < x && item_do_perdeu.width > x)
            return (*it).action;
    }
    
    return Nada;
}

Perdeu::perdeu Perdeu::obter_resposta_perdeu(sf::RenderWindow& window)
{
    sf::Event evento_perdeu;
    
    while (1 != 0)
    {
        while (window.pollEvent(evento_perdeu))
        {
            if (evento_perdeu.type == sf::Event::MouseButtonPressed)
                return clique(int(evento_perdeu.mouseButton.x), int(evento_perdeu.mouseButton.y));
            if (evento_perdeu.type == sf::Event::Closed)
                return Sair;
        }
    }
}
