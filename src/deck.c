#include "../headers/deck.h"

/*
    OBJETIVO: Preencher 'deck' corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' com todas as cartas que serão usadas na bisca nele.
*/
void preenche(tDeck *deck){
    if(!vazio(deck)){
            printf(" ***Esvazie o deck antes de preencher!");
        return;
    }

    tCarta atual;
    for(char naipe = 0; naipe < NUMERODENAIPES; naipe++)
        for(char valor = 0; valor < NUMERODEVALORES; valor++){
            atual = criaCarta(&naipe, &valor);
            insereCarta(&atual, deck);
        }
}

/*
    OBJETIVO: Transferir um Ponteiro tCelula* de um Deck ao outro Deck.
        EXEMPLO: Comprar uma carta do monte exige tirar ela do monte e colocar ela na mao do jogador.
    ENTRADAS: Ponteiro tDeck* para 'primeiro deck' e um Ponteiro tDeck* para 'segundo deck', Variavel int para 'indice da carta'.
    SAIDA: -
    PRE-CONDICAO: 'deck1 e deck2' existe e está alocado corretamente.
    POS-CONDICAO: Mudanca de deck da Celula feita.
*/
void transfereCelula(tDeck *deck1, tDeck *deck2, int n){
    if(deck2 == NULL || n < 0 || n > getQuantidade(deck2)) return;

    tCelula *celula = retiraCelula(deck2, n);

    if(getQuantidade(deck1) == 0)
        deck1->primeiro = deck1->ultimo = celula;
    else{       //nn tô usando funções do TAD pq deu bosta e ed 1 é 10
        deck1->ultimo->proximo = celula;
        deck1->ultimo = celula;
    }
    setQuantidade(deck1, getQuantidade(deck1) + 1);
}

