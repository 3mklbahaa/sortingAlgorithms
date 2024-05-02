#include <stdio.h>

void bubbleSort(int A[], int n){
    int pass, i, temp, swapped=1;
    for(pass = n-1; pass>=0 && swapped; pass--){
        swapped = 0;
        for(i = 0; i<pass;i++){
            if(A[i]>A[i+1]){
                int tmp = A[i+1];
                A[i+1] = A[i];
                A[i] = tmp;
                swapped = 1;
            }
        }
    }
}

int main(){
    int A[10] = {1,10,2,15,10,18,20,10,5,7};
    bubbleSort(A,10);
    printf("buble Sort:\n");
    for(int i=0;i<10;i++){
        printf("%d ",A[i]);
    }
