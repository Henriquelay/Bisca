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
    tCelula *cartaAtual = deck->primeiro;
    while(!vazio(cartaAtual)){
        filtrAEPrinta(&cartaAtual->carta);
        cartaAtual = cartaAtual->proximo;
    }
}

tCelula* criaItem(tCarta *carta){
    if(carta == NULL)
        return;

    tCelula *item = (tCelula*) malloc(sizeof(tCelula));
    item->proximo = NULL;
}

/*
    OBJETIVO: Inserir 'carta' em 'deck'. //*Será inserida no início
    ENTRADAS: Ponteiro para 'deck', ponteiro para 'carta'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'carta' está contida em 'deck'.
*/
void insereCarta(tCarta *carta, tDeck *deck){
    if(deck == NULL){
        printf(" *** DECK EH NULO!!! ***");
        return;
    }

    tCelula *item = (tCelula*) malloc(sizeof(tCelula));
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