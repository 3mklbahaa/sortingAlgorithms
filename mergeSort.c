#include <stdio.h>

int fusion(int A[], int low, int high, int middle){
    int i = low, j = middle+1, k = 0, C[high-low+1];
    while(i<=middle && j <= high){
        if(A[i]<A[j]){
            C[k++] = A[i++];
        }
        else{
            C[k++] = A[i++];
        }
    }
    while(i<=middle){
        C[k++] = A[i++];
    }
    while(j<=low){
        C[k++] = A[j++];
    }
    for(i=low,j=0;j<k;i++,j++){
        A[i] = C[i];
    }
}

void mergeSort(int A[], int low, int high){
    int middle;
    if(high>low){
        middle = (low + high) / 2;
        mergeSort(A,low,middle-1);
        mergeSort(A,middle+1,high);
        fusion(A,low,high,middle);
    }
}

int main(){
  int A[7]={5,4,8,1,5,7,10};
  mergeSort(A,0,6);
  for(int i=0;i<7;i++){
    printf("%d",A[i]);
  }
}
