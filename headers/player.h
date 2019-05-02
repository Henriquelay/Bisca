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
    tDeck hand;
    tPlayer *proximo; 
}tPlayer;


//FUNÇÕES

/*
    OBJETIVO: Inicia os jogadores que jogarão o jogo.
    ENTRADAS: A quantidade de jogadores a serem iniciados.
    SAIDA: Ponteiro para o primeiro dos jogadores a ser iniciado.
    PRE-CONDICAO: 'qtde' > 0.
    POS-CONDICAO: Os jogadores são alocados dinâmicamente e corretamente.
*/
tPlayer* iniciaJogadores(int qtde);




#endif