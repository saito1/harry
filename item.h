//#ifndef ITEM_H
//#define ITEM_H
//
//#include "SFML/Window.hpp"
//#include "SFML/Graphics.hpp"
//
//class item
//{
//public:
//	//CONSTRUTOR
//	item();
//
//	//DESTRUTOR
//	virtual ~item();
//
//	//FUNCOES
//	virtual void carregar(std::string nome_arquivo);
//	virtual void desenhar(sf::RenderWindow& window);
//
//	virtual void set_posicao(float x, float y);
//	virtual float get_x() const;
//	virtual float get_y() const;
//
//	virtual void set_origem(float x, float y);
//	virtual float get_origem_x() const;
//	virtual float get_origem_y() const;
//
//	virtual float get_altura() const;
//	virtual float get_largura() const;
//
//	virtual sf::Rect<float> get_bounding_rect();
//
//	bool selecionado(sf::RenderWindow& window);
//	bool pressionado(sf::RenderWindow& window);
//
//	bool mouse_intersects(sf::RenderWindow& window);
//
//	sf::Sprite _sprite;
//
//private:
//
//	sf::Texture _imagem;
//	std::string nome_arquivo;
//	int valor;
//	bool carregou;
//	bool estado;
//	bool destruido;
//};
//#endif
