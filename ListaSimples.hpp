#ifndef LISTASIMPLES_HPP
#define LISTASIMPLES_HPP

#include "Nodetype.hpp"
#include <iostream>
using namespace std;

//implementação da classe Lista

class ListaSimples
{
public:
	ListaSimples();
	//~ListaSimples();

	void Cria(int x);
	bool Vazia();
	void ExibeLista();
	void Insere(int x);
	void InsereADireita(int x);
	void ProcuraRemove(int x, bool DeuCerto); //DEPOIS PARAMETRO DE BUSCA SERA ALTERADO
	void Remove(Nodetype *Premove, bool DeuCerto);
private:
	Nodetype *P;
};


//ARQUIVO .CPP

ListaSimples::ListaSimples(){
	P = NULL;
}

void ListaSimples::Cria(int x){
	P = new Nodetype();
	P->next = NULL;
	P->id = x;
	//P->info = string(x) + ".png"; FAZER VERIFICACAO DA IMAGEM, NAO EH ATRAVES DO ID
}

bool ListaSimples::Vazia(){
	if(P==NULL){
		return true;
	}else{
		return false;
	}
}

void ListaSimples::ExibeLista(){
	Nodetype *Paux;
	Paux = P;
	while(Paux!=NULL){
		cout<<Paux->id<<endl;
		Paux = Paux->next;
	}
}

void ListaSimples::Insere(int x){
	if(Vazia()==true){
		Cria(x);
	}else{
		InsereADireita(x);
	}
}

void ListaSimples::InsereADireita(int x){
	Nodetype *Paux;
	Nodetype *Paux2 = new Nodetype();
	Paux = P;
	while(Paux->next!=NULL){
		Paux = Paux->next;
	}
	Paux->next = Paux2;
	Paux2->next = NULL;
	Paux2->id = x;
	//INSERIR IMAGEM NO INFO TAMBEM
}

void ListaSimples::ProcuraRemove(int x, bool DeuCerto){
	Nodetype *Paux;
	if(Vazia()){
		DeuCerto = false;
	}
	else if(P->id==x){
		Paux = P;
		P = P->next;
		delete Paux;
	}
	else{
		Paux = P;
		while((Paux->next->id!=x)&&(Paux->next!=NULL)){
			Paux = Paux->next;
		}
		if(Paux->next!=NULL){
			Remove(Paux, DeuCerto);
		}
	}
}

void ListaSimples::Remove(Nodetype *Premove, bool DeuCerto){
	Nodetype *Paux2;
	Paux2 = Premove;
	Premove = Premove->next;
	Paux2->next = Paux2->next->next;
	delete Premove;
	DeuCerto = true;
}


#endif
