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

	Nodetype* get_next() const;
	void set_next(Nodetype *);
	string get_info() const;
	void set_info(string);
	int get_id() const;
	void set_id(int);


private:
	Nodetype *next;
	int id;
	string info;
	//int x; //IMPLEMENTAR QUANDO FIZER INTEGRACAO
	//int y;
};


Nodetype::Nodetype(){
	next = NULL;
	id = 0;
	info = "vazia";
}

Nodetype::~Nodetype(){

}


Nodetype* Nodetype::get_next() const{
	return this->next;
}

void Nodetype::set_next(Nodetype *pnext){
	this->next = pnext;
}
string Nodetype::get_info() const{
	return this->info;
}
void Nodetype::set_info(string pinfo){
	this->info = pinfo;
}
int Nodetype::get_id() const{
	return this->id;
}
void Nodetype::set_id(int pid){
	if(pid>0)
		this->id = pid;
}

#endif
