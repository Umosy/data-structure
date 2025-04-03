#include<stdio.h>
void merge(int a[],int low,int mid,int high)
{
    int b[6];
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;

        }
        k++;
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;

    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for (int i=low;i<k;i++)
    {
        a[i]=b[i];

    }
    

}
void merge_sort(int a[],int low,int high)
{    

    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }

}






int main()
{
    int a[6]={3,0,2,7,4,6};
    int low=0;
    int high =5;
    merge_sort(a,low,high);
    for(int i=0;i<=high;i++)
    {
        printf("%d ",a[i]);
    }
    

}