#include "../headers/deck.h"

/*
    OBJETIVO: Preencher 'deck' corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' com todas as cartas que serão usadas na bisca nele.
*/
void preenche(tDeck *deck){
    if(deck == NULL)
        deck = iniciaVazio();

    if(deck->primeiro != NULL || deck->ultimo != NULL){
        printf(" ***Esvazie o deck antes de preencher!");
        return;
    }

    tCarta atual;
    for(int naipe = 0; naipe < 4; naipe++)
        for(int valor = 0; valor < 10; valor++){
            atual.naipe = naipe;
            atual.valor = valor;
            insereCarta(&atual, deck);
        }
}

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
void destroiDeck(tDeck *deck){
    if(deck == NULL)
        return;
    if(deck->primeiro == NULL){
        free(deck);
        return;
    }

    for(tCelula *atual = deck->primeiro; atual != NULL; atual = deck->primeiro){
        deck->primeiro = deck->primeiro->proximo;
        free(atual);
        deck->quantidade--;
    }
    free(deck); 
}

/*
    OBJETIVO: Imprimir 'deck' na tela.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: Nada é alterado.
*/
void imprimeDeck(tDeck *deck){
    tCelula *cartaAtual = NULL;

    if(!vazio(deck))
        cartaAtual = deck->primeiro;

    while(cartaAtual != NULL){
        filtrAEPrinta(&cartaAtual->carta);
        printf("\n");
        cartaAtual = cartaAtual->proximo;
    }
}

tCelula* criaItem(tCarta *carta){
    if(carta == NULL)
        return NULL;

    tCelula *item = (tCelula*) malloc(sizeof(tCelula));
    if(item == NULL)
        printf(" ***DEU BOSTA AO ALOCAR CARTA!!!");
    else{
        item->proximo = NULL;
        item->carta = *carta;
    }
    return item;
}

/*
    OBJETIVO: Inserir 'carta' em 'deck'. *Será inserida no início
    ENTRADAS: Ponteiro para 'deck', ponteiro para 'carta'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'carta' está contida em 'deck'.
*/
void insereCarta(tCarta *carta, tDeck *deck){
    if(deck == NULL){ //não passei na função 'vazio()' pq ele pode não apontar pro inicio e final
        printf(" *** DECK TA ZUADO!!! ***");
        return;
    }

    tCelula *item = criaItem(carta);
    item->proximo = deck->primeiro;
    deck->primeiro = item;
    deck->quantidade++;
    if(deck->ultimo == NULL)
        deck->ultimo = item;
}

/*
    OBJETIVO: Verificar se 'deck' está alocado corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: 0 quando não está corretamente alocado, 1 quando está.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char vazio(tDeck *deck){
    if(deck == NULL)
        return 1;
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

    if(deck == NULL)
        printf(" ***DEU BOSTA AO ALOCAR O DECK");
    else{
    deck->primeiro = deck->ultimo = NULL;
    deck->quantidade = 0;
    }
    return deck;
}