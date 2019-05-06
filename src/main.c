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
    char trunfo = defineTrunfo(baralho);
    printf("\nO Trunfo eh %d\n", trunfo);
    tCarta *menor = menorCarta(baralho, &trunfo);
    printf("\nA menor carta eh: ");
    filtrAEPrinta(menor);
    char pontos = contaPontos(baralho);
    printf("\nPontuacao Total: %d\nIniciando jogadores...", pontos);
    
    destroiDeck(baralho);
    return 0;
}