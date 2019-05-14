#include "../headers/jogo.h"

/*
    OBJETIVO: Calcular quem foi o ganhador (quem encartou) do monte.
    ENTRADAS: Ponteiro tDeck* para 'monte' e pontei tCarta* para 'trunfo'.
    SAIDA: A posição na lista encadeada do player ganhador.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
int ganhador(tDeck *monte, tCarta *trunfo){
    if(vazio(monte))
        return -1;

    tCelula *aux = primeiro(monte);
    tCarta *maior;
    int cont = 0, indice;

    for(maior = getCarta(aux); aux != NULL; aux = proximo(aux), cont++){
        if(getNaipe(getCarta(aux)) == getNaipe(maior)) //para encarte
            if(getValor(getCarta(aux)) >= getValor(maior)){
                indice = cont;
                maior = getCarta(aux);
            }
        if(getNaipe(getCarta(aux)) == getNaipe(trunfo) && getNaipe(maior) != getNaipe(trunfo)){  //para corte
                indice = cont;
                maior = getCarta(aux);
        }
    }

    printf("Indice do ganhador do monte: %d\n", indice);
    return indice;

}

/*
    OBJETIVO: Fazer com que todos os jogadores coprem uma carta do monte.
    ENTRADAS: Ponteiro tPlayer* para 'jogador' e ponteiro tDeck* para 'monte' e uma Variavel int para 'numero de jogadores'.
    SAIDA: -
    PRE-CONDICAO: Jogadores necessitarem comprar uma carta do monte.
    POS-CONDICAO: Jogadores com tres cartas novamente.
*/
void todosCompram(tPlayer *player, tDeck *baralho, int nJogares){
    if(vazio(baralho)) return;
    tPlayer *aux = player;
    for(int i = 0; i < nJogares; i++, aux = pGetProximo(aux)){
        if(pGetId(aux) == 0)
            printf("VOCE");
        else
            printf("BOT %d", pGetId(aux));
        printf(" COMPROU A CARTA ");
        filtrAEPrinta(getCarta(primeiro(baralho)));
        compraCarta(aux, baralho);
    }
}

/*
    OBJETIVO: Realizar uma jogada (do usuário).
    ENTRADAS: Ponteiro tPlayer* para 'jogador' e ponteiro tDeck* para 'monte' e um Ponteiro tCarta* para 'trunfo'.
    SAIDA: -
    PRE-CONDICAO: Ser um jogador com tres cartas ma mao.
    POS-CONDICAO: Jogador ter efetuado a jogada.
*/
void jogadaPlayer(tDeck *monte, tCarta *trunfo, tPlayer *jogador, tDeck *baralho){
    printf("VOCE VAI JOGAR\nOpcoes: \nm - mostra baralho\tc - corta baralho\np - exibir pontuacoes\tq - exibir quantidades de cartas\te - embaralhar\n");
    char cartaJogada = -1;
    int cartaJogadaInt = -1;
    int embaralhos = -1;
    if(primeiro(monte) != NULL){    //caso o jogador não seja o primeiro
        puts("Monte:");
        imprimeDeck(monte);
    }
    puts("Sua mao:");
    imprimeDeck(pGetMao(jogador));
    printf("O trunfo é ");
    filtrAEPrinta(trunfo);
    do{
        printf("Que carta quer jogar?\n>> ");
        scanf(" %c", &cartaJogada);
        switch(cartaJogada){
            case 'm':
            case 'M':
                puts("Baralho:");
                imprimeDeck(baralho);
                break;
            case 'c':
            case 'C':
                corta(baralho);
                puts("Cortado!");
                break;
            case 'p':
            case 'P':
                mostraPontuacao(jogador);
                break;
            case 'e':
            case 'E':
                printf("Quantas trocas devo fazer? >> ");
                scanf(" %d", &embaralhos);
                embaralha(baralho, embaralhos);
                puts("Embaralhado!");
                break;
            case 'q':
            case 'Q':
                printf("Baralho: %d\t Monte: %d\t Sua mao: %d\n", getQuantidade(baralho), getQuantidade(monte), getQuantidade(pGetMao(jogador)));
                int i = 1;
                for(tPlayer *aux = pGetProximo(jogador); aux != jogador; aux = pGetProximo(aux), i++)
                    printf("BOT %d: %d ", i, getQuantidade(pGetMao(aux)));
                puts("");
                puts("Sua mao:");
                imprimeDeck(pGetMao(jogador));
                puts("Monte:");
                imprimeDeck(monte);
                i = 1;
                for(tPlayer *aux = pGetProximo(jogador); aux != jogador; aux = pGetProximo(aux), i++){
                    printf("BOT %d: \n", i);
                    imprimeDeck(pGetMao(aux));
                }
                puts("");
                break;
            default:
                cartaJogadaInt = atoi(&cartaJogada);
                if(!(cartaJogadaInt > 0 && cartaJogadaInt <= (getQuantidade(pGetMao(jogador)))))  //guard para não jogar carta inválida
                    puts("Esse indice de carta eh invalido! Escolha um que represente uma carta na sua mao!\n");
        }
        cartaJogadaInt = atoi(&cartaJogada);
    } while(!(cartaJogadaInt > 0 && cartaJogadaInt <= (getQuantidade(pGetMao(jogador)))));
    printf("Opcao aceita: ");
    filtrAEPrinta(getCarta(buscaCelula(pGetMao(jogador), cartaJogadaInt - 1)));
    jogaCarta(jogador, monte, cartaJogadaInt);
}

