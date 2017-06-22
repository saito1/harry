#ifndef NODETYPE_HPP
#define NODETYPE_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"
#include "feitico.h"

using namespace std;

// Nó - Representa um elemento da lista

class Nodetype
{
public:
	//CONSTRUTOR
	Nodetype();

	//DESTRUTOR
	~Nodetype();

	//FUNCOES
	virtual void carregar(std::string nomearquivo);
	virtual void desenhar(sf::RenderWindow& renderWindow);
	virtual bool colidiu(feitico& _feitico);

	virtual float get_x() const;
	virtual float get_y() const;

	virtual void set_posicao(float x, float y);
	virtual void set_origem(float x, float y);

	virtual sf::Rect<float> get_bounding_rect();

	Nodetype* get_next() const;
	void set_next(Nodetype *);
	string get_info() const;
	void set_info(string);
	int get_id() const;
	void set_id(int);
	void ExibeInformacoes() const;
	void CopiaNode(Nodetype *original);
	void set_tipo(int);
	int get_tipo() const;
	void set_valor(int);
	int get_valor() const;

	sf::Sprite _sprite;

private:
	int tipo; //1 - INIMIGO, 2 - AMIGO, 3 - HORCRUX, 4 - PEGAR
	Nodetype *next;
	int id;
	int valor;
	string info;
	bool carregou;
	sf::Texture _imagem;
	std::string nome_arquivo;
};


Nodetype::Nodetype(){
	next = NULL;
	id = 0;
	info = "vazia";
	tipo = 0;
	valor = 0;
}

Nodetype::~Nodetype(){
	//cout << "GAME OVER NO DESTRUTOR DO ID = " << get_id() <<endl;
}

void Nodetype::carregar(std::string nomearquivo)
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

void Nodetype::desenhar(sf::RenderWindow & renderWindow)
{
    if (carregou)
		renderWindow.draw(_sprite);
}

bool Nodetype::colidiu(feitico& _feitico)
{
	if (_feitico.lancado == true)
	{
		if(_sprite.getPosition().x - _sprite.getLocalBounds().width/2 <= _feitico.get_bounding_rect().left + _feitico.get_bounding_rect().width
			&& _sprite.getPosition().x + _sprite.getLocalBounds().width / 2  >= _feitico.get_bounding_rect().left 
			&& _sprite.getPosition().y - _sprite.getLocalBounds().height / 2 <= _feitico.get_bounding_rect().top + _feitico.get_bounding_rect().height
			&& _sprite.getPosition().y + _sprite.getLocalBounds().height / 2 >= _feitico.get_bounding_rect().top )
		{

			return true;
		}
	}
	return false;
}

float Nodetype::get_x() const
{
	return _sprite.getPosition().x;
}

 float Nodetype::get_y() const
{
	return _sprite.getPosition().y;
}

void Nodetype::set_posicao(float x, float y)
{
	if (carregou)
		_sprite.setPosition(x, y);
}

void Nodetype::set_origem(float x, float y)
{
	_sprite.setOrigin(x, y);
}

sf::Rect<float> Nodetype::get_bounding_rect()
{
	sf::Vector2f position = _sprite.getPosition();

	return sf::Rect<float>(position.x - _sprite.getGlobalBounds().width / 2, position.y - _sprite.getGlobalBounds().height / 2, _sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height);
}

Nodetype* Nodetype::get_next() const{
	return this->next;
}

void Nodetype::set_next(Nodetype *pnext){
	this->next = pnext;
}
string Nodetype::get_info() const{
	return this->info;
}
void Nodetype::set_info(string pinfo){
	this->info = pinfo;
}
int Nodetype::get_id() const{
	return this->id;
}
void Nodetype::set_id(int pid){
	if(pid>=0)
		this->id = pid;
}

void Nodetype::set_tipo(int ptipo)
{
    this->tipo = ptipo;
}

int Nodetype::get_tipo() const
{
    return this->tipo;
}

void Nodetype::set_valor(int pvalor)
{
    this->valor = pvalor;
}

int Nodetype::get_valor() const
{
    return this->valor;
}

void Nodetype::ExibeInformacoes() const{
	cout << "ID = " << get_id() << endl;
	cout << "INFO = " << get_info() << endl;
	cout << "NEXT = " << get_next()->get_info() << endl;
	cout << "TIPO = " << get_tipo() << endl;
	cout << "VALOR = " << get_valor() << endl;
}

void Nodetype::CopiaNode(Nodetype *original){

	this->set_next(original->get_next());
   // cout << endl << endl << "NEXT = " << this->get_next()->get_info() << endl;
	this->set_id(original->get_id());
   // cout << "ID = " << this->get_id() << endl;
	this->set_info(original->get_info());
    //cout << "INFO = " << this->get_info() << endl;
	this->set_tipo(original->get_tipo());
   // cout << "TIPO = " << this->get_tipo() << endl;
	this->set_valor(original->get_valor());
    //cout << "VALOR = " << this->get_valor() << endl;
}



#endif
