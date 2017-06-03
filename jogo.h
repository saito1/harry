#ifndef JOGO_H
#define JOGO_H

#include "headers.h"

class jogo
{
public:
	static void Start();
	//static void CriandoTudo();
	static void JogarNovamente();

private:
	static bool IsExiting();
	static void loop_jogo();

	static void mostrar_tela_inicial();
	static void mostrar_menu();
	//	static void mostrar_instrucao();
	static void mostrar_ganhou();
	static void mostrar_perdeu();

	enum GameState {
		Inicializado, Mostrando_Tela_Inicial, Pausado, Mostrando_Menu, Jogando, Saindo, Ganhando, Perdendo, Mostrando_Instrucao
	}; // estado que o jogo pode estar durante a partida

	static GameState estado_jogo;
	static sf::RenderWindow janela;
	static sf::Sprite background;
	static bool selecionado;
};
#endif // !JOGO_H