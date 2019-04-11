#include "../headers/deck.h"

char checaExistencia(){

}

void iniciaDeckCheio(tDeck *deck){
    deck->cartas = NULL;
    deck->cartas = (tDeck*) malloc(sizeof(tCarta) * (MAXIMODODECK + 1));
    if(deck->cartas == NULL){
        printf("\n=#=#=#=#=DEU ALGO DE MUITO ERRADO AO TENTAR ALOCAR O DECK!! SAINDO DO PROGRAMA...=#=#=#=#=");
        EXIT_FAILURE;
    }

    deck->Primeiro = INICIODODECK;

    for(char naipe = 0; naipe < NUMERODENAIPES; naipe++)
        for(char valor = 0; valor < NUMERODEVALORES; valor++){
            deck->cartas[NUMERODEVALORES * naipe + valor] = criaCarta(naipe, valor);
            deck->Ultimo++;
        }

}

void swapCartas(tDeck *a, tDeck *b){
    tDeck *aux = a;
    a = b;
    b = aux;
}

void embaralha(tDeck *deck){
    struct timeval tempo1;
    struct timeval tempo2;
    gettimeofday(&tempo1,NULL);
    gettimeofday(&tempo2,NULL);
    
    for(int i = 0; i < 40; i++) //40 = numero de swaps de 2 cartas aleatórias
        swapCartas(&deck->cartas[(srand((unsigned int)tempo.tv_usec) % deck->Ultimo)], &deck->cartas[(srand((unsigned int)tempo.tv_usec) % deck->Ultimo)]);

}

void imprimeDeck(tDeck *deck){
}