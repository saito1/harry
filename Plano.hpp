#ifndef Plano_hpp
#define Plano_hpp

#include <iostream>
#include "ListaSimples.hpp"
#include "Nodetype.hpp"
using namespace std;

class Plano : public ListaSimples{
public:
    Plano();
    ~Plano();
    void InsereNplano(int n, ListaSimples * listaGeral, ItensGanhar *itensGanhar);
};

#endif /* Plano_hpp */


Plano::Plano() : ListaSimples(){
    
}

Plano::~Plano(){
    
}

void Plano::InsereNplano(int n, ListaSimples * listaGeral, ItensGanhar *itensGanhar)
{
    int i, x, y, qtd = 0, r;
    // int restantes = n, qtd, maisI;
    Nodetype *no;
    Nodetype *noPtr;
    
    // 33% de chance de ter 1 horcrux na fase e 66% de chance de nao ter nenhuma (pode ser alterado, apenas mudando o 2 ali)
    //r = (rand() % 2); // DESCOMENTAR ESSE;
    r = 0; // MUDAR ISSO DEPOIS
    if(r==0){
        // Inserindo horcrux
        no = itensGanhar->PegaElementoAleatorio();
        noPtr = new Nodetype();
        noPtr->CopiaNode(no);
        noPtr->set_id(0);
        noPtr->carregar(noPtr->get_info());
        x = (rand() % 919);
        y = (rand() % 300 + 321);
        noPtr->set_posicao(x, y);
        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
        
        Insere(noPtr);
        qtd = 1;
    }
    
    for (i = qtd; i<n; i++)
    {
        no = listaGeral->PegaElementoAleatorioTodosTipoX(5);
        noPtr = new Nodetype();
        noPtr->CopiaNode(no);
        noPtr->set_id(i);
        noPtr->carregar(noPtr->get_info());
        x = (rand() % 919);
        y = (rand() % 300 + 321);
        noPtr->set_posicao(x, y);
        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
        
        Insere(noPtr);
    }
    
    
    //    // QUERIA ESCOLHER A QUANTIDADE CERTA DE CADA COISA, MAS ESTAVA DANDO ERRADO
    //    //Inserindo horcrux
    //    cout << "HORCRUX " << endl;
    //    qtd = 1;
    //    no = listaGeral->PegaElementoAleatorioTodosTipoX(3);
    //     cout << " Elemento = " << no->get_id()<< endl;
    //    noPtr = new Nodetype();
    //    noPtr->CopiaNode(no);
    //    noPtr->set_id(0);
    //    noPtr->carregar(noPtr->get_info());
    //    x = (rand() % 919);
    //    y = (rand() % 300 + 321);
    //    noPtr->set_posicao(x, y);
    //    noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
    //
    //    //Insere(noPtr);
    //    restantes -= qtd;
    //
    //    maisI = 1;
    //
    //
    //
    //    //Inserindo ITENS
    //    qtd = restantes/2;
    //    cout << "Primeiro qtd = " << qtd << endl;
    //    for (i = 0; i<qtd; i++)
    //        {
    //            no = listaGeral->PegaElementoAleatorioTodosTipoX(4);
    //            cout << "i = " << i << " Elemento = " << no->get_id()<< endl;
    //            noPtr = new Nodetype();
    //            noPtr->CopiaNode(no);
    //            noPtr->set_id(i+maisI);
    //            noPtr->carregar(noPtr->get_info());
    //            x = (rand() % 919);
    //            y = (rand() % 300 + 321);
    //            noPtr->set_posicao(x, y);
    //            noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
    //
    //            cout << "AAAA" << endl;
    //            //Insere(noPtr);
    //        }
    //    restantes-=qtd;
    //
    //    maisI += qtd;
    //
    //    cout << "TERMINEI PRIMEIRO FOR" << endl;
    //    //Inserindo INIMIGOS
    //    qtd = restantes/2;
    //    for (i = 0; i<qtd; i++)
    //    {
    //        no = listaGeral->PegaElementoAleatorioTodosTipoX(1);
    //        noPtr = new Nodetype();
    //        noPtr->CopiaNode(no);
    //        noPtr->set_id(i+maisI);
    //        noPtr->carregar(noPtr->get_info());
    //        x = (rand() % 919);
    //        y = (rand() % 300 + 321);
    //        noPtr->set_posicao(x, y);
    //        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
    //
    //       // Insere(noPtr);
    //    }
    //    restantes-=qtd;
    //
    //    maisI += qtd;
    //
    //    //Inserindo AMIGOS
    //    qtd = restantes;
    //    for (i = 0; i<qtd; i++)
    //    {
    //        no = listaGeral->PegaElementoAleatorioTodosTipoX(2);
    //        noPtr = new Nodetype();
    //        noPtr->CopiaNode(no);
    //        noPtr->set_id(i+maisI);
    //        noPtr->carregar(noPtr->get_info());
    //        x = (rand() % 919);
    //        y = (rand() % 300 + 321);
    //        noPtr->set_posicao(x, y);
    //        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
    //        
    //       // Insere(noPtr);
    //    }
    //    restantes-=qtd;
    //    maisI += qtd;
    //    
    //    cout << "restantes = " << restantes << endl;
}