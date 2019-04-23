#include "../headers/deck.h"


//DEFINEM AS CARTAS PARA LEGIBILIDADE (O VALOR REPRESENTA A ORDEM DE ENCARTE)
#define CARTA1 9
#define CARTA2 0
#define CARTA3 1
#define CARTA4 2
#define CARTA5 3
#define CARTA6 4
#define CARTA7 8
#define CARTAJ 6
#define CARTAQ 5
#define CARTAK 7

//DEFINEM OS NAIPES PARA LEGIBILIDADE
#define NAIPEO 0
#define NAIPEP 1
#define NAIPEC 2
#define NAIPEE 3

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
    tDeck *cartaAtual = deck;
    while(!vazio(cartaAtual)){
        filtrAEPrinta(&cartaAtual->primeiro->carta);
        cartaAtual = cartaAtual->Prox;
    }
}

/*
    OBJETIVO: Inserir 'carta' em 'deck'. //TODO: A SER DEFINIDISE SERÁ INCLUÍDA NO INÍCIO OU NO FIM
    ENTRADAS: Ponteiro para 'deck', ponteiro para 'carta'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'carta' está contida em 'deck'.
*/
void insereCarta(tCarta *carta, tDeck *deck);

/*
    OBJETIVO: Verificar se 'deck' está alocado corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: 0 quando não está corretamente alocado, 1 quando está.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char vazio(tDeck *deck){
    if(deck->primeiro == NULL || deck->ultimo == NULL || quantidade == 0)
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
    tDeck *deck = (deck*) malloc(sizeof(deck));
    deck->primeiro = deck->ultimo = NULL;
    deck->quantidade = 0;
    return deck;
}