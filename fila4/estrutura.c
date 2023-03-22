#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include "requisicao.h"

struct node
{
    struct Requisicao *value;
    struct node *next;
};

struct queue{
    struct node *head;
    struct node *tail;
    int size;
};

void initQueue(struct queue *q){
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

struct queue* get_queue(){
    return (struct queue *)malloc(sizeof(struct queue));
}

bool enqueue(struct queue *q, struct Requisicao *newValue){
    
    //cria um novo ponteiro nova_requisicao dentro da instancia enqueue
    struct Requisicao *nova_requisicao = get_requisicao();
    
    cria_requisicao(nova_requisicao,get_nome(newValue),get_identificador(newValue),get_procedimento(newValue));

    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode==NULL) return false; // return false if there is no memory enough
    newNode->value = nova_requisicao;
    
    newNode->next = NULL;
    

    // if a tail exists the connect the actual tail node to the new node, so the new node will be the new tail
    if (q->tail != NULL){
        (q->tail)->next = newNode;
    }
    (q->tail) = newNode;
    
    
    //if the head does not exist the make the new node the head of the queue
    if (q->head == NULL){
        q->head = newNode;
    }
    
    
    //increments the queue size
    q->size = q->size+1;
    return true;
}

int get_size(struct queue *q){
    return q->size;
}

void dequeue(struct queue *q, struct Requisicao *resultado){
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