/* HEADER PARA A BIBLIOTECA PLAYER 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tPlayer
*/
#ifndef _H_PLAYERBISCA
#define _H_PLAYERBISCA
/*Aqui vai as funcoes*/
#include "deck.h"

//Define os jogadores em lista circular;

typedef struct Player tPlayer;

typedef struct Player{
    char points;
    tDeck *mao;
    tPlayer *proximo; 
}tPlayer;


//FUNÇÕES

void pSetPontos(tPlayer *player, char pontos);

char pGetPontos(tPlayer *player);

void pSetProximo(tPlayer *player, tPlayer *proximo);

tPlayer* pGetProximo(tPlayer *player);

void pSetMao(tPlayer *player, tDeck *mao);

tDeck *pGetMao(tPlayer *player);

/*
    OBJETIVO: Iniciar 'Player' vazio corretamente.
    ENTRADAS: -
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: -
    POS-CONDICAO: Inicializado, porém sem elementos, ou zerados.
*/
tPlayer* iniciaPlayerVazio(void);

/*
    OBJETIVO: Iniciar 'n' quantidades de tPlayers vazios corretamente.
    ENTRADAS: A quantidade de players a ser inicializada.
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: n > 0.
    POS-CONDICAO: Inicializados, porém sem elementos, ou zerados.
*/
tPlayer* iniciaNPlayers(int n);

/*
    OBJETIVO: Imprimir 'mao' na tela.
    ENTRADAS: Ponteiro para 'player'.
    SAIDA: -Copas 
A de Ou
    PRE-CONDCopas 
A de Oustá alocado corretamente.
    POS-CONDCopas 
A de Ou
*/
void imprimeMao(tPlayer *player);

/*
    OBJETIVO: Verificar se 'player' está alocado corretamente.
    ENTRADAS: Ponteiro para 'player'.
    SAIDA: 1 quando é nulo, 2 quando a mão é nula, 3 quando o próximo é nulo, 0 quando 
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char invalido(tPlayer *player);

/*
    OBJETIVO: Faz 'player' compra a carta do topo de 'deck'.
    ENTRADAS: Ponteiro para 'player' e ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente, o mesmo para player.
    POS-CONDICAO: Nada é alterado.
*/
void compraCarta(tPlayer *player, tDeck *deck);

/*
    OBJETIVO: Desalocar toda a memória ocupada por 'player'.
    ENTRADAS: Ponteiro para 'player'.
    SAIDA: -
    PRE-CONDICAO: 'player' existe e está alocado corretamente.
    POS-CONDICAO: 'player' não ocupa mais espaço no HEAP e aponta para NULL.
*/
void destroiPlayers(tPlayer *player);

#endif