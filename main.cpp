#include <iostream>
#include "ListaSimples.hpp"
#include "Nodetype.hpp"

using namespace std;

int main()
{
    ListaSimples x;
    bool Ok;

    x.Cria(10);
    Ok = x.Vazia();
    x.Insere(20);
    x.ExibeLista();
    x.ProcuraRemove(10, Ok);
    x.ExibeLista();


    return 0;
}

