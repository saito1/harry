#include <iostream>
#include "ListaSimples.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ListaSimples x;
    bool Ok;

    x.Cria();
    Ok = x.Vazia();
    x.Insere(10);
    x.ExibeLista();

    return 0;
}