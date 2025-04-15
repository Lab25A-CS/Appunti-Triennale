#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef struct coda {
  int *a;
  int n;
  int c;
} coda;

coda codaInit(void);
void codaDefine(coda *, int);
int isEmpty(coda);
void enqueue(coda *, int);
int dequeue(coda *);
int first(coda);

void main() {
  coda c = codaInit();
  codaDefine(&c, 10);
  int d = isEmpty(c);
  enqueue(&c, 10);
  int f = dequeue(&c);
  int t = first(c);

  printf("%d, %d, %d\n", d, f, t);
}

coda codaInit() {
  coda c = {NULL, 0, 0};
  return c;
}

void codaDefine(coda *c, int e) {
  c->a = malloc(sizeof(int) * e);
  for (int i = 0; i < e; i++) {
    c->a[i] = i;
  }
  c->n = e;
  c->c = e;
}

int isEmpty(coda c) {
  if (c.n == 0) {
    return true;
  } else {
    return false;
  }
}

void enqueue(coda *p, int e) {
  if (p->n == p->c) {
    p->a = realloc(p->a, sizeof(int) * (p->c * 2));
    p->c = p->c * 2;
  }
  p->a[p->n] = e;
  p->n++;
  return;
}

int dequeue(coda *p) {
  int e = p->a[0];
  p->a++;
  p->n--;
  if (p->n == p->c / 4) {
    p->a = realloc(p->a, sizeof(int) * p->c / 2);
    p->c = p->c / 2;
  }
  return e;
}

int first(coda p) { return p.a[0]; }
