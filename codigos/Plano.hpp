#ifndef Plano_hpp
#define Plano_hpp

#include <iostream>
#include "ListaSimples.hpp"
#include "Nodetype.hpp"
#include "feitico.h"
using namespace std;

class Plano : public ListaSimples{
public:
    Plano();
    ~Plano();
    void InsereNplano(int n, ListaSimples * listaGeral, ItensGanhar *itensGanhar);
	void InsereFaseFinal(ListaSimples* listaGeral);
    void desenha_todos_plano(sf::RenderWindow& window);
private:
	float x;
	float a, b;
	int contador;
};

#endif /* Plano_hpp */


Plano::Plano() : ListaSimples(){
	x = 1.0;
	a = 1.0;
	b = 1.0;
}

Plano::~Plano(){
    
}

void Plano::InsereNplano(int n, ListaSimples * listaGeral, ItensGanhar *itensGanhar)
{
    int i, qtd = 0, r;
	float _x, _y;

    Nodetype *no;
    Nodetype *noPtr;
    
    // 50% de chance de ter 1 horcrux na fase e 50% de chance de nao ter nenhuma (pode ser alterado, apenas mudando o 2 ali)
	r = (rand() % 2);
    if(r==0){
        // Inserindo horcrux
        no = itensGanhar->PegaElementoAleatorio();
        noPtr = new Nodetype();
        noPtr->CopiaNode(no);
        noPtr->set_id(0);
        noPtr->carregar(noPtr->get_info());
        _x = (rand() % 919);
        _y = (rand() % 300 + 321);
        noPtr->set_posicao(_x, _y);
        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
        
        Insere(noPtr);
        qtd = 1;
    }
    
    for (i = qtd; i<n; i++)
    {
        no = listaGeral->PegaElementoAleatorioTodosTipoX(5);
        noPtr = new Nodetype();
        noPtr->CopiaNode(no);
        noPtr->set_id(i);
        noPtr->carregar(noPtr->get_info());
        _x = (rand() % 919);
        _y = (rand() % 300 + 321);
        noPtr->set_posicao(_x, _y);

		if (noPtr->get_info() == "imagens/pomo1.png")
		{
			if (noPtr->get_x() > 924)
			{
				noPtr->set_posicao(noPtr->get_x() - 100, noPtr->get_y());
			}
			if (noPtr->get_x() < 100)
			{
				noPtr->set_posicao(noPtr->get_x() + 100, noPtr->get_y());
			}
		}

        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
        
        Insere(noPtr);
    }

	
}


void Plano::desenha_todos_plano(sf::RenderWindow& window)
{
	Nodetype *Paux;
	float _x, _y;

    if (QuantidadeElementos() > 0)
        Paux = PegaElementoN(1);
    else
        Paux = NULL;

    while (Paux != NULL)
    {

		if (Paux->get_info() == "imagens/pomo1.png")
		{
			Paux->move(x, 0);
			
			if (Paux->get_x() >= 924 || Paux->get_x() <= 100)
			{
				x = -x;
			}
		}

		if (Paux->get_info() == "imagens/voldemort.png")
		{
			contador += 1;
			if ((contador == 100) && (feitico::lancado == false)) {
				_x = (rand() % 919);
				_y = (rand() % 300 + 321);
				Paux->set_posicao(_x, _y);
				contador = 0;
			}
			else if (contador == 100)
				contador = 0;
		}

        Paux->desenhar(window);
        Paux = Paux->get_next();
    }
}

void Plano::InsereFaseFinal(ListaSimples* listaGeral)
{
	float _x, _y;
	Nodetype *noPtr;
	Nodetype *no;
	contador = 0;

	no = listaGeral->PegaElementoN(7); //PEGA VOLDEMORT
	noPtr = new Nodetype();
	noPtr->CopiaNode(no);
	noPtr->set_id(0);
	noPtr->carregar(noPtr->get_info());
	_x = (rand() % 919);
	_y = (rand() % 300 + 321);
	noPtr->set_posicao(_x, _y);
	noPtr->set_origem(noPtr->_sprite.getLocalBounds().width / 2, noPtr->_sprite.getLocalBounds().height / 2);

	Insere(noPtr);
}