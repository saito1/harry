#include "jogo.h"
#include "headers.h"

jogo::GameState jogo::estado_jogo = Inicializado;
sf::RenderWindow jogo::janela;
sf::Sprite jogo::background;
bool jogo::selecionado = false;

void jogo::Start()
{
	if (estado_jogo != Inicializado)
		return;

	janela.create(sf::VideoMode(1024, 768), "99 Cartas", sf::Style::Close); //DEFINE TAMANHO DA JANELA, O QUE APARECE NO CABEÇALHO E FUNCOES DISPONIVEIS (FECHAR, RESIZE, MINIMIZAR)

	sf::Texture imagem;
	imagem.loadFromFile("imagens/fundo2.jpg");
	background.setTexture(imagem); //DEFINE O BACKGROUND

	estado_jogo = jogo::Mostrando_Tela_Inicial;

	item harry;

	harry.carregar("imagens/harry.png");
	harry.desenhar(janela);

	while (!IsExiting())
	{
		loop_jogo();
	}

	janela.close();
}

void jogo::JogarNovamente()
{
	jogo::Start();
	estado_jogo = jogo::Jogando;
}

bool jogo::IsExiting()
{
	if (estado_jogo == jogo::Saindo)
		return true;
	else
		return false;
}

void jogo::loop_jogo()
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
	case jogo::Ganhando:
	{
		mostrar_ganhou();
		break;
	}
	case jogo::Perdendo:
	{
		mostrar_perdeu();
		break;
	}
	case jogo::Jogando:
	{
		sf::Event evento_atual;

		while (janela.pollEvent(evento_atual))
		{
			janela.clear();
			//janela.draw(background);
			janela.display();

			switch (evento_atual.type)
			{
			case sf::Event::Closed:
				estado_jogo = jogo::Saindo;
				break;

			case sf::Event::KeyPressed:
				if (evento_atual.key.code == sf::Keyboard::Escape)
					mostrar_menu();
				break;

			default:
				break;
			}
		}
		break;
	}
	}
}

void jogo::mostrar_tela_inicial()
{
	Tela_Inicial tela_incial;
	tela_incial.Mostrar(janela);
	estado_jogo = jogo::Mostrando_Menu;
}

void jogo::mostrar_ganhou()
{
	Ganhou ganhou;
	Ganhou::ganhou resultado = ganhou.Mostrar(janela);
	switch (resultado)
	{
	case Ganhou::Sair:
		estado_jogo = jogo::Saindo;
		break;
	case Ganhou::Jogar_Novamente:
		jogo::JogarNovamente();
		break;
	}
}

