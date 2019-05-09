#include "../headers/jogo.h"
// #include <locale.h>  //decidi não incluir por pesar mais 10 MB no HEAP e 10 allocs


int main(void){
    // setlocale(LC_ALL, "Portuguese_Brasil");
    tDeck *baralho = iniciaVazio();
    jogo(baralho);

    destroiDeck(baralho);
    return 0;
}