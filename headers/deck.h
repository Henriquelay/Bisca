/* HEADER PARA A BIBLIOTECA DECK */
#ifndef _H_DECKBISCA
#define _H_DECKBISCA
/*Aqui vai as funcoes*/

//Uma matriz para armazenar todo o baralho apenas uma única vez. Ao longo do jogo, será operado ponteiros para esse struct, nem a necessidade de declarar novamente.
typedef struct Cartas{
    // 1 = não usada; 0 = usada
    char **disponiveis;
    int cartas_nao_usadas;
}tCartas;


void printaCartas(tCartas *baralho);
tCartas iniciaCartas(void);
void freeCartas(tCartas *cartas);


/*Endif para evitar warnings*/
#endif