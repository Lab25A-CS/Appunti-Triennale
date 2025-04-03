#include <stdio.h>
#include <stdlib.h>

typedef struct arrayInt {
    int *array;
    int len;
    int cap;
} arrayInt;

typedef struct node {
    struct node **children;
    int val;
} node;

typedef struct tree {
    node *root;
    int len;
} tree;

arrayInt arrayIntInit(void);
void *arrayIntCreate(arrayInt *, int);
tree treeInit(void);
node *nodeCreate(int, int);
void *treeCompile(tree *, node *, arrayInt *, int, int, int);
void *treeCreate(tree *, arrayInt *, int, int);
// void treePrint(tree);

void main() {
    arrayInt a = arrayIntInit();
    int b[] = {5, 3, 6, 9, 8, 6, 5, 2, 4, 5, 8, 7, 14};
    for (int i = 0; i < (sizeof(b) / sizeof(int)); i++) {
        arrayIntCreate(&a, b[i]);
    }
    tree t = treeInit();
    treeCreate(&t, &a, 2, 3);
}

arrayInt arrayIntInit(void) {
    arrayInt a = {NULL, 0, 0};
    return a;
}

void *arrayIntCreate(arrayInt *a, int e) {
    if (a->len == a->cap) {
        a->array = realloc(a->array, sizeof(int) * ((a->cap * 2) + 1));
        a->cap = (a->cap * 2) + 1;
    }

    a->array[a->len] = e;
    a->len++;
    return;
}

tree treeInit(void) {
    tree t = {NULL, 0};
    return t;
}

node *nodeCreate(int e, int child) {
    node *n = malloc(sizeof(node));
    n->father = NULL;
    n->children = malloc(sizeof(arrayInt));
    n->children->array = malloc(sizeof(int) * child);
    n->val = e;
    return n;
}

void *treeCompile(tree *t, node *v, arrayInt *a, int child, int h, int alt) {
    if (a->len == 0 || alt == h++) {
        return;
    }
    node *n = nodeCreate(a->array[a->len - 1], child);
    a->len--;
    for (int i = 0; i < child; i++) {
        t->len++;
        treeCompile(&t, &v->children[i], &a, child, h, alt++);
    }
}

void *treeCreate(tree *t, arrayInt *a, int child, int h) {
    if (a->len == 0) {
        return;
    }

    if (t->len == 0) {
        node *n = nodeCreate(a->array[a->len - 1], child);
        a->len--;
        t->root = n;
        t->len++;
    }

    treeCompile(&t, &t->root, &a, child, h, 0);
    return;
}
