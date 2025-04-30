#include<stdio.h>
void constructheap(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int child =i;
        int parent=(child-1)/2;
        while(child>0&&a[parent]<a[child])
        {
            int temp;
            temp=a[parent];
            a[parent]=a[child];
            a[child]=temp;
            child=parent;
            parent=(child-1)/2;
        }
    }
}
void heapsort(int a[],int n)
{
    constructheap(a,n);
    while(n>0)
    {
        int temp;
        temp=a[0];
        a[0]=a[n-1];
        a[n-1]=temp;
        n--;
        int parent=0;
        
        while(parent*2+1<n)
        {
            int left=2*parent+1;
            int child;
            int right=left+1;
            if(right<n && a[right]>a[left])
            {
                child=right; 
            }
            else
            {
                child=left;
            }
            if (a[parent]>a[child])
            {
                break;
            }
            int temp1;
            temp1=a[parent];
            a[parent]=a[child];
            a[child]=temp1;
            parent=child;


        }
    }
    
}

int main()
{   int n=6;
    int a[6]={2,5,7,8,3,1};
    heapsort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}
