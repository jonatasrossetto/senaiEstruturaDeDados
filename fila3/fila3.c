#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "requisicao.h"

//para montar a aplicação utilizando o struct definido em requisicao.c e compilado para requisicao.o com o head
//gcc fila3.c requisicao.o

typedef struct node
{
    struct Requisicao *value;
    struct node *next;
} node;

typedef struct{
    node *head;
    node *tail;
    int size;
} queue;

void initQueue(queue *q){
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

bool enqueue(queue *q, struct Requisicao *newValue){
    
    //cria um novo ponteiro nova_requisicao dentro da instancia enqueue
    struct Requisicao *nova_requisicao = get_requisicao();
    
    cria_requisicao(nova_requisicao,get_nome(newValue),get_identificador(newValue),get_procedimento(newValue));

    //create a new node
    node *newNode = malloc(sizeof(node));
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

int get_size(queue *q){
    return q->size;
}

void dequeue(queue *q, struct Requisicao *resultado){
    //checks if the queue is empty
    if (q->head==NULL) {
        cria_requisicao(resultado,"erro",-1,"erro");
    } else {
        
        // creates a temporary node to store the actual head info
        node *temp = q->head;

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

void main(){
   struct Requisicao *req=get_requisicao();
//    cria_requisicao(req,"Joao",1,"ABC");
//    printf("nome:%40s\n",get_nome(req));
   
   queue q;
   initQueue(&q);
   cria_requisicao(req,"Joao",1,"ABC");
   printf("nome:%40s\n",get_nome(req));
   enqueue(&q,req);
   printf("size:%d\n",get_size(&q));
   
   cria_requisicao(req,"Maria",2,"BCA");
   printf("nome:%40s\n",get_nome(req));
   enqueue(&q,req);
   printf("size:%d\n",get_size(&q));
   
   cria_requisicao(req,"Jose",3,"CAB");
   printf("nome:%40s\n",get_nome(req));
   enqueue(&q,req);
   printf("size:%d\n",get_size(&q));
   cria_requisicao(req,"fim",-1,"fim");
   
   printf("\n\n-------------------\n\n");
   
   printf("size:%d\n",get_size(&q));
   dequeue(&q,req);
   printf("nome:%40s\n",get_nome(req));

   printf("size:%d\n",get_size(&q));
   dequeue(&q,req);
   printf("nome:%40s\n",get_nome(req));
   
   printf("size:%d\n",get_size(&q));
   dequeue(&q,req);
   printf("nome:%40s\n",get_nome(req));

   printf("size:%d\n",get_size(&q));
   dequeue(&q,req);
   printf("nome:%40s\n",get_nome(req));
   

}

