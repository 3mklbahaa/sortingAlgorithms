#include <stdio.h>

void insertionSort(int A[], int n){
    int i, j, v;
    for(i=1;i<n;i++){
        v = A[i];
        j = i;
        while(A[j-1]>v && j>0){
            A[j] = A[j-1];
            j--;
        }
        A[j] = v;
    }
}

int main(){
  int A[3] = {3,10,1};
    insertionSort(A,3);
    printf("\ninsertion Sort:\n");
    for(int i=0; i<3; i++){
        printf("%d ",A[i]);
    }
}
