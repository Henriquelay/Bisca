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
        aux = pGetProximo(aux);
    }
}

void jogada(tPlayer *player, tDeck *monte, tCarta *trunfo, char dificuldade){
    
    int cartaJogada = -1;
    for(tPlayer *aux = player; aux != player; aux = pGetProximo(aux)){
        if(pGetHumano(aux)){
            puts("Sua mao:");
            imprimeDeck(pGetMao(aux));
        }
        else jogadaBot(aux, monte, trunfo, dificuldade);
    }
}

void turno(tPlayer *player, tDeck *baralho, tDeck *monte, tCarta *trunfo, char dificuldade){

    printf("\nQTD NA MAO: %d", getQuantidade(pGetMao(player)));
    if(getQuantidade(pGetMao(player)) < 3)
        todosCompram(player, baralho);
    jogada(player, monte, trunfo, 0);
    


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
    preenche(baralho);
    embaralha(baralho, 15000);
    corta(baralho);
    tCarta *trunfo = defineTrunfo(baralho);
    int nJogadores;
    printf("O jogo sera para quantos jogadores? >");
    scanf(" %d", &nJogadores);
    tPlayer *players = iniciaNPlayers(nJogadores);
    for(int i = 0; i < 3; i++)
        todosCompram(players, baralho);
    while(ultimo(baralho) != NULL){
        printf("O Trunfo é ");
        filtrAEPrinta(trunfo);
        turno(players, baralho, monte, trunfo, 0);  //teste no easy
    }
    destroiPlayers(players);
    destroiDeck(monte);
}