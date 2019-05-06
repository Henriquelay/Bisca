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
    else if(!vazio(deck)){
            printf(" ***Esvazie o deck antes de preencher!");
        return;
    }

    tCarta atual;
    for(char naipe = 0; naipe < 4; naipe++)
        for(char valor = 0; valor < 10; valor++){
            atual = criaCarta(&naipe, &valor);
            insereCarta(&atual, deck);
        }
}

/*
    OBJETIVO: Troca 2 células de lugar.
    ENTRADAS: Ponteiro para duas células.
    SAIDA: -
    PRE-CONDICAO: As células existem e são válidas.
    POS-CONDICAO: As duas células trocam de posição na lista, inalteradas.
*/
void swap2Celulas(tCelula *a, tCelula *b){
    tCarta cartaAux = a->carta;
    
    a->carta = b->carta;
    b->carta = cartaAux;
}

/*
    OBJETIVO: Cortar 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' está cortado (a carta cortada é o trunfo e ela vai pro fundo do deck).
*/
void corta(tDeck *deck){
    if(vazio(deck))
        return;

    srand(time(NULL));
    tCelula *aux = deck->primeiro;
    tCelula *anterior = NULL;
    int lugardocorte = rand() % 39;

    printf("\nLUGAR DO CORTE = %d\n", lugardocorte);

    for(int i = 0; i < lugardocorte; i++){
        if(aux->proximo == NULL)
            break;
        anterior = aux;
        aux = aux->proximo;
    }

    if(anterior != NULL)
        anterior->proximo = aux->proximo;
    aux->proximo = NULL;
    deck->ultimo -> proximo = aux;
    deck->ultimo = aux;
}


/*
    OBJETIVO: Embaralhar 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' está embaralhado.
*/
void embaralha(tDeck *deck, int passes){
    if(vazio(deck))
        return;

    tCelula *aux = deck->primeiro;
    srand(time(NULL));

    int iteracao = rand() % 40;
    for(int i = 0; i < passes; i++){
        for(int n = 0; n < iteracao; n++){
            if(aux->proximo == NULL)
                break;
            aux = aux->proximo;
        }

        swap2Celulas(deck->primeiro, aux);

        iteracao = rand() % 40;
        aux = deck->primeiro;
    }
}

/*
    OBJETIVO: Desalocar toda a memória ocupada por 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' não ocupa mais espaço no HEAP e aponta para NULL.
*/
void destroiDeck(tDeck *deck){
    if(vazio(deck))
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


/*
    OBJETIVO: Inserir 'carta' em 'deck'. *Será inserida no início
    ENTRADAS: Ponteiro para 'deck', ponteiro para 'carta'.
    SAIDA: Endereço para a célula criada.
    PRE-CONDICAO: A carta existe.
    POS-CONDICAO: A célula foi corretamente alocada, a carta não foi alterada.
*/
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
    OBJETIVO: Cria uma célula para ser inserido em 'deck'.
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
    SAIDA: 3 quando é nulo, 1 quando está vazio 2 quando a sentila está errada, 0 quando não é vazio nem nulo, e está OK, -1 quando tem algo de muito errado.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char vazio(tDeck *deck){
    if(deck == NULL)
        return 3;
    if(deck->quantidade == 0)
        return 1;
    if(deck->primeiro == NULL || deck->ultimo == NULL)
        return 2;
    if(deck->ultimo->proximo == NULL)
        return 0;
    return -1;              //algo de muito errado
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

/*
    OBJETIVO: Selecionar a menor carta de 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: Ponteiro para a menor carta.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: .
*/
tCarta* menorCarta(tDeck *deck, char *trunfo){
    if(vazio(deck))
        return NULL;

    tCelula *aux = deck->primeiro;
    tCarta *menor = &aux->carta;

    while(aux != NULL){
        if(getValor(&aux->carta) < getValor(menor))
            if(getNaipe(menor) == *trunfo || getNaipe(&aux->carta) != *trunfo)
                menor = &aux->carta;

        aux = aux->proximo;
    }

    return menor;
}

/*
    OBJETIVO: Selecionar a menor carta de 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: Ponteiro para a menor carta.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: .
*/
char contaPontos(tDeck *deck);