/*
    OBJETIVO: Retirar um Ponteiro tCelula* de um Deck e retornar ela.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo', Variavel int para 'indice da carta no deck'.
    SAIDA: Ponteiro tCarta* para 'carta retirada'.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente e o indice 'n' ser um valor possivel dado o tamanho do deck.
    POS-CONDICAO: Celula retirada do 'deck' e retornada.
*/
tCelula* retiraCelula(tDeck *deck, int n){
    if(deck == NULL || n < 0 || n > getQuantidade(deck)) return NULL;

    tCelula *anterior = NULL;
    tCelula *aux = primeiro(deck);
    for(int i = 0 ; i < n; i++){
        anterior = aux;
        aux = proximo(aux);
    }   //cheguei na celula que quero

    if(aux == NULL) return NULL;
    if(aux == primeiro(deck) && aux == ultimo(deck))
        deck->primeiro = deck->ultimo = NULL;

    if(aux == ultimo(deck)){
        deck->ultimo = anterior;
        dSetProximo(anterior, NULL);
    }
    if(aux == primeiro(deck))
        deck->primeiro = proximo(aux);  
    else
        dSetProximo(anterior, proximo(aux));

    setQuantidade(deck, getQuantidade(deck) - 1);
    dSetProximo(aux, NULL);
    return aux;

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
    int lugardocorte = rand() % deck->quantidade - 1;

    // printf("\nLUGAR DO CORTE = %d\n", lugardocorte);

    for(int i = 0; i < lugardocorte; i++){
        if(proximo(aux) == NULL)
            break;
        dSetCel(anterior, aux);
        dSetCel(aux, proximo(aux));
    }

    if(anterior != NULL)    // aux nao eh a primeira do baralho
        dSetCel(proximo(anterior), proximo(aux));   //configurei a lista a passar por cima de aux
    dSetProximo(aux, NULL);             // Colocando a carta no fundo do deck
    dSetProximo(ultimo(deck), aux);
    dSetCel(ultimo(deck), aux);         // Atualizando a sentinela
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

    tCelula *aux = primeiro(deck);
    srand(time(NULL));

    int iteracao = rand() % getQuantidade(deck);
    for(int i = 0; i < passes; i++){
        for(int n = 0; n < iteracao; n++){
            if(proximo(aux) == NULL)
                break;
            aux = proximo(aux);
        }

        swap2Celulas(primeiro(deck), aux);

        iteracao = rand() % getQuantidade(deck);
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
    tCelula *Aux = NULL;
    while(deck->primeiro != NULL){
        Aux = deck->primeiro;
        deck->primeiro = deck->primeiro->proximo;
        free(Aux);
    }
    free(deck);
}

/*
    OBJETIVO: Desalocar toda a memória ocupada por 'deck' menos na primeira Celula.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' estar vazio.
*/
void esvaziaDeck(tDeck *deck){
    tCelula *Aux = NULL;
    while(deck->primeiro != NULL){
        Aux = deck->primeiro;
        deck->primeiro = deck->primeiro->proximo;
        free(Aux);
    }
    deck->primeiro = deck->ultimo = NULL;   //só pra garantir, e setar o último
    deck->quantidade = 0;
}

/*
    OBJETIVO: Retornar um Ponteiro tCelula* do Deck de acordo com o indice.
    ENTRADAS: Ponteiro tDeck* para 'deck' e uma Variavel int para 'indice da Celula'.
    SAIDA: Ponteiro tCelula* para 'Celula selecionada'
    PRE-CONDICAO: 'deck' existente.
    POS-CONDICAO: Nada é alterado.
*/
tCelula* buscaCelula(tDeck* deck, int n){
    if(vazio(deck) || n < 0)
        return NULL;

    tCelula *aux = deck->primeiro;
    for(int i = 0; i < n && aux != NULL; i++)
        aux = proximo(aux);
    return aux;
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
        cartaAtual = primeiro(deck);
    for(int cont = 1; cartaAtual != NULL; cont++){
        printf("%d. ", cont);
        filtrAEPrinta(getCarta(cartaAtual));
        cartaAtual = proximo(cartaAtual);
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
        printf(" ***DEU BOSTA AO ALOCAR CARTA!!!\n");
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
//TODO: NÃO CONSIGO MEXER NESSA FUNÇÃO PRA ELA NÃO USA ACESSO DIRETO
void insereCarta(tCarta *carta, tDeck *deck){
    if(deck == NULL) return;
    tCelula *item = criaItem(carta);
    if(item == NULL) return;
    if(vazio(deck))
        deck->primeiro = deck->ultimo = item;
    else{
        deck->ultimo->proximo = item;
        deck->ultimo = deck->ultimo->proximo;
    }
    deck->quantidade++;
}

/*
    OBJETIVO: Verificar se 'deck' está alocado corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: 3 quando é nulo, 1 quando está vazio 2 quando a sentila está errada, 0 quando não é vazio nem nulo, e está OK, -1 quando tem algo de muito errado.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char vazio(tDeck *deck){
    if(deck == NULL) return -1;
    return (deck->primeiro == NULL);
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
            if(getNaipe(&aux->carta) != getNaipe(trunfo) || getNaipe(menor) == getNaipe(trunfo))
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
    return getCarta(ultimo(deck));
}

/*
    OBJETIVO: Funcao que seta qual sera a proxima celula.
    ENTRADAS: Ponteiro tCelula* para 'celula' e Ponteiro tCelula* para 'proxima celula'.
    SAIDA: -
    PRE-CONDICAO: Celula atual e o proximo existirem.
    POS-CONDICAO: O proximo da Celula de entrada ser a celula 'proximo' tambem da entrada.
*/
void dSetProximo(tCelula *cel, tCelula *proximo){
    if(cel != NULL)
        cel->proximo = proximo;
}

/*
    OBJETIVO: Faz Celula1 receber Celula2.
    ENTRADAS: Ponteiro tCelula* para 'celula1' e Ponteiro tCelula* para 'celula2'.
    SAIDA: -
    PRE-CONDICAO: Celula 1 e 2 existirem.
    POS-CONDICAO: Celula1 ter os mesmos atributos da Celula2.
*/
void dSetCel(tCelula *cel1, tCelula *cel2){
    cel1 = cel2;
}

/*
    OBJETIVO: Funcao que retorna o proximo de uma celula.
    ENTRADAS: Ponteiro tCelula* para 'celula alvo'.
    SAIDA: Ponteiro tCelula* para 'proximo celula'.
    PRE-CONDICAO: Celula existir.
    POS-CONDICAO: Proximo da celula retornado.
*/
tCelula* proximo(tCelula *cel){
    if(cel != NULL)
        return cel->proximo;
    return NULL;
}

/*
    OBJETIVO: Funcao que retorna a primeira celula do deck.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo'.
    SAIDA: Ponteiro tCelula* para 'primeira celula'.
    PRE-CONDICAO: Deck existir.
    POS-CONDICAO: Primeira celula do deck retornada.
*/
tCelula* primeiro(tDeck *deck){
    if(deck != NULL)
        return deck->primeiro;
    return NULL;
}

/*
    OBJETIVO: Funcao que retorna a ultima celula do deck.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo'.
    SAIDA: Ponteiro tCelula* para 'ultima celula'.
    PRE-CONDICAO: Deck existir.
    POS-CONDICAO: Ultima celula do deck retornada.
*/
tCelula* ultimo(tDeck *deck){
    if(deck != NULL)
        return deck->ultimo;
    return NULL;
}

/*
    OBJETIVO: Funcao que acessa a carta de uma celula.
    ENTRADAS: Ponteiro tCelula* para 'celula alvo'.
    SAIDA: Ponteiro tCarta* para 'carta'.
    PRE-CONDICAO: Celula existir.
    POS-CONDICAO: Carta da celula retornada.
*/
tCarta* getCarta(tCelula *cel){
    if(cel != NULL)
        return &cel->carta;
    return NULL;
}

/*
    OBJETIVO: Funcao que seta a carta de uma celula.
    ENTRADAS: Ponteiro tCelula* para 'celula alvo' e uma Variavel tCarta para 'carta'.
    SAIDA: -
    PRE-CONDICAO: Celula existir.
    POS-CONDICAO: Carta da celula ser a carta de entrada.
*/
void setCarta(tCelula *cel, tCarta carta){
    if(cel != NULL)
        cel->carta = carta;
}

/*
    OBJETIVO: Funcao que seta a quantidade de cartas de um Deck.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo' e uma Variavel int para 'quantidade de celulas'.
    SAIDA: -
    PRE-CONDICAO: Deck existir.
    POS-CONDICAO: Quantidade do deck ser a quantidade da entrada.
*/
void setQuantidade(tDeck *deck, int qtd){
    if(!vazio(deck))
        deck->quantidade = qtd;
}

/*
    OBJETIVO: Funcao que acessa a quantidade de celulas de um deck.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo'.
    SAIDA: Variavel int para 'quantidade de celulas em um deck'.
    PRE-CONDICAO: Deck existir.
    POS-CONDICAO: Quantidade de celulas retornada.
*/
int getQuantidade(tDeck *deck){
    if(deck != NULL)
        return deck->quantidade;
    return 0;
}