/* HEADER PARA A BIBLIOTECA PLAYER 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tPlayer
*/
#ifndef _H_PLAYERBISCA
#define _H_PLAYERBISCA
/*Aqui vai as funcoes*/
#include "deck.h"

//Define os jogadores em lista circular;

typedef struct Player tPlayer;

typedef struct Player{
    char points;
    tDeck *mao;
    tPlayer *proximo; 
}tPlayer;


//FUNÇÕES

/*
    OBJETIVO: Inserir 'inserir' em 'lista', no final, e caso 'lista' seja vazio, inicia com ele.
    ENTRADAS: Ponteiros de jogadores para 'lista' e 'inserir'.
    SAIDA: -
    PRE-CONDICAO: -
    POS-CONDICAO: Os jogadores são inseridos na lista.
*/
void inserePlayer(tPlayer* lista, tPlayer* inserir);




#endif