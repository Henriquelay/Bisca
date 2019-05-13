#include "../headers/AI.h"

/*
    OBJETIVO: Funcao que joga a carta no modo facil;
    ENTRADAS: Ponteiro tCelula* para 'celula alvo'.
    SAIDA: Ponteiro tCarta* para 'carta'.
    PRE-CONDICAO: Celula existir.
    POS-CONDICAO: Carta da celula retornada.
*/
//eu reverti algumas coisas antes de botar a IA pra continuar testando
void jogadaEasy(tPlayer *player, tDeck *monte, tCarta *trunfo){
    printf("Jogada feita pelo bot %d = ", pGetId(player));
    filtrAEPrinta(getCarta(primeiro(pGetMao(player))));
    jogaCarta(player, monte, 1);
}

void jogadaHard(tPlayer *player, tDeck *monte, tDeck *mao, tCarta *trunfo){
    /*printf("Jogada feita pelo bot %d = ", pGetId(player));

    if(){
        
    }*/
}

void jogadaBot(tPlayer *player, tDeck *monte, tCarta *trunfo, char dificuldade){
    if(dificuldade == 0)
        jogadaEasy(player, monte, trunfo);
    else
        jogadaHard(player, monte, pGetMao(player), trunfo);
}