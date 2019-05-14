/* HEADER PARA A BIBLIOTECA PLAYER 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tPlayer
*/
#ifndef _H_PLAYERBISCA
#define _H_PLAYERBISCA
/*Aqui vai as funcoes*/
#include "deck.h"



//  Define os jogadores em lista circular;
typedef struct Player tPlayer;

typedef struct Player{
    char points, Id;
    tDeck *mao;
    tPlayer *proximo;
}tPlayer;


/*______ FUNÇÕES ______*/

/*
    OBJETIVO: Verificar se 'player' está alocado corretamente.
    ENTRADAS: Ponteiro para 'player'.
    SAIDA: 1 quando é nulo, 2 quando a mão é nula, 3 quando o próximo é nulo, 0 quando tá safe
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char invalido(tPlayer *player);

/*
    OBJETIVO: Funcao que seta a quantidade de pontos de um player.
    ENTRADAS: Ponteiro tPLayer* para 'player alvo' e uma Variavel char para 'pontos'.
    SAIDA: -
    PRE-CONDICAO: Player existir.
    POS-CONDICAO: Quantidade de pontos atribuida ao jogador.
*/
void pSetPontos(tPlayer *player, char pontos);

/*
    OBJETIVO: Funcao que retorna a quantidade de pontos de um player.
    ENTRADAS: Ponteiro tPLayer* para 'player alvo'.
    SAIDA: Pontuacao de um player dado.
    PRE-CONDICAO: Player existir.
    POS-CONDICAO: Nada alterado.
*/
char pGetPontos(tPlayer *player);

/*
    OBJETIVO: Funcao que seta o ID de um player (humano ou bot).
    ENTRADAS: Ponteiro tPLayer* para 'player' e uma Variavel char para dizer que eh humano.
    SAIDA: -
    PRE-CONDICAO: Player existir.
    POS-CONDICAO: ID humano atribuido ao jogador.
*/
void pSetId(tPlayer *player, char humano);

/*
    OBJETIVO: Funcao que retorna ID de um player.
    ENTRADAS: Ponteiro tPLayer* para 'player alvo'.
    SAIDA: ID de um player dado.
    PRE-CONDICAO: Player existir.
    POS-CONDICAO: Nada alterado.
*/
char pGetId(tPlayer *player);

/*
    OBJETIVO: Funcao que seta qual sera a proxima celula.
    ENTRADAS: Ponteiro tPLayer* para 'player' e Ponteiro tPLayer* para 'proximo player'.
    SAIDA: -
    PRE-CONDICAO: Player atual e o proximo existirem.
    POS-CONDICAO: O proximo do Player de entrada ser o Player 'proximo' tambem da entrada.
*/
void pSetProximo(tPlayer *player, tPlayer *proximo);

/*
    OBJETIVO: Funcao que retorna o proximo player de uma celula na lista.
    ENTRADAS: Ponteiro tPLayer* para 'player alvo'.
    SAIDA: Ponteiro tPLayer* para 'proximo player'.
    PRE-CONDICAO: Player existir.
    POS-CONDICAO: Proximo player retornado.
*/
tPlayer* pGetProximo(tPlayer *player);

/*
    OBJETIVO: Funcao que seta a 'mao' do jogador.
    ENTRADAS: Ponteiro tPLayer* para 'player' e Ponteiro tDeck* para 'mao'.
    SAIDA: -
    PRE-CONDICAO: Player atual e o deck da mao existirem.
    POS-CONDICAO: Mao do jogador ser o deck passado na entrada.
*/
void pSetMao(tPlayer *player, tDeck *mao);

/*
    OBJETIVO: Funcao que retorna a 'mao' do jogador.
    ENTRADAS: Ponteiro tPLayer* para 'player alvo'.
    SAIDA: Ponteiro tDeck* para 'mao'.
    PRE-CONDICAO: Player existir.
    POS-CONDICAO: Mao do jogador retornada.
*/
tDeck *pGetMao(tPlayer *player);

/*
    OBJETIVO: Iniciar 'Player' vazio corretamente.
    ENTRADAS: -
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: -
    POS-CONDICAO: Inicializado, porém sem elementos, ou zerados.
*/
tPlayer* iniciaPlayerVazio(int i);

/*
    OBJETIVO: Iniciar 'n' quantidades de tPlayers vazios corretamente.
    ENTRADAS: A quantidade de players a ser inicializada.
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: n > 0.
    POS-CONDICAO: Inicializados, porém sem elementos, ou zerados.
*/
tPlayer* iniciaNPlayers(int n);

/*
    OBJETIVO: Imprimir 'mao' na tela.
    ENTRADAS: Ponteiro para 'player'.
    SAIDA: -Copas 
A de Ou
    PRE-CONDCopas 
A de Oustá alocado corretamente.
    POS-CONDCopas 
A de Ou
*/
void imprimeMao(tPlayer *player);

/*
    OBJETIVO: Faz 'player' compra a carta do topo de 'deck'.
    ENTRADAS: Ponteiro para 'player' e ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente, o mesmo para player.
    POS-CONDICAO: Nada é alterado.
*/
void compraCarta(tPlayer *player, tDeck *deck);

/*
    OBJETIVO: Faz 'player' jogar a carta da posição 'n' da sua mão em 'deck'.
    ENTRADAS: Ponteiro para 'player' e ponteiro para 'deck' e a posição da carta.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente, o mesmo para player.
    POS-CONDICAO: Nada é alterado.
*/
void jogaCarta(tPlayer *player, tDeck *deck, int n);

/*
    OBJETIVO: Desalocar toda a memória ocupada por 'player'.
    ENTRADAS: Ponteiro para 'player'.
    SAIDA: -
    PRE-CONDICAO: 'player' existe e está alocado corretamente.
    POS-CONDICAO: 'player' não ocupa mais espaço no HEAP e aponta para NULL.
*/
void destroiPlayers(tPlayer *player);
#endif