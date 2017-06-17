#ifndef FEITICO_H
#define FEITICO_H

#include "headers.h"

class feitico
{
public:
	feitico();
	virtual ~feitico();
	void Update(float);

	virtual void bombarda();
	virtual void accio();
	virtual void nada();
	virtual void desenhar(sf::RenderWindow& window);
	virtual void set_posicao();
	virtual void set_estado();
	virtual void set_estado_false();
	virtual bool verifica_estado();
	virtual int get_tipo() const;

	virtual sf::Rect<float> get_bounding_rect();

	virtual float get_x();
	virtual float get_y();

	static float dir;
	static bool lancado;

private:
	int tipo;
	float _velocity;
	float _angle;
	float _elapsedTimeSinceStart;
	bool existe_feitico;

	sf::Sprite _sprite;
	sf::Texture _imagem;
};
#endif // !FEITICO_H
