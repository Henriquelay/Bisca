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
    tCarta cartaAux = *getCarta(a);
    
    setCarta(a, *getCarta(b));
    setCarta(b, cartaAux);
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
    tCelula *aux = NULL;
    dSetCel(aux, primeiro(deck));
    tCelula *anterior = NULL;
    int lugardocorte = rand() % 39;

    printf("\nLUGAR DO CORTE = %d\n", lugardocorte);

    for(int i = 0; i < lugardocorte; i++){
        if(dGetProximo(aux) == NULL)
            break;
        dSetCel(anterior, aux);
        dSetCel(aux, dGetProximo(aux));
    }

    if(anterior != NULL)
        dSetCel(dGetProximo(anterior), dGetProximo(aux));
    dSetProximo(aux, NULL);
    dSetProximo(ultimo(deck), aux);
    dSetCel(ultimo(deck), aux);
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
            if(dGetProximo(aux) == NULL)
                break;
            aux = dGetProximo(aux);
        }

        swap2Celulas(primeiro(deck), aux);

        iteracao = rand() % 40;
        aux = primeiro(deck);
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
    if(primeiro(deck) == NULL){
        free(deck);
        return;
    }

    for(tCelula *atual = primeiro(deck); atual != NULL; atual = primeiro(deck)){
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
tCarta* menorCarta(tDeck *deck, tCarta *trunfo){
    if(vazio(deck))
        return NULL;

    tCelula *aux = deck->primeiro;
    tCarta *menor = &aux->carta;

    while(aux != NULL){
        if(getValor(&aux->carta) < getValor(menor))
            if( getNaipe(&aux->carta) != getNaipe(trunfo) || getNaipe(menor) == getNaipe(trunfo))
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
char contaPontos(tDeck *deck){
    if(vazio(deck))
        return 0;

    tCelula *aux = deck->primeiro;
    char acc = 0;
    while(aux != NULL){
        acc += filtroDePontos(&aux->carta);
        aux = aux->proximo;
    }

    return acc;
}

/*
    OBJETIVO: Pegar o trunfo do fundo do baralho.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: O naipe do fundo de 'deck'.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: Nada é alterado.
*/
tCarta* defineTrunfo(tDeck *deck){
    if(vazio(deck))
        return NULL;
    tCarta *trunfo = getCarta(ultimo(deck));
    return trunfo;
}

void dSetProximo(tCelula *cel, tCelula *proximo){
    if(cel != NULL)
        cel->proximo = proximo;
}

void dSetCel(tCelula *cel1, tCelula *cel2){
    cel1 = cel2;
}

tCelula* dGetProximo(tCelula *cel){
    if(cel != NULL)
        return cel->proximo;
    return NULL;
}

tCelula* primeiro(tDeck *deck){
    if(!vazio(deck))
        return deck->primeiro;
    return NULL;
}

tCelula* ultimo(tDeck *deck){
    if(!vazio(deck))
        return deck->ultimo;
    return NULL;
}

tCarta* getCarta(tCelula *cel){
    if(cel != NULL)
        return &cel->carta;
    return NULL;
}

void setCarta(tCelula *cel, tCarta carta){
    if(cel != NULL)
        cel->carta = carta;
}

void setQuantidade(tDeck *deck, int qtd){
    if(!vazio(deck))
        deck->quantidade = qtd;
}

int getQuantidade(tDeck *deck){
    if(!vazio(deck))
        return deck->quantidade;
    return 0;
}