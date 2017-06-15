#include <iostream>
#include "ListaSimples.hpp"
#include "Nodetype.hpp"
#include "ListaPlano.hpp"

using namespace std;

int main()
{
    ListaSimples todosItens, itensGanhar;
    ListaPlano plano;
    Nodetype *no;
    Nodetype *no1 = new Nodetype(), *no2 = new Nodetype(), *no3 = new Nodetype();
    bool ok = false;
    //int i;


    //Inserindo Nodes na Lista todosItens
    cout << "Inserindo e listando os elemtnso de todosItens" << endl;

	no1->set_id(1);
	no1->set_info("1.png");
	todosItens.Insere(no1);

	no2->set_id(2);
	no2->set_info("2.png");
	todosItens.Insere(no2);

	no3->set_id(3);
	no3->set_info("3.png");
	todosItens.Insere(no3);


	//Exibindo todos os itens
    todosItens.ExibeLista();

    cout << "Quantidade de elementos todosItens: " << todosItens.QuantidadeElementos() << endl;

//    cout << "Removendo..." << endl;
//
//    todosItens.ProcuraRemove(todosItens.PegaElementoAletorio()->get_id(), ok);
//
//    cout << "Quantidade de elementos todosItens: " << todosItens.QuantidadeElementos() << endl << endl;


    // Agora sobre o plano


    cout << "Quantidade de elementos plano: " << plano.QuantidadeElementos() << endl;

//    cout << "Pegando um elemento aleatorio: " ;
//
//    no = todosItens.PegaElementoAletorio();
//
//    cout << no->get_id() << endl;
//
//
//    //Inserindo na lista plano
//    cout << "Inserindo elemento em plano: " << endl;
//
//    plano.Insere(no);

    cout << "Inserindo... " << endl;

    plano.InsereNplano(10, &todosItens);


    //Exibindo a lista plano
    plano.ExibeLista();

    cout << "Quantidade de elementos plano: " << plano.QuantidadeElementos() << endl;


    return 0;
}

