/*
 * Node.hpp
 *
 *  Created on: 12/06/2017
 *      Author: renatasarmet
 */

#include <iostream>
#include <string>
using namespace std;
// Nó - Representa um elemento da lista


class Node
{
public:
	Node();
	~Node();

//	Node get_next() const;
//	void set_next(Node *);
//	string get_info() const;
//	void set_info(string);
//	int get_id() const;
//	void set_id(int);


private:
	Node *next;
	int id;
	string info;
	//int x;
	//int y;
};


Node::Node(){
	next = NULL;
	id = 0;
	info = "vazia";
}
