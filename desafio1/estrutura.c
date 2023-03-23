#include <stdlib.h>

#include "requisicao.h"

struct node
{
    struct Requisicao *value; // Requisição armazenada no nó
    struct node *next; // aqui fica o ponteiro para o próximo nó
};

struct fila{
    struct node *head; //aponta para o nó cabeça no início da fila
    struct node *tail; //aponta para o nó cauda no fim da fila
    int size;
};

//inicializada a fila passada como argumento
void inicia_fila(struct fila *q){
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

//aloca a memória para a estrutura que armazena os ponteiros para a cabeça e para a cauda da fila
struct fila* aloca_fila(){
    return (struct fila *)malloc(sizeof(struct fila));
}

void inserir(struct fila *q, struct Requisicao *novo_valor){
    //adiciona 1 elemento na fila

    //cria um novo ponteiro nova_requisicao dentro da instancia de inserir
    struct Requisicao *nova_requisicao = get_requisicao();
    
    cria_requisicao(nova_requisicao,get_nome(novo_valor),get_identificador(novo_valor),get_procedimento(novo_valor));

    //cria um novo nó alocando o espaço na memória
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node!=NULL) {
        new_node->value = nova_requisicao;
        new_node->next = NULL;
    
        if (q->tail != NULL){
            // se o fim da fila (tail/cauda) existir então conecte a cauda atual ao novo nó, de modo que o novo nó se torne a nova cauda
            (q->tail)->next = new_node;
        }
        //defina a cauda/tail da fila como o novo nó
        (q->tail) = new_node;
        
        if (q->head == NULL){
            //se o início da fila (head/cabeça) não existir então faça que a nova cabeça da fila seja o novo nó, isto acontece quando a fila está vazia
            q->head = new_node;
        }
        
        //adiciona 1 elemento ao tamanho (size) da fila
        q->size = q->size+1;
    }
    
    

}

int get_size(struct fila *q){
    return q->size;
}

void remover(struct fila *q, struct Requisicao *resultado){
    //remove um elemento da fila
    if (q->head==NULL) {
        //retorna um erro se a fila estiver vazia
        cria_requisicao(resultado,"erro",-1,"erro");
    } else {
        
        //retorna em resultado os dados armazenados na cabeça/head da fila 
        cria_requisicao(resultado,get_nome(q->head->value),get_identificador(q->head->value),get_procedimento(q->head->value)); 
        
        // faz com que o próximo nó seja a nova cabeça/head da fila
        q->head = (q->head)->next; 
    
        //caso o próximo nó seja nulo (todos os elementos já foram removidos)
        //atribua nulo à cauda/tail da fila 
        if (q->head==NULL){
            q->tail=NULL;
        }
    
        //diminui 1 elemento do tamanho (size) da fila 
        q->size = q->size-1;

    }
}