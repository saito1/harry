#ifndef menu_h
#define menu_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "ResourcePath.hpp"

using namespace std;

class Menu
{
public:
    enum menu_inicial { Nada, Sair, Jogar, Instrucoes };
    
    struct Item_Menu
    {
    public:
        sf::Rect<int> rect;
        menu_inicial action;
    };
    
    menu_inicial Mostrar(sf::RenderWindow& window);
    
private:
    menu_inicial obter_resposta_menu(sf::RenderWindow& window);
    menu_inicial clique(int x, int y);
    std::list<Item_Menu> itens_menu;
};
#endif // !menu_h