//#ifndef GERENCIADOR_ITENS_H
//#define GERENCIADOR_ITENS_H
//
//#include "headers.h"
//
//class gerenciador_itens
//{
//public:
//	//CONSTRUTOR
//	gerenciador_itens();
//	//DESTRUTOR
//	~gerenciador_itens();
//	//FUNÇOES
//	void adicionar(std::string nome, item* item_jogo);
//	void remover(std::string nome);
//	int get_contador_itens() const;
//	item* get(std::string nome) const;
//
//	void desenhar_todos(sf::RenderWindow& renderWindow);
//
//private:
//	std::map<std::string, item*> _item_jogo;
//
//	struct item_jogo_alocador
//	{
//		void operator()(const std::pair < std::string, item*> & p) const
//		{
//			delete p.second;
//		}
//	};
//};
//#endif // !gerenciador_cartas
