#include <stdio.h>
#include <strings.h>

int main(){
    struct empregado
    {
        char nome[50];
        double cpf;
        double salario;
    };
    
    struct empregado e;
    strcpy(e.nome, "Maria Joaquina");
    e.cpf=987654321;
    e.salario=1312.57;
    printf("nome: %s\n",e.nome);
    printf("cpf: %.0f\n",e.cpf);
    printf("salario: %.2f\n",e.salario);
    return 0;

}