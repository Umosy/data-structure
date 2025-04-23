#include<stdio.h>
void shellsort(int a[],int n)
{   int swapped;
    int gap;
    int t;
    gap=n/2;
    do{
        do{
             swapped=0;
            for(int i=0;i<n-gap;i++)
            {
                if(a[i]>a[i+gap])
                {
                    
                    t=a[i];
                    a[i]=a[i+gap];
                    a[i+gap]=t;
                    swapped=1;
                }
            }
        }while(swapped==1);
        gap=gap/2;
    }while(gap>0);
}



int main()
{ int i,n;
  printf("enter n:");
  scanf("%d",&n);
  int a[n];
 for(i=0;i<n;i++)
 {
    printf("enter a[%d]:",i);
    scanf("%d",&a[i]);
  }
 shellsort(a,n); 
 
 for(i=0;i<n;i++)
 {
    printf("%d",a[i]);
    
  }
}
