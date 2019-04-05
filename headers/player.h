/* HEADER PARA A BIBLIOTECA HAND */
#ifndef _H_PLAYERBISCA
#define _H_PLAYERBISCA
/*Aqui vai as funcoes*/
#include <stdlib.h>
#include "cards.h"

//Define os jogadores em lista;
typedef struct Player{
    char points;
    tListaCarta hand;
    tPlayer *proximo; 
}tPlayer;

/*Endif para evitar warnings*/
#endif