#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_EMPTY INT_MIN

typedef struct node
{
    int value;
    int index;
    struct node *nextNode;
} node;

typedef node * stack;

bool push(stack *mystack, int newValue){
    bool nulo;
    if (*mystack==NULL) {
        printf("mystack==null\n");
        node *newNode = malloc(sizeof(node));
        if (newNode==NULL) {
            return false;
        }
        newNode->value = newValue;
        newNode->nextNode = *mystack; 
        newNode->index = 0;
        *mystack = newNode;
        return true;
    } 
    node *newNode = malloc(sizeof(node));
    if (newNode==NULL) return false;
    newNode->value = newValue;
    newNode->nextNode = *mystack;
    newNode->index = (*mystack)->index+1; 
    *mystack = newNode;
    return true;
}

int pop(stack *mystack){
    if (*mystack==NULL) return STACK_EMPTY;
    int result = (*mystack)->value;
    // int index = (*mystack)->index;
    node *tmp = *mystack;
    *mystack = (*mystack)->nextNode;
    // (*mystack)->index = index-1;
    free(tmp);
    return result;
}

int stackSize(stack *mystack){
    if (*mystack==NULL) return -1;
    return (*mystack)->index;
}

int main(){
    stack pilha1 = NULL;
    
    push(&pilha1,10);
    printf("size1:%d\n",stackSize(&pilha1));

    push(&pilha1,11);
    printf("size1:%d\n",stackSize(&pilha1));

    push(&pilha1,12);
    printf("size1:%d\n",stackSize(&pilha1));
        
    printf("pop1:%d\n",pop(&pilha1));
    printf("size1:%d\n",stackSize(&pilha1));
    printf("pop1:%d\n",pop(&pilha1));
    printf("size1:%d\n",stackSize(&pilha1));
    printf("pop1:%d\n",pop(&pilha1));
    printf("size1:%d\n",stackSize(&pilha1));
    printf("pop1:%d\n",pop(&pilha1));
    printf("size1:%d\n",stackSize(&pilha1));

    push(&pilha1,13);
    printf("size1:%d\n",stackSize(&pilha1));
    push(&pilha1,14);
    printf("size1:%d\n",stackSize(&pilha1));
    push(&pilha1,15);
    printf("size1:%d\n",stackSize(&pilha1));

    printf("pop1:%d\n",pop(&pilha1));
    printf("size1:%d\n",stackSize(&pilha1));
    printf("pop1:%d\n",pop(&pilha1));
    printf("size1:%d\n",stackSize(&pilha1));
    printf("pop1:%d\n",pop(&pilha1));
    printf("size1:%d\n",stackSize(&pilha1));
    

}















