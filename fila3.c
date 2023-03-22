#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "requisicao.h"

//para montar a aplicação utilizando o struct definido em requisicao.c e compilado para requisicao.o com o head
//gcc fila3.c requisicao.o

// typedef struct node
// {
//     struct Requisicao *value;
//     struct node *next;
// } node;

// typedef struct{
//     node *head;
//     node *tail;
//     int size;
// } queue;

// void initQueue(queue *q){
//     q->head = NULL;
//     q->tail = NULL;
//     q->size = 0;
// }

// bool enqueue(queue *q, struct Requisicao *newValue){
    
//     //create a new node
//     node *newNode = malloc(sizeof(node));
//     if (newNode==NULL) return false; // return false if there is no memory enough
//     newNode->value = newValue;
//     newNode->next = NULL;
    
//     // if a tail exists the connect the actual tail node to the new node, so the new node will be the new tail
//     if (q->tail != NULL){
//         (q->tail)->next = newNode;
//     }
//     (q->tail) = newNode;
    
//     //if the head does not exist the make the new node the head of the queue
//     if (q->head == NULL){
//         q->head = newNode;
//     }
    
//     //increments the queue size
//     q->size = q->size+1;
//     return true;
// }

// int get_size(queue *q){
//     return q->size;
// }

// struct Requisicao* dequeue(queue *q){
//     //checks if the queue is empty
//     struct Requisicao erro = cria_requisicao("erro",-1,"erro");
        
//     if (q->head==NULL) return erro;
    
//     // creates a temporary node to store the actual head info
//     node *temp = q->head;
//     struct Requisicao *result = temp->value; // get the value stored in the head
//     q->head = (q->head)->next; // make the next node the new head
    
//     //deals with the queue being empty by the dequeue action
//     if (q->head==NULL){
//         q->tail=NULL;
//     }
    
//     //decrements the queue size
//     q->size = q->size-1;
    
//     //free the memory allocated for the temp variable
//     free(temp);
//     return result;
// }








void main(){
   struct Requisicao *req=get_requisicao();
   cria_requisicao(req,"Joao",1,"ABC");
   printf("nome:%40s\n",get_nome(req));
//    queue q;
//    initQueue(&q);
//    enqueue(&q,cria_requisicao("João",1,"ABC"));
//    printf("size:%d\n",get_size(&q));
//    enqueue(&q,cria_requisicao("Maria",2,"BCA"));
//    printf("size:%d\n",get_size(&q));
//    enqueue(&q,cria_requisicao("José",3,"CAB"));
//    printf("size:%d\n",get_size(&q));
//    printf("-------------------\n");
//    printf("size:%d\n",get_size(&q));
//    printf("nome:%40s\n",get_nome(dequeue(&q)));
//    printf("size:%d\n",get_size(&q));
//    printf("nome:%40s\n",get_nome(dequeue(&q)));
//    printf("size:%d\n",get_size(&q));
//    printf("nome:%40s\n",get_nome(dequeue(&q)));
//    printf("size:%d\n",get_size(&q));
//    printf("nome:%40s\n",get_nome(dequeue(&q)));
//    printf("size:%d\n",get_size(&q));

}

