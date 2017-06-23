#ifndef LISTASIMPLES_HPP
#define LISTASIMPLES_HPP

#include "Nodetype.hpp"
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

//implementação da classe Lista Simples

class ListaSimples
{
public:
	ListaSimples();
	//~ListaSimples();

	void Cria(Nodetype *x);
	bool Vazia();
	void ExibeLista();
	void Insere(Nodetype *x);
	void InsereADireita(Nodetype *x);
	void ProcuraRemove(int x, bool &DeuCerto); 
	void ProcuraRemove(string x, bool &DeuCerto);
    void DeletaTudo();
    
    
	Nodetype* PegaElementoAleatorio() const; // pega um elemento na lista aleatorio
    Nodetype* PegaElementoAleatorioTodosTipoX(int x) const; // pega um elemento aleatorio do tipo X
	Nodetype* PegaElementoN(int n) const; // pega o N-esimo elemento da lista
	int QuantidadeElementos() const; // conta a quantidade de elementos da lista
    Nodetype* PegaElementoInfo(string info, bool &DeuCerto) ; // pega o elemento da lista pelo ID

private:
	Nodetype *P;
	void Remove(Nodetype *Premove, bool &DeuCerto); // metodo privado pois quem deve ser chamado eh o procura remove
};


//ARQUIVO .CPP

ListaSimples::ListaSimples(){
	P = NULL;
}

void ListaSimples::Cria(Nodetype *x){
	P = new Nodetype();
	P = x;
	P->set_next(NULL);
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
		cout<<"ID: "<<Paux->get_id();
		cout << " ,Info: " << Paux->get_info();
		cout << " e Tipo: " << Paux->get_tipo() << endl;
		Paux = Paux->get_next();
	}

}

void ListaSimples::Insere(Nodetype *x){
	if(Vazia()==true){
		Cria(x);
	}else{
		InsereADireita(x);
	}
}

void ListaSimples::InsereADireita(Nodetype *x){
	Nodetype *Paux;
	Nodetype *Paux2 = new Nodetype();
	Paux2 = x;
	Paux2->set_next(NULL);
	Paux = P;
	while(Paux->get_next()!=NULL){
		Paux = Paux->get_next();
	}
	Paux->set_next(Paux2);
}

void ListaSimples::ProcuraRemove(int x, bool &DeuCerto){
	Nodetype *Paux;
	if(Vazia()){
		DeuCerto = false;
	}
	else if(P->get_id()==x){
		DeuCerto = true;
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

inline void ListaSimples::ProcuraRemove(string x, bool & DeuCerto)
{
	Nodetype *Paux;
	if (Vazia()) {
		DeuCerto = false;
	}
	else if (P->get_info() == x) {
		DeuCerto = true;
		Paux = P;
		P = P->get_next();
		delete Paux;
	}
	else {
		Paux = P;
		while ((Paux->get_next()->get_info() != x) && (Paux->get_next() != NULL)) {
			Paux = Paux->get_next();
		}
		if (Paux->get_next() != NULL) {
			Remove(Paux, DeuCerto);
		}
	}
}

void ListaSimples::Remove(Nodetype *Premove, bool &DeuCerto){
	Nodetype *Paux2;
	DeuCerto = true;
	Paux2 = Premove;
	Premove = Premove->get_next();
	Paux2->set_next(Paux2->get_next()->get_next());
	delete Premove;
}

void ListaSimples::DeletaTudo(){
    bool ok;
    while(QuantidadeElementos()!=0){
        ProcuraRemove(P->get_id(), ok);
    }
}

int ListaSimples::QuantidadeElementos() const {
	Nodetype *Paux;
	Paux = P;
	int q = 0;
	while(Paux!=NULL){
		q += 1;
		Paux = Paux->get_next();
	}

	return q;
}

Nodetype* ListaSimples::PegaElementoAleatorio() const{
	Nodetype *Paux;
	Paux = P;
	int r,i;
    if(QuantidadeElementos()>1)
        r = (rand() % (QuantidadeElementos()-1) + 1); //TA DANDO ERRO AQUI QUANDO CHEGA LA PRO NIVEL 5 OU 6, CONFERIR
    else
        r = 1;

	for(i=1;i<r;i++){
		Paux = Paux->get_next();
	}
    
	return Paux;
}


Nodetype* ListaSimples::PegaElementoAleatorioTodosTipoX(int x) const{
    
    Nodetype *Paux;
    Paux = P;
    int r,i;
    
    switch (x) {
        case 1:
            r = (rand() % 7 + 6);
            break;
        case 2:
            r = (rand() % 7 + 13);
            break;
        case 3:
             r = (rand() % 6);
            break;
        case 4:
            r = (rand() % 6 + 20);
            break;
            
        case 5:
            r = (rand() % (QuantidadeElementos()-8) + 8); // NAO INSERE HORCRUX NEM VOLDEMORT
            break;
        default:
            r = 0; // should never happen
            break;
    }
    

    for(i=1;i<r;i++){
        Paux = Paux->get_next();
    }
    
    return Paux;
}

Nodetype* ListaSimples::PegaElementoN(int n) const{
	Nodetype *Paux;
	Paux = P;
	int i;

	for(i=1;i<n;i++){
		Paux = Paux->get_next();
	}

	return Paux;
}

Nodetype* ListaSimples::PegaElementoInfo(string info, bool &DeuCerto) {
    Nodetype *Paux;
    if (Vazia()) {
        DeuCerto = false;
    }

    else if (P->get_info() == info) {
        DeuCerto = true;
        return P;
    }
    else {
        Paux = P;
        while ((Paux->get_next() != NULL) && (Paux->get_next()->get_info() != info)) {
            Paux = Paux->get_next();
        }
        if (Paux->get_next() != NULL) {
            DeuCerto = true;
            return Paux->get_next();
        }
        else{
            DeuCerto = false;
        }
    }
    
    return NULL;
    
}

#endif
