#ifndef NODETYPE_HPP
#define NODETYPE_HPP

#include <iostream>
#include <string>
using namespace std;
// Nó - Representa um elemento da lista


class Nodetype
{
public:
	Nodetype();
	~Nodetype();

//	Nodetype get_next() const;
//	void set_next(Nodetype *);
//	string get_info() const;
//	void set_info(string);
//	int get_id() const;
//	void set_id(int);


//private:
	Nodetype *next;
	int id;
	string info;
	//int x;
	//int y;
};


Nodetype::Nodetype(){
	next = NULL;
	id = 0;
	info = "vazia";
}

Nodetype::~Nodetype(){

}

#endif
