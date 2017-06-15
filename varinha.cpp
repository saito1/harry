#include "headers.h"

varinha::varinha(): _velocity(20.f), _elapsedTimeSinceStart(0.0f)
{
	direcao_rotacao = 0.5;
}

varinha::~varinha()
{
}

void varinha::update()
{
	_sprite.setRotation(_sprite.getRotation() + direcao_rotacao);
	if (_sprite.getRotation() == 80 || _sprite.getRotation() == 300)
	{
		direcao_rotacao = - direcao_rotacao;
	}
}

void varinha::update_todos()
{
	timeDelta = clock.restart().asSeconds();
	_feitico.Update(timeDelta);
}

void varinha::desenhar(sf::RenderWindow& renderWindow)
{
	_imagem.loadFromFile("imagens/varinha.png");
	_sprite.setTexture(_imagem);
	_sprite.setPosition(515, 111);

	switch (_estado_varinha)
	{
	case varinha::Rotacionando:
		update();
		break;
	case varinha::Atirando:
		_feitico.bombarda();
		//_feitico.loadFromFile("imagens/explosao.png");
		//feitico.setTexture(_feitico);
		//feitico.setPosition(10 * cos(dir) + 510, 10 * sin(dir) + 117);
		_estado_varinha = varinha::Feitico_lancado;
		break;
	case varinha::Puxando:
		_feitico.accio();
		//_feitico.loadFromFile("imagens/accio.png");
		//feitico.setTexture(_feitico);
		//feitico.setPosition(10 * cos(dir) + 510, 10 * sin(dir) + 117);
		_estado_varinha = varinha::Feitico_lancado;
		break;
	case varinha::Feitico_lancado:
		_feitico.set_posicao();
		//feitico.setPosition(feitico.getPosition().x + 40 * cos(dir), feitico.getPosition().y + 40 * sin(dir));
		break;
	default:
		break;
	}

	renderWindow.draw(_sprite);
	_feitico.desenhar(renderWindow);
	//renderWindow.draw(feitico);
}

float varinha::get_rotacao() const
{
	return _sprite.getRotation();
}

