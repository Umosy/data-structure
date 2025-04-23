#include <stdio.h>
void bubblesort(int arr[],int n){
    for(int i=1;i<=n-1;i++)
        for (int j=0;j<=n-i-1;j++)
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
}
int main() {
    int n;
    printf("size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    bubblesort(arr,n);
    for(int i=0;i<n;i++)
        printf("|%d|\t",arr[i]);
    
    return 0;
}