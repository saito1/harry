#include "ListaSimples.h"
#include <iostream>
using namespace std;

ListaSimples::ListaSimples(){
	P = NULL;
}

void ListaSimples::Cria(){
	Node *Paux = new Node();
	P = Paux;
	P->next = NULL;
}

bool ListaSimples::Vazia(){
	if(P==NULL){
		return true;
	}else{
		return false;
	}
}

void ListaSimples::ExibeLista(){
	Node *Paux = new Node();
	Paux = P;
	while(Paux!=NULL){
		cout<<Paux->info<<endl;
		Paux = Paux->next;
	} 
}

void ListaSimples::Insere(int x){
	if(Vazia()==true){
		P->info = x;
		P->next = NULL;
	}else{
		InsereADireita(x);
	}
}

void ListaSimples::InsereADireita(int x){
	Node *Paux = new Node();
	Node *Paux2 = new Node();
	Paux = P;
	while(Paux->next!=NULL){
		Paux = Paux->next;
	}
	Paux->next = Paux2;
	Paux2->next = NULL;
	Paux2->info = x;
}	
// ListaSimples *newListaSimples(int info) {
//     ListaSimples *p;
//     p = new ListaSimples();
//     p->info = info;
//     p->next = NULL;
//     return p;
// }

// /* Operações sobre um nó */
// Node *newNode(int n) {
//     Node *q;
//     q = new Node();
//     q->data = n;
//     q->next = NULL;
//     return q;
// }

// void freeNode(Node *p) {
//     delete(p);
//     return;
// }

// Node *printNode(Node *p) {
//     cout << p->data;
// }