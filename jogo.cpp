#include "jogo.h"
#include "headers.h"

jogo::GameState jogo::estado_jogo = Inicializado;
sf::RenderWindow jogo::janela;
sf::Text jogo::timerText;
sf::Text jogo::totalText;
sf::Sprite jogo::background;
bool feitico::lancado = false;
varinha::estado_varinha varinha::_estado_varinha = Rotacionando;
float feitico::dir = 0;
int jogo::countdown = 59;
int jogo::total = 0;

void jogo::Start(varinha* hook, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar)
{
   
    
    //GAME CLOCK & TOTAL
    countdown = 59;
    total = 0;
    
    //convert countdown to a string
    string countdownString = "00:" + to_string(countdown);
    
    //LOAD FONT AND TEXT
    timerText.setString(countdownString);
    

    //LOAD FONT AND TEXT
    totalText.setString("$ " + to_string(total));
    
    
    
    //OLHAR ISSO DIREITO
    
    
    
//    //Inicializando itensGanhar
//    InicializaItensGanhar(itensGanhar, todosItens);
//    
//    itensGanhar->ExibeLista();
    //if (estado_jogo != Inicializado)
     //   return;
    
    janela.create(sf::VideoMode(1024, 768), "HARRY", sf::Style::Close); //DEFINE TAMANHO DA JANELA, O QUE APARECE NO CABE�ALHO E FUNCOES DISPONIVEIS (FECHAR, RESIZE, MINIMIZAR)
    
    sf::Texture imagem;
    imagem.loadFromFile("imagens/fundo2.jpg");
    background.setTexture(imagem); //DEFINE O BACKGROUND
    
    //Resetando plano
    plano->DeletaTudo();
    
    InsereNplano(20, plano, todosItens);
    
    estado_jogo = jogo::Mostrando_Tela_Inicial;
    
    while (!IsExiting())
    {
        loop_jogo(hook, clock, plano, todosItens, itensGanhar);
    }
    
    janela.close();
}

