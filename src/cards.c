#include "../headers/cards.h"

/*
    OBJETIVO: Inicializa a carta e cria um ponteiro para ela
    ENTRADAS: O naipe da carta, a valor da carta
    SAIDA: Um ponteiro do tipo tCartas
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca
    POS-CONDICAO: Ponteiro criado com a carta identificada com o naipe e o seu simbulo/valor
*/
tCarta criaCarta(char *naipe, char *valor){
    tCarta cartaAux;

    cartaAux.naipe = *naipe;
    cartaAux.valor = *valor;

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
    if(carta == NULL) return -1;
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
    if(carta == NULL) return -1;
    return carta->valor;
}

/*
    OBJETIVO: Traduzir a saída de números para cartas.
    ENTRADAS: A carta.
    SAIDA: -
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca.
    POS-CONDICAO: O valor "traduzido" foi impresso na tela e nada foi alterado.
*/
void filtrAEPrinta(tCarta *carta){
    if(carta == NULL)
        return;

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

    printf("de ");
    
    switch(carta->naipe){
        case 0: printf("Ouros "); break;
        case 1: printf("Paus "); break;
        case 2: printf("Copas "); break;
        case 3: printf("Espadas "); break;
        default: puts("###### DEU ALGO ERRADO COM O NAIPE MEU PROGRAMADO ######");
    }
    puts("");
}

/*
    OBJETIVO: Retornar o número de pontos da carta.
    ENTRADAS: Ponteiro para a carta.
    SAIDA: O valor em pontos dela.
    PRE-CONDICAO: Ser um naipe e um valor valido dentro do jogo de bisca.
    POS-CONDICAO: Nada foi alterado.
*/
char filtroDePontos(tCarta *carta){
    if(carta == NULL)
        return 0;

    switch(carta->valor){
        case 0: 
        case 1: 
        case 2: 
        case 3: 
        case 4: 
            return 0;
        case 5: return 2;
        case 6: return 3;
        case 7: return 4;
        case 8: return 10;
        case 9: return 11;
        default: puts("###### DEU ALGO ERRADO COM O VALOR MEU CONSAGRATED ######");
    }
    return 0;
}

/*
    OBJETIVO: Verificar se duas cartas sao iguais.
    ENTRADAS: Ponteiro tCarta* para a 'carta1' e um Ponteiro tCarta* para a 'carta2'.
    SAIDA: Retorna 1 se as duas cartas de entrada forem as mesmas, e 0 caso contrario.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada foi alterado.
*/
char cartasIguais(tCarta *carta1, tCarta *carta2){
    return (getNaipe(carta1) == getNaipe(carta2) && getValor(carta1) == getValor(carta2));
}