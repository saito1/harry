#ifndef LISTAPLANO_HPP
#define LISTAPLANO_HPP

#include "ListaSimples.hpp"
#include "Nodetype.hpp"
#include <iostream>
using namespace std;

//implementação da classe Lista Plano

class ListaPlano: public ListaSimples{
public:
	ListaPlano();
	//~ListaPlano();
	void InsereNplano(int n, ListaSimples *listaGeral);

private:

};


//ARQUIVO .CPP
ListaPlano::ListaPlano(){

}

void ListaPlano::InsereNplano(int n, ListaSimples *listaGeral){
	int i;
	Nodetype *no;
	for(i=0;i<n;i++){
		no = listaGeral->PegaElementoAletorio();
		cout << "AQUI INSERINDO " << no->get_id() << endl;;
		Insere(no);
	}
}


#endif
