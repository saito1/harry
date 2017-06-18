#include "headers.h"

transicao_passou::transicao_passou()
{
	meta = 650;
}

void transicao_passou::Mostrar(sf::RenderWindow & renderWindow)
{
	//LOAD GAME FONT
	sf::Font Font;
	Font.loadFromFile("imagens/harry.ttf");

	//LOAD FONT AND TEXT
	metaText.setFont(Font);
	metaText.setPosition(630, 480);
	metaText.setCharacterSize(50);
	metaText.setFillColor(sf::Color::Black);
	metaText.setString(to_string(get_meta()));

	sf::Texture imagem;
	if (imagem.loadFromFile("imagens/transicao1.jpg") != true)
		return;

	sf::Sprite sprite;
	sprite.setTexture(imagem);

	renderWindow.draw(sprite);
	renderWindow.draw(metaText);
	renderWindow.display();

	sf::Clock clock;
	
	while (true)
	{
		if (clock.getElapsedTime().asSeconds() > 3)
		{
			return;
		}
	}
}

void transicao_passou::set_meta(int meta)
{
	this->meta = meta + get_meta();
}

int transicao_passou::get_meta() const
{
	return this->meta;
}