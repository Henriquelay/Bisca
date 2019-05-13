#include "../headers/AI.h"

/*
    OBJETIVO: Funcao que joga a carta no modo facil;
    ENTRADAS: Ponteiro tCelula* para 'celula alvo'.
    SAIDA: Ponteiro tCarta* para 'carta'.
    PRE-CONDICAO: Celula existir.
    POS-CONDICAO: Carta da celula retornada.
*/
void jogadaEasy(tPlayer *player, tDeck *mao, tCarta *trunfo){
    printf("Jogada feita pelo bot %d = ", pGetId(player));
    filtrAEPrinta(getCarta(primeiro(pGetMao(player))));
    jogaCarta(player, mao, 1);
}

void jogadaHard(tPlayer *player, tDeck *monte, tDeck *mao, tCarta *trunfo){
    printf("Jogada feita pelo bot %d = ", pGetId(player));

    if(){
        
    }
}

void jogadaBot(tPlayer *player, tDeck *monte, tDeck *mao, tCarta *trunfo, char dificuldade){
    if(dificuldade == 0)
        jogadaEasy(player, mao, trunfo);
    else
        jogadaHard(player, monte, mao, trunfo);
}