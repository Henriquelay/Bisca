/* HEADER PARA A BIBLIOTECA DECK 
por Henrique Layber e Ezequiel Schneider
        Suplementa o programa de bisca,
    adicionando funcionalidades ao TAD tipoDeck
*/
#ifndef _H_DECKBISCA
#define _H_DECKBISCA
/*Aqui vai as funcoes*/
#include "cards.h"  //já inclui a <stdlib.h> e <stdio.h>
#include <time.h>


//*STRUCTS

//Define os items que serão contidos no deck. (lista encadeada de cartas com sentinela)
typedef struct tCelula tCelula;
typedef struct tCelula{
    tCarta carta;
    tCelula *proximo;
} tCelula;

//Define as sentinelas e auxiliadores do deck. (lista encadeada de cartas com sentinela)
typedef struct tDeck{
    tCelula *primeiro, *ultimo;
    int quantidade;
} tDeck;


//*DEFINEM AS CARTAS PARA LEGIBILIDADE (O VALOR REPRESENTA A ORDEM DE ENCARTE)
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

//*DEFINEM OS NAIPES PARA LEGIBILIDADE
#define NAIPEO 0
#define NAIPEP 1
#define NAIPEC 2
#define NAIPEE 3

//*FUNÇÕES

/*
    OBJETIVO: Funcao que seta qual sera a proxima celula.
    ENTRADAS: Ponteiro tCelula* para 'celula' e Ponteiro tCelula* para 'proxima celula'.
    SAIDA: -
    PRE-CONDICAO: Celula atual e o proximo existirem.
    POS-CONDICAO: O proximo da Celula de entrada ser a celula 'proximo' tambem da entrada.
*/
void dSetProximo(tCelula *cel, tCelula *proximo);

/*
    OBJETIVO: Faz Celula1 receber Celula2.
    ENTRADAS: Ponteiro tCelula* para 'celula1' e Ponteiro tCelula* para 'celula2'.
    SAIDA: -
    PRE-CONDICAO: Celula 1 e 2 existirem.
    POS-CONDICAO: Celula1 ter os mesmos atributos da Celula2.
*/
void dSetCel(tCelula *cel1, tCelula *cel2);

/*
    OBJETIVO: Funcao que retorna o proximo de uma celula.
    ENTRADAS: Ponteiro tCelula* para 'celula alvo'.
    SAIDA: Ponteiro tCelula* para 'proximo celula'.
    PRE-CONDICAO: Celula existir.
    POS-CONDICAO: Proximo da celula retornado.
*/
tCelula* proximo(tCelula *cel);

/*
    OBJETIVO: Funcao que retorna a primeira celula do deck.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo'.
    SAIDA: Ponteiro tCelula* para 'primeira celula'.
    PRE-CONDICAO: Deck existir.
    POS-CONDICAO: Primeira celula do deck retornada.
*/
tCelula* primeiro(tDeck *deck);

/*
    OBJETIVO: Funcao que retorna a ultima celula do deck.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo'.
    SAIDA: Ponteiro tCelula* para 'ultima celula'.
    PRE-CONDICAO: Deck existir.
    POS-CONDICAO: Ultima celula do deck retornada.
*/
tCelula* ultimo(tDeck *deck);

/*
    OBJETIVO: Funcao que acessa a carta de uma celula.
    ENTRADAS: Ponteiro tCelula* para 'celula alvo'.
    SAIDA: Ponteiro tCarta* para 'carta'.
    PRE-CONDICAO: Celula existir.
    POS-CONDICAO: Carta da celula retornada.
*/
tCarta* getCarta(tCelula *cel);

/*
    OBJETIVO: Funcao que seta a carta de uma celula.
    ENTRADAS: Ponteiro tCelula* para 'celula alvo' e uma Variavel tCarta para 'carta'.
    SAIDA: -
    PRE-CONDICAO: Celula existir.
    POS-CONDICAO: Carta da celula ser a carta de entrada.
*/
void setCarta(tCelula *cel, tCarta card);

/*
    OBJETIVO: Funcao que seta a quantidade de cartas de um Deck.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo' e uma Variavel int para 'quantidade de celulas'.
    SAIDA: -
    PRE-CONDICAO: Deck existir.
    POS-CONDICAO: Quantidade do deck ser a quantidade da entrada.
*/
void setQuantidade(tDeck *deck, int qtd);

/*
    OBJETIVO: Funcao que acessa a quantidade de celulas de um deck.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo'.
    SAIDA: Variavel int para 'quantidade de celulas em um deck'.
    PRE-CONDICAO: Deck existir.
    POS-CONDICAO: Quantidade de celulas retornada.
*/
int getQuantidade(tDeck *deck);

/*
    OBJETIVO: Preencher 'deck' corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' com todas as cartas que serão usadas na bisca nele.
*/
void preenche(tDeck *deck);

/*
    OBJETIVO: Transferir um Ponteiro tCelula* de um Deck ao outro Deck.
        EXEMPLO: Comprar uma carta do monte exige tirar ela do monte e colocar ela na mao do jogador.
    ENTRADAS: Ponteiro tDeck* para 'primeiro deck' e um Ponteiro tDeck* para 'segundo deck', Variavel int para 'indice da carta'.
    SAIDA: -
    PRE-CONDICAO: 'deck1 e deck2' existe e está alocado corretamente.
    POS-CONDICAO: Mudanca de deck da Celula feita.
*/
void transfereCelula(tDeck *deck1, tDeck *deck2, int n);

