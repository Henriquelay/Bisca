/* HEADER PARA A BIBLIOTECA JOGO
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funções de controle de jogo
*/
#ifndef _H_JOGOBISCA
#define _H_JOGOBISCA
/*Aqui vai as funcoes*/
#include "player.h"


int ganhador(tDeck *monte, tCarta *trunfo);

/*
    OBJETIVO: Iniciar 'n' quantidades de tPlayers vazios corretamente.
    ENTRADAS: A quantidade de players a ser inicializada.
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: n > 0.
    POS-CONDICAO: Inicializados, porém sem elementos, ou zerados.
*/
void jogo(tDeck *baralho);


#endif