void jogo::CriandoTudo()
{
    //GAME CLOCK & TIMER
    sf::Clock clock;
    int countdown = 30;
    
    //LOAD GAME TIMER FONT
    sf::Font timerFont;
    timerFont.loadFromFile("imagens/harry.ttf");
    
    //convert countdown to a string
    string countdownString = "00:" + to_string(countdown);
    
    //LOAD FONT AND TEXT
    timerText.setFont(timerFont);
    timerText.setPosition(200, 22);
    timerText.setCharacterSize(30);
    timerText.setFillColor(sf::Color::Black);
    
    //LOAD GAME TOTAL FONT
    sf::Font totalFont;
    totalFont.loadFromFile("imagens/harry.ttf");
    
    //LOAD FONT AND TEXT
    totalText.setFont(totalFont);
    totalText.setPosition(67, 43);
    totalText.setCharacterSize(25);
    totalText.setFillColor(sf::Color::Black);
    
    varinha *hook = new varinha();
    
    ListaSimples plano, todosItens, itensGanhar;
    
    Nodetype *anel = new Nodetype(), *bellatrix = new Nodetype(), *calice = new Nodetype(), *chapeu = new Nodetype(), *comensal = new Nodetype(), *coruja = new Nodetype(),
    *dementador = new Nodetype(), *diadema = new Nodetype(), *diario = new Nodetype(), *dobby = new Nodetype(), *dolores = new Nodetype(), *draco = new Nodetype(),
    *dumbledore = new Nodetype(), *felix = new Nodetype(), *hagrid = new Nodetype(), *hermione = new Nodetype(), *livro = new Nodetype(), *lucius = new Nodetype(),
    *medalhao = new Nodetype(), *minerva = new Nodetype(), *nagini = new Nodetype(), *pomo = new Nodetype(), *ron = new Nodetype(), *snape = new Nodetype(),
    *taca = new Nodetype(), *voldemort = new Nodetype(), *horcrux1 = new Nodetype(), *horcrux2 = new Nodetype(), *horcrux3 = new Nodetype(), *horcrux4 = new Nodetype(),
    *horcrux5 = new Nodetype(), *horcrux6 = new Nodetype();
    
    srand(time(NULL));
    
    //HORCRUX 1 a 6
    
    anel->set_id(1);
    anel->set_info("imagens/anel.png");
    anel->set_tipo(3);
    anel->set_valor(1000);
    todosItens.Insere(anel);
    horcrux1->CopiaNode(anel);                      //DEPOIS TEM Q COMENTAR TODOS AQUI Q INICIALIZA O ITENS GANHAR
    itensGanhar.Insere(horcrux1);
    
    taca->set_id(2);
    taca->set_info("imagens/taca.png");
    taca->set_tipo(3);
    taca->set_valor(1000);
    todosItens.Insere(taca);
    horcrux2->CopiaNode(taca);
    itensGanhar.Insere(horcrux2);
    
    medalhao->set_id(3);
    medalhao->set_info("imagens/medalhao.png");
    medalhao->set_tipo(3);
    medalhao->set_valor(1000);
    todosItens.Insere(medalhao);
    horcrux3->CopiaNode(medalhao);
    itensGanhar.Insere(horcrux3);
    
    diadema->set_id(4);
    diadema->set_info("imagens/diadema.png");
    diadema->set_tipo(3);
    diadema->set_valor(1000);
    horcrux4->CopiaNode(diadema);
    itensGanhar.Insere(horcrux4);
    
    diario->set_id(5);
    diario->set_info("imagens/diario.png");
    diario->set_tipo(3);
    diario->set_valor(1000);
    horcrux5->CopiaNode(diario);
    itensGanhar.Insere(horcrux5);
    
    nagini->set_id(6);
    nagini->set_info("imagens/nagini.png");
    nagini->set_tipo(3);
    nagini->set_valor(1000);
    horcrux6->CopiaNode(nagini);
    itensGanhar.Insere(horcrux6);
    
    
    // INIMIGOS 7 a 13
    
    voldemort->set_id(7);
    voldemort->set_info("imagens/voldemort.png");
    voldemort->set_tipo(1);
    voldemort->set_valor(5000);
    todosItens.Insere(voldemort);
    
    dementador->set_id(8);
    dementador->set_info("imagens/dementador.png");
    dementador->set_tipo(1);
    dementador->set_valor(300);
    todosItens.Insere(dementador);
    
    bellatrix->set_id(9);
    bellatrix->set_info("imagens/bellatrix.png");
    bellatrix->set_tipo(1);
    bellatrix->set_valor(250);
    todosItens.Insere(bellatrix);
    
    dolores->set_id(10);
    dolores->set_info("imagens/dolores.png");
    dolores->set_tipo(1);
    dolores->set_valor(200);
    todosItens.Insere(dolores);
    
    lucius->set_id(11);
    lucius->set_info("imagens/lucius.png");
    lucius->set_tipo(1);
    lucius->set_valor(150);
    todosItens.Insere(lucius);
    
    comensal->set_id(12);
    comensal->set_info("imagens/comensal.png");
    comensal->set_tipo(1);
    comensal->set_valor(100);
    todosItens.Insere(comensal);
    
    draco->set_id(13);
    draco->set_info("imagens/draco.png");
    draco->set_tipo(1);
    draco->set_valor(75);
    todosItens.Insere(draco);
    
    
    // AMIGOS 14 a 20
    
    dumbledore->set_id(14);
    dumbledore->set_info("imagens/dumbledore.png");
    dumbledore->set_tipo(2);
    dumbledore->set_valor(300);
    todosItens.Insere(dumbledore);
    
    minerva->set_id(15);
    minerva->set_info("imagens/minerva.png");
    minerva->set_tipo(2);
    minerva->set_valor(300);
    todosItens.Insere(minerva);
    
    hermione->set_id(16);
    hermione->set_info("imagens/hermione.png");
    hermione->set_tipo(2);
    hermione->set_valor(250);
    todosItens.Insere(hermione);
    
    ron->set_id(17);
    ron->set_info("imagens/ron.png");
    ron->set_tipo(2);
    ron->set_valor(250);
    todosItens.Insere(ron);
    
    
    snape->set_id(18);
    snape->set_info("imagens/snape.png");
    snape->set_tipo(2);
    snape->set_valor(200);
    todosItens.Insere(snape);
    
    
    hagrid->set_id(19);
    hagrid->set_info("imagens/hagrid.png");
    hagrid->set_tipo(2);
    hagrid->set_valor(125);
    todosItens.Insere(hagrid);
    
    dobby->set_id(20);
    dobby->set_info("imagens/dobby.png");
    dobby->set_tipo(2);
    dobby->set_valor(50);
    todosItens.Insere(dobby);
    
    
    // ITENS 21 a 26
    
    pomo->set_id(21);
    pomo->set_info("imagens/pomo1.png");
    pomo->set_tipo(4);
    pomo->set_valor(500);
    todosItens.Insere(pomo);
    
    chapeu->set_id(22);
    chapeu->set_info("imagens/chapeu.png");
    chapeu->set_tipo(4);
    chapeu->set_valor(75);
    todosItens.Insere(chapeu);
    
    calice->set_id(23);
    calice->set_info("imagens/calice.png");
    calice->set_tipo(4);
    calice->set_valor(60);
    todosItens.Insere(calice);
    
    felix->set_id(24);
    felix->set_info("imagens/felix.png");
    felix->set_tipo(4);
    felix->set_valor(50);
    todosItens.Insere(felix);
    
    coruja->set_id(25);
    coruja->set_info("imagens/coruja.png");
    coruja->set_tipo(4);
    coruja->set_valor(30);
    todosItens.Insere(coruja);
    
    livro->set_id(26);
    livro->set_info("imagens/livro.png");
    livro->set_tipo(4);
    livro->set_valor(10);
    todosItens.Insere(livro);
    
    
    
    
    jogo::Start(hook, clock, &plano, &todosItens, &itensGanhar);
}

