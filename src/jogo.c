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
    int cont = 0, indice = 0;

    for(maior = getCarta(aux); aux != NULL; aux = proximo(aux), cont++){
        if(getValor(getCarta(aux)) >= getValor(maior))
            if(getNaipe(getCarta(aux)) == getNaipe(maior) || getNaipe(getCarta(aux)) == getNaipe(trunfo))
                indice = cont;
    }
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
        printf("JOGADOR %d COMPROU!\n", i);
        compraCarta(aux, baralho);
    }
}

/*
    OBJETIVO: Realizar uma jogada (do usuário e dos bots).
    ENTRADAS: Ponteiro tPlayer* para 'jogador' e ponteiro tDeck* para 'monte' e uma variavel char para 'dificuldade do jogo'.
    SAIDA: -
    PRE-CONDICAO: Ser um jogador com tres cartas ma mao.
    POS-CONDICAO: Jogador ter efetuado a jogada.
*/
void jogada(tPlayer *player, tDeck *monte, tCarta *trunfo, char dificuldade, int nJogadores){
    
    int cartaJogada = -1;
    tPlayer *aux = player;
    for(int i = 0; i < nJogadores; i++, aux = pGetProximo(aux)){
        if(!pGetId(aux)){
            if(primeiro(monte) != NULL){    //caso o jogador não seja o primeiro
                puts("Monte:");
                imprimeDeck(monte);
            }
            puts("Sua mao:");
            imprimeDeck(pGetMao(aux));
            printf("O trunfo é ");
            filtrAEPrinta(trunfo);
            do{
                printf("Que carta quer jogar? > ");
                scanf(" %d", &cartaJogada);
                if(!(cartaJogada > 0 && cartaJogada <= (getQuantidade(pGetMao(aux)))))  //guard para não jogar carta inválida
                    puts("Esse indice de carta eh invalido! Escolha um que represente uma carta na sua mao!\n");
            } while(!(cartaJogada > 0 && cartaJogada <= (getQuantidade(pGetMao(aux)))));
            printf("Opcao aceita: ");
            filtrAEPrinta(getCarta(buscaCelula(pGetMao(aux), cartaJogada - 1)));
            jogaCarta(aux, monte, cartaJogada);
        }
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
    int bot = 1, maior = -1, pontosAux = 0, indice = 0, indiceGanhador = -1, ocorrencias = 0;
    for(tPlayer *aux = pGetProximo(players); aux != players; aux = pGetProximo(aux)){
        pontosAux = pGetPontos(aux);
        printf("PONTOS BOT %d: %d\n", bot++, pontosAux);

        if(pontosAux > maior){
            maior = pontosAux;
            ocorrencias = 1;
            indiceGanhador = indice;
        }else 
            if(pontosAux == maior)
                ocorrencias++;

        indice++;
    }
    printf("Seus pontos: %d\n", pGetPontos(players));

    if(ocorrencias > 1)
        printf("Ocorreu um empate! TODOS PERDEM!!!\n");
    else
        if(indiceGanhador == 0)
            printf("Voce ganhou, parabens!\n");
        else
            printf("O jogador BOT %d ganhou.\n", indiceGanhador);

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

    printf("ID : %d ", pGetId(qmGanhou));
    if(pGetId(qmGanhou) == 0){
        printf("Voce Ganhhou!\n");
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
tPlayer* turno(tPlayer *player, tDeck *baralho, tDeck *monte, tCarta *trunfo, char dificuldade, int nJogadores){

    // if(player != NULL)
    //     imprimeDeck(pGetMao(player));
    if(getQuantidade(pGetMao(player)) < 3)
        todosCompram(player, baralho, nJogadores);
    jogada(player, monte, trunfo, 0, nJogadores);
    
    puts("#MONTE NO FIM DO TURNO#");
    imprimeDeck(monte);
    //indicar quem ganhou
    tPlayer *qmGanhou = ganhadorMonte(player, monte, trunfo);

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
    POS-CONDICAO: Inicializados, porém sem eleme0ntos, ou zerados.
*/
void jogo(tDeck *baralho){
    preenche(baralho);
    embaralha(baralho, 15000);
    // imprimeDeck(baralho);
    corta(baralho);
    // puts("Baralho:");
    // imprimeDeck(baralho);
    // puts("Trunfo:");
    // filtrAEPrinta(trunfo);

    //-----------------
    int nJogadores;
    do{
        printf("O jogo sera para quantos jogadores? > ");
        scanf(" %d", &nJogadores);

        if((NUMERODENAIPES * NUMERODEVALORES) % nJogadores != 0)
            printf("O jogo n funciona com essa quantidade de players. Coloque uma quantidade que todos comprem carta iguais. Sao %d cartas.\n", NUMERODENAIPES * NUMERODEVALORES);

    }while((NUMERODENAIPES * NUMERODEVALORES) % nJogadores != 0);
    
    if(nJogadores > getQuantidade(baralho)) return;

    tPlayer *players = iniciaNPlayers(nJogadores);
    pSetId(players, 1);      //define o primeiro player como player humano

    for(int i = 0; i < 3; i++)   //jogares compram 3 cartas
        todosCompram(players, baralho, nJogadores);
    // puts("Baralho:");
    // imprimeDeck(baralho);

    
    tCarta *trunfo = defineTrunfo(baralho);
    // puts("SUA MAO");
    // imprimeDeck(pGetMao(players));
    tDeck *monte = iniciaVazio();
    while(!vazio(pGetMao(players)))
        players = turno(players, baralho, monte, trunfo, 0, nJogadores);
    // preenche(monte);
    // puts("Carta \"comprada\":");
    // filtrAEPrinta(getCarta(retiraCelula(baralho, 0)));
    // puts("Baralho apos o turno:");
    // imprimeDeck(baralho);

    // printf("MAO APOS O TURNO:\n");
    // imprimeDeck(players->mao);
    // printf("MONTE:\n");
    // imprimeDeck(monte);

    // while(ultimo(baralho) != NULL){
    //     printf("O Trunfo é ");
    //     filtrAEPrinta(trunfo);
    //     turno(players, baralho, monte, trunfo, 0);  //teste no easy
    // }

    destroiDeck(monte);
    mostraPontuacaoEQuemGanhou(players);

    destroiPlayers(players);
}