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
    tCarta *trunfo = defineTrunfo(baralho);
    printf("\nO Trunfo eh \n");
    filtrAEPrinta(trunfo);
    tCarta *menor = menorCarta(baralho, trunfo);
    printf("\nA menor carta eh: ");
    filtrAEPrinta(menor);
    char pontos = contaPontos(baralho);
    printf("\nPontuacao Total: %d\nIniciando jogadores...", pontos);
    tPlayer *jogador = iniciaNPlayers(4);
    // compraCarta(jogador, baralho);compraCarta(jogador, baralho);compraCarta(jogador, baralho);compraCarta(jogador, baralho);    
    printf("A mao do jogador 1 eh:\n");
    imprimeMao(jogador);
    destroiPlayers(jogador);
    destroiDeck(baralho);
    return 0;
}