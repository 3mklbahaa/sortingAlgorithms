#include <stdio.h>

int partition(int A[], int low, int high){
    int left, right, pivot = A[low];
    left = low + 1, right = high;
    while(left <= right){
        while(A[left] < pivot){
            left ++;
        }
        while(A[right]>pivot){
            right --;
        }
        if(left<right){
            int tmp = A[left];
            A[left] = A[right];
            A[right] = tmp;
        }
    }
    A[low] = A[right];
    A[right] = pivot;
    return right;
}

void quickSortHelper(int A[], int low, int high){
    int pivot ;
    if(high>low){
        pivot = partition(A,low,high);
        quickSortHelper(A,low,pivot-1);
        quickSortHelper(A,pivot+1,high);
    }
}

void quickSort(int A[], int n){
    quickSortHelper(A,0,n-1);
}

int main(){
   printf("\nQuickSort:\n");
    int A[6] = {10, 7, 8, 9, 1, 5};
    quickSort(A,6);
    for(int i=0; i<6; i++){
        printf("%d ",A[i]);
    }
}
