#include "jogo.h"

jogo::GameState jogo::estado_jogo = Inicializado;
sf::RenderWindow jogo::janela;
sf::Text jogo::timerText;
sf::Text jogo::totalText;
sf::Text jogo::nivelText;
sf::Text jogo::metaText;
sf::Sprite jogo::background;
bool feitico::lancado = false;
varinha::estado_varinha varinha::_estado_varinha = Rotacionando;
float feitico::dir = 0;
int jogo::countdown = 30;
int jogo::total = 0;
int jogo::meta = 0;
int jogo::nivel = 1;

void jogo::Start(varinha* hook, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos)
{
   
    
    //GAME CLOCK & TOTAL
    countdown = 30;
    total = 0;
    meta = 650;
    nivel = 1;
    
    //convert countdown to a string
    string countdownString = "00:" + to_string(countdown);
    
    //LOAD FONT AND TEXT
    timerText.setString(countdownString);
    
    nivelText.setString(to_string(nivel));

    

    //LOAD FONT AND TEXT
    totalText.setString("$ " + to_string(total));
    
    
    metaText.setString("$ " + to_string(meta));

    
    janela.create(sf::VideoMode(1024, 768), "HARRY", sf::Style::Close); //DEFINE TAMANHO DA JANELA, O QUE APARECE NO CABEÇALHO E FUNCOES DISPONIVEIS (FECHAR, RESIZE, MINIMIZAR)
    
    sf::Texture imagem;
    imagem.loadFromFile(resourcePath() + "fundo2.jpg");
    background.setTexture(imagem); //DEFINE O BACKGROUND
    
    //Resetando as listas
    plano->DeletaTudo();
    itensGanhar->DeletaTudo();
    destruidos->DeletaTudo();
    
    itensGanhar->InicializaItensGanhar(todosItens);  // INICIALIZANDO ITENS GANHAR
    plano->InsereNplano(20, todosItens, itensGanhar); // INICIALIZANDO O PLANO
    
    
    estado_jogo = jogo::Mostrando_Tela_Inicial;
    
    while (!IsExiting())
    {
        loop_jogo(hook, clock, plano, todosItens, itensGanhar, destruidos);
    }
    
    janela.close();
}

