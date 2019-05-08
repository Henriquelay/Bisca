#include "../headers/player.h"



int main(void){
    tDeck *baralho = iniciaVazio();
    preenche(baralho);
    // imprimeDeck(baralho);
    printf("\n\n");
    embaralha(baralho, 15000);
    // imprimeDeck(baralho);
    corta(baralho);
    imprimeDeck(baralho);
    tCarta *trunfo = defineTrunfo(baralho);
    printf("\nO Trunfo eh \n");
    filtrAEPrinta(trunfo);
    // tCarta *menor = menorCarta(baralho, trunfo);
    // printf("\nA menor carta eh: ");
    // filtrAEPrinta(menor);
    char pontos = contaPontos(baralho);
    printf("\nPontuacao Total: %d\nIniciando jogadores...\n", pontos);
    tPlayer *jogador = iniciaNPlayers(4);
    for(int i =)    
    printf("A mao do jogador 1 eh:\n");
    imprimeMao(jogador);
    printf("\nBaralho:\n");
    imprimeDeck(baralho);
    destroiPlayers(jogador);
    destroiDeck(baralho);
    return 0;
}