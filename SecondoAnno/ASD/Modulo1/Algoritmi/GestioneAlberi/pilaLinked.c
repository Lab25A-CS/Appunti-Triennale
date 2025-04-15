#include "pilaLinked.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
    pila p = pilaInit();
    push(&p, 11);
    push(&p, 10);
    push(&p, 9);
    int e = pop(&p);
    int d = pop(&p);

    printf("%d, %d \n", e, d);
}

node *nodeCreate(int e) {
    node *n = malloc(sizeof(node));
    n->next = NULL;
    n->v = e;
    n->prev = NULL;
    return n;
}

pila pilaInit(void) {
    pila p = {NULL, 0};
    return p;
}

int pilaIsEmpty(pila p) {
    if (p.len == 0) {
        return true;
    } else {
        return false;
    }
}

void push(pila *p, int e) {
    node *n = nodeCreate(e);

    if (p->len > 0) {
        n->next = p->head;
        p->head->prev = n;
        p->head = n;
    } else {
        p->head = n;
    }
    p->len++;
    return;
}

int pop(pila *p) {
    int e = p->head->v;
    node *n = p->head;
    p->head = p->head->next;
    p->head->prev = NULL;
    p->len--;
    free(n);
    return e;
}

int top(pila p) {
    int e = p.head->v;
    return e;
}
