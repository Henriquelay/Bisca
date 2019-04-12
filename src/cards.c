#include <stdio.h>
#include <stdlib.h>

#include "../headers/cards.h"

/*
    um vetor que guarda os valores validos de uma carta
    char valores[14];
    valores[0] = 'A';
    valores[1] = 'K';
    valores[2] = 'Q';
    valores[3] = 'J';
    valores[4] = '2';
    valores[5] = '3';
    valores[6] = '4';
    valores[7] = '5';
    valores[8] = '6';
    valores[9] = '7';

    Um vetor que guarda os naipes validos de uma carta
    char naipe[8];
    naipe[0] = 'C';
    naipe[1] = 'E';
    naipe[2] = 'P';
    naipe[3] = 'O';
*/

/*
    OBJETIVO: Inicializa a carta e cria um ponteiro para ela
    ENTRADAS: O naipe da carta, a valor da carta
    SAIDA: Um ponteiro do tipo tCartas
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca
    POS-CONDICAO: Ponteiro criado com a carta identificada com o naipe e o seu simbulo/valor
*/
tCarta criaCarta(char naipe, char valor)
{
    tCarta cartaAux;

    cartaAux -> naipe = naipe;
    cartaAux -> valor = valor;

    return cartaAux;
}

/*
    OBJETIVO: retorna o valor do naipe da carta
    ENTRADAS: Uma carta
    SAIDA: O naipe da carta de entrada
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Nenhuma
*/
char getNaipe(tCarta *carta)
{
    return carta->naipe;
}

/*
    OBJETIVO: retorna o valor da carta
    ENTRADAS: Uma carta
    SAIDA: O valor da carta de entrada
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Nenhuma
*/
char getValor(tCarta *carta)
{
    return carta->valor;
}

/*
    OBJETIVO: Inicializa a carta e cria um ponteiro para ela
    ENTRADAS: O naipe da carta, a valor da carta
    SAIDA: Um ponteiro do tipo tCartas
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca
    POS-CONDICAO: Ponteiro criado com a carta identificada com o naipe e o seu simbulo/valor
*/
void trocaCarta(tCarta* card1, tCarta* card2)
{
    tCarta* cardAux;
    
    cardAux -> valor = card1 -> valor;
    cardAux -> naipe = card1 -> naipe;

    card1 -> valor = card2 -> valor;
    card1 -> naipe = card2 -> naipe;

    card2 -> valor = cardAux -> valor;
    card2 -> naipe = cardAux -> naipe;
}

/*
    OBJETIVO: Verificar se o valor da carta eh valido
    ENTRADAS: Uma variavel do tipo tCarta
    SAIDA: 1 para valido e 0 para invalido
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Valor validado ou invalidado
*/
int verificaValor(tCarta card)
{
    for(int i = 0; i < NUMERODEVALORES; i++)
    {
        if(card -> valor == valores[i])   return 1;       // Valor valido
        else return 0;                                    // Valor invalido
    }

    return 0;                                             // return para evitar erro
}

/*
    OBJETIVO: Verificar se o naipe da carta eh valido
    ENTRADAS: Uma variavel do tipo tCarta
    SAIDA: 1 para valido e 0 para invalido
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Naipe validado ou invalidado
*/
int verificaNaipe(tCarta card)
{
    for(int i = 0; i < NUMERODENAIPES; i++)
    {
        if(card -> naipe == naipe[i])   return 1;       // Naipe valido
        else return 0;                                  // Naipe invalido
    }

    return 0;                                           // return para evitar erro
}

/*
    OBJETIVO: Printa a carta
    ENTRADAS: o naipe da carta, a valor da carta
    SAIDA: Nenhuma
    PRE-CONDICAO: Carta existir
    POS-CONDICAO: Print executado
*/
void imprimeCarta(tCarta card)
{
    if(verificaNaipe(card) && verificaValor(card))
    {
        printf("NAIPE: %c VALOR: %c\n", card -> naipe, card -> valor);
    }
}