void jogo::CriandoTudo()
{
    //GAME CLOCK & TIMER
    sf::Clock clock;
    
    //LOAD GAME TIMER FONT
    sf::Font Font;
    Font.loadFromFile(resourcePath() + "harry.ttf");
    
    //convert countdown to a string
    string countdownString = "00:" + to_string(countdown);
    
    //LOAD FONT AND TEXT
    timerText.setFont(Font);
    timerText.setPosition(200, 22);
    timerText.setCharacterSize(30);
    timerText.setFillColor(sf::Color::Black);
    
    //LOAD FONT AND TEXT
    totalText.setFont(Font);
    totalText.setPosition(67, 43);
    totalText.setCharacterSize(25);
    totalText.setFillColor(sf::Color::Black);
    
    //LOAD FONT AND TEXT
    metaText.setFont(Font);
    metaText.setPosition(67, 13);
    metaText.setCharacterSize(25);
    metaText.setFillColor(sf::Color::Black);
    
    //LOAD FONT AND TEXT
    nivelText.setFont(Font);
    nivelText.setPosition(360, 40);
    nivelText.setCharacterSize(30);
    nivelText.setFillColor(sf::Color::Black);
  
    
    varinha *hook = new varinha();
    
    ListaSimples todosItens;
    ItensGanhar itensGanhar, destruidos;
    Plano plano;
    
    Nodetype *anel = new Nodetype(), *bellatrix = new Nodetype(), *calice = new Nodetype(), *chapeu = new Nodetype(), *comensal = new Nodetype(), *coruja = new Nodetype(),
    *dementador = new Nodetype(), *diadema = new Nodetype(), *diario = new Nodetype(), *dobby = new Nodetype(), *dolores = new Nodetype(), *draco = new Nodetype(),
    *dumbledore = new Nodetype(), *felix = new Nodetype(), *hagrid = new Nodetype(), *hermione = new Nodetype(), *livro = new Nodetype(), *lucius = new Nodetype(),
    *medalhao = new Nodetype(), *minerva = new Nodetype(), *nagini = new Nodetype(), *pomo = new Nodetype(), *ron = new Nodetype(), *snape = new Nodetype(),
    *taca = new Nodetype(), *voldemort = new Nodetype();
    
    srand(time(NULL));
    
    //HORCRUX 1 a 6
    
    anel->set_id(1);
    anel->set_info(resourcePath() + "anel.png");
    anel->set_tipo(3);
    anel->set_valor(1000);
    todosItens.Insere(anel);
    
    taca->set_id(2);
    taca->set_info(resourcePath() + "taca.png");
    taca->set_tipo(3);
    taca->set_valor(1000);
    todosItens.Insere(taca);
    
    medalhao->set_id(3);
    medalhao->set_info(resourcePath() + "medalhao.png");
    medalhao->set_tipo(3);
    medalhao->set_valor(1000);
    todosItens.Insere(medalhao);
    
    diadema->set_id(4);
    diadema->set_info(resourcePath() + "diadema.png");
    diadema->set_tipo(3);
    diadema->set_valor(1000);
    todosItens.Insere(diadema);
    
    diario->set_id(5);
    diario->set_info(resourcePath() + "diario.png");
    diario->set_tipo(3);
    diario->set_valor(1000);
    todosItens.Insere(diario);
    
    nagini->set_id(6);
    nagini->set_info(resourcePath() + "nagini.png");
    nagini->set_tipo(3);
    nagini->set_valor(1000);
    todosItens.Insere(nagini);
    
    
    // INIMIGOS 7 a 13
    
    voldemort->set_id(7);
    voldemort->set_info(resourcePath() + "voldemort.png");
    voldemort->set_tipo(1);
    voldemort->set_valor(5000);
    todosItens.Insere(voldemort);
    
    dementador->set_id(8);
    dementador->set_info(resourcePath() + "dementador.png");
    dementador->set_tipo(1);
    dementador->set_valor(300);
    todosItens.Insere(dementador);
    
    bellatrix->set_id(9);
    bellatrix->set_info(resourcePath() + "bellatrix.png");
    bellatrix->set_tipo(1);
    bellatrix->set_valor(250);
    todosItens.Insere(bellatrix);
    
    dolores->set_id(10);
    dolores->set_info(resourcePath() + "dolores.png");
    dolores->set_tipo(1);
    dolores->set_valor(200);
    todosItens.Insere(dolores);
    
    lucius->set_id(11);
    lucius->set_info(resourcePath() + "lucius.png");
    lucius->set_tipo(1);
    lucius->set_valor(150);
    todosItens.Insere(lucius);
    
    comensal->set_id(12);
    comensal->set_info(resourcePath() + "comensal.png");
    comensal->set_tipo(1);
    comensal->set_valor(100);
    todosItens.Insere(comensal);
    
    draco->set_id(13);
    draco->set_info(resourcePath() + "draco.png");
    draco->set_tipo(1);
    draco->set_valor(75);
    todosItens.Insere(draco);
    
    
    // AMIGOS 14 a 20
    
    dumbledore->set_id(14);
    dumbledore->set_info(resourcePath() + "dumbledore.png");
    dumbledore->set_tipo(2);
    dumbledore->set_valor(300);
    todosItens.Insere(dumbledore);
   
    minerva->set_id(15);
    minerva->set_info(resourcePath() + "minerva.png");
    minerva->set_tipo(2);
    minerva->set_valor(300);
    todosItens.Insere(minerva);
   
    hermione->set_id(16);
    hermione->set_info(resourcePath() + "hermione.png");
    hermione->set_tipo(2);
    hermione->set_valor(250);
    todosItens.Insere(hermione);
   
    ron->set_id(17);
    ron->set_info(resourcePath() + "ron.png");
    ron->set_tipo(2);
    ron->set_valor(250);
    todosItens.Insere(ron);
   
    
    snape->set_id(18);
    snape->set_info(resourcePath() + "snape.png");
    snape->set_tipo(2);
    snape->set_valor(200);
    todosItens.Insere(snape);
   
    
    hagrid->set_id(19);
    hagrid->set_info(resourcePath() + "hagrid.png");
    hagrid->set_tipo(2);
    hagrid->set_valor(125);
    todosItens.Insere(hagrid);
    
    dobby->set_id(20);
    dobby->set_info(resourcePath() + "dobby.png");
    dobby->set_tipo(2);
    dobby->set_valor(50);
    todosItens.Insere(dobby);
    
    
    // ITENS 21 a 26
    
    pomo->set_id(21);
    pomo->set_info(resourcePath() + "pomo1.png");
    pomo->set_tipo(4);
    pomo->set_valor(500);
    todosItens.Insere(pomo);
    
    chapeu->set_id(22);
    chapeu->set_info(resourcePath() + "chapeu.png");
    chapeu->set_tipo(4);
    chapeu->set_valor(75);
    todosItens.Insere(chapeu);
    
    calice->set_id(23);
    calice->set_info(resourcePath() + "calice.png");
    calice->set_tipo(4);
    calice->set_valor(60);
    todosItens.Insere(calice);
    
    felix->set_id(24);
    felix->set_info(resourcePath() + "felix.png");
    felix->set_tipo(4);
    felix->set_valor(50);
    todosItens.Insere(felix);
    
    coruja->set_id(25);
    coruja->set_info(resourcePath() + "coruja.png");
    coruja->set_tipo(4);
    coruja->set_valor(30);
    todosItens.Insere(coruja);
    
    livro->set_id(26);
    livro->set_info(resourcePath() + "livro.png");
    livro->set_tipo(4);
    livro->set_valor(10);
    todosItens.Insere(livro);
 
    
    jogo::Start(hook, clock, &plano, &todosItens, &itensGanhar, &destruidos);
}

