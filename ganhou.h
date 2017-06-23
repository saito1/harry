#ifndef ganhou_h
#define ganhou_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
 

using namespace std;

class Ganhou
{
public:
    enum ganhou { Nada, Sair, Jogar_Novamente };
    
    ganhou Mostrar(sf::RenderWindow& window);
    
    struct item_ganhou
    {
    public:
        sf::Rect<int> rect;
        ganhou action;
    };
    
private:
    ganhou obter_resposta_ganhou(sf::RenderWindow& window);
    ganhou clique(int x, int y);
    std::list<item_ganhou> itens_ganhou;
};
#endif // !ganhou_h