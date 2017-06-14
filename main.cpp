#include <iostream>
#include "ListaSimples.hpp"
#include "Nodetype.hpp"

using namespace std;

int main()
{
    ListaSimples plano, todosItens, itensGanhar;
   // Nodetype *no1, *no2, *no3, *no4, *no5, *no = new Nodetype();
   // Nodetype *no;
    Nodetype *no1 = new Nodetype(), *no2 = new Nodetype();
   // bool ok = false;
    //int i;


//    no1->set_id(1);
//    no1->set_info("1.png");
//    no1->set_next(NULL);


    cout << "Inserindo e exibindo todosItens:" << endl;

	no1->set_id(1);
	cout << "id no1 = " << no1->get_id() << endl;
	todosItens.Insere(no1);

	no2->set_id(2);
	cout << "id no2 = " << no2->get_id() << endl;
	todosItens.Insere(no2);

//	no3->set_id(3);
//	todosItens.Insere(no3);
//
//	no4->set_id(4);
//	todosItens.Insere(no4);
//
//	no5->set_id(5);
//	todosItens.Insere(no5);


    todosItens.ExibeLista(); // TEM ALGO ERRADO COM EXIBE LISTA OU INSERE?
//
//    cout << "Quantidade de elementos todosItens: " << todosItens.QuantidadeElementos() << endl;
//
//    cout << "Removendo..." << endl;
//
//    todosItens.ProcuraRemove(7, ok);
//
//    cout << "Quantidade de elementos todosItens: " << todosItens.QuantidadeElementos() << endl;
//
//
//    cout << "Quantidade de elementos plano: " << plano.QuantidadeElementos() << endl;
//
//    cout << "Pegando um elemento aleatorio: " ;
//
//    no = todosItens.PegaElementoAletorio();
//
//    cout << no->get_id() << endl;
//
//    cout << "Exibindo novamente: ";
//
//    todosItens.ExibeLista();
//
//    cout << "Inserindo elemento em plano: ";
//
//    plano.Insere(no);
//
//    plano.ExibeLista();


    return 0;
}

