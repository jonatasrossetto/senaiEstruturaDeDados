#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int *ponteiro = (int *)malloc(sizeof(int)*10);
    
    int inc;
    for (inc = 0; inc < 10; inc++){
        printf("vetor[%d]: %d \n",inc,vetor[inc]);
        *ponteiro = vetor[inc]*10;
        printf("ponteiro[%d]: %d \n",ponteiro, *ponteiro);
        ponteiro++;
    }
    ponteiro = ponteiro -10;
    printf("------------------------\n");
    free(ponteiro);
    for (inc = 0; inc < 10; inc++){
        printf("ponteiro[%d]: %d \n",ponteiro, *ponteiro);
        ponteiro++;
    }
    printf("------------------------\n");
    ponteiro=ponteiro-10;
    free(ponteiro);
    for (inc = 0; inc < 10; inc++){
        printf("inc: %d \n",inc);
        printf("ponteiro[%d]: %d \n",ponteiro[inc], *ponteiro);
        ponteiro++;
    }
    return 0;
}