void jogo::JogarNovamente(varinha* hook, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar)
{
    jogo::Start(hook, clock, plano, todosItens, itensGanhar);
    estado_jogo = jogo::Jogando;
}

bool jogo::IsExiting()
{
    if (estado_jogo == jogo::Saindo)
        return true;
    else
        return false;
}

void jogo::loop_jogo(varinha* hook, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar)
{
    switch (estado_jogo)
    {
        case jogo::Mostrando_Menu:
        {
            mostrar_menu();
            break;
        }
        case jogo::Mostrando_Tela_Inicial:
        {
            mostrar_tela_inicial();
            break;
        }
        case jogo::Mostrando_Instrucao:
        {
            //mostrar_instrucao();
            break;
        }
        case jogo::Mostrando_Transicao:
        {
            mostrar_transicao();
            break;
        }
        case jogo::Ganhando:
        {
            mostrar_ganhou(hook, clock, plano, todosItens, itensGanhar);
            break;
        }
        case jogo::Perdendo:
        {
            mostrar_perdeu(hook, clock, plano, todosItens, itensGanhar);
            break;
        }
        case jogo::Jogando:
        {
            sf::Event evento_atual;
            sf::Sprite botao_pausar;
            sf::Texture imagem1;
            sf::Sprite botao_sair;
            sf::Texture imagem2;
            
            imagem1.loadFromFile("imagens/pausar.png");
            botao_pausar.setTexture(imagem1);
            botao_pausar.setPosition(897, 30);
            
            imagem2.loadFromFile("imagens/sair.png");
            botao_sair.setTexture(imagem2);
            botao_sair.setPosition(910, 75);
            
            //TIMER - 30 SECONDS
            int timer = clock.getElapsedTime().asSeconds();
            
            if (timer > 0)
            {
                countdown = countdown - 1;
                string countdownString = "00:" + to_string(countdown);
                timerText.setString(countdownString);
                clock.restart();
            }
            
            verifica_colisao(hook, plano, itensGanhar);
            janela.clear();
            janela.draw(background);
            hook->desenhar(janela);
            hook->update_todos();
            desenha_todos_plano(plano, janela);
            janela.draw(botao_pausar);
            janela.draw(botao_sair);
            janela.draw(timerText);
            janela.draw(totalText);
            janela.display();
            
            while (janela.pollEvent(evento_atual))
            {
                switch (evento_atual.type)
                {
                    case sf::Event::Closed:
                        estado_jogo = jogo::Saindo;
                        break;
                    case sf::Event::KeyPressed:
                        if (evento_atual.key.code == sf::Keyboard::Escape)
                            mostrar_menu();
                        else if(evento_atual.key.code == sf::Keyboard::F && feitico::lancado == false){
                            varinha::_estado_varinha = varinha::Bombarda;
                            feitico::dir = (hook->get_rotacao() + 90)*0.0174532925;
                        }
                        else if(evento_atual.key.code == sf::Keyboard::J && feitico::lancado == false){
                            varinha::_estado_varinha = varinha::Accio;
                            feitico::dir = (hook->get_rotacao() + 90)*0.0174532925;
                        }

                        break;
                    case sf::Event::MouseButtonPressed:
                        if (evento_atual.mouseButton.button == sf::Mouse::Left && feitico::lancado == false)
                        {
                            varinha::_estado_varinha = varinha::Bombarda;
                            feitico::dir = (hook->get_rotacao() + 90)*0.0174532925;
                        }
                        if (evento_atual.mouseButton.button == sf::Mouse::Right && feitico::lancado == false)
                        {
                            varinha::_estado_varinha = varinha::Accio;
                            feitico::dir = (hook->get_rotacao() + 90)*0.0174532925;
                        }
                        if (evento_atual.mouseButton.button == sf::Mouse::Left)
                            if (botao_pausar.getGlobalBounds().contains(sf::Mouse::getPosition(janela).x, sf::Mouse::getPosition(janela).y))
                            {
                                mostrar_menu();
                            }
                        if (evento_atual.mouseButton.button == sf::Mouse::Left)
                            if (botao_sair.getGlobalBounds().contains(sf::Mouse::getPosition(janela).x, sf::Mouse::getPosition(janela).y))
                            {
                                estado_jogo = jogo::Saindo;
                            }
                        break;
                    case sf::Event::MouseButtonReleased:
                        break;
                    default:
                        break;
                }
            }
            break;
        }
    }
}

