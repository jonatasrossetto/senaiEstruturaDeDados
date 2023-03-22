#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "requisicao.h"
#include "estrutura.h"

//para montar e executar a aplicação utilizar o arquivo de lote fila4.bat

void main(){
   struct Requisicao *req=get_requisicao();
//    cria_requisicao(req,"Joao",1,"ABC");
//    printf("nome:%40s\n",get_nome(req));
   
   struct queue *q = get_queue();
   
   initQueue(q);
   cria_requisicao(req,"Joao",1,"ABC");
   printf("nome:%40s\n",get_nome(req));
   enqueue(q,req);
   printf("size:%d\n",get_size(q));
   
   cria_requisicao(req,"Maria",2,"BCA");
   printf("nome:%40s\n",get_nome(req));
   enqueue(q,req);
   printf("size:%d\n",get_size(q));
   
   cria_requisicao(req,"Jose",3,"CAB");
   printf("nome:%40s\n",get_nome(req));
   enqueue(q,req);
   printf("size:%d\n",get_size(q));
   cria_requisicao(req,"fim",-1,"fim");
   
   printf("\n\n-------------------\n\n");
   
   printf("size:%d\n",get_size(q));
   dequeue(q,req);
   printf("nome:%40s\n",get_nome(req));

   printf("size:%d\n",get_size(q));
   dequeue(q,req);
   printf("nome:%40s\n",get_nome(req));
   
   printf("size:%d\n",get_size(q));
   dequeue(q,req);
   printf("nome:%40s\n",get_nome(req));

   printf("size:%d\n",get_size(q));
   dequeue(q,req);
   printf("nome:%40s\n",get_nome(req));
   

}

