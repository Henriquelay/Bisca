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


//*STRUCTS

//Define os items que serão contidos no deck. (lista encadeada de cartas com sentinela)
typedef struct tCelula tCelula;
typedef struct tCelula{
    tCarta carta;
    tCelula *proximo;
} tCelula;

//Define as sentinelas e auxiliadores do deck. (lista encadeada de cartas com sentinela)
typedef struct tDeck{
    tCelula *primeiro, *ultimo;
    int quantidade;
} tDeck;


//*DEFINEM AS CARTAS PARA LEGIBILIDADE (O VALOR REPRESENTA A ORDEM DE ENCARTE)
#define CARTA1 9
#define CARTA2 0
#define CARTA3 1
#define CARTA4 2
#define CARTA5 3
#define CARTA6 4
#define CARTA7 8
#define CARTAJ 6
#define CARTAQ 5
#define CARTAK 7

//*DEFINEM OS NAIPES PARA LEGIBILIDADE
#define NAIPEO 0
#define NAIPEP 1
#define NAIPEC 2
#define NAIPEE 3

//*FUNÇÕES

/*
    OBJETIVO: Embaralhar 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' está embaralhado.
*/
void embaralha(tDeck *deck);

/*
    OBJETIVO: Preencher 'deck' corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' com todas as cartas que serão usadas na bisca nele.
*/
void preenche(tDeck *deck);

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
tDeck* iniciaVazio(void);

#endif  //_H_DECKBISCA