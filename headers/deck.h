/* HEADER PARA A BIBLIOTECA DECK 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tipoDeck
*/
#ifndef _H_DECKBISCA
#define _H_DECKBISCA
/*Aqui vai as funcoes*/
#include "cards.h"  //já inclui a <stdlib.h> e <stdio.h>
#include <time.h>


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
void embaralha(tDeck *deck, int passes);

/*
    OBJETIVO: Cortar 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' está cortado (a carta cortada é o trunfo e ela vai pro fundo do deck).
*/
void corta(tDeck *deck);

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
    SAIDA: 3 quando é nulo, 1 quando está vazio 2 quando a sentila está errada, 0 quando não é vazio nem nulo, e está OK, -1 quando tem algo de muito errado.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char vazio(tDeck *deck);

/*
    OBJETIVO: Troca 2 células de lugar.
    ENTRADAS: Ponteiro para duas células.
    SAIDA: -
    PRE-CONDICAO: As células existem e são válidas.
    POS-CONDICAO: As duas células trocam de posição na lista, inalteradas.
*/
void swap2Celulas(tCelula *a, tCelula *b);

/*
    OBJETIVO: Iniciar 'deck' vazio corretamente.
    ENTRADAS: -
    SAIDA: 'deck'.
    PRE-CONDICAO: -
    POS-CONDICAO: Inicializado, porém sem elementos.
*/
tDeck* iniciaVazio(void);

/*
    OBJETIVO: Inserir 'carta' em 'deck'. *Será inserida no início
    ENTRADAS: Ponteiro para 'deck', ponteiro para 'carta'.
    SAIDA: Endereço para a célula criada.
    PRE-CONDICAO: A carta existe.
    POS-CONDICAO: A célula foi corretamente alocada, a carta não foi alterada.
*/
tCelula* criaItem(tCarta *carta);

/*
    OBJETIVO: Selecionar a menor carta de 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: Ponteiro para a menor carta.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: .
*/
tCarta* menorCarta(tDeck *deck, char *trunfo);

#endif  //_H_DECKBISCA