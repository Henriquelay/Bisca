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


    for(char valor = 0; valor < 10; valor++){            //pois sao 10 valores
        for(char naipe = 0; naipe < 4; naipe++){       //e 4 naipes
            
        }
    }
}