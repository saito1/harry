#include "headers.h"

feitico::feitico() :_velocity(100.f), _elapsedTimeSinceStart(0.0f)
{
}


feitico::~feitico()
{
}

void feitico::Update(float elapsedTime)
{
	_elapsedTimeSinceStart += elapsedTime;

	float moveAmount = _velocity * elapsedTime;

	cout << "teste:" << moveAmount << endl;

	float moveByX = cos(dir) * moveAmount;
	float moveByY = sin(dir) * moveAmount;

	_sprite.move(moveByX, moveByY);
}

void feitico::bombarda()
{
	_imagem.loadFromFile("imagens/explosao.png");
	_sprite.setTexture(_imagem);
	_sprite.setPosition(10 * cos(dir) + 510, 10 * sin(dir) + 117);
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
	_sprite.setPosition(_sprite.getPosition().x + 40 * cos(dir), _sprite.getPosition().y + 40 * sin(dir));
}

float feitico::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0) angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float feitico::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0) angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}


