#ifndef perdeu_h
#define perdeu_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
 

using namespace std;

class Perdeu
{
public:
    enum perdeu { Nada, Sair, Jogar_Novamente };
    
    perdeu Mostrar(sf::RenderWindow& window);
    
    struct item_perdeu
    {
    public:
        sf::Rect<int> rect;
        perdeu action;
    };
    
private:
    perdeu obter_resposta_perdeu(sf::RenderWindow& window);
    perdeu clique(int x, int y);
    std::list<item_perdeu> itens_perdeu;
};
#endif // !perdeu_h