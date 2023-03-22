#include <stdlib.h>

#include "requisicao.h"

struct node
{
    struct Requisicao *value; // aqui fica o valor armazenado no nó
    struct node *next; // aqui fica o ponteiro para o próximo nó
};

struct queue{
    struct node *head; //aponta para o nó cabeça no início da fila
    struct node *tail; //aponta para o nó cauda no fim da fila
    int size;
};

//inicializada a fila passada como argumento
void initQueue(struct queue *q){
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

//aloca a memória para a estrutura que armazena os ponteiros para a cabeça e para a cauda da fila
struct queue* aloca_fila(){
    return (struct queue *)malloc(sizeof(struct queue));
}

void inserir(struct queue *q, struct Requisicao *newValue){
    
    //cria um novo ponteiro nova_requisicao dentro da instancia de inserir
    struct Requisicao *nova_requisicao = get_requisicao();
    
    cria_requisicao(nova_requisicao,get_nome(newValue),get_identificador(newValue),get_procedimento(newValue));

    //cria um novo nó alocando o espaço na memória
    struct node *newNode = malloc(sizeof(struct node));
    
    newNode->value = nova_requisicao;
    newNode->next = NULL;
    
    // se o fim da fila (tail/cauda) existir então conecte a cauda atual ao novo nó, de modo que o novo nó se torne a nova cauda
    
    if (q->tail != NULL){
        (q->tail)->next = newNode;
    }
    (q->tail) = newNode;
        
    //se o início da fila (head/cabeça) não existir então faça que a nova cabeça da fila seja o novo nó, isto acontece quando a fila está vazia
    if (q->head == NULL){
        q->head = newNode;
    }
        
    //adiciona 1 elemente ao tamanho (size) da fila
    q->size = q->size+1;
    

}

int get_size(struct queue *q){
    return q->size;
}

void remover(struct queue *q, struct Requisicao *resultado){
    //checks if the queue is empty
    if (q->head==NULL) {
        cria_requisicao(resultado,"erro",-1,"erro");
    } else {
        
        // creates a temporary node to store the actual head info
        struct node *temp = q->head;

        cria_requisicao(resultado,get_nome(q->head->value),get_identificador(temp->value),get_procedimento(temp->value)); // get the value stored in the head
        
        q->head = (q->head)->next; // make the next node the new head
    
        //deals with the queue being empty by the dequeue action
        if (q->head==NULL){
            q->tail=NULL;
        }
    
        //decrements the queue size
        q->size = q->size-1;

        //free the memory allocated for the temp variable
        free(temp);
    }
}