/*
    OBJETIVO: Retirar um Ponteiro tCelula* de um Deck e retornar ela.
    ENTRADAS: Ponteiro tDeck* para 'deck alvo', Variavel int para 'indice da carta no deck'.
    SAIDA: Ponteiro tCarta* para 'carta retirada'.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente e o indice 'n' ser um valor possivel dado o tamanho do deck.
    POS-CONDICAO: Celula retirada do 'deck' e retornada.
*/
tCelula* retiraCelula(tDeck *deck, int n);

/*
    OBJETIVO: Troca 2 células de lugar.
    ENTRADAS: Ponteiro para duas células.
    SAIDA: -
    PRE-CONDICAO: As células existem e são válidas.
    POS-CONDICAO: As duas células trocam de posição na lista, inalteradas.
*/
void swap2Celulas(tCelula *a, tCelula *b);

/*
    OBJETIVO: Cortar 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' está cortado (a carta cortada é o trunfo e ela vai pro fundo do deck).
*/
void corta(tDeck *deck);

/*
    OBJETIVO: Embaralhar 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' está embaralhado.
*/
void embaralha(tDeck *deck, int passes);

/*
    OBJETIVO: Desalocar toda a memória ocupada por 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' não ocupa mais espaço no HEAP e aponta para NULL.
*/
void destroiDeck(tDeck *deck);

/*
    OBJETIVO: Desalocar toda a memória ocupada por 'deck' menos na primeira Celula.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'deck' estar vazio.
*/
void esvaziaDeck(tDeck *deck);

/*
    OBJETIVO: Retornar um Ponteiro tCelula* do Deck de acordo com o indice.
    ENTRADAS: Ponteiro tDeck* para 'deck' e uma Variavel int para 'indice da Celula'.
    SAIDA: Ponteiro tCelula* para 'Celula selecionada'
    PRE-CONDICAO: 'deck' existente.
    POS-CONDICAO: Nada é alterado.
*/
tCelula* buscaCelula(tDeck* deck, int n);

/*
    OBJETIVO: Imprimir 'deck' na tela.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: Nada é alterado.
*/
void imprimeDeck(tDeck *deck);

/*
    OBJETIVO: Inserir 'carta' em 'deck'. *Será inserida no início
    ENTRADAS: Ponteiro para 'deck', ponteiro para 'carta'.
    SAIDA: Endereço para a célula criada.
    PRE-CONDICAO: A carta existe.
    POS-CONDICAO: A célula foi corretamente alocada, a carta não foi alterada.
*/
tCelula* criaItem(tCarta *carta);

/*
    OBJETIVO: Inserir 'carta' em 'deck'.
    ENTRADAS: Ponteiro para 'deck', ponteiro para 'carta'.
    SAIDA: -
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: 'carta' está contida em 'deck'.
*/
void insereCarta(tCarta *carta, tDeck *deck);

/*
    OBJETIVO: Verificar se 'deck' está alocado corretamente.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: 3 quando é nulo, 1 quando está vazio 2 quando a sentila está errada, 0 quando não é vazio nem nulo, e está OK, -1 quando tem algo de muito errado.
    PRE-CONDICAO: -
    POS-CONDICAO: Nada é alterado.
*/
char vazio(tDeck *deck);

/*
    OBJETIVO: Iniciar 'deck' vazio corretamente.
    ENTRADAS: -
    SAIDA: 'deck'.
    PRE-CONDICAO: -
    POS-CONDICAO: Inicializado, porém sem elementos.
*/
tDeck* iniciaVazio(void);

/*
    OBJETIVO: Selecionar a menor carta de 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: Ponteiro para a menor carta.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: .
*/
tCarta* menorCarta(tDeck *deck, tCarta *trunfo);

/*
    OBJETIVO: Selecionar a maior carta de 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: Ponteiro para a maior carta.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: .
*/
tCarta* maiorCarta(tDeck *deck, tCarta *trunfo);

/*
    OBJETIVO: Selecionar a menor carta de 'deck'.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: Ponteiro para a menor carta.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: .
*/
char contaPontos(tDeck *deck);

/*
    OBJETIVO: Pegar o trunfo do fundo do baralho.
    ENTRADAS: Ponteiro para 'deck'.
    SAIDA: O naipe do fundo de 'deck'.
    PRE-CONDICAO: 'deck' existe e está alocado corretamente.
    POS-CONDICAO: Nada é alterado.
*/
tCarta* defineTrunfo(tDeck *deck);

/*
    OBJETIVO: Dizer se tem uma carta especifica em um deck.
    ENTRADAS: Ponteiro tDeck* para 'deck' e ponteiro para carta.
    SAIDA: >0 quando existe, 0 quando nao existe.
    PRE-CONDICAO: Deck existir.
    POS-CONDICAO: Nada e alterado.
*/
char possui(tDeck *deck, tCarta *carta);

void resgataTrunfo(tDeck *monte, tCelula* trunfo);

char buscaCarta(tCarta *carta, tDeck *deck);

#endif  //_H_DECKBISCA