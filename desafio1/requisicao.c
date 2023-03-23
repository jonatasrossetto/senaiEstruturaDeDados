#include <stdlib.h>
#include <strings.h>

//para gerar o arquivo compilado
//gcc -c requisicao.c

struct Requisicao {
    char nome[40];
    int identificador;
    char procedimento[10];
};

struct Requisicao* get_requisicao(){
    //aloca um bloco de memória para a struct empregado e retorna o endereço do bloco
    return (struct Requisicao *)malloc(sizeof(struct Requisicao));
}

void cria_requisicao(struct Requisicao *requisicao, char *novo_nome, int novo_identificador, char *novo_procedimento){
    //atribui valores aos campos da Requisicao no endereço definido em requisicao
    int tamanho = strlen(novo_nome);
    if (tamanho > 40) {
        novo_nome[40-1]='\0';
    }
    tamanho = strlen(novo_procedimento);
    if (tamanho > 10) {
        novo_procedimento[10-1]='\0';
    }
    strcpy(requisicao->nome,novo_nome);
    strcpy(requisicao->procedimento,novo_procedimento);
    requisicao->identificador=novo_identificador;
};

char* get_nome(struct Requisicao *req){
    //retorna o nome da Requisição req
    return req->nome;
}

int get_identificador(struct Requisicao *req){
    //retorna o identificador da Requisição req
    return req->identificador;
}

char* get_procedimento(struct Requisicao *req){
    //retorna o procedimento da Requisição req
    return req->procedimento;
}