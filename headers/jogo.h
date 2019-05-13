/* HEADER PARA A BIBLIOTECA JOGO
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funções de controle de jogo
*/
#ifndef _H_JOGOBISCA
#define _H_JOGOBISCA
/*Aqui vai as funcoes*/
#include "AI.h"

/*
    OBJETIVO: Calcular quem foi o ganhador (quem encartou) do monte.
    ENTRADAS: Ponteiro tDeck* para 'monte' e ponteiro tCarta* para 'trunfo'.
    SAIDA: A posição na lista encadeada do player ganhador.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
int ganhador(tDeck *monte, tCarta *trunfo);

/*
    OBJETIVO: Fazer com que todos os jogadores coprem uma carta do monte.
    ENTRADAS: Ponteiro tPlayer* para 'jogador' e ponteiro tDeck* para 'monte' e uma Variavel int para 'numero de jogadores'.
    SAIDA: -
    PRE-CONDICAO: Jogadores necessitarem comprar uma carta do monte.
    POS-CONDICAO: Jogadores com tres cartas novamente.
*/
void todosCompram(tPlayer *player, tDeck *baralho, int nJogadores);

/*
    OBJETIVO: Realizar uma jogada (do usuário).
    ENTRADAS: Ponteiro tPlayer* para 'jogador' e ponteiro tDeck* para 'monte' e um Ponteiro tCarta* para 'trunfo'.
    SAIDA: -
    PRE-CONDICAO: Ser um jogador com tres cartas ma mao.
    POS-CONDICAO: Jogador ter efetuado a jogada.
*/
void jogadaPlayer(tDeck *monte, tCarta *trunfo, tPlayer *jogador);

/*
    OBJETIVO: Realizar uma jogada (do usuário e dos bots).
    ENTRADAS: Ponteiro tPlayer* para 'jogador' e ponteiro tDeck* para 'monte' e uma variavel char para 'dificuldade do jogo'.
    SAIDA: -
    PRE-CONDICAO: Ser um jogador com tres cartas ma mao.
    POS-CONDICAO: Jogador ter efetuado a jogada.
*/
void jogada(tPlayer *player, tDeck *monte, tCarta *trunfo, char dificuldade, int nJogadores);

/*
    OBJETIVO: Printa qual jogador ganhou a partida e a sua pontuacao (int) final.
    ENTRADAS: Ponteiro tPlayer* para 'Lista de jogadores'.
    SAIDA: -
    PRE-CONDICAO: O jogo ter terminado.
    POS-CONDICAO: Nada alterado.
*/
void mostraPontuacaoEQuemGanhou(tPlayer *players);

/*
    OBJETIVO: Printa e define qual jogador ganhou a rodada e soma sua pontuacao (int).
    ENTRADAS: Ponteiro tPlayer* para 'Lista de jogadores', Ponteiro tDeck* para 'monte', Ponteiro tCarta* para 'trunfo'.
    SAIDA: Ponteiro tPlayer* para 'jogador vencedor da rodada'.
    PRE-CONDICAO: O turno ter terminado.
    POS-CONDICAO: Definido o proximo a jogar.
*/
tPlayer* ganhadorMonte(tPlayer *player, tDeck *monte, tCarta* trunfo);

/*
    OBJETIVO: Funcao que realiza a jogada, distribui os pontos ao ganhador da rodada e retorna o jogador vencedor do turno.
    ENTRADAS: Ponteiro tPlayer* para 'Lista de jogadores', Ponteiro tDeck* para 'baralho', Ponteiro tDeck* para 'monte', Ponteiro tCarta para 'trunfo', Variavel char para 'Dificuldade do jogo', Variavel int para 'numero de jogadores'.
    SAIDA: Ponteiro tPlayer* para 'Jogador vencedor da rodada'.
    PRE-CONDICAO: Haver cartas para os jogadores comprar.
    POS-CONDICAO: Todos os jogadores terem feitos uma jogada, proximo a jogar definido.
*/
tPlayer* turno(tPlayer *player, tDeck *baralho, tDeck *monte, tCarta *trunfo, char dificuldade, int nJogadores);

/*
    OBJETIVO: Printa a pontuacao (int) do jogador.
    ENTRADAS: Ponteiro tPlayer* para 'jogador'.
    SAIDA: -
    PRE-CONDICAO: -
    POS-CONDICAO: Nada alterado.
*/
void mostraPontuacao(tPlayer *player);

/*
    OBJETIVO: Iniciar 'n' quantidades de tPlayers vazios corretamente.
    ENTRADAS: A quantidade de players a ser inicializada.
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: n > 0.
    POS-CONDICAO: Inicializados, porém sem elementos, ou zerados.
*/
void jogo(tDeck *baralho);

/* __________ MENU DE OPCOES _________ */

/*
    OBJETIVO: Recebe do teclado a quantidade de jogadores da partida e trada a entrada.
    ENTRADAS: -
    SAIDA: Variavel int qtd para 'quantidade de jogadores'
    PRE-CONDICAO: -
    POS-CONDICAO: Nada alterado.
*/
int quantosJogadores();

/*
    OBJETIVO: Recebe do teclado a dificuldade da partida e trada a entrada.
    ENTRADAS: -
    SAIDA: Variavel int dificuldade para 'dificuldade do jogo'
    PRE-CONDICAO: -
    POS-CONDICAO: Nada alterado.
*/
int dificuldadeMenu();

#endif