// LEMBRAR DE SETTAR O FEITICO PARA NAO LANCADO

void jogo::JogarNovamente(varinha* hook, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos)
{
    jogo::Start(hook, clock, plano, todosItens, itensGanhar, destruidos);
    estado_jogo = jogo::Jogando;
}
                       
void jogo::nova_fase(varinha * hook, sf::Clock & clock, Plano* plano, ListaSimples * todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos)
    {
    //GAME CLOCK & TOTAL
    countdown = 30 + (nivel * 5);
    meta += 650 + (total/2);
    nivel += 1;
        
    //convert countdown to a string
    string countdownString = "00:" + to_string(countdown);
        
    //LOAD FONT AND TEXT
    timerText.setString(countdownString);
        
    //LOAD FONT AND TEXT
    nivelText.setString(to_string(nivel));
        
    //LOAD FONT AND TEXT
    totalText.setString("$ " + to_string(total));
        
    //LOAD FONT AND TEXT
    metaText.setString("$ " + to_string(meta));
        
    //OLHAR ISSO DIREITO
        
    //    //Inicializando itensGanhar
    //    InicializaItensGanhar(itensGanhar, todosItens);
    //
    //    itensGanhar->ExibeLista();
    //if (estado_jogo != Inicializado)
    //   return;
        
    plano->DeletaTudo();
    plano->InsereNplano(20, todosItens, itensGanhar);
        
    estado_jogo = jogo::Jogando;
    feitico::lancado = false;
    
        
    while (!IsExiting())
    {
        loop_jogo(hook, clock, plano, todosItens, itensGanhar, destruidos);
    }
        
    janela.close();
}
                       
bool jogo::IsExiting()
{
    if (estado_jogo == jogo::Saindo)
        return true;
    else
        return false;
}

