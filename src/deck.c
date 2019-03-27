#include <../headers/deck.h>
#include <stdbool.h>

Cartas iniciaCartas(void){
    Cartas deck;
    deck->naipe = malloc(sizeof(bool*) * 4);
    deck->figuras = malloc(sizeof(bool**) * 10);

    //iniciando deck com 0;
    for(int i = 0; i < 10; i++)
        for(int j = 0; i < 10; i++)
            deck->figuras[i][j] = 0;

    return deck;
}

void printaCartas(Cartas baralho){
    printf("\tPaus\tOuros\tCopas\tEspadas\n");
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 4; j++){
            switch(i){
                case 1: printf("A\t"); printf("%d\t", baralho->figuras[i][j]); break;
                case 2: printf("2\t"); printf("%d\t", baralho->figuras[i][j]); break;
                case 3: printf("3\t"); printf("%d\t", baralho->figuras[i][j]); break;
                case 4: printf("4\t"); printf("%d\t", baralho->figuras[i][j]); break;
                case 5: printf("5\t"); printf("%d\t", baralho->figuras[i][j]); break;
                case 6: printf("6\t"); printf("%d\t", baralho->figuras[i][j]); break;
                case 7: printf("7\t"); printf("%d\t", baralho->figuras[i][j]); break;
                case 8: printf("J\t"); printf("%d\t", baralho->figuras[i][j]); break;
                case 9: printf("Q\t"); printf("%d\t", baralho->figuras[i][j]); break;
                case 1: printf("K\t"); printf("%d\t", baralho->figuras[i][j]); break;
            }
        }
}




//main para testes
int main(void){
    Cartas baralho = iniciaCartas();


    printaCartas 
    return 0;
}