#include <stdio.h>
#include<stdlib.h>
void display(int*m,int*n,int**result)
{
    
    for(int i=0;i<*m;i++)
    {
       for(int j=0;j<*n;j++)
       {
           printf("%d\t",result[i][j]);
       }
        printf("\n");
    }
    
    
}

void getroco(int*m,int*n)
{
    printf("enter the number of rows:");
    scanf("%d",m);
    printf("enter the number of column:");
    scanf("%d",n);
    
}
void getmatrix(int*m,int*n,int **a)
{
    for(int i=0;i<*m;i++)
    {
       for(int j=0;j<*n;j++)
       {
           printf("enter the [%d][%d] position:",i,j);
           scanf("%d",&a[i][j]);
       }
        
    }
    
}

void add(int*m,int*n,int**a,int **b,int**result)
{
    for(int i=0;i<*m;i++)
    {
       for(int j=0;j<*n;j++)
       {
           result[i][j]=a[i][j]+b[i][j];
       }
        
    }
    display(m,n,result);
}
void sub(int*m,int*n,int**a,int **b,int**result)
{
    for(int i=0;i<*m;i++)
    {
       for(int j=0;j<*n;j++)
       {
           result[i][j]=a[i][j]-b[i][j];
       }
        
    }
    display(m,n,result);
}

void mul(int* m,int*n,int*d,int**a,int**b,int**result)
{
    
    for(int i=0;i<*m;i++)
    {
     for(int j=0;j<*d;j++)
     {   int sum=0;
         for(int k =0;k<*n;k++)
         {
             sum=sum+a[i][k]*b[k][j];
             
         }
         result[i][j]=sum;
     }
     
    }
    display(m,d,result);
    
    
}

void transpose(int*m,int *n,int **a,int**result )
{
    
    
    for(int i=0;i<*m;i++)
    {
     for(int j=0;j<*n;j++)
     {
       result[j][i]=a[i][j];    
         
     }
    
    }
    
     display(n,m,result);
}

int main() {
    
    int x;
    int m,n,c,d;
    while (x!=5 )
    {
    printf("enter the option:");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
        getroco(&m,&n);
        int **a=(int**)malloc(m*sizeof(int));
        int **b=(int**)malloc(m*sizeof(int));
        int **result=(int**)malloc(m*sizeof(int));
        for(int i=0;i<m;i++)
        {
        a[i]=(int*)malloc(n*sizeof(int));
        b[i]=(int*)malloc(n*sizeof(int));
        result[i]=(int*)malloc(n*sizeof(int));
        }
        printf("enter the matrix 1\n");
        getmatrix(&m,&n,a);
        printf("enter the matrix 2\n");
        getmatrix(&m,&n,b);
        printf("the resultant matrix\n");
        add(&m,&n,a,b,result);
    
        case 2:
        getroco(&m,&n);
        a=(int**)malloc(m*sizeof(int));
        b=(int**)malloc(m*sizeof(int));
        result=(int**)malloc(m*sizeof(int));
        for(int i=0;i<m;i++)
        {
        a[i]=(int*)malloc(n*sizeof(int));
        b[i]=(int*)malloc(n*sizeof(int));
        result[i]=(int*)malloc(n*sizeof(int));
        }
        printf("enter the matrix 1\n");
        getmatrix(&m,&n,a);
        printf("enter the matrix 2\n");
        getmatrix(&m,&n,b);
        printf("the resultant matrix\n");
        sub(&m,&n,a,b,result);
        break;
      
        case 3:
        {
        jumphere:
        getroco(&m,&n);
        a=(int**)malloc(m*sizeof(int));
        for(int i=0;i<m;i++)
        {
        a[i]=(int*)malloc(n*sizeof(int));
        }
        getroco(&c,&d);
        b=(int**)malloc(c*sizeof(int));
        for(int i=0;i<c;i++)
        {
        b[i]=(int*)malloc(d*sizeof(int));
        }
        if(n!=c)
        {
            goto jumphere;
        }
        result=(int**)malloc(m*sizeof(int));
        for(int i=0;i<m;i++)
        {
        result[i]=(int*)malloc(d*sizeof(int));
        }
        printf("enter the matrix 1\n");
        getmatrix(&m,&n,a);
        printf("enter the matrix 2\n");
        getmatrix(&c,&d,b);
        mul(&m,&n,&d,a,b,result);
        
        }
        break;
        
        case 4:
        getroco(&m,&n);
        a=(int**)malloc(m*sizeof(int));
        for(int i=0;i<m;i++)
        {
        a[i]=(int*)malloc(n*sizeof(int));
        }
        getmatrix(&m,&n,a);
        result=(int**)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        {
        result[i]=(int*)malloc(m*sizeof(int));
        }
        printf("the original matrix\n");
        display(&m,&n,a);
        printf("the resultant matrix\n");
        transpose(&m,&n,a,result);
        
    }
   }
    return 0;
}