void jogo::mostrar_tela_inicial()
{
    Tela_Inicial tela_incial;
    tela_incial.Mostrar(janela);
    estado_jogo = jogo::Mostrando_Menu;
}

void jogo::mostrar_ganhou(varinha *hook, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar)
{
    Ganhou ganhou;
    Ganhou::ganhou resultado = ganhou.Mostrar(janela);
    switch (resultado)
    {
        case Ganhou::Sair:
            estado_jogo = jogo::Saindo;
            break;
        case Ganhou::Jogar_Novamente:
            jogo::JogarNovamente(hook, clock, plano, todosItens, itensGanhar);
            break;
    }
}

void jogo::mostrar_perdeu(varinha *hook, sf::Clock & clock, ListaSimples* plano, ListaSimples* todosItens, ListaSimples* itensGanhar)
{
    Perdeu perdeu;
    Perdeu::perdeu resultado = perdeu.Mostrar(janela);
    switch (resultado)
    {
        case Perdeu::Sair:
            estado_jogo = jogo::Saindo;
            break;
        case Perdeu::Jogar_Novamente:
            jogo::JogarNovamente(hook, clock, plano, todosItens, itensGanhar);
            break;
    }
}


//OLHAR ISSO DIREITO
//void jogo::InicializaItensGanhar(ListaSimples *itensGanhar, ListaSimples *listaGeral){
//    int i, x, y;
//    Nodetype *no;
//    Nodetype *noPtr;
//    
//    
//    cout << "agora 4 : " << listaGeral->PegaElementoN(4)->get_id() << endl;
//    for (i = 1; i<=6; i++)
//    {
//        no = listaGeral->PegaElementoN(i);
//        noPtr = new Nodetype();
//        noPtr->CopiaNode(no);
//        noPtr->carregar(noPtr->get_info());
//        
//        itensGanhar->Insere(noPtr);
//    }
//    
//}

