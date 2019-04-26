/* HEADER PARA A BIBLIOTECA CARDS 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tCards
*/
#ifndef _H_CARDSBISCA
#define _H_CARDSBISCA
/*Aqui vai as funcoes*/
#include <stdlib.h>
#include <stdio.h>

#define NUMERODENAIPES      4
#define NUMERODEVALORES     10

/*define o numero da carta e o naipe;
char naipe, valor;*/
typedef struct structCarta{
    char naipe, valor;
}tCarta;

//FUNÇÕES

/*
    OBJETIVO: Inicializa a carta e cria um ponteiro para ela
    ENTRADAS: O naipe da carta, a valor da carta
    SAIDA: Um ponteiro do tipo tCartas
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca
    POS-CONDICAO: Ponteiro criado com a carta identificada com o naipe e o seu simbulo/valor
*/
tCarta criaCarta(char naipe, char valor);

/*
    OBJETIVO: retorna o valor do naipe da carta
    ENTRADAS: Uma carta
    SAIDA: O naipe da carta de entrada
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Nenhuma
*/
char getNaipe(tCarta *carta);

/*
    OBJETIVO: retorna o valor da carta
    ENTRADAS: Uma carta
    SAIDA: O valor da carta de entrada
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Nenhuma
*/
char getValor(tCarta *carta);

/*
    OBJETIVO: Traduzir a saída de números para cartas.
    ENTRADAS: A carta.
    SAIDA: -
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca.
    POS-CONDICAO: O valor "traduzido" foi impresso na tela e nada foi alterado.
*/
void filtrAEPrinta(tCarta *carta);


#endif