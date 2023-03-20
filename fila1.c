#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
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

bool enqueue(queue *q, int newValue){
    
    //create a new node
    node *newNode = malloc(sizeof(node));
    if (newNode==NULL) return false; // return false if there is no memory enough
    newNode->value = newValue;
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
    q->size = q->size+1;
    return true;
}

int queueSize(queue *q){
    return q->size;
}

int dequeue(queue *q){
    if (q->head==NULL) return INT_MIN;
    node *temp = q->head;
    int result = temp->value;
    q->head = (q->head)->next;
    if (q->head==NULL){
        q->tail=NULL;
    }
    q->size = q->size-1;
    free(temp);
    return result;
}

void main(){
    queue q1;
    initQueue(&q1);
    enqueue(&q1,10);
    printf("size1:%d\n",queueSize(&q1));
    enqueue(&q1,11);
    printf("size1:%d\n",queueSize(&q1));
    enqueue(&q1,12);
    printf("size1:%d\n",queueSize(&q1));
    enqueue(&q1,13);
    printf("size1:%d\n",queueSize(&q1));
    printf("pop1:%d\n",dequeue(&q1));
    printf("size1:%d\n",queueSize(&q1));
    printf("pop1:%d\n",dequeue(&q1));
    printf("size1:%d\n",queueSize(&q1));
    printf("pop1:%d\n",dequeue(&q1));
    printf("size1:%d\n",queueSize(&q1));
    printf("pop1:%d\n",dequeue(&q1));
    printf("size1:%d\n",queueSize(&q1));
    printf("pop1:%d\n",dequeue(&q1));
    printf("size1:%d\n",queueSize(&q1));


}
