#include<stdio.h>

int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low+1;
    int j=high;
    while(i<=j)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;

        }
    }
    int tempo;
    tempo=a[low];
    a[low]=a[j];
    a[j]=tempo;
    return j;
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }

}
int main()
{
    int a[6]={4,35,6,17,24,6};
    quicksort(a,0,5);
    for (int i=0;i<=5;i++)
    {
        printf("%d ",a[i]);
    }



}






















