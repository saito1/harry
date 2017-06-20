#ifndef JOGO_H
#define JOGO_H

#include "headers.h"
#include "ListaSimples.hpp"
#include "ItensGanhar.hpp"

class jogo
{
public:
    static void Start(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    static void CriandoTudo();
    static void JogarNovamente(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    static void nova_fase(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    
private:
    static bool IsExiting();
    static void loop_jogo(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    
    static void mostrar_tela_inicial();
    static void mostrar_menu();
    static void mostrar_transicao();
    static void mostrar_transicao_horcrux();
    //static void mostrar_instrucao();
    static void mostrar_ganhou(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    static void mostrar_perdeu(varinha*, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    
    static void InsereNplano(int n, ListaSimples *plano, ListaSimples *listaGeral, ItensGanhar* itensGanhar);
    static void InicializaItensGanhar(ItensGanhar* itensGanhar, ListaSimples *listaGeral);
    static bool VerificaGanhou(ItensGanhar* itensGanhar);
    static bool verifica_passou();
    static void desenha_todos_plano(ListaSimples * plano, sf::RenderWindow& window);
    static void verifica_colisao(varinha*, ListaSimples * plano, ItensGanhar* itensGanhar, ItensGanhar* destruidos, ListaSimples* todosItens);
    
    enum GameState {
        Inicializado, Mostrando_Tela_Inicial, Pausado, Mostrando_Menu, Jogando, Saindo, Ganhando, Perdendo, Mostrando_Instrucao, Mostrando_Transicao_Passou, Mostrando_Transicao_Horcrux, Nova_Fase
    }; // estado que o jogo pode estar durante a partida
    
    static GameState estado_jogo;
    static sf::RenderWindow janela;
    static sf::Sprite background;
    static sf::Text timerText;
    static sf::Text nivelText;
    static sf::Text totalText;
    static sf::Text metaText;
    static int countdown;
    static int total;
    static int meta;
    static int nivel;
};
#endif // !JOGO_H