#include <stdio.h>
#include <stdlib.h>

typedef struct array_int {
    int *a;
    int n;
    int c;
} array_int;

void insertion_sort(array_int);
void array_print(array_int);
void swap(int *, int *);

int main() {
    int a[] = {5, 7, 8, 9, 2, 6, 4, 58, 45, 7, 45, 41, 2, 1, 5};
    array_int t = {a, 15, sizeof(a) / sizeof(int)};
    insertion_sort(t);
    array_print(t);
    return 0;
}

void insertion_sort(array_int v) {

    if (v.n <= 1) {
        return;
    }

    for (int k = 1; k < v.n; k++) {
        for (int i = 0; i < k; i++) {
            if (v.a[k] < v.a[i]) {
                swap(&v.a[k], &v.a[i]);
            }
        }
    }
    return;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;

    return;
}

void array_print(array_int v) {

    printf("[");
    for (int i = 0; i < v.n; i++) {
        printf("%d,", v.a[i]);
    }
    printf("]\n");
}
