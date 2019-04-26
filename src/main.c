#include "../headers/deck.h"



int main(void){
    tDeck *baralho = iniciaVazio();
    preenche(baralho);
    imprimeDeck(baralho);
    destroiDeck(baralho);
    return 0;
}