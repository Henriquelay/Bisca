#include "../headers/jogo.h"
// #include <locale.h>  //decidi não incluir por pesar mais 10 MB no HEAP e 10 allocs


int main(void){
    // setlocale(LC_ALL, "Portuguese_Brasil");
    tDeck *baralho = iniciaVazio();
    preenche(baralho);
    embaralha(baralho, 15000);
    // imprimeDeck(baralho);
    // printf("\n\n");
    // imprimeDeck(baralho);
    corta(baralho);
    imprimeDeck(baralho);
    tCarta *trunfo = defineTrunfo(baralho);
    printf("\nO Trunfo eh \n");
    filtrAEPrinta(trunfo);
    tCarta *menor = menorCarta(baralho, trunfo);
    printf("\nA menor carta eh: ");
    filtrAEPrinta(menor);
    char pontos = contaPontos(baralho);
    printf("\nPontuacao Total: %d\nIniciando jogadores...\n", pontos);
    tPlayer *jogador = iniciaNPlayers(4);
    printf("A mao do jogador 1 eh:\n");
    compraCarta(jogador, baralho);
    compraCarta(jogador, baralho);
    compraCarta(jogador, baralho);
    imprimeMao(jogador);
    puts("Menor carta da mao");
    filtrAEPrinta(menorCarta(pGetMao(jogador), trunfo));
    // printf("\nBaralho:\n");
    // imprimeDeck(baralho);
    puts("Jogando a carta 2:");
    jogaCarta(jogador, baralho, 2);
    // printf("\nBaralho:\n");
    imprimeDeck(baralho);
    printf("\n\nO GANHADOR EH: ");
    tCelula *maior = primeiro(baralho);
    for(int i = 0; i < ganhador(baralho, trunfo); i++){
        maior = proximo(maior);
    }
    filtrAEPrinta(getCarta(maior));
    printf("TRUNFO EH: ");
    filtrAEPrinta(trunfo);
    destroiPlayers(jogador);
    destroiDeck(baralho);
    return 0;
}