#include <stdio.h>
#include <stdlib.h>

#include "../headers/cards.h"

// Struct que define as variaveis que representam as cartas do jogo
/* typedef struct{
    char naipe, valor;
} tCartas;
 */ ///Está definida na .h --Henr
/*
//  um vetor que guarda os valores validos de uma carta
    char valores[14];
    valores[0] = 'a';
    valores[1] = 'A';
    valores[2] = 'k';
    valores[3] = 'K';
    valores[4] = 'q';
    valores[5] = 'Q';
    valores[6] = 'j';
    valores[7] = 'J';
    valores[8] = '2';
    valores[9] = '3';
    valores[10] = '4';
    valores[11] = '5';
    valores[12] = '6';
    valores[13] = '7';

//  Um vetor que guarda os naipes validos de uma carta
    char naipe[8];
    naipe[0] = 'c';
    naipe[1] = 'C';
    naipe[2] = 'e';
    naipe[3] = 'E';
    naipe[4] = 'p';
    naipe[5] = 'P';
    naipe[6] = 'o';
    naipe[7] = 'O';
*/

/*
    OBJETIVO: Inicializa a carta e cria um ponteiro para ela
    ENTRADAS: o naipe da carta, a valor da carta
    SAIDA: um ponteiro do tipo tCartas
    PRE-CONDICAO: ser um naipe e um valor valido dentro do jogo de bisca
    POS-CONDICAO: ponteiro criado com a carta identificada com o naipe e o seu simbulo/valor
*/
tCarta criaCarta(char naipe, char valor){
    //tCartas cartaAux = (tCartas) malloc(sizeof(tCartas));
    cartaAux->naipe = naipe;
    cartaAux->valor = valor;

    return cartaAux;
}

void imprimeCarta(char naipe; char valor){
    printf("%c", )
}
/*
    OBJETIVO: Libera o espaco de alocacao de um ponteiro de cartas na memoria
    ENTRADAS: um ponteiro do tipo tCartas
    SAIDA: nenhuma
    PRE-CONDICAO: ser uma carta existente
    POS-CONDICAO: ponteiro liberado na memoria
*/
void destroiCarta(tCartas* cartaAlvo){
    if(cartaAlvo == NULL){
        printf("ESSA CARTA NAO EXISTE!!");
        exit(1);
    } else{
        free(cartaAlvo);
    }
}