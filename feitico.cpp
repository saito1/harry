#include "headers.h"

feitico::feitico() :_velocity(100.f), _elapsedTimeSinceStart(0.0f)
{
	existe_feitico = false;
}

feitico::~feitico()
{
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
	_imagem.loadFromFile("imagens/explosao.png");
	_sprite.setTexture(_imagem);
	_sprite.setPosition(10 * cos(dir) + 510,10 * sin(dir) + 117);
}

void feitico::accio()
{
	_imagem.loadFromFile("imagens/accio.png");
	_sprite.setTexture(_imagem);
	_sprite.setPosition(10 * cos(dir) + 510,10 * sin(dir) + 117);
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
}

bool feitico::verifica_estado()
{
	return existe_feitico;
}

float feitico::get_x()
{
	return _sprite.getPosition().x;
}

float feitico::get_y()
{
	return _sprite.getPosition().y;
}



