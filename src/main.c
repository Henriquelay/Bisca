#include "../headers/player.h"



int main(void){
    tDeck *baralho = iniciaVazio();
    preenche(baralho);
    imprimeDeck(baralho);
    printf("\n\n");
    embaralha(baralho, 15000);
    imprimeDeck(baralho);
    corta(baralho);
    imprimeDeck(baralho);
    char trunfo = 3;
    tCarta *menor = menorCarta(baralho, &trunfo);
    printf("\nA menor carta eh: ");
    filtrAEPrinta(menor);
    destroiDeck(baralho);
    return 0;
}