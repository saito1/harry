//#include "headers.h"
//
//gerenciador_itens::gerenciador_itens()
//{
//}
//
//gerenciador_itens::~gerenciador_itens()
//{
//	std::for_each(_item_jogo.begin(), _item_jogo.end(), item_jogo_alocador());
//}
//
//void gerenciador_itens::adicionar(std::string nome, item* item_jogo)
//{
//	_item_jogo.insert(std::pair<std::string, item*>(nome, item_jogo));
//}
//
//
//void gerenciador_itens::remover(std::string nome)
//{
//	std::map<std::string, item*>::iterator resultado = _item_jogo.find(nome);
//	if (resultado != _item_jogo.end())
//	{
//		delete resultado->second;
//		_item_jogo.erase(resultado);
//	}
//}
//
//item* gerenciador_itens::get(std::string nome) const
//{
//	std::map<std::string, item*>::const_iterator resultado = _item_jogo.find(nome);
//	if (resultado == _item_jogo.end())
//		return NULL;
//	return resultado->second;
//}
//
//int gerenciador_itens::get_contador_itens() const
//{
//	return _item_jogo.size();
//}
//
//void gerenciador_itens::desenhar_todos(sf::RenderWindow& renderWindow)
//{
//	std::map<std::string, item*>::const_iterator itr = _item_jogo.begin();
//	while (itr != _item_jogo.end())
//	{
//		itr->second->desenhar(renderWindow);
//		itr++;
//	}
//}