/*
    OBJETIVO: Realizar uma jogada (do usuário e dos bots).
    ENTRADAS: Ponteiro tPlayer* para 'jogador' e ponteiro tDeck* para 'monte' e uma variavel char para 'dificuldade do jogo'.
    SAIDA: -
    PRE-CONDICAO: Ser um jogador com tres cartas ma mao.
    POS-CONDICAO: Jogador ter efetuado a jogada.
*/
void jogada(tPlayer *player, tDeck *monte, tCarta *trunfo, char dificuldade, int nJogadores, tDeck *baralho){

    tPlayer *aux = player;
    for(int i = 0; i < nJogadores; i++, aux = pGetProximo(aux)){
        if(pGetId(aux) == 0)               //0 é o código de humano
            jogadaPlayer(monte, trunfo, aux, baralho);
        else 
            jogadaBot(aux, monte, trunfo, dificuldade);
    }
}

/*
    OBJETIVO: Printa qual jogador ganhou a partida e a sua pontuacao (int) final.
    ENTRADAS: Ponteiro tPlayer* para 'Lista de jogadores'.
    SAIDA: -
    PRE-CONDICAO: O jogo ter terminado.
    POS-CONDICAO: Nada alterado.
*/
void mostraPontuacaoEQuemGanhou(tPlayer *players){
    int maior = -1, pontosAux = 0, indice = 0, indiceGanhador = -1, ocorrencias = 0;
    tPlayer *aux = players;
    do{
        pontosAux = pGetPontos(aux);
        if(pGetId(aux) == 0){    //se for humano
            printf("Seus pontos: %d\n", pontosAux);
        }else{
        printf("PONTOS BOT %d: %d\n", pGetId(aux), pontosAux);
        }

        if(pontosAux > maior){
            maior = pontosAux;
            ocorrencias = 1;
            indiceGanhador = indice;
        }else 
            if(pontosAux == maior)
                ocorrencias++;

        indice++;
        aux = pGetProximo(aux);
    } while(aux != players);

    if(ocorrencias > 1)
        printf("Ocorreu um empate! TODOS PERDEM!!!\n");
    else{
        for(int i = 0; i < indiceGanhador; i++)
            aux = pGetProximo(aux);
        if(pGetId(aux) == 0){
            printf("Parabens, voce ganhou!!!onzwe!w111\n\n");
            system("eject -T");
        }
        else
            printf("BOT %d ganhou!\n\n", pGetId(aux));
    }   
}

/*
    OBJETIVO: Printa e define qual jogador ganhou a rodada e soma sua pontuacao (int).
    ENTRADAS: Ponteiro tPlayer* para 'Lista de jogadores', Ponteiro tDeck* para 'monte', Ponteiro tCarta* para 'trunfo'.
    SAIDA: Ponteiro tPlayer* para 'jogador vencedor da rodada'.
    PRE-CONDICAO: O turno ter terminado.
    POS-CONDICAO: Definido o proximo a jogar.
*/
tPlayer* ganhadorMonte(tPlayer *player, tDeck *monte, tCarta* trunfo){
    int qmGanhouIndice = ganhador(monte, trunfo);
    tPlayer *qmGanhou = player;
    
    for(int i = 0; i < qmGanhouIndice; i++)
        qmGanhou = pGetProximo(qmGanhou);
    printf("O ganhador do monte eh: ");

    if(pGetId(qmGanhou) == 0){
        printf("Voce Ganhou!\n");
    }
    else{
        printf("BOT %d Ganhou!\n", pGetId(qmGanhou));
    }

    //somar os pontos
    pSetPontos(qmGanhou, pGetPontos(qmGanhou) + contaPontos(monte));

    return qmGanhou;
}

/*
    OBJETIVO: Funcao que realiza a jogada, distribui os pontos ao ganhador da rodada e retorna o jogador vencedor do turno.
    ENTRADAS: Ponteiro tPlayer* para 'Lista de jogadores', Ponteiro tDeck* para 'baralho', Ponteiro tDeck* para 'monte', Ponteiro tCarta para 'trunfo', Variavel char para 'Dificuldade do jogo', Variavel int para 'numero de jogadores'.
    SAIDA: Ponteiro tPlayer* para 'Jogador vencedor da rodada'.
    PRE-CONDICAO: Haver cartas para os jogadores comprar.
    POS-CONDICAO: Todos os jogadores terem feitos uma jogada, proximo a jogar definido.
*/
tPlayer* turno(tPlayer *player, tDeck *baralho, tDeck *monte, tCelula *trunfo, char dificuldade, int nJogadores){

    // if(player != NULL)
    //     imprimeDeck(pGetMao(player));
    if(getQuantidade(pGetMao(player)) < 3)
        todosCompram(player, baralho, nJogadores);

    jogada(player, monte, getCarta(trunfo), dificuldade, nJogadores, baralho);
    
    system("clear");
    puts("#MONTE NO FIM DO TURNO#");
    imprimeDeck(monte);
    //indicar quem ganhou
    tPlayer *qmGanhou = ganhadorMonte(player, monte, getCarta(trunfo));

    if(possui(monte, getCarta(trunfo)))
        resgataTrunfo(monte, trunfo);
    esvaziaDeck(monte);
    puts("--------------------------");
    return qmGanhou;
}

