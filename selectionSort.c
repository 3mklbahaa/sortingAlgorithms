#include <stdio.h>

void selectionSort(int A[], int n){
    int i, j, min, tmp;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        if(min!=i){
            tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
        }
    }
}

int main(){
  int B[10] = {1867,1057,432,15,190,1,2540,154540,1,3};
    selectionSort(B,10);
    printf("\nselection Sort:\n");
    for(int i=0;i<10;i++){
        printf("%d ",B[i]);
    }
}
