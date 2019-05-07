#include "../headers/player.h"

/*
    OBJETIVO: Verificar se 'player' está alocado corretamente.
    ENTRADAS: Ponteiro para 'player'.
    SAIDA: 1 quando é nulo, 2 quando a mão é nula, 3 quando o próximo é nulo.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char invalido(tPlayer *player){
    if(player == NULL) return 1;
    if(player->mao == NULL) return 2;
    if(player->proximo == NULL) return 3;
    return 0;
}

void pSetPontos(tPlayer *player, char pontos){
    if(player != NULL)
        player->points = pontos;
}

char pGetPontos(tPlayer *player){
    if(player != NULL)
        return player->points;
    return 0;
}

void pSetProximo(tPlayer *player, tPlayer *proximo){
    if(player != NULL)
        player->proximo = proximo;
}

tPlayer* pGetProximo(tPlayer *player){
    if(player != NULL)
        return player->proximo;
    return NULL;
}

void pSetMao(tPlayer *player, tDeck *mao){
    if(player != NULL)
        player->mao = mao;
}

tDeck* pGetMao(tPlayer *player){
    if(player != NULL)
        return player->mao;
    return NULL; 
}

/*
    OBJETIVO: Iniciar 'Player' vazio corretamente.
    ENTRADAS: -
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: -
    POS-CONDICAO: Inicializado, porém sem elementos, ou zerados.
*/
tPlayer* iniciaPlayerVazio(void){
    tPlayer *player = (tPlayer*) malloc(sizeof(tPlayer));
    pSetPontos(player, 0);
    pSetProximo(player, NULL);
    pSetMao(player, NULL);
    return player;
}

/*
    OBJETIVO: Iniciar 'n' quantidades de tPlayers vazios corretamente.
    ENTRADAS: A quantidade de players a ser inicializada.
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: n > 0.
    POS-CONDICAO: Inicializados, porém sem elementos, ou zerados.
*/
tPlayer* iniciaNPlayers(int n){
    if(n < 1)
        return NULL;
    tPlayer *cabeca, *atual;
    cabeca = atual = iniciaPlayerVazio();
    for(int i = 1; i < n; i++){
    atual->proximo = iniciaPlayerVazio();   //percorre criando os outros N players
    atual = atual->proximo;
    }   
    atual->proximo = cabeca;    //faz a lista ficar circular;

    return cabeca;
}

/*
    OBJETIVO: Imprimir 'mao' na tela.
    ENTRADAS: Ponteiro para 'player'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: Nada é alterado.
*/
void imprimeMao(tPlayer *player){
    if(player != NULL)
        imprimeDeck(pGetMao(player));
}

/*
    OBJETIVO: Faz 'player' compra a carta do topo de 'deck'.
    ENTRADAS: Ponteiro para 'player' e ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente, o mesmo para player.
    POS-CONDICAO: Nada é alterado.
*/
void compraCarta(tPlayer *player, tDeck *deck){
    if(invalido(player) == 1) 
        return;
    if(invalido(player) == 2) 
        pSetMao(player, iniciaVazio());

    //TODO: NAO ACABADA TODO:
}