void jogo::InsereNplano(int n, ListaSimples * plano, ListaSimples * listaGeral)
{
    int i, x, y, qtd = 0, r;
   // int restantes = n, qtd, maisI;
    Nodetype *no;
    Nodetype *noPtr;
    
    // 33% de chance de ter 1 horcrux na fase e 66% de chance de nao ter nenhuma (pode ser alterado, apenas mudando o 2 ali)
    //r = (rand() % 2);
    r = 0;
    cout << "r = " << r << endl; // confirmar a frequencia que o 1 aparece
    if(r==0){
        // Inserindo horcrux
        no = listaGeral->PegaElementoAleatorioTodosTipoX(3);
        noPtr = new Nodetype();
        noPtr->CopiaNode(no);
        noPtr->set_id(0);
        noPtr->carregar(noPtr->get_info());
        x = (rand() % 919);
        y = (rand() % 300 + 321);
        noPtr->set_posicao(x, y);
        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
        
        plano->Insere(noPtr);
        qtd = 1;
    }

    for (i = qtd; i<n; i++)
    {
        no = listaGeral->PegaElementoAleatorioTodosTipoX(5);
        noPtr = new Nodetype();
        noPtr->CopiaNode(no);
        noPtr->set_id(i);
        noPtr->carregar(noPtr->get_info());
        x = (rand() % 919);
        y = (rand() % 300 + 321);
        noPtr->set_posicao(x, y);
        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
        
        plano->Insere(noPtr);
    }
    

//    // QUERIA ESCOLHER A QUANTIDADE CERTA DE CADA COISA, MAS ESTAVA DANDO ERRADO
//    //Inserindo horcrux
//    cout << "HORCRUX " << endl;
//    qtd = 1;
//    no = listaGeral->PegaElementoAleatorioTodosTipoX(3);
//     cout << " Elemento = " << no->get_id()<< endl;
//    noPtr = new Nodetype();
//    noPtr->CopiaNode(no);
//    noPtr->set_id(0);
//    noPtr->carregar(noPtr->get_info());
//    x = (rand() % 919);
//    y = (rand() % 300 + 321);
//    noPtr->set_posicao(x, y);
//    noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
//    
//    //plano->Insere(noPtr);
//    restantes -= qtd;
//    
//    maisI = 1;
//
//    
//    
//    //Inserindo ITENS
//    qtd = restantes/2;
//    cout << "Primeiro qtd = " << qtd << endl;
//    for (i = 0; i<qtd; i++)
//        {
//            no = listaGeral->PegaElementoAleatorioTodosTipoX(4);
//            cout << "i = " << i << " Elemento = " << no->get_id()<< endl;
//            noPtr = new Nodetype();
//            noPtr->CopiaNode(no);
//            noPtr->set_id(i+maisI);
//            noPtr->carregar(noPtr->get_info());
//            x = (rand() % 919);
//            y = (rand() % 300 + 321);
//            noPtr->set_posicao(x, y);
//            noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
//            
//            cout << "AAAA" << endl;
//            //plano->Insere(noPtr);
//        }
//    restantes-=qtd;
//    
//    maisI += qtd;
//    
//    cout << "TERMINEI PRIMEIRO FOR" << endl;
//    //Inserindo INIMIGOS
//    qtd = restantes/2;
//    for (i = 0; i<qtd; i++)
//    {
//        no = listaGeral->PegaElementoAleatorioTodosTipoX(1);
//        noPtr = new Nodetype();
//        noPtr->CopiaNode(no);
//        noPtr->set_id(i+maisI);
//        noPtr->carregar(noPtr->get_info());
//        x = (rand() % 919);
//        y = (rand() % 300 + 321);
//        noPtr->set_posicao(x, y);
//        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
//        
//       // plano->Insere(noPtr);
//    }
//    restantes-=qtd;
//    
//    maisI += qtd;
//    
//    //Inserindo AMIGOS
//    qtd = restantes;
//    for (i = 0; i<qtd; i++)
//    {
//        no = listaGeral->PegaElementoAleatorioTodosTipoX(2);
//        noPtr = new Nodetype();
//        noPtr->CopiaNode(no);
//        noPtr->set_id(i+maisI);
//        noPtr->carregar(noPtr->get_info());
//        x = (rand() % 919);
//        y = (rand() % 300 + 321);
//        noPtr->set_posicao(x, y);
//        noPtr->set_origem(noPtr->_sprite.getLocalBounds().width/2, noPtr->_sprite.getLocalBounds().height/2);
//        
//       // plano->Insere(noPtr);
//    }
//    restantes-=qtd;
//    maisI += qtd;
//    
//    cout << "restantes = " << restantes << endl;
 }


