#include "requisicao.h"
#include "estrutura.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>


void imprime(struct Requisicao *requisicao) {
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Endereco: %p\nNome        : %40s\nInscricao   : %40d\nProcedimento: %40s\n\n", requisicao, get_nome(requisicao), get_identificador(requisicao), get_procedimento(requisicao));
}

int main() {
    
    char nomes[][40] = {"Joao", "Jose", "Maria", "Silvia", "Sonia", "Pedro", "Lucas", "Bernardete", "Lucia", "Olivia"}; 

    char procedimentos[][20] = {"123.1", "345.6", "678.9", "098.1", "758.5", "23.4", "5.98", "4,32", "3.3", "1.4"};
    
    struct queue *estrutura = aloca_fila(); //
    initQueue(estrutura);

    int i;
    
    struct Requisicao *requisicao = get_requisicao();
    for(i = 0; i < 10; i++) {
        cria_requisicao(requisicao, nomes[i], i, procedimentos[i]);
        inserir(estrutura, requisicao);
        printf("Insercao de %40s, quantidade na estrutura: %04d\n", get_nome(requisicao), get_size(estrutura));
    }

    printf("Fim da insercao.\nInicio da remocao\n");
    
    for(i = 0; i < 11; i++) {
        struct Requisicao *r = get_requisicao();
        remover(estrutura,r);
        printf("Removido    %40s, quantidade na estrutura: %04d\n", get_nome(r), get_size(estrutura));
        imprime(r);
        free(r);
    }

   

    return 0;
}
