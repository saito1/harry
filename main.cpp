#include <iostream>
#include "ListaSimples.hpp"
#include "Nodetype.hpp"

#include <time.h>
#include <ctime>

using namespace std;


void InsereNplano(int n, ListaSimples *plano, ListaSimples *listaGeral){
	int i;
	Nodetype *no;
	Nodetype *noPtr;
	for(i=0;i<n;i++){
		no = listaGeral->PegaElementoAleatorio();
		noPtr = new Nodetype();
		noPtr->CopiaNode(no);
		plano->Insere(noPtr);
	}
}


int main()
{
    ListaSimples plano, todosItens, itensGanhar;
   // Nodetype *no;
    Nodetype *no1 = new Nodetype(), *no2 = new Nodetype(), *no3 = new Nodetype(), *no4 = new Nodetype(), *no5 = new Nodetype();
   // bool ok = false;
   // int i;

    srand(time(NULL));

    //Inserindo Nodes na Lista todosItens
//AQUI    cout << "Inserindo e listando os elementos de todosItens" << endl;

	no1->set_id(1);
	no1->set_info("1.png");
	todosItens.Insere(no1);

	no2->set_id(2);
	no2->set_info("2.png");
	todosItens.Insere(no2);

	no3->set_id(3);
	no3->set_info("3.png");
	todosItens.Insere(no3);

	no4->set_id(4);
	no4->set_info("4.png");
	todosItens.Insere(no4);

	no5->set_id(5);
	no5->set_info("5.png");
	todosItens.Insere(no5);


	//Exibindo todos os itens
	cout << "Todos os itens: " << endl;
	todosItens.ExibeLista();

	cout << "Quantidade de elementos todosItens: " << todosItens.QuantidadeElementos() << endl << endl;


//	 Removendo item
//    cout << "Removendo..." << endl;
//
//    todosItens.ProcuraRemove(todosItens.PegaElementoAletorio()->get_id(), ok);
//
//    cout << "Quantidade de elementos todosItens: " << todosItens.QuantidadeElementos() << endl << endl;



	// Agora sobre o plano


	cout << "Quantidade de elementos plano: " << plano.QuantidadeElementos() << endl;


//    //Inserindo na lista plano

	cout << "Inserindo... " << endl;

    InsereNplano(10, &plano, &todosItens);

    //Exibindo a lista plano
   plano.ExibeLista();

   cout << "Quantidade de elementos plano: " << plano.QuantidadeElementos() << endl;


    return 0;
}

