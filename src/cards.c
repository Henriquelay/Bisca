#include "../headers/cards.h"

/*
    OBJETIVO: Traduzir a saída de números para cartas.
    ENTRADAS: A carta.
    SAIDA: -
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca.
    POS-CONDICAO: O valor "traduzido" foi impresso na tela e nada foi alterado.
*/
void filtrAEPrinta(tCarta *carta){
    switch(carta->valor){
        case 0: printf("2 "); break; 
        case 1: printf("3 "); break; 
        case 2: printf("4 "); break; 
        case 3: printf("5 "); break; 
        case 4: printf("6 "); break; 
        case 5: printf("Q "); break; 
        case 6: printf("J "); break; 
        case 7: printf("K "); break; 
        case 8: printf("7 "); break; 
        case 9: printf("A "); break;
        default: puts("###### DEU ALGO ERRADO COM O VALOR MEU CONSAGRATED ######");
    }
    switch(carta->naipe){
        case 0: printf("Ouros"); break;
        case 1: printf("Paus"); break;
        case 2: printf("Copas"); break;
        case 3: printf("Espadas"); break;
        default: puts("###### DEU ALGO ERRADO COM O NAIPE MEU CONSAGRATED ######");
    }
}

/*
    OBJETIVO: Inicializa a carta e cria um ponteiro para ela
    ENTRADAS: O naipe da carta, a valor da carta
    SAIDA: Um ponteiro do tipo tCartas
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca
    POS-CONDICAO: Ponteiro criado com a carta identificada com o naipe e o seu simbulo/valor
*/
tCarta criaCarta(char naipe, char valor){
    tCarta cartaAux;

    cartaAux.naipe = naipe;
    cartaAux.valor = valor;

    return cartaAux;
}

/*
    OBJETIVO: retorna o naipe da carta
    ENTRADAS: Uma carta
    SAIDA: O naipe da carta de entrada
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Nenhuma
*/
char getNaipe(tCarta *carta){
    return carta->naipe;
}

/*
    OBJETIVO: retorna o valor da carta
    ENTRADAS: Uma carta
    SAIDA: O valor da carta de entrada
    PRE-CONDICAO: Nenhuma
    POS-CONDICAO: Nenhuma
*/
char getValor(tCarta *carta){
    return carta->valor;
}

