#include "../headers/deck.h"

itemDeck* inicializaItem(void){
    itemDeck *item = (itemDeck*) malloc(sizeof(itemDeck));
    item->proximo = NULL;
    
    return item;
}

tipoDeck* iniciaDeckVazio(void){
    tipoDeck *deck = (tipoDeck*) malloc(sizeof(tipoDeck));
    deck->primeiro = deck->ultimo = NULL;
    deck->tamanho = 0;
    return deck;
}

void preencheDeck(tipoDeck *deck){
    if(deck == NULL)
        printf("======INICIE O DECK ANTES DE ALOCAR!!!====\n");


    for(char valor = 0; valor < 10; valor++)            //pois sao 10 valores
        for(char naipe = 0; naipe < 4; naipe++)       //e 4 naipes
            if(valor == 0 && naipe == 0){
                deck->primeiro = deck->ultimo = inicializaItem();
                deck->tamanho++;
                deck->primeiro->carta = criaCarta(naipe, valor);
            } else{
                deck->ultimo = inicializaItem();
                deck->tamanho++;
                deck->ultimo->carta = criaCarta(naipe, valor);
            }
}

void imprimeDeck(tipoDeck *deck){
    for(int i = 0; i < deck->tamanho; i++){
        printf("\tCARTA %d = ");
        imprimeCarta(deck->primeiro[i].carta);
    }
}