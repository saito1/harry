#include "headers.h"

item::item()
{
	carregou = false;
}

item::~item()
{
}

void item::carregar(std::string nomearquivo)
{
	if (_imagem.loadFromFile(nomearquivo) == false)
	{
		nome_arquivo = "";
		carregou = false;
	}
	else
	{
		nome_arquivo = nomearquivo;
		_sprite.setTexture(_imagem);
		carregou = true;
	}
}

void item::desenhar(sf::RenderWindow& renderWindow)
{
	if (carregou)
		renderWindow.draw(_sprite);
}

void item::set_posicao(float x, float y)
{
	if (carregou)
		_sprite.setPosition(x, y);
}

float item::get_x() const
{
	return _sprite.getPosition().x;
}

float item::get_y() const
{
	return _sprite.getPosition().y;
}

void item::set_origem(float x, float y)
{
	if (carregou)
		_sprite.setOrigin(x, y);
}

float item::get_origem_x() const
{
	return _sprite.getOrigin().x;
}

float item::get_origem_y() const
{
	return _sprite.getOrigin().y;
}

float item::get_altura() const
{
	return _sprite.getLocalBounds().height;
}

float item::get_largura() const
{
	return _sprite.getLocalBounds().width;
}

sf::Rect<float> item::get_bounding_rect()
{
	sf::Vector2f position = _sprite.getPosition();

	return sf::Rect<float>(position.x - _sprite.getGlobalBounds().width / 2, position.y - _sprite.getGlobalBounds().height / 2, _sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height);
}

bool item::selecionado(sf::RenderWindow & window)
{
	if (mouse_intersects(window))
	{
		estado = true;
		return true;
	}
	else
	{
		estado = false;
		return false;
	}
}

bool item::pressionado(sf::RenderWindow & window)
{
	if (selecionado(window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		estado = false;
		return true;
	}
	else
	{
		return false;
	}
}

bool item::mouse_intersects(sf::RenderWindow & window)
{
	sf::FloatRect aux;
	aux = get_bounding_rect();

	if (sf::Mouse::getPosition(window).x >= aux.left
		&& sf::Mouse::getPosition(window).x <= aux.left + aux.width
		&& sf::Mouse::getPosition(window).y >= aux.top
		&& sf::Mouse::getPosition(window).y <= aux.top + aux.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

