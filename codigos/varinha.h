#ifndef VARINHA_H
#define VARINHA_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
 
#include "feitico.h"

using namespace std;

class varinha
{
public:
    //CONSTRUTOR
    varinha();
    
    //DESTRUTOR
    ~varinha();
    
    void update_todos();
    void update();
    
    enum estado_varinha {
        Rotacionando, Bombarda, Accio, Accio_Lancado, Bombarda_Lancada, Acertou
    }; // estado que o jogo pode estar durante a partida
    
    virtual void desenhar(sf::RenderWindow& window);
    
    virtual float get_rotacao() const;
    
    feitico _feitico;
    
    sf::Sprite _sprite;
    
    static estado_varinha _estado_varinha;
    
private:
    sf::Sprite feitico;
    sf::Texture _imagem;
    std::string nome_arquivo;
    float direcao_rotacao;
    
    sf::Clock clock;
    float timeDelta;
    
    float _velocity;
    float _angle;
    float _elapsedTimeSinceStart;
};
#endif