/*
    OBJETIVO: Printa a pontuacao (int) do jogador.
    ENTRADAS: Ponteiro tPlayer* para 'jogador'.
    SAIDA: -
    PRE-CONDICAO: -
    POS-CONDICAO: Nada alterado.
*/
void mostraPontuacao(tPlayer *player){
    int bot = 1;
    for(tPlayer *aux = pGetProximo(player); aux != player; aux = pGetProximo(aux))
        printf("PONTOS BOT %d: %d\n", bot++, pGetPontos(aux));

    printf("Seus pontos: %d\n", pGetPontos(player));
}

/*
    OBJETIVO: Iniciar 'n' quantidades de tPlayers vazios corretamente.
    ENTRADAS: A quantidade de players a ser inicializada.
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: n > 0.
    POS-CONDICAO: Inicializados, porém sem elementos, ou zerados.
*/
void jogo(tDeck *baralho){
    preenche(baralho);
    embaralha(baralho, 150000);
    corta(baralho);

    system("clear");
    int nJogadores = quantosJogadores();
    int dificuldade = dificuldadeMenu();
    if(nJogadores > getQuantidade(baralho)) return;

    tPlayer *players = iniciaNPlayers(nJogadores);

    for(int i = 0; i < 3; i++)   //jogares compram 3 cartas
        todosCompram(players, baralho, nJogadores);
    
    tCelula *trunfo = ultimo(baralho);
    tDeck *monte = iniciaVazio();
    system("clear");
    while(!vazio(pGetMao(players)))
        players = turno(players, baralho, monte, trunfo, dificuldade, nJogadores);
    free(trunfo);
    destroiDeck(monte);
    mostraPontuacaoEQuemGanhou(players);

    destroiPlayers(players);
}

/*
__________ MENU OPCOES _________

1. Número de jogadores
2. Dificuldade
3. Embaralhar
4. Cortar
    a. Começa o jogo
    b. Durante o jogo:
5. Mostrar o baralho
6. Mostrar pontuação de todos
7. Exibir  informações  como:  Cartas  restantes  no  baralho,  quantidade  de  cartas  na  mão.
8. Printar quando o bot compra, e qual compra
*/

/*
    OBJETIVO: Recebe do teclado a quantidade de jogadores da partida e trada a entrada.
    ENTRADAS: -
    SAIDA: Variavel int qtd para 'quantidade de jogadores'
    PRE-CONDICAO: -
    POS-CONDICAO: Nada alterado.
*/
int quantosJogadores(){
    char qtd = -1;

    printf("O JOGO SERA PARA QUANTOS JOGADORES?\n>> ");
    scanf(" %c", &qtd);
    
    while(qtd != '2' && qtd != '4'){
        printf("\nO JOGO SO PODE SER DE DOIS OU QUATRO JOGADORES\nO JOGO SERA PARA QUANTOS JOGADORES?\n>> ");
        scanf(" %c", &qtd); 
    }
    int qtdInt = 0;
    switch(qtd){
        case '2':
            qtdInt = 2;
            break;
        case '4':
            qtdInt = 4;
            break;
    }

    return qtdInt;
}

/*
    OBJETIVO: Recebe do teclado a dificuldade da partida e trada a entrada.
    ENTRADAS: -
    SAIDA: Variavel int dificuldade para 'dificuldade do jogo'
    PRE-CONDICAO: -
    POS-CONDICAO: Nada alterado.
*/
int dificuldadeMenu(){
    char dificuldade;

    printf("DEFINA A DIFICULDADE\nf/F PARA FACIL\nd/D PARA DIFICIL\n>> ");
    scanf(" %c", &dificuldade);
    
    while(dificuldade != 'f' && dificuldade != 'd'){
        printf("\nDIFICULDADE INVALIDA, LEMBRE-SE\nf/F PARA FACIL\nd/D PARA DIFICIL\nDIGITE NOVAMENTE\n>> ");
        scanf(" %c", &dificuldade);
    }
    int dificuldadeInt = -1;
    switch(dificuldade){
        case 'f': 
        case 'F':
            dificuldadeInt = 0;
            break;
        case 'd':
        case 'D':
            dificuldadeInt = 1;
            break;
    }

    return dificuldadeInt;
}