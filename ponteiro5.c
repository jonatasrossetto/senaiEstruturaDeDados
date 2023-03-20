#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(){
    char nome1[] = "Jose Antonio";
    char nome2[] = {'J', 'o', 's', 'e', ' ', 'A', 'n', 't', 'o', 'n',
'i', 'o', '\0'};
    char nome3[50];
    int inc=0;
    for (inc=0;inc<12;inc++){
        nome3[inc]=nome1[inc];
    }
    
    nome3[12]='\0';
    printf(nome1);
    printf("\n");
    printf(nome2);
    printf("\n");
    printf(nome3);
    printf("\n");
    int dif;
    dif=strcmp(nome1,nome2);
    printf("strcmp(nome1,nome2) dif: %d \n",dif);
    dif=strcmp(nome1,nome3);
    printf("strcmp(nome1,nome3) dif: %d \n",dif);

}