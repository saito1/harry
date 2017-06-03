#ifndef VARINHA_H
#define VARINHA_H

#include "headers.h"

class varinha
{
public:
	//CONSTRUTOR
	varinha();

	//DESTRUTOR
	~varinha();

	enum estado_varinha {
		Rotacionando, Atirando, Puxando, Feitico_lancado, Acertou
	}; // estado que o jogo pode estar durante a partida

	virtual void desenhar(sf::RenderWindow& window);

	virtual float get_rotacao() const;

	sf::Sprite _sprite;

	static estado_varinha _estado_varinha;
	static float dir;

private:
	sf::Sprite feitico;
	sf::Texture _feitico;
	sf::Texture _imagem;
	std::string nome_arquivo;
	int direcao_rotacao;
};
#endif
