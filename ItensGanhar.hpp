#ifndef ITENSGANHAR_HPP
#define ITENSGANHAR_HPP

#include <iostream>
#include "ListaSimples.hpp"
#include "Nodetype.hpp"
using namespace std;

class ItensGanhar : public ListaSimples{
public:
    ItensGanhar();
    ~ItensGanhar();
    void InicializaItensGanhar(ListaSimples *listaGeral);
    void ProcuraRemove(string info, bool &DeuCerto, ItensGanhar *destruidos, ListaSimples *todosItens);
};

ItensGanhar::ItensGanhar() : ListaSimples(){
    
}

ItensGanhar::~ItensGanhar(){
    
}

void ItensGanhar::InicializaItensGanhar(ListaSimples *listaGeral){
    int i;
    Nodetype *no;
    Nodetype *noPtr;

    for (i = 1; i<=6; i++)
    {
        no = listaGeral->PegaElementoN(i);
        noPtr = new Nodetype();
        noPtr->CopiaNode(no);
        noPtr->carregar(noPtr->get_info());

        Insere(noPtr);
    }
    
}


void ItensGanhar::ProcuraRemove(string info, bool &DeuCerto, ItensGanhar *destruidos, ListaSimples * todosItens){
    
    Nodetype *no, *noPtr = new Nodetype();
    no = todosItens->PegaElementoInfo(info, DeuCerto);
    no -> ExibeInformacoes();
    noPtr->CopiaNode(no);
    noPtr->set_id(destruidos->QuantidadeElementos()+1);
    noPtr->carregar(noPtr->get_info());
    noPtr->ExibeInformacoes();
    
    ListaSimples::ProcuraRemove(info,DeuCerto);
    if(DeuCerto){
        destruidos->Insere(noPtr);
    }    
}

#endif /* ItensGanhar_hpp */
