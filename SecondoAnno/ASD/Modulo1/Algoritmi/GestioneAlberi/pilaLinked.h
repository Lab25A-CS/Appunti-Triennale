#ifndef PILA_H
#define PILA_H

#ifndef TRUE_FALSE
#define TRUE_FALSE
#define true 1
#define false 0
#endif

#ifndef NODE
#define NODE
typedef struct node{
    struct node *next;
    int v;
    struct node *prev;
}node;
#endif

typedef struct pila{
    node *head;
    int len;
}pila;

node *nodeCreate(int);
pila pilaInit(void);

int pilaIsEmpty(pila);
void push(pila*, int);
int pop(pila*);
int top(pila);


#endif // !DEBUGdef
