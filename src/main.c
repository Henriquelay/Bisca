#include "../headers/deck.h"



int main(void){
    tDeck *baralho = iniciaVazio();
    preenche(baralho);
    imprimeDeck(baralho);
    printf("\n\n");
    embaralha(baralho, 15000);
    imprimeDeck(baralho);
    corta(baralho);
    imprimeDeck(baralho);
    destroiDeck(baralho);
    return 0;
}