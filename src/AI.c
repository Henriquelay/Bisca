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

void jogadaHard(tPlayer *player, tDeck *monte, tCarta *trunfo){
    //printf("Jogada feita pelo bot %d = ", pGetId(player));

    if(getNaipe(maiorCarta(monte, trunfo)) == getNaipe(trunfo)){          // compara se a maior carta do monte eh trunfo
        tCarta* menor = menorCarta(pGetMao(player), trunfo);
        jogaCarta(player, monte, buscaCarta(menor, pGetMao(player)));
    }
    else{ 
        if(contaPontos(monte) > 0){
            tCarta* maior = maiorCarta(pGetMao(player), trunfo);
            jogaCarta(player, monte, buscaCarta(maior, pGetMao(player)));
        }
        else{
            tCarta* menor = menorCarta(pGetMao(player), trunfo);
            jogaCarta(player, monte, buscaCarta(menor, pGetMao(player)));
        }
    }
}

void jogadaBot(tPlayer *player, tDeck *monte, tCarta *trunfo, char dificuldade){
    printf("QUEM VAI JOGAR: BOT %d\n", pGetId(player));
    if(dificuldade == 0)
        jogadaEasy(player, monte, trunfo);
    else
        jogadaHard(player, monte, trunfo);
}