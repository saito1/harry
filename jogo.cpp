#include "jogo.h"
#include "headers.h"

jogo::GameState jogo::estado_jogo = Inicializado;
sf::RenderWindow jogo::janela;
sf::Text jogo::timerText;
sf::Sprite jogo::background;
bool feitico::lancado = false;
gerenciador_itens jogo::_gerenciador_itens;
varinha::estado_varinha varinha::_estado_varinha = Rotacionando;
float feitico::dir = 0;
int jogo::countdown = 30;

void jogo::Start(varinha* hook, sf::Clock & clock)
{
	if (estado_jogo != Inicializado)
		return;

	janela.create(sf::VideoMode(1024, 768), "HARRY", sf::Style::Close); //DEFINE TAMANHO DA JANELA, O QUE APARECE NO CABEÇALHO E FUNCOES DISPONIVEIS (FECHAR, RESIZE, MINIMIZAR)

	sf::Texture imagem;
	imagem.loadFromFile("imagens/fundo2.jpg");
	background.setTexture(imagem); //DEFINE O BACKGROUND

	estado_jogo = jogo::Mostrando_Tela_Inicial;

	while (!IsExiting())
	{
		loop_jogo(hook, clock);
	}

	janela.close();
}

void jogo::CriandoTudo()
{
	//TESTE
	//GAME CLOCK & TIMER
	sf::Clock clock;
	//int countdown = 30;

	//LOAD GAME TIMER FONT
	sf::Font timerFont;
	timerFont.loadFromFile("imagens/harry.ttf");

	//convert countdown to a string
	string countdownString = "00:" + to_string(countdown);

	//LOAD FONT AND TEXT
	//sf::Text timerText;
	timerText.setFont(timerFont);
	timerText.setString(countdownString);
	timerText.setPosition(200, 22);
	timerText.setCharacterSize(30);
	timerText.setFillColor(sf::Color::Black);

	varinha *hook = new varinha();

	jogo::Start(hook, clock);
}

void jogo::JogarNovamente(varinha* hook, sf::Clock & clock)
{
	jogo::Start(hook, clock);
	estado_jogo = jogo::Jogando;
}

bool jogo::IsExiting()
{
	if (estado_jogo == jogo::Saindo)
		return true;
	else
		return false;
}

void jogo::loop_jogo(varinha* hook, sf::Clock & clock)
{
	switch (estado_jogo)
	{
	case jogo::Mostrando_Menu:
	{
		mostrar_menu();
		break;
	}
	case jogo::Mostrando_Tela_Inicial:
	{
		mostrar_tela_inicial();
		break;
	}
	case jogo::Mostrando_Instrucao:
	{
		//mostrar_instrucao();
		break;
	}
	case jogo::Mostrando_Transicao:
	{
		mostrar_transicao();
		break;
	}
	case jogo::Ganhando:
	{
		mostrar_ganhou(hook, clock);
		break;
	}
	case jogo::Perdendo:
	{
		mostrar_perdeu(hook, clock);
		break;
	}
	case jogo::Jogando:
	{
		sf::Event evento_atual;
		sf::Sprite botao_pausar;
		sf::Texture imagem1;
		sf::Sprite botao_sair;
		sf::Texture imagem2;

		imagem1.loadFromFile("imagens/pausar.png");
		botao_pausar.setTexture(imagem1);
		botao_pausar.setPosition(897, 30);

		imagem2.loadFromFile("imagens/sair.png");
		botao_sair.setTexture(imagem2);
		botao_sair.setPosition(910, 75);

		//TIMER - 30 SECONDS
		int timer = clock.getElapsedTime().asSeconds();

		if (timer > 0) 
		{
			countdown = countdown - 1;
			string countdownString = "00:" + to_string(countdown);
			timerText.setString(countdownString);
			clock.restart();
		}

		janela.clear();
		janela.draw(background);
		hook->desenhar(janela);
		hook->update_todos();
		_gerenciador_itens.desenhar_todos(janela);
		janela.draw(timerText);
		janela.draw(botao_pausar);
		janela.draw(botao_sair);
		janela.display();

		janela.pollEvent(evento_atual);

		switch (evento_atual.type)
		{
		case sf::Event::Closed:
			estado_jogo = jogo::Saindo;
			break;
		case sf::Event::KeyPressed:
			if (evento_atual.key.code == sf::Keyboard::Escape)
				mostrar_menu();
			break;
		case sf::Event::MouseButtonPressed:
			if (evento_atual.mouseButton.button == sf::Mouse::Left && feitico::lancado == false)
			{
				varinha::_estado_varinha = varinha::Bombarda;
				feitico::dir = (hook->get_rotacao() + 90)*0.0174532925;
			}
			if (evento_atual.mouseButton.button == sf::Mouse::Right && feitico::lancado == false)
			{
				varinha::_estado_varinha = varinha::Accio;
				feitico::dir = (hook->get_rotacao() + 90)*0.0174532925;
			}
			if (evento_atual.mouseButton.button == sf::Mouse::Left)
				if (botao_pausar.getGlobalBounds().contains(sf::Mouse::getPosition(janela).x, sf::Mouse::getPosition(janela).y))
				{
					mostrar_menu();
				}
			if (evento_atual.mouseButton.button == sf::Mouse::Left)
				if (botao_sair.getGlobalBounds().contains(sf::Mouse::getPosition(janela).x, sf::Mouse::getPosition(janela).y))
				{
					estado_jogo = jogo::Saindo;
				}
			break;
		case sf::Event::MouseButtonReleased:
			varinha::_estado_varinha = varinha::Rotacionando;
			break;
		default:
			break;
		}
	}
	break;
	}
}

void jogo::mostrar_tela_inicial()
{
	Tela_Inicial tela_incial;
	tela_incial.Mostrar(janela);
	estado_jogo = jogo::Mostrando_Menu;
}

void jogo::mostrar_ganhou(varinha *hook, sf::Clock & clock)
{
	Ganhou ganhou;
	Ganhou::ganhou resultado = ganhou.Mostrar(janela);
	switch (resultado)
	{
	case Ganhou::Sair:
		estado_jogo = jogo::Saindo;
		break;
	case Ganhou::Jogar_Novamente:
		jogo::JogarNovamente(hook, clock);
		break;
	}
}

void jogo::mostrar_perdeu(varinha *hook, sf::Clock & clock)
{
	Perdeu perdeu;
	Perdeu::perdeu resultado = perdeu.Mostrar(janela);
	switch (resultado)
	{
	case Perdeu::Sair:
		estado_jogo = jogo::Saindo;
		break;
	case Perdeu::Jogar_Novamente:
		jogo::JogarNovamente(hook, clock);
		break;
	}
}

void jogo::mostrar_menu()
{
	Menu menu;
	Menu::menu_inicial resultado = menu.Mostrar(janela);
	switch (resultado)
	{
	case Menu::Sair:
		estado_jogo = jogo::Saindo;
		break;
	case Menu::Jogar:
		estado_jogo = jogo::Jogando;
		break;
		/*case Menu::Instrucoes:
		estado_jogo = jogo::Mostrando_Instrucao;*/
	}
}

void jogo::mostrar_transicao()
{
}

int main(int argc, char** argv)
{
	jogo::CriandoTudo();

	return 0;
}