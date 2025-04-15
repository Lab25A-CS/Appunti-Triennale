#include <stdio.h>
#include <stdlib.h>

struct array_int{
    int *a; //array
    int n;  //caratteri
    int c;  //capacità
};
typedef struct array_int array_int;

void booble_sort(array_int);
void swap(int*, int*);
void array_print(array_int);

void main(){
    int a[] = {5,7,8,9,2,6,4,58,45,7,45,41,2,1,5};
    array_int t = {a, 15, sizeof(a)/sizeof(int)};
    booble_sort(t);
    array_print(t); 
}

void booble_sort(array_int v){

    if (v.n <= 1){
        return;
    }
    
    for (int k = 0; k < v.n; k++){
        for (int i = 0; i < v.n-k; i++){
            if (v.a[i+1] < v.a[i]){
                swap(&v.a[i],&v.a[i+1]);
            }
        }
    }
    return;

}

void swap (int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
    return;
}

void array_print(array_int v) {
	
	printf("[");
	for (int i=0; i<v.n; i++){
		printf("%d,", v.a[i]);
	}
	printf("]\n");
}