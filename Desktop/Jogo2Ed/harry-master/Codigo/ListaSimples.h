#ifndef LISTASIMPLES
#define LISTASIMPLES_H value
#endif
using namespace std;
#include <iostream>
// Nó - Representa um elemento da lista

struct node {
    int info;
    struct node *next;
};

typedef struct node Node;
typedef Node *Ptrnode;

//implementação da classe Lista

class ListaSimples
{
public:
	Node *P;
public:
	ListaSimples();
	//~ListaSimples();

	void Cria();
	bool Vazia();
	void ExibeLista();	
	void Insere(int x);
	void InsereADireita(int x);
};


// void Insere(int x, bool &DeuCerto){
// 	if(P==NULL){
// 		P = x;
// 		DeuCerto = true;
// 	}else{
// 		InsereADireita(x,&DeuCerto);
// 	}
// }

// void InsereADireita(int x, bool &DeuCerto){
// 	Paux = new Node();
// 	Paux = P->next;
// 	Paux->next = NULL;
// 	Paux->info = x;
// }

// void Lista<Gen>::cria(){
//     struct Node<Gen> *Paux = new Node<Gen>();
//     header=Paux;
//     header->esq=header;
//     header->dir=header;
//     Paux=NULL;
//     delete Paux;
// }