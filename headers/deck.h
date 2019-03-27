/* HEADER PARA A BIBLIOTECA DECK */
#ifndef _H_DECK_BISCA
#define _H_DECK_BISCA
/*Aqui vai as funcoes*/
#include <stdbool.h>

struct Cartas{
    bool *naipe, **figuras;
    int cartas_nao_usadas;
    //Uma matriz para armazenar todo o baralho apenas uma única vez. Ao longo do jogo, será operado ponteiros para esse struct, nem a necessidade de declarar novamente.
};
typedef Cartas Cartas;




/*Endif para evitar warnings*/
#endif