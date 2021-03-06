#ifndef JOGO_H
#define JOGO_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <locale>

#include "menu.h"
#include "tela_inicial.h"
#include "ganhou.h"
#include "perdeu.h"
#include "varinha.h"
#include "feitico.h"
#include "ListaSimples.hpp"
#include "Nodetype.hpp"
#include "transicao_passou.h"
#include "transicao_horcrux2.hpp"
#include "ItensGanhar.hpp"
#include "Plano.hpp"
#include "instrucoes.h"

 

using namespace std;

class jogo
{
public:
    static void Start(varinha*, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    static void CriandoTudo();
    static void JogarNovamente(varinha*, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    static void nova_fase(varinha*, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
	static void mostrar_fase_final(varinha*, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    
private:
    static bool IsExiting();
    static void loop_jogo(varinha*, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    
    static void mostrar_tela_inicial();
    static void mostrar_menu();
    static void mostrar_transicao(ItensGanhar* destruidos);
    static void mostrar_transicao_horcrux(ItensGanhar* destruidos);
	static void mostrar_instrucao();
    static void mostrar_ganhou(varinha*, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
    static void mostrar_perdeu(varinha*, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos);
  
    static bool VerificaGanhou(ItensGanhar* itensGanhar);
    static bool verifica_passou();
    static void verifica_colisao(varinha*, Plano* plano, ItensGanhar* itensGanhar, ItensGanhar* destruidos, ListaSimples* todosItens);
    
    enum GameState {
        Inicializado, Mostrando_Tela_Inicial, Pausado, Mostrando_Menu, Jogando, Saindo, Ganhando, Perdendo, Mostrando_Instrucao, Mostrando_Transicao_Passou, Mostrando_Transicao_Horcrux, Nova_Fase, Fase_Final
    }; // estado que o jogo pode estar durante a partida
    
    static GameState estado_jogo;
    static sf::RenderWindow janela;
    static sf::Sprite background;
    static sf::Text timerText;
    static sf::Text nivelText;
    static sf::Text totalText;
    static sf::Text metaText;
	static sf::Music musica_jogo;
	static sf::Music musica_final;
    static int countdown;
    static int total;
    static int meta;
    static int nivel;
    static bool voldemort_morreu;
	static bool to_na_transicao;
};
#endif // !JOGO_H