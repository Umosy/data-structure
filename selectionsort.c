#include <stdio.h>
void selectionsort(int arr[],int n){
    int i,j,min,t;
    for( i=0;i<n-1;i++){
        min=i;
        for (j=i+1;j<n;j++)
            if(arr[j]<arr[min])
                min=j;
                
        if(min!=i){
            t=arr[min];
            arr[min]=arr[i];
            arr[i]=t;
        }
            
    }
}
int main() {
    int n;
    printf("size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    selectionsort(arr,n);
    for(int i=0;i<n;i++)
        printf("|%d|\t",arr[i]);
    
    return 0;
}
