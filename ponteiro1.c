#include <stdio.h>

int main() {
    int a;
    int *p;
    p=&a;
    a=10;
    printf("a=%d\n",a);
    printf("&a=%d\n",&a);
    printf("p=%d\n",p);
    printf("&p=%d\n",&p);
    printf("*p=%d\n",*p);
    a=20;
    printf("-----------------\n");
    printf("a=%d\n",a);
    printf("&a=%d\n",&a);
    printf("p=%d\n",p);
    printf("&p=%d\n",&p);
    printf("*p=%d\n",*p);
    printf("-----------------\n");
    *p=30;
    printf("a=%d\n",a);
    printf("&a=%d\n",&a);
    printf("p=%d\n",p);
    printf("&p=%d\n",&p);
    printf("*p=%d\n",*p);
}
