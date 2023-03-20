#include <stdio.h>

void adiciona1PorValor(int valor) {
    printf("Argumento valor antes= %d\n",valor);
    valor++;
    printf("Argumento valordepois = %d\n",valor);
}

void adiciona1PorReferencia(int *valor){
    printf("Argumento valor antes= %d\n",*valor);
    (*valor)++;
    printf("Argumento valordepois = %d\n",*valor);
}

int main(){
    int valorOriginal = 5;
    printf("valor original: %d\n",valorOriginal);
    adiciona1PorValor(valorOriginal);
    printf("valor original: %d\n",valorOriginal);
    printf("------------------------------\n");
    printf("valor original: %d\n",valorOriginal);
    adiciona1PorReferencia(&valorOriginal);
    printf("valor original: %d\n",valorOriginal);
    
}