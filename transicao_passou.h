#ifndef TRANSICAO_PASSOU_H
#define TRANSICAO_PASSOU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "feitico.h" 

using namespace std;

class transicao_passou
{
public:
	transicao_passou();

	void Mostrar(sf::RenderWindow& renderWindow);
    void MostrarHarry(sf::RenderWindow& renderWindow);
	void set_meta(int meta);
	int get_meta() const;

private:
	sf::Text metaText;
	int meta;
};
#endif