bool jogo::VerificaGanhou(ListaSimples *itensGanhar){
    if(itensGanhar->QuantidadeElementos()==0)
        return true;
    else
        return false;
}

void jogo::desenha_todos_plano(ListaSimples * plano, sf::RenderWindow& window)
{
    Nodetype *Paux;
    if (plano->QuantidadeElementos() > 0)
        Paux = plano->PegaElementoN(1);
    else
        Paux = NULL;
    
    while (Paux != NULL) 
    {
        Paux->desenhar(window);
        Paux = Paux->get_next();
    }
}

void jogo::verifica_colisao(varinha* hook, ListaSimples * plano, ListaSimples * itensGanhar)
{
    Nodetype *Paux;
    bool ok = false;
    Paux = plano->PegaElementoN(1);
    
    while ((Paux != NULL) && (ok == false))
    {
        if (Paux->colidiu(hook->_feitico))
        {
            switch (Paux->get_tipo())
            {
                case 1:
                    if (hook->_feitico.get_tipo() == 2)
                        total -= 200;
                    else
                        total += Paux->get_valor();
                    break;
                case 2:
                    if (hook->_feitico.get_tipo() == 2)
                        total += Paux->get_valor();
                    else
                        total -= 500;
                    break;
                case 3:
                    if (hook->_feitico.get_tipo() == 2)
                        estado_jogo = Perdendo;
                    else
                    {
                        total += Paux->get_valor();
                        itensGanhar->ProcuraRemove(Paux->get_info(), ok);
                    }
                    break;
                case 4:
                    if (hook->_feitico.get_tipo() == 2)
                        total += Paux->get_valor();
                    break;
                default:
                    break;
            }
            feitico::lancado = false;
            varinha::_estado_varinha = varinha::Acertou;
            plano->ProcuraRemove(Paux->get_id(), ok);
            totalText.setString(to_string(total));
        }
        Paux = Paux->get_next();
    }
}

void jogo::mostrar_menu()
{
    Menu menu;
    Menu::menu_inicial resultado = menu.Mostrar(janela);
    switch (resultado)
    {
        case Menu::Sair:
            estado_jogo = jogo::Saindo;
            break;
        case Menu::Jogar:
            estado_jogo = jogo::Jogando;
            break;
            /*case Menu::Instrucoes:
             estado_jogo = jogo::Mostrando_Instrucao;*/
    }
}

void jogo::mostrar_transicao()
{
}

int main(int argc, char** argv)
{
    jogo::CriandoTudo();
    
    return 0;
}