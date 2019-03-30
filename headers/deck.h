/* HEADER PARA A BIBLIOTECA DECK */
#ifndef _H_DECKBISCA
#define _H_DECKBISCA
/*Aqui vai as funcoes*/
#include "cartas.h"

//Lista encadeada pra representar o deck, apontando as cartas já criadas
typedef struct CartaDeck{
    char* carta;
    tCarta* proxima;
} tCarta;



/*Endif para evitar warnings*/
#endif