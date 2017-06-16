//#include <iostream>
//#include "ListaSimples.hpp"
//#include "Nodetype.hpp"
//
//#include <time.h>
//#include <ctime>
//
//using namespace std;
//
//
//void InsereNplano(int n, ListaSimples *plano, ListaSimples *listaGeral){
//	int i;
//	Nodetype *no;
//	Nodetype *noPtr;
//	for(i=0;i<n;i++){
//		no = listaGeral->PegaElementoAleatorio();
//		noPtr = new Nodetype();
//		noPtr->CopiaNode(no);
//		plano->Insere(noPtr);
//	}
//}
//
//
//int main()
//{
//    ListaSimples plano, todosItens, itensGanhar;
//   // Nodetype *no;
//	Nodetype *anel = new Nodetype(), *bellatrix = new Nodetype(), *calice = new Nodetype(), *chapeu = new Nodetype(), *comensal = new Nodetype(), *coruja = new Nodetype(), 
//		*dementador = new Nodetype(), *diadema = new Nodetype(), *diario = new Nodetype(), *dobby = new Nodetype(), *dolores = new Nodetype(), *draco = new Nodetype(), 
//		*dumbledore = new Nodetype(), *felix = new Nodetype(), *hagrid = new Nodetype(), *hermione = new Nodetype(), *livro = new Nodetype(), *lucius = new Nodetype(), 
//		*medalhao = new Nodetype(), *minerva = new Nodetype(), *nagini = new Nodetype(), *pomo = new Nodetype(), *ron = new Nodetype(), *snape = new Nodetype(), 
//		*taca = new Nodetype(), *voldemort = new Nodetype();
//
//   // bool ok = false;
//   // int i;
//
//    srand(time(NULL));
//
//    //Inserindo Nodes na Lista todosItens
//	//AQUI    cout << "Inserindo e listando os elementos de todosItens" << endl;
//
//	anel->set_id(1);
//	anel->set_info("anel.png");
//	todosItens.Insere(anel);
//
//	bellatrix->set_id(2);
//	bellatrix->set_info("bellatrix.png");
//	todosItens.Insere(bellatrix);
//
//	calice->set_id(3);
//	calice->set_info("calice.png");
//	todosItens.Insere(calice);
//
//	chapeu->set_id(4);
//	chapeu->set_info("chapeu.png");
//	todosItens.Insere(chapeu);
//
//	comensal->set_id(5);
//	comensal->set_info("comensal.png");
//	todosItens.Insere(comensal);
//
//	coruja->set_id(6);
//	coruja->set_info("coruja.png");
//	todosItens.Insere(coruja);
//
//	dementador->set_id(7);
//	dementador->set_info("dementador.png");
//	todosItens.Insere(dementador);
//
//	diadema->set_id(8);
//	diadema->set_info("diadema.png");
//	todosItens.Insere(diadema);
//
//	diario->set_id(9);
//	diario->set_info("diario.png");
//	todosItens.Insere(diario);
//
//	dobby->set_id(10);
//	dobby->set_info("dobby.png");
//	todosItens.Insere(dobby);
//
//	dolores->set_id(11);
//	dolores->set_info("dolores.png");
//	todosItens.Insere(dolores);
//
//	draco->set_id(12);
//	draco->set_info("draco.png");
//	todosItens.Insere(draco);
//
//	dumbledore->set_id(13);
//	dumbledore->set_info("dumbledore.png");
//	todosItens.Insere(dumbledore);
//
//	felix->set_id(14);
//	felix->set_info("felix.png");
//	todosItens.Insere(felix);
//
//	hagrid->set_id(15);
//	hagrid->set_info("hagrid.png");
//	todosItens.Insere(hagrid);
//
//	hermione->set_id(16);
//	hermione->set_info("hermione.png");
//	todosItens.Insere(hermione);
//
//	livro->set_id(17);
//	livro->set_info("livro.png");
//	todosItens.Insere(livro);
//
//	lucius->set_id(18);
//	lucius->set_info("lucius.png");
//	todosItens.Insere(lucius);
//
//	medalhao->set_id(19);
//	medalhao->set_info("medalhao.png");
//	todosItens.Insere(medalhao);
//
//	minerva->set_id(20);
//	minerva->set_info("minerva.png");
//	todosItens.Insere(minerva);
//
//	nagini->set_id(21);
//	nagini->set_info("21.png");
//	todosItens.Insere(nagini);
//
//	pomo->set_id(22);
//	pomo->set_info("pomo.png");
//	todosItens.Insere(pomo);
//
//	ron->set_id(23);
//	ron->set_info("ron.png");
//	todosItens.Insere(ron);
//
//	snape->set_id(24);
//	snape->set_info("snape.png");
//	todosItens.Insere(snape);
//
//	taca->set_id(25);
//	taca->set_info("taca.png");
//	todosItens.Insere(taca);
//
//	voldemort->set_id(26);
//	voldemort->set_info("26.png");
//	todosItens.Insere(voldemort);
//
//	//Exibindo todos os itens
//	cout << "Todos os itens: " << endl;
//	todosItens.ExibeLista();
//
//	cout << "Quantidade de elementos todosItens: " << todosItens.QuantidadeElementos() << endl << endl;
//
////	 Removendo item
////    cout << "Removendo..." << endl;
////
////    todosItens.ProcuraRemove(todosItens.PegaElementoAletorio()->get_id(), ok);
////
////    cout << "Quantidade de elementos todosItens: " << todosItens.QuantidadeElementos() << endl << endl;
//
//	// Agora sobre o plano
//
//	cout << "Quantidade de elementos plano: " << plano.QuantidadeElementos() << endl;
//
////    //Inserindo na lista plano
//
//	cout << "Inserindo... " << endl;
//
//    InsereNplano(10, &plano, &todosItens);
//
//    //Exibindo a lista plano
//   plano.ExibeLista();
//
//   cout << "Quantidade de elementos plano: " << plano.QuantidadeElementos() << endl;
//
//   return 0;
//}
//
