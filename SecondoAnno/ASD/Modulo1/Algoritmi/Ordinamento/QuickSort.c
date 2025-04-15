#include <stdio.h>
#include <stdlib.h>

typedef struct array_int {
    int *a;
    int n;
    int c;
} array_int;

int partition(array_int, int, int);
void quick_sort(array_int, int, int);
void swap(int *, int *);
void array_print(array_int);

int main() {
    int a[] = {4, 8, 9, 6, 5, 7, 2, 5, 4, 6, 1};
    array_int v = {a, 11, sizeof(a) / sizeof(int)};
    quick_sort(v, 0, v.n - 1);
    array_print(v);

    return 0;
}

int partition(array_int v, int i, int f) {
    int x = v.a[i];
    int inf = i + 1;
    int sup = f;
    int t = 0;

    while (inf < sup) {
        while (v.a[inf] <= x && sup != inf) {
            inf++;
        }
        while (v.a[sup] > x && sup != inf) {
            sup--;
        }
        if (sup <= inf) {
            break;
        }
        swap(&v.a[sup], &v.a[inf]);
    }
    swap(&v.a[i], &v.a[sup]);
    return inf;
}

void quick_sort(array_int v, int i, int f) {

    if (i < f) {
        int m = partition(v, i, f);
        quick_sort(v, i, m - 1);
        quick_sort(v, m + 1, f);
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
