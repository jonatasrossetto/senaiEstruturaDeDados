#include <stdlib.h>
#include <strings.h>

//para gerar o arquivo compilado
//gcc -c tad.c

struct empregado
{
    char nome[50];
    double cpf;
    double salario;
};

struct empregado* get_empregado(){
    //aloca um bloco de memória para a struct empregado e retorna o endereço do bloco
    return (struct empregado *)malloc(sizeof(struct empregado));
}

void set_nome(struct empregado *e, char *nome){
    int tamanho = strlen(nome);
    if (tamanho > 50) {
        nome[50-1]='\0';
    }
    strcpy(e->nome, nome);
}

char* get_nome(struct empregado *e) {
    return e->nome;
}

void set_cpf(struct empregado *e, double cpf) {
    e->cpf = cpf;
}

double get_cpf(struct empregado *e) {
    return e->cpf;
}

void set_salario(struct empregado *e, double salario) {
    e->salario = salario;
}

double get_salario(struct empregado *e) {
return e->salario;
}