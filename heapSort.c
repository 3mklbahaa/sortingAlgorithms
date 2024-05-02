#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *array;
    int capacity;
    int count;
    int heap_type;
} Heap;

Heap *createHeap(int capacity, int heap_type) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->capacity = capacity;
    h->count = 0;
    h->heap_type = heap_type;
    h->array = (int *)malloc(sizeof(int) * capacity);
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void percolateDown(Heap *h, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->count && h->array[left] > h->array[max])
        max = left;

    if (right < h->count && h->array[right] > h->array[max])
        max = right;

    if (max != i) {
        swap(&h->array[i], &h->array[max]);
        percolateDown(h, max);
    }
}

void buildHeap(Heap *h, int A[], int n) {
    if (n > h->capacity) {
        printf("Array size exceeds heap capacity.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        h->array[i] = A[i];
    }
    h->count = n;
    for (int i = (n - 1) / 2; i >= 0; i--) {
        percolateDown(h, i);
    }
}


void heapSort(int A[], int n) {
    Heap *h = createHeap(n, 0);
    buildHeap(h, A, n);

    int oldSize = h->count;
    for (int i = n - 1; i >= 0; i--) {
        int tmp = h->array[0];
        h->array[0] = h->array[h->count - 1];
        h->array[h->count - 1] = tmp;
        h->count--;
        percolateDown(h, 0);
    }
    h->count = oldSize;
    for (int i = 0; i < h->count; i++) {
        A[i] = h->array[i];
    }

    free(h->array);
    free(h);
}

int main(){
    int A[6] = {15,63,4,0,1,55};
    heapSort(A,6);
    for(int i=0;i<6;i++){
        printf("%d ",A[i]);
    }
}
