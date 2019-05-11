#include "../headers/AI.h"

void jogadaEasy(tPlayer *player, tDeck *monte, tCarta *trunfo){
    printf("Jogada feita pelo bot %d = ", pGetId(player));
    filtrAEPrinta(getCarta(primeiro(pGetMao(player))));
    jogaCarta(player, monte, 1);
}

void jogadaBot(tPlayer *player, tDeck *monte, tCarta *trunfo, char dificuldade){
    if(dificuldade == 0)
        jogadaEasy(player, monte, trunfo);
}