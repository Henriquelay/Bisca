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

/*
    OBJETIVO: Inicializa a carta e cria um ponteiro para ela
    ENTRADAS: O naipe da carta, a valor da carta
    SAIDA: Um ponteiro do tipo tCartas
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca
    POS-CONDICAO: Ponteiro criado com a carta identificada com o naipe e o seu simbulo/valor
*/
tCarta criaCarta(char naipe, char valor);

/*
    OBJETIVO: Verificar se o valor da carta eh valido
    ENTRADAS: Uma variavel do tipo tCarta
    SAIDA: 1 para valido e 0 para invalido
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Valor validado ou invalidado
*/
int verificaValor(tCarta card);

/*
    OBJETIVO: Verificar se o naipe da carta eh valido
    ENTRADAS: Uma variavel do tipo tCarta
    SAIDA: 1 para valido e 0 para invalido
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Naipe validado ou invalidado
*/
int verificaNaipe(tCarta card);

/*
    OBJETIVO: Printa a carta
    ENTRADAS: o naipe da carta, a valor da carta
    SAIDA: Nenhuma
    PRE-CONDICAO: Carta existir
    POS-CONDICAO: Print executado
*/
void imprimeCarta(tCarta card);

//TODO: Filtro de impressão como função (switch)


#endif