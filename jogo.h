#ifndef JOGO_H
#define JOGO_H

#include "headers.h"

class jogo
{
public:
	static void Start(varinha*);
	static void CriandoTudo();
	static void JogarNovamente(varinha*);

private:
	static bool IsExiting();
	static void loop_jogo(varinha*);

	static void mostrar_tela_inicial();
	static void mostrar_menu();
	//	static void mostrar_instrucao();
	static void mostrar_ganhou(varinha*);
	static void mostrar_perdeu(varinha*);

	enum GameState {
		Inicializado, Mostrando_Tela_Inicial, Pausado, Mostrando_Menu, Jogando, Saindo, Ganhando, Perdendo, Mostrando_Instrucao
	}; // estado que o jogo pode estar durante a partida

	static GameState estado_jogo;
	static sf::RenderWindow janela;
	static sf::Sprite background;
	static gerenciador_itens _gerenciador_itens;
};
#endif // !JOGO_H