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
    tCarta *maior = getCarta(aux);
    int cont = 0;

    while(aux != NULL){
        if(getValor(getCarta(aux)) >= getValor(maior))
            if(getNaipe(getCarta(aux)) == getNaipe(trunfo) || getNaipe(getCarta(aux)) == getNaipe(trunfo))
                maior = getCarta(aux);

        aux = proximo(aux);
    }

    for(aux = primeiro(monte); !cartasIguais(getCarta(aux), maior); aux = proximo(aux)){
        // printf("Achei a carta!\n");
        cont++;    //só para achar qual foi o jogador que ganhou
    }
    
    return cont;
}

void todosCompram(tPlayer *player, tDeck *baralho){
    if(vazio(baralho)) return;
    tPlayer *aux = player;
    do{
        compraCarta(aux, baralho);
        aux = pGetProximo(aux);
    } while(aux != player);
}

void jogada(tPlayer *player, tDeck *monte, tCarta *trunfo, char dificuldade){
    
    int cartaJogada = -1;
    tPlayer *aux = player;
    do{
        if(pGetHumano(aux)){
            // puts("Monte:");
            // imprimeDeck(monte);
            puts("Sua mao:");
            imprimeDeck(pGetMao(aux));
            printf("O trunfo é ");
            filtrAEPrinta(trunfo);
            do{
                printf("Que carta quer jogar? > ");
                scanf(" %d", &cartaJogada);
                if(!(cartaJogada > 0 && cartaJogada <= (getQuantidade(pGetMao(aux)))))
                    puts("Esse indice de carta eh invalido! Escolha um que represente uma carta na sua mao!\n");
            }   while(!(cartaJogada > 0 && cartaJogada <= (getQuantidade(pGetMao(aux)))));
            printf("Opcao aceita: ");
            filtrAEPrinta(getCarta(buscaCelula(pGetMao(aux), cartaJogada - 1)));
            jogaCarta(aux, monte, cartaJogada);
        }
        else jogadaBot(aux, monte, trunfo, dificuldade);
        aux = pGetProximo(aux);
    } while(aux != player);
}

void mostraPontuacao(tPlayer *players){
    int cont0 = 1, maior = 0, pontosAux = 0;
    for(tPlayer *aux = pGetProximo(players); aux != players; aux = pGetProximo(aux)){
        pontosAux = pGetPontos(aux);
        printf("PONTOS BOT %d: %d\n", cont0++, pontosAux);
        if(pontosAux > maior)
            maior = pontosAux;
    }
    printf("Seus pontos: %d\n", pGetPontos(players));
}

void turno(tPlayer *player, tDeck *baralho, tDeck *monte, tCarta *trunfo, char dificuldade){

    // if(player != NULL)
    //     imprimeDeck(pGetMao(player));
    if(getQuantidade(pGetMao(player)) < 3)
        todosCompram(player, baralho);
    jogada(player, monte, trunfo, 0);
    
    //indicar quem ganhou
    int qmGanhouIndice = ganhador(monte, trunfo);
    tPlayer *qmGanhou = player;
    for(int i = 0; i < qmGanhouIndice; i++)
        qmGanhou = pGetProximo(qmGanhou);
    printf("O ganhador do monte eh: ");
    if(qmGanhouIndice == 0) 
        printf("Voce!\n");
    else 
        printf("BOT %d!\n", qmGanhouIndice);

    //somar os pontos
    pSetPontos(qmGanhou, pGetPontos(qmGanhou) + contaPontos(monte));

    puts("#MONTE NO FIM DO TURNO#");
    imprimeDeck(monte);
    esvaziaDeck(monte);
}

void mostraquemganha(tPlayer *player){
    mostraPontuacao(player);
    int maiorponto = 0;
    for(tPlayer *aux = player; proximo(aux) != player; aux = proximo(aux)){
        maiorponto = pGetPontos(aux);
        aux = proximo(aux);
        if(pGetPontos(aux) > maiorponto)
            maiorponto = (pGetPontos(aux));
    }
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
    imprimeDeck(baralho);
    corta(baralho);
    tCarta *trunfo = defineTrunfo(baralho);
    int nJogadores;

    // puts("Baralho:");
    // imprimeDeck(baralho);
    // puts("Trunfo:");
    // filtrAEPrinta(trunfo);

    //-----------------
    printf("O jogo sera para quantos jogadores? > ");
    scanf(" %d", &nJogadores);
    if((NUMERODENAIPES * NUMERODEVALORES) % nJogadores != 0){
        printf("O jogo n funciona com essa quantidade de players. Coloque uma quantidade que todos comprem carta iguais. Sao %d cartas.\n", NUMERODENAIPES * NUMERODEVALORES);
    }
    if(nJogadores > getQuantidade(baralho)) return;

    tPlayer *players = iniciaNPlayers(nJogadores);
    pSetHumano(players, 1);      //define o primeiro player como player humano

    for(int i = 0; i < 3; i++)
        todosCompram(players, baralho);

    // puts("Baralho:");
    // imprimeDeck(baralho);

    
    // puts("SUA MAO");
    // imprimeDeck(pGetMao(players));
    tDeck *monte = iniciaVazio();
    while(!vazio(pGetMao(players)))
        turno(players, baralho, monte, trunfo, 0);
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

    mostraquemganha(players);

    destroiPlayers(players);
    destroiDeck(monte);
}