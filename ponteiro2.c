#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main() {
    int a=10;
    int *p;
    int *w;
    printf("sizeof(int): %d\n",sizeof(int));
    p = (int *) malloc(sizeof(int));
    w = (int *) malloc(sizeof(int));
    if (p == NULL) return 1;
    if (w == NULL) return 1;
    printf("-----------------\n");
    *p = a;
    w=p;
    printf("a=%d\n",a);
    printf("&a=%d\n",&a);
    printf("p=%d\n",p);
    printf("&p=%d\n",&p);
    printf("*p=%d\n",*p);
    printf("w=%d\n",w);
    printf("&w=%d\n",&w);
    printf("*w=%d\n",*w);
    printf("-----------------\n");
    a = 20;
    printf("a=%d\n",a);
    printf("&a=%d\n",&a);
    printf("p=%d\n",p);
    printf("&p=%d\n",&p);
    printf("*p=%d\n",*p);
    printf("w=%d\n",w);
    printf("&w=%d\n",&w);
    printf("*w=%d\n",*w);
    printf("-----------------\n");
    *p = 20;
    printf("a=%d\n",a);
    printf("&a=%d\n",&a);
    printf("p=%d\n",p);
    printf("&p=%d\n",&p);
    printf("*p=%d\n",*p);
    printf("w=%d\n",w);
    printf("&w=%d\n",&w);
    printf("*w=%d\n",*w);
    printf("-----------------\n");
    
    w=NULL;free(w);
    w = (int *) malloc(sizeof(int));
    *p = 20;*w=30;
    printf("a=%d\n",a);
    printf("&a=%d\n",&a);
    printf("p=%d\n",p);
    printf("&p=%d\n",&p);
    printf("*p=%d\n",*p);
    printf("w=%d\n",w);
    printf("&w=%d\n",&w);
    printf("*w=%d\n",*w);



}