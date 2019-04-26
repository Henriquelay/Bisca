/* HEADER PARA A BIBLIOTECA PLAYER 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tPlayer
*/
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

#endif