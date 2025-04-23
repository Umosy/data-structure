#include<stdio.h>
void insertion_sort(int a[],int n){
    int t,j;
    for (int i=1;i<n;i++){
     t=a[i];
     j=i-1;
     while(j>=0&&t<a[j]){
         a[j+1]=a[j];
         j--;
     }
     a[j+1]=t;
        
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int ar[n];
    for(int i=0;i<n;i++){
    scanf("%d ",&ar[i]);
    }
    insertion_sort(ar,n);
    for(int i=0;i<n;i++){
    printf("%d ",ar[i]);
    }
    return 0;
}