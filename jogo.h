#ifndef JOGO_H
#define JOGO_H

#include "headers.h"
#include "ListaSimples.hpp"

class jogo
{
public:
    static void Start(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar);
    static void CriandoTudo();
    static void JogarNovamente(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar);
    
private:
    static bool IsExiting();
    static void loop_jogo(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar);
    
    static void mostrar_tela_inicial();
    static void mostrar_menu();
    static void mostrar_transicao();
    //static void mostrar_instrucao();
    static void mostrar_ganhou(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar);
    static void mostrar_perdeu(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar);
    
    static void InsereNplano(int n, ListaSimples *plano, ListaSimples *listaGeral);
    static void InicializaItensGanhar(ListaSimples *itensGanhar, ListaSimples *listaGeral);
    static bool VerificaGanhou(ListaSimples *itensGanhar);
    static void desenha_todos_plano(ListaSimples * plano, sf::RenderWindow& window);
    static void verifica_colisao(varinha*, ListaSimples * plano, ListaSimples * itensGanhar);
    
    enum GameState {
        Inicializado, Mostrando_Tela_Inicial, Pausado, Mostrando_Menu, Jogando, Saindo, Ganhando, Perdendo, Mostrando_Instrucao, Mostrando_Transicao
    }; // estado que o jogo pode estar durante a partida
    
    static GameState estado_jogo;
    static sf::RenderWindow janela;
    static sf::Sprite background;
    static sf::Text timerText;
    static sf::Text totalText;
    static int countdown;
    static int total;
    //static int meta;
};
#endif // !JOGO_H