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

//Define os items que serão contidos no deck. (lista encadeada de cartas com sentinela)
typedef struct itemDeck{
    tCarta carta;
    itemDeck *proximo;
} itemDeck;

//Define as sentinelas e auxiliadores do deck. (lista encadeada de cartas com sentinela)
typedef struct tDeck{
    itemDeck *primeiro, *ultimo;
    int quantidade;
} tDeck;


////FUNÇÕES

/*
    OBJETIVO: Embaralhar 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' está embaralhado.
*/
void embaralha(tDeck *deck);

/*
    OBJETIVO: Desalocar toda a memória ocupada por 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' não ocupa mais espaço no HEAP e aponta para NULL.
*/
void destroiDeck(tDeck *deck);

/*
    OBJETIVO: Imprimir 'deck' na tela.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: Nada é alterado.
*/
void imprimeDeck(tDeck *deck);

/*
    OBJETIVO: Inserir 'carta' em 'deck'. //TODO: A SER DEFINIDISE SERÁ INCLUÍDA NO INÍCIO OU NO FIM
    ENTRADAS: Ponteiro para 'deck', ponteiro para 'carta'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'carta' está contida em 'deck'.
*/
void insereCarta(tCarta *carta, tDeck *deck);

/*
    OBJETIVO: Verificar se 'deck' está alocado corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: 0 quando não está corretamente alocado, 1 quando está.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char vazio(tDeck *deck);

/*
    OBJETIVO: Iniciar 'deck' vazio corretamente.
    ENTRADAS: -
    SAIDA: 'deck'.
    PRE-CONDICAO: -
    POS-CONDICAO: Inicializado, porém sem elementos.
*/
tDeck iniciaVazio(void);

#endif  //_H_DECKBISCA