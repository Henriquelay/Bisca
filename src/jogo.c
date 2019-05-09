#include "../headers/jogo.h"


/*
    OBJETIVO: Calcular quem foi o ganhador (quem encartou) do monte.
    ENTRADAS: Ponteiro tDeck* para 'monte' e pontei tCarta* para 'trunfo'.
    SAIDA: A posição na lista encadeada do player ganhador.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
int ganhador(tDeck *monte, tCarta *trunfo){
    if(vazio(monte))
        return -1;

    tCelula *aux = primeiro(monte);
    tCarta *maior = getCarta(aux);
    int cont = 0;

    while(aux != NULL){
        if(getValor(getCarta(aux)) >= getValor(maior))
            if(getNaipe(getCarta(aux)) == getNaipe(trunfo) || getNaipe(getCarta(aux)) == getNaipe(trunfo))
                maior = getCarta(aux);

        aux = proximo(aux);
    }

    for(aux = primeiro(monte); !cartasIguais(getCarta(aux), maior); aux = proximo(aux)){
        cont++;    //só para achar qual foi o jogador que ganhou
    }
    
    return cont;
}

void todosCompram(tPlayer *player, tDeck *baralho){
    tPlayer *aux = player;
    while(aux != player){
        compraCarta(aux, baralho);
        aux = aux->proximo;
    }
}

void turno(tPlayer *player, tDeck *baralho, tDeck *monte){

}

/*
    OBJETIVO: Iniciar 'n' quantidades de tPlayers vazios corretamente.
    ENTRADAS: A quantidade de players a ser inicializada.
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: n > 0.
    POS-CONDICAO: Inicializados, porém sem elementos, ou zerados.
*/
void jogo(tDeck *baralho){
    tDeck *monte = iniciaVazio();
    embaralha(baralho, 15000);
    corta(baralho);
    tCarta *trunfo = defineTrunfo(baralho);
    int nJogadores;
    while(baralho->ultimo != NULL){
        printf("O jogo sera para quantos jogadores? >");
        scanf(" %d", &nJogadores);
        tPlayer *players = iniciaNPlayers(nJogadores);
        tPlayer *humano = players;



        printf("O Trunfo é ");
        filtrAEPrinta(trunfo);
        turno(players, baralho, monte);
    }
}