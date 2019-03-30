#include "../headers/cartas.h"
#include <stdlib.h>
#include <stdio.h>

#define numeroNaipes 4
#define numeroFiguras 10


////////////main para testes
/*int main(void){
    tCartas baralho = iniciaCartas();

    printaCartas(&baralho);
    freeCartas(&baralho);  

    return 0;
}
*/

tCartas iniciaCartas(void){
    tCartas deck;

    deck.disponiveis = (char**) malloc(sizeof(char*) * numeroFiguras);

    for(int i = 0; i < numeroFiguras; i++)
        deck.disponiveis[i] = (char*) malloc(sizeof(char) * numeroNaipes);

    if(deck.disponiveis == NULL || deck.disponiveis[0] == NULL){
        puts("\nOpa amigao, deu algo de errado ao alocar tCartas! Saindo\n");
        EXIT_FAILURE;
    }

    //iniciando deck com 0;
    for(int i = 0; i < numeroFiguras; i++)
        for(int j = 0; j < numeroNaipes; j++)
            deck.disponiveis[i][j] = 1;
    // 1 = não usada; 0 = usada

    return deck;
}

void printaCartas(tCartas *baralho){
    printf("\tPaus\tOuros\tCopas\tEspadas\n");
    
    for(int i = 0; i < numeroFiguras; i++){
        switch(i){
                case 0: printf("A\t"); break;
                case 1: printf("2\t"); break;
                case 2: printf("3\t"); break;
                case 3: printf("4\t"); break;
                case 4: printf("5\t"); break;
                case 5: printf("6\t"); break;
                case 6: printf("7\t"); break;
                case 7: printf("J\t"); break;
                case 8: printf("Q\t"); break;
                case 9: printf("K\t"); break;
                default: puts("WTF cara deu ruim aí");
            }
        for(int j = 0; j < numeroNaipes; j++)
            printf("%d\t", baralho->disponiveis[i][j]);
            
        printf("\n");
    }
}

void freeCartas(tCartas *cartas){
    for(int i = 0; i < numeroFiguras; i++)
        free(cartas->disponiveis[i]);
    free(cartas->disponiveis);
}
