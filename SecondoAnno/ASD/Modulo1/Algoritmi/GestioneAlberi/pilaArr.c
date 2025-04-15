#include <stdio.h>
#include <stdlib.h>

#define false  0
#define true  1


typedef struct pila{
    int *a;
    int n;
    int c;
}pila;


void pila_define(pila*, int);
pila pila_init(void);
int isEmpty(pila);
void push(pila*, int);
int pop(pila*);
int top(pila);

void main(){
    pila p = pila_init();
    pila_define(&p, 10);
    push(&p,10);
    int e = pop(&p);
    int d = top(p);
    int t = isEmpty(p);

    printf("%d, %d, %d \n", e, d, t);
}

int isEmpty(pila p){
    if (sizeof(p.a)/sizeof(int) == 0){
        return true;
    }
    else{
        return false;
    }
}

pila pila_init(void) {
    pila p = {NULL, 0, 0};
    return p;
}

void pila_define(pila *p, int e){
    p->a = malloc(sizeof(int)*(e));
    for (int i = 0; i < e; i++ ){
        p->a[i] = i;
    }
    p->n = e;
    p->c = e;
}

void push(pila *p, int e){
    if (p->c == p->n){
        p->a = realloc(p->a,(p->c*2)*sizeof(int));
        p->c =(p->n*2);
    }
     p->a[p->n] = e;
     p->n++;
     return;   
}

int pop(pila *p){
    int e = p->a[p->n-1];
    p->n--;
    if (p->n == (p->c/4)){
        p->a = realloc(p->a, sizeof(int)*(p->c/2));
        p->c = p->c/2;
    }
    return e;
}

int top(pila p){
    int e = p.a[p.n-1];
    return e;
}

