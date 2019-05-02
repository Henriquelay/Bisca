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
        tPlayer *inserir =  (tPlayer*) malloc(sizeof(tPlayer));
    
    tPlayer *aux = inserir;

    if(lista != NULL)
        lista->proximo = aux;
    else
        lista = aux;
}

/*
    OBJETIVO: Troca 2 células de lugar.
    ENTRADAS: Ponteiro para duas células.
    SAIDA: -
    PRE-CONDICAO: As células existem e são válidas.
    POS-CONDICAO: As duas células trocam de posição na lista, inalteradas.
*/
tPlayer* iniciaJogador(int qtde){
    if(qtde < 1)
        return NULL;

    tPlayer *primeiro;
    
}