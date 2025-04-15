#include "codaLinked.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
    coda c = codaInit();
    for (int i = 0; i < 10; i++) {
        enqueue(&c, i);
    }
    int e = isEmpty(c);
    int d = dequeue(&c);
    int f = first(c);

    printf("%d, %d, %d\n", e, d, f);
}

node *nodeCreate(int e) {
    node *n = malloc(sizeof(node));
    n->next = NULL;
    n->v = e;
    n->prev = NULL;
    return n;
}

coda codaInit(void) {
    coda c = {NULL, 0, NULL};
    return c;
}

int codaIsEmpty(coda c) {
    if (c.len == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueue(coda *c, int e) {
    node *n = nodeCreate(e);
    if (c->len == 0) {
        c->head = n;
        c->tail = n;
    } else {
        n->prev = c->tail;
        c->tail->next = n;
        c->tail = n;
    }
    c->len++;
}

int dequeue(coda *c) {
    int e = c->head->v;
    node *p = c->head;
    c->head = c->head->next;
    c->len--;
    c->head->prev = NULL;
    free(p);
    return e;
}

int first(coda c) {
    int e = c.head->v;
    return e;
}
