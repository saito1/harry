/*
 * main.cpp
 *
 *  Created on: 12/06/2017
 *      Author: renatasarmet
 */



#include <iostream>
#include "ListaSimples.hpp"
#include "Node.hpp"

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
