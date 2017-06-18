#include "headers.h"

void transicao_horcrux::Mostrar(sf::RenderWindow & renderWindow)
{
	sf::Texture imagem;
	if (imagem.loadFromFile("imagens/transicao2.jpg") != true)
		return;

	sf::Sprite sprite;
	sprite.setTexture(imagem);

	renderWindow.draw(sprite);
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