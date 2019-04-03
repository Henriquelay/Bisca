/* HEADER PARA A BIBLIOTECA CARTAS */
#ifndef _H_CARDSBISCA
#define _H_CARDSBISCA
/*Aqui vai as funcoes*/
#include <stdlib.h>

//define o numero da carta e o naipe;
typedef struct Carta{
    char naipe;
    char valor;
}tCarta;

//define a lista de cartas (seria usado em várias bibliotecas relacionadas às cartas então é melhor deixar aqui);
typedef struct ListaCarta{
    tCarta carta;
    tListaCarta *proxima;
}tListaCarta;

/*Endif para evitar warnings*/
#endif