void jogo::loop_jogo(varinha* hook, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos)
{
    switch (estado_jogo)
    {
        case jogo::Mostrando_Menu:
        {
            mostrar_menu();
            break;
        }
        case jogo::Nova_Fase:
        {
            nova_fase(hook, clock, plano, todosItens, itensGanhar, destruidos);
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
        case jogo::Mostrando_Transicao_Passou:
        {
            mostrar_transicao();
            break;
        }
        case jogo::Mostrando_Transicao_Horcrux:
        {
            mostrar_transicao_horcrux(destruidos);
            break;
        }
        case jogo::Ganhando:
        {
            mostrar_ganhou(hook, clock, plano, todosItens, itensGanhar, destruidos);
            break;
        }
        case jogo::Perdendo:
        {
            mostrar_perdeu(hook, clock, plano, todosItens, itensGanhar, destruidos);
            break;
        }
        case jogo::Jogando:
        {
            sf::Event evento_atual;
            sf::Sprite botao_pausar;
            sf::Texture imagem1;
            sf::Sprite botao_sair;
            sf::Texture imagem2;
            
            imagem1.loadFromFile(resourcePath() + "pausar.png");
            botao_pausar.setTexture(imagem1);
            botao_pausar.setPosition(897, 30);
            
            imagem2.loadFromFile(resourcePath() + "sair.png");
            botao_sair.setTexture(imagem2);
            botao_sair.setPosition(910, 75);
            
            //TIMER - 30 SECONDS
            int timer = clock.getElapsedTime().asSeconds();
            
            if (timer > 0)
            {
                string countdownString;
                if (countdown > 9)
                {
                    countdownString = "00:" + to_string(countdown);
                }
                else
                    countdownString = "00:0" + to_string(countdown);
                
                countdown = countdown - 1;
                timerText.setString(countdownString);
                clock.restart();
            }
            
            
            if (countdown == 0 || plano->QuantidadeElementos() == 0)
            {
                if (verifica_passou())
                {
                    cout << "VERIFICANDO" << verifica_passou() << endl;
                    if(itensGanhar->QuantidadeElementos() != 6)
                        estado_jogo = jogo::Mostrando_Transicao_Horcrux;
                    else
                        estado_jogo = jogo::Mostrando_Transicao_Passou;
                }
                else
                    estado_jogo = jogo::Perdendo;
            }
            
            if (VerificaGanhou(itensGanhar))
                estado_jogo = jogo::Ganhando;
            
            
            
            
            verifica_colisao(hook, plano, itensGanhar, destruidos, todosItens);
            
            janela.clear();
            janela.draw(background);
            hook->desenhar(janela);
            hook->update_todos();
            plano->desenha_todos_plano(janela);
            janela.draw(botao_pausar);
            janela.draw(botao_sair);
            janela.draw(nivelText);
            janela.draw(timerText);
            janela.draw(metaText);
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
                                
                                // PRESTAR ATENCAO PQ ESTA SOLTANDO UM FEITICO QUANDO DESPAUSA
                                
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

void jogo::mostrar_ganhou(varinha *hook, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos)
{
    Ganhou ganhou;
    Ganhou::ganhou resultado = ganhou.Mostrar(janela);
    switch (resultado)
    {
        case Ganhou::Sair:
            estado_jogo = jogo::Saindo;
            break;
        case Ganhou::Jogar_Novamente:
            jogo::JogarNovamente(hook, clock, plano, todosItens, itensGanhar, destruidos);
            break;
    }
}

void jogo::mostrar_perdeu(varinha *hook, sf::Clock & clock, Plano* plano, ListaSimples* todosItens, ItensGanhar* itensGanhar, ItensGanhar* destruidos)
{
    Perdeu perdeu;
    Perdeu::perdeu resultado = perdeu.Mostrar(janela);
    switch (resultado)
    {
        case Perdeu::Sair:
            estado_jogo = jogo::Saindo;
            break;
        case Perdeu::Jogar_Novamente:
            jogo::JogarNovamente(hook, clock, plano, todosItens, itensGanhar, destruidos);
            break;
    }
}

bool jogo::VerificaGanhou(ItensGanhar* itensGanhar)
{
    if (itensGanhar->QuantidadeElementos() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
                       
bool jogo::verifica_passou()
{
    if (total >= meta)
    {
        return true;
    }
    return false;
}





// PODE SER UMA FUNCAO DO PLANO



//void jogo::desenha_todos_plano(Plano* plano, sf::RenderWindow& window)
//{
//    Nodetype *Paux;
//    if (plano->QuantidadeElementos() > 0)
//        Paux = plano->PegaElementoN(1);
//    else
//        Paux = NULL;
//    
//    while (Paux != NULL) 
//    {
//        Paux->desenhar(window);
//        Paux = Paux->get_next();
//    }
//}

void jogo::verifica_colisao(varinha* hook, Plano* plano, ItensGanhar* itensGanhar, ItensGanhar* destruidos, ListaSimples* todosItens)
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
                        itensGanhar->ProcuraRemove(Paux->get_info(), ok, destruidos, todosItens);  // ACHO QUE O ERRO ESTA AQUI
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
            totalText.setString("$ " + to_string(total));
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
    transicao_passou _transicao_passou;
    _transicao_passou.set_meta(meta + (total/2));
    _transicao_passou.Mostrar(janela);
    estado_jogo = jogo::Nova_Fase;
}
                       
void jogo::mostrar_transicao_horcrux(ItensGanhar* destruidos)
{
    transicao_horcrux2 _transicao_horcrux;
    _transicao_horcrux.MostrarHorcrux(janela, destruidos);
    estado_jogo = jogo::Mostrando_Transicao_Passou;
}
                       
int main(int argc, char** argv)
{
    jogo::CriandoTudo();
    
    return 0;
}