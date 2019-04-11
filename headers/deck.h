/* HEADER PARA A BIBLIOTECA DECK 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tDeck
*/
#ifndef _H_DECKBISCA
#define _H_DECKBISCA
/*Aqui vai as funcoes*/
#include "cards.h"  //já inclui a <stdlib.h>

////DEFINES
#define INICIODODECK    0
#define MAXIMODODECK    39


////STRUCTS
typedef struct{
    tCarta* cartas;
    int Primeiro, Ultimo;
} tDeck;


////FUNÇÕES
/*
    OBJETIVO: Inicia o deck de maneira correta.
    ENTRADAS: Ponteiro para o deck.
    SAIDA: -
    PRE-CONDICAO: Foi passado tDeck* deck como argumento para que seja obrigado a existir.
    POS-CONDICAO: deck é alocado na memória corretamente.
*/
void iniciaDeckCheio(tDeck *deck);

/*
    OBJETIVO: Embaralhar o deck.
    ENTRADAS: Ponteiro para o deck.
    SAIDA: -
    PRE-CONDICAO: O deck existe e está alocado corretamente.
    POS-CONDICAO: O deck está embaralhado.
*/
void embaralha(tDeck *deck);




#endif  //_H_DECKBISCA