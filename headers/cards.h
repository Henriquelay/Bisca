/* HEADER PARA A BIBLIOTECA CARDS 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tCards
*/
#ifndef _H_CARDSBISCA
#define _H_CARDSBISCA
/*Aqui vai as funcoes*/
#include <stdlib.h>

#define NUMERODENAIPES      4
#define NUMERODEVALORES     10

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

////FUNÇÕES

tCarta criaCarta(char naipe; char valor);

//TODO: Filtro de impressão como função (switch)


#endif