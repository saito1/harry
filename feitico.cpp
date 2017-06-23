#include "feitico.h"

feitico::feitico() :_velocity(50.f), _elapsedTimeSinceStart(0.0f)
{
	existe_feitico = true;
	tipo = 0;
}

feitico::~feitico()
{
	existe_feitico = false;
}

void feitico::Update(float elapsedTime)
{
	_elapsedTimeSinceStart += elapsedTime;

	float moveAmount = _velocity * elapsedTime;

	float moveByX = (10 * cos(dir)) * moveAmount;
	float moveByY =  (10 * sin(dir)) * moveAmount;

	if (_sprite.getPosition().x + moveByX <= 0 + (_sprite.getLocalBounds().width) / 2 || _sprite.getPosition().x + (_sprite.getLocalBounds().height) / 2 + moveByX >= 1024
		|| _sprite.getPosition().y + moveByY <= 0 + (_sprite.getLocalBounds().height) / 2 || _sprite.getPosition().y + (_sprite.getLocalBounds().width) / 2 + moveByY >= 768)
		lancado = false;

	_sprite.move(moveByX, moveByY);
}

void feitico::bombarda()
{
	if (existe_feitico)
	{
		_imagem.loadFromFile("imagens/bombarda.png");
		_sprite.setTexture(_imagem);
		_sprite.setPosition(10 * cos(dir) + 510, 10 * sin(dir) + 117);
		tipo = 1;
	}
}

void feitico::accio()
{
	if (existe_feitico)
	{
		_imagem.loadFromFile("imagens/accio.png");
		_sprite.setTexture(_imagem);
		_sprite.setPosition(10 * cos(dir) + 510, 10 * sin(dir) + 117);
		tipo = 2;
	}
}

void feitico::nada()
{
	_sprite.setPosition(1024,768);
}

void feitico::desenhar(sf::RenderWindow & window)
{
	window.draw(_sprite);
}

void feitico::set_posicao()
{
	_sprite.setPosition(_sprite.getPosition().x + 2 * cos(dir), _sprite.getPosition().y + 2 * sin(dir));
}

void feitico::set_estado()
{
	lancado = true;
}

void feitico::set_estado_false()
{
	lancado = false;
	tipo = -1;
}

bool feitico::verifica_estado()
{
	return existe_feitico;
}

int feitico::get_tipo() const
{
	return tipo;
}

sf::Rect<float> feitico::get_bounding_rect()
{
	sf::Vector2f position = _sprite.getPosition();

	return sf::Rect<float>(position.x - _sprite.getGlobalBounds().width / 2, position.y - _sprite.getGlobalBounds().height / 2, _sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height);
}

float feitico::get_x()
{
	return _sprite.getPosition().x;
}

float feitico::get_y()
{
	return _sprite.getPosition().y;
}



