#include "headers.h"

varinha::varinha()
{
	direcao_rotacao = 2;
}

varinha::~varinha()
{
}

void varinha::desenhar(sf::RenderWindow& renderWindow)
{
	_imagem.loadFromFile("imagens/varinha.png");
	_sprite.setTexture(_imagem);
	_sprite.setPosition(515, 111);

	switch (_estado_varinha)
	{
	case varinha::Rotacionando:
		_sprite.setRotation(_sprite.getRotation() + direcao_rotacao);
		if (_sprite.getRotation() == 80 || _sprite.getRotation() == 300)
		{
			direcao_rotacao = - direcao_rotacao;
		}
		break;
	case varinha::Atirando:
		_feitico.loadFromFile("imagens/explosao.png");
		feitico.setTexture(_feitico);
		feitico.setPosition(10 * cos(dir) + 510, 10 * sin(dir) + 117);
		_estado_varinha = varinha::Feitico_lancado;
		break;
	case varinha::Puxando:
		_feitico.loadFromFile("imagens/accio.png");
		feitico.setTexture(_feitico);
		feitico.setPosition(10 * cos(dir) + 510, 10 * sin(dir) + 117);
		_estado_varinha = varinha::Feitico_lancado;
		break;
	case varinha::Feitico_lancado:
		feitico.setPosition(feitico.getPosition().x + 40 * cos(dir), feitico.getPosition().y + 40 * sin(dir));
		break;
	case varinha::Acertou:

			break;
	default:
		break;
	}

	renderWindow.draw(_sprite);
	renderWindow.draw(feitico);
}

float varinha::get_rotacao() const
{
	return _sprite.getRotation();
}

