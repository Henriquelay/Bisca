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
    tDeck hand;
    tPlayer *proximo; 
}tPlayer;


/*
    OBJETIVO: Troca 2 células de lugar.
    ENTRADAS: Ponteiro para duas células.
    SAIDA: -
    PRE-CONDICAO: As células existem e são válidas.
    POS-CONDICAO: As duas células trocam de posição na lista, inalteradas.
*/
tPlayer* iniciaJogadores(int qtde);




#endif