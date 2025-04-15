#ifndef CODA_H
#define CODA_H

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

typedef struct coda{
    node *head;
    int len;
    node *tail;
}coda;

node *nodeCreate(int);
coda codaInit(void);
int codaIsEmpty(coda);
void enqueue(coda*, int);
int dequeue(coda*);
int first(coda);



#endif // !CODA_H



