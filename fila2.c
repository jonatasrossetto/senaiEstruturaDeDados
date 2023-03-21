#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

typedef struct Requisicao {
    char nome[40];
    int identificador;
    char procedimento[10];
} Requisicao;

Requisicao cria_requisicao(char newNome[40], int newIdent, char newProced[10]){
    Requisicao req;
    strcpy(req.nome,newNome);
    strcpy(req.procedimento,newProced);
    req.identificador=newIdent;
    return req;
};

char *get_nome(Requisicao req){
    char *nome = req.nome;
    return nome;
}

int get_identificador(Requisicao req){
    return req.identificador;
}

char *get_procedimento(Requisicao req){
    char *procedimento = req.procedimento;
    return procedimento;
}

typedef struct node
{
    Requisicao value;
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

bool enqueue(queue *q, Requisicao newValue){
    
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
    
    //increments the queue size
    q->size = q->size+1;
    return true;
}

int queueSize(queue *q){
    return q->size;
}

Requisicao dequeue(queue *q){
    //checks if the queue is empty
    Requisicao erro;
    strcpy(erro.nome,"erro");
    erro.identificador=-1;
    strcpy(erro.procedimento,"erro");
    
    if (q->head==NULL) return erro;
    
    // creates a temporary node to store the actual head info
    node *temp = q->head;
    Requisicao result = temp->value; // get the value stored in the head
    q->head = (q->head)->next; // make the next node the new head
    
    //deals with the queue being empty by the dequeue action
    if (q->head==NULL){
        q->tail=NULL;
    }
    
    //decrements the queue size
    q->size = q->size-1;
    
    //free the memory allocated for the temp variable
    free(temp);
    return result;
}

void main(){
    queue q1;
    char nomes[][40] = {"Joao", "Jose", "Maria", "Silvia", "Sonia", "Pedro", "Lucas", "Bernardete", "Lucia", "Olivia"}; 
    char procedimentos[][10] = {"123.1", "345.6", "678.9", "098.1", "758.5", "23.4", "5.98", "4,32", "3.3", "1.4"};

    initQueue(&q1);

    for (int i=0;i<10;i++){
        Requisicao req = cria_requisicao(nomes[i],i,procedimentos[i]);

        enqueue(&q1,req);
        printf("-------------\n");
        printf("identificador(%d)\n",i);
        printf("nome:%40s\n",req.nome);
        printf("procedimento:%10s\n",req.procedimento);
        printf("size1:%d\n",queueSize(&q1));    
    }
    printf("\n\n\n -------------\nretirando elementos da fila\n\n\n");
    
    for (int i=0;i<11;i++){
        Requisicao req;
        req = dequeue(&q1);
        printf("-------------\n");
        printf("identificador(%d)\n",get_identificador(req));
        printf("nome:%40s\n",get_nome(req));
        printf("procedimento:%10s\n",get_procedimento(req));
        printf("size1:%d\n",queueSize(&q1));    
    }

    // printf("size1:%d\n",queueSize(&q1));
    
    // printf("size1:%d\n",queueSize(&q1));
    // printf("pop1:%d\n",dequeue(&q1));
    


}
