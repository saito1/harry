#ifndef JOGO_H
#define JOGO_H

#include "headers.h"

class jogo
{
public:
	static void Start(varinha*, sf::Clock & clock);
	static void CriandoTudo();
	static void JogarNovamente(varinha*, sf::Clock & clock);

private:
	static bool IsExiting();
	static void loop_jogo(varinha*, sf::Clock & clock);

	static void mostrar_tela_inicial();
	static void mostrar_menu();
	static void mostrar_transicao();
	//	static void mostrar_instrucao();
	static void mostrar_ganhou(varinha*, sf::Clock & clock);
	static void mostrar_perdeu(varinha*, sf::Clock & clock);

	enum GameState {
		Inicializado, Mostrando_Tela_Inicial, Pausado, Mostrando_Menu, Jogando, Saindo, Ganhando, Perdendo, Mostrando_Instrucao, Mostrando_Transicao
	}; // estado que o jogo pode estar durante a partida

	static GameState estado_jogo;
	static sf::RenderWindow janela;
	static sf::Sprite background;
	static sf::Text timerText;
	static gerenciador_itens _gerenciador_itens;
	static int countdown;
};
#endif // !JOGO_H