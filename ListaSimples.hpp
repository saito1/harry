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
	P->set_next(NULL);
	P->set_id(x);
	//P->set_info(string(x) + ".png"); FAZER VERIFICACAO DA IMAGEM, NAO EH ATRAVES DO ID
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
		cout<<Paux->get_id()<<endl;
		Paux = Paux->get_next();
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
	while(Paux->get_next()!=NULL){
		Paux = Paux->get_next();
	}
	Paux->set_next(Paux2);
	Paux2->set_next(NULL);
	Paux2->set_id(x);
	//INSERIR IMAGEM NO INFO TAMBEM
}

void ListaSimples::ProcuraRemove(int x, bool DeuCerto){
	Nodetype *Paux;
	if(Vazia()){
		DeuCerto = false;
	}
	else if(P->get_id()==x){
		Paux = P;
		P = P->get_next();
		delete Paux;
	}
	else{
		Paux = P;
		while((Paux->get_next()->get_id()!=x)&&(Paux->get_next()!=NULL)){
			Paux = Paux->get_next();
		}
		if(Paux->get_next()!=NULL){
			Remove(Paux, DeuCerto);
		}
	}
}

void ListaSimples::Remove(Nodetype *Premove, bool DeuCerto){
	Nodetype *Paux2;
	Paux2 = Premove;
	Premove = Premove->get_next();
	Paux2->set_next(Paux2->get_next()->get_next());
	delete Premove;
	DeuCerto = true;
}


#endif
