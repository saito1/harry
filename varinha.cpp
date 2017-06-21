#include "varinha.h"

varinha::varinha(): _velocity(20.f), _elapsedTimeSinceStart(0.0f)
{
    direcao_rotacao = 0.5;
}

varinha::~varinha()
{
}

void varinha::update()
{
    _sprite.setRotation(_sprite.getRotation() + direcao_rotacao);
    if (_sprite.getRotation() == 70 || _sprite.getRotation() == 290)
    {
        direcao_rotacao = - direcao_rotacao;
    }
}

void varinha::update_todos()
{
    timeDelta = clock.restart().asSeconds();
    _feitico.Update(timeDelta);
}

void varinha::desenhar(sf::RenderWindow& renderWindow)
{
    _imagem.loadFromFile(resourcePath() + "varinha.png");
    _sprite.setTexture(_imagem);
    _sprite.setPosition(524, 115);
    _sprite.setOrigin(8, 8);
    
    switch (_estado_varinha)
    {
        case varinha::Rotacionando:
            update();
            break;
        case varinha::Bombarda:
            _feitico.bombarda();
            _feitico.set_estado();
            _estado_varinha = varinha::Bombarda_Lancada;
            break;
        case varinha::Accio:
            _feitico.accio();
            _feitico.set_estado();
            _estado_varinha = varinha::Accio_Lancado;
            break;
        case varinha::Bombarda_Lancada:
            _feitico.set_posicao();
            _estado_varinha = varinha::Rotacionando;
            break;
        case varinha::Accio_Lancado:
            _feitico.set_posicao();
            _estado_varinha = varinha::Rotacionando;
            break;
        case varinha::Acertou:
            _feitico.nada();
            _estado_varinha = varinha::Rotacionando;
        default:
            break;
    }
    
    renderWindow.draw(_sprite);
    _feitico.desenhar(renderWindow);
}

float varinha::get_rotacao() const
{
    return _sprite.getRotation();
}

