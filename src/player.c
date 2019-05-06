#include "../headers/player.h"

/*
    OBJETIVO: Inserir 'inserir' em 'lista', no final, e caso 'lista' seja vazio, inicia com ele.
    ENTRADAS: Ponteiros de jogadores para 'lista' e 'inserir'.
    SAIDA: -
    PRE-CONDICAO: -
    POS-CONDICAO: Os jogadores são inseridos na lista.
*/
void inserePlayer(tPlayer* lista, tPlayer* inserir){
    if(inserir == NULL)
        inserir =  (tPlayer*) malloc(sizeof(tPlayer));
    
    tPlayer *aux = inserir;

    if(lista != NULL)
        lista->proximo = aux;
    else
        lista = aux;
}

void setPontos(tPlayer *player){

}

char getPontos(tPlayer *player){

}

void setProximo(tPlayer *player, tPlayer *proximo){

}

tPlayer* getProximo(tPlayer *player){
    
}

/*
    OBJETIVO: Iniciar 'Player' vazio corretamente.
    ENTRADAS: -
    SAIDA: Ponteiro para tPlayer, apontando para o jogador criado.
    PRE-CONDICAO: -
    POS-CONDICAO: Inicializado, porém sem elementos, ou zerados.
*/
tPlayer* iniciaPlayerVazio(void){
    tPlayer *player = (tPlayer*) malloc(sizeof(tPlayer));
    setPontos 
}