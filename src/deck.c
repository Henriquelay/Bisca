#include "../headers/deck.h"


/*
    OBJETIVO: Embaralhar 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' está embaralhado.
*/
void embaralha(tDeck *deck);

/*
    OBJETIVO: Desalocar toda a memória ocupada por 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' não ocupa mais espaço no HEAP e aponta para NULL.
*/
void destroiDeck(tDeck *deck);

/*
    OBJETIVO: Imprimir 'deck' na tela.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: Nada é alterado.
*/
void imprimeDeck(tDeck *deck){
    itemDeck *cartaAtual = deck->primeiro;
    while(!vazio(cartaAtual)){
        filtrAEPrinta(&cartaAtual->carta);
        cartaAtual = cartaAtual->proximo;
    }
}

itemDeck* criaItem(tCarta *carta){
    if(carta == NULL)
        return;

    itemDeck *item = (itemDeck*) malloc(sizeof(itemDeck));
    item->proximo = NULL;
}


/*
    OBJETIVO: Inserir 'carta' em 'deck'. //TODO: A SER DEFINIR SE SERÁ INCLUÍDA NO INÍCIO OU NO FIM
    ENTRADAS: Ponteiro para 'deck', ponteiro para 'carta'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'carta' está contida em 'deck'.
*/
void insereCarta(tCarta *carta, tDeck *deck){
    if(deck == NULL)
        return;

    itemDeck *atual = deck->primeiro;
    while(atual != NULL && !(getvalor(atual->carta) == getvalor(carta) && getnaipe(atual->carta) == getnaipe(carta)))
        atual = atual->proximo;

    if(atual != NULL){      //encontrou uma carta
        printf(" *** Foi tentando alocar a carta %d %d duas vezes! ***\n", getvalor(carta), getnaipe(carta));
        return;
    }

    itemDeck *item = (itemDeck*) malloc(sizeof(itemDeck));
    item->carta = *carta;
    item->proximo = deck->primeiro;
    deck->primeiro = item;
}

/*
    OBJETIVO: Verificar se 'deck' está alocado corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: 0 quando não está corretamente alocado, 1 quando está.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char vazio(tDeck *deck){
    if(deck->primeiro == NULL || deck->ultimo == NULL || deck->quantidade == 0)
        return 1;
    return 0;
}

/*
    OBJETIVO: Iniciar 'deck' vazio corretamente.
    ENTRADAS: -
    SAIDA: 'deck'.
    PRE-CONDICAO: -
    POS-CONDICAO: Inicializado, porém sem elementos.
*/
tDeck* iniciaVazio(void){
    tDeck *deck = (tDeck*) malloc(sizeof(tDeck));
    deck->primeiro = deck->ultimo = NULL;
    deck->quantidade = 0;
    return deck;
}