/* HEADER PARA A BIBLIOTECA DECK 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tipoDeck
*/
#ifndef _H_DECKBISCA
#define _H_DECKBISCA
/*Aqui vai as funcoes*/
#include "cards.h"  //já inclui a <stdlib.h>
#include <sys/time.h>


////STRUCTS
typedef struct structDeck{
    tCarta carta;
    tipoDeck* proximo;
} itemDeck;

typedef struct controladorDeck{
    itemDeck *primeiro, *ultimo;
    int tamanho;
} tipoDeck;


////FUNÇÕES
/*
    OBJETIVO: Preenche 'deck' de maneira correta.\n
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' está alocado.
    POS-CONDICAO: 'deck' é alocado na memória corretamente, de maneira ordenada. 
    O que 'deck' apontava antes é perdido.
*/
void preencheDeck(tipoDeck *deck);

/*
    OBJETIVO: Embaralhar 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' está embaralhado.
*/
void embaralha(tipoDeck *deck);

/*
    OBJETIVO: Desalocar toda a memória ocupada por 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' não ocupa mais espaço no HEAP e aponta para NULL.
*/
void destroiDeck(tipoDeck *deck);

/*
    OBJETIVO: Imprimir 'deck' na tela.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: Nada é alterado.
*/
void imprimeDeck(tipoDeck *deck);

/*
    OBJETIVO: Verificar se 'deck' está alocado corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: 0 quando não está corretamente alocado, 1 quando está.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char checaExistencia(tDeck *deck);

#endif  //_H_DECKBISCA