void jogo::mostrar_perdeu()
{
	Perdeu perdeu;
	Perdeu::perdeu resultado = perdeu.Mostrar(janela);
	switch (resultado)
	{
	case Perdeu::Sair:
		estado_jogo = jogo::Saindo;
		break;
	case Perdeu::Jogar_Novamente:
		jogo::JogarNovamente();
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

int main(int argc, char** argv)
{
	jogo::Start();

	return 0;
}

//int main()
//{
//	// number of boulders in the game
//	int itens = 20, i;
//	for (i = 1; i <= itens; i++) {
//		// creating the boulders
//		item = _root.attachMovie("boulder", "boulder_" + _root.getNextHighestDepth(), _root.getNextHighestDepth());
//		// placing them in random positions and with random dimensions
//		item._x = Math.floor(Math.random() * 400) + 50;
//		item._y = Math.floor(Math.random() * 200) + 150;
//		item._width = Math.floor(Math.random() * 30) + 20;
//		item._height = item._width;
//		// setting picked attribute as false
//		// picked = false => the boulder has not been picked by the hook
//		// picked = true => the boulder has been picked
//		item.picked = false;
//		// function to be executed at every frame for the boulder
//		item.onEnterFrame = function() {
//			// if it's not been picked...
//			if (!this.picked) {
//				// check if the hook is in shoot mode and touched the boulder
//				// you'll see later what do hot_spot_x and hot_spot_y mean
//				if (pod_status == "Lançou" and this.hitTest(hot_spot_x, hot_spot_y, true)) {
//					// set the hook on rewind mode
//					pod_status = "Voltando";
//					// mark this boulder as picked
//					this.picked = true;
//					// determining the slowdown according to boulder size
//					slowdown = Math.floor(this._width / 5);
//				}
//			}
//			else {
//				// the boulder has been picked, so move it as the hook moves
//				this._x = hot_spot_x;
//				this._y = hot_spot_y;
//				// if the hook status changed to rotate
//				// (this means: if the hook took a boulder and pulled it out to surface...
//				if (pod_status == "rotate") {
//					// remove the boulder
//					this.removeMovieClip();
//				}
//			}
//		};
//	}
//	// placing the hook on stage
//	_root.attachMovie("pod", "pod", _root.getNextHighestDepth(), { _x:250 });
//	// creating an empty movie clip to draw the rope
//	_root.createEmptyMovieClip("rod", _root.getNextHighestDepth());
//	// this is the rotation direction and speed
//	rotation_dir = 2;
//	// hook initial status
//	pod_status = "rotate";
//	// slowdown malus
//	slowdown = 0;
//	// function the hook will execute at every frame
//	pod.onEnterFrame = function() {
//		// getting pod status
//		switch (pod_status) {
//		case "rotate":
//			// if the status is rotate, just rotate the hook according to rotation_dir
//			this._rotation += rotation_dir;
//			if (this._rotation == 80 or this._rotation == -80) {
//				// invert rotation_dir if the hook reaches its minimum (or maximum) rotation allowed
//				rotation_dir *= -1;
//			}
//			break;
//		case "shoot":
//			// the hook has ben shoot
//			// (re)set slowdown malus to zero
//			slowdown = 0;
//			// moving the hook using trigonometry
//			this._x += 10 * Math.cos(dir);
//			this._y += 10 * Math.sin(dir);
//			// determining the hot spot of the hook
//			// the hot spot is the lowest corner of the hook (that acts like an harpoon in this case)
//			hot_spot_x = this._x + 40 * Math.cos(dir);
//			hot_spot_y = this._y + 40 * Math.sin(dir);
//			// if the hot spot goes off the stage
//			if (hot_spot_y>400 or hot_spot_x<0 or hot_spot_x>500) {
//				// then rewind the hook
//				pod_status = "rewind";
//			}
//			// draw a line from the hook starting position to its actual position 
//			// this will simulate the rope
//			rod.clear();
//			rod.lineStyle(1, 0x000000);
//			rod.moveTo(250, 0);
//			rod.lineTo(this._x, this._y);
//			break;
//		case "rewind":
//			// rewinding the hook...
//			// it may seem a nonsense determining the hot spot now, but I need id
//			// to move the boulder (if I have any boulder attached to the hook)
//			hot_spot_x = this._x + 40 * Math.cos(dir);
//			hot_spot_y = this._y + 40 * Math.sin(dir);
//			// moving the hook with slowdown malus (if any)
//			this._x -= (10 - slowdown)*Math.cos(dir);
//			this._y -= (10 - slowdown)*Math.sin(dir);
//			// if the hook returns in its initial position...
//			if (this._y<0) {
//				// then reset its position and set its status to rotate
//				this._y = 0;
//				this._x = 250;
//				pod_status = "rotate";
//			}
//			// drawing a line as seen in shoot status
//			rod.clear();
//			rod.lineStyle(1, 0x000000);
//			rod.moveTo(250, 0);
//			rod.lineTo(this._x, this._y);
//			break;
//		}
//	};
//	// when the mouse is clicked...
//	_root.onMouseDown = function() {
//		// if the status is rotate...
//		if (pod_status == "rotate") {
//			// save hook heading and convert it to radians
//			dir = (pod._rotation + 90)*0.0174532925;
//			// set pod status to shoot
//			pod_status = "shoot";
//		}
//	};
//}