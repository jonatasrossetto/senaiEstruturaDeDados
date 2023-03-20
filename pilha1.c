#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *nextNode;
} node;

typedef node * stack;

node *head = NULL;
int size = 0;

bool push(int newValue){
    node *newNode = malloc(sizeof(node));
    if (newNode==NULL) return false;
    newNode->value = newValue;
    newNode->nextNode = head; 
    head = newNode;
    size++;
    return true;
}

int pop(){
    if (head==NULL) return STACK_EMPTY;
    int result = head->value;
    node *tmp = head;
    head = head->nextNode;
    free(tmp);
    size--;
    return result;
}

int main(){
    printf("size:%d\n",size);
    push(10);
    printf("size:%d\n",size);
    push(30);
    printf("size:%d\n",size);
    push(40);
    printf("size:%d\n",size);
    printf("%d\n",pop());
    printf("size:%d\n",size);
    printf("%d\n",pop());
    printf("size:%d\n",size);
    printf("%d\n",pop());
    printf("size:%d\n",size);

}















