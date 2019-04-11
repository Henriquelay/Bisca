#include "../headers/deck.h"

void iniciaDeckCheio(tDeck *deck){
    deck->cartas = NULL;
    deck->cartas = (tDeck*) malloc(sizeof(tCarta) * (MAXIMODODECK + 1));
    if(deck->cartas == NULL){
        printf("\n=#=#=#=#=DEU ALGO DE MUITO ERRADO AO TENTAR ALOCAR O DECK!! SAINDO DO PROGRAMA...=#=#=#=#=");
        EXIT_FAILURE;
    }

    for(char naipe = 0; naipe < NUMERODENAIPES; naipe++)
        for(char valor = 0; valor < NUMERODEVALORES; valor++)
            deck->cartas[NUMERODEVALORES * naipe + valor] = criaCarta(naipe, valor);

}

void embaralha(tDeck *deck){
    struct timeval tempo;
    gettimeofday(&tempo,NULL);
    srand((unsigned int)tempo.tv_usec);    
}