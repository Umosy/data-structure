#include<stdio.h>

int insertfront(int q[],int*f,int*r,int x,int*max)
{
    if(((*f)==0&&(*r)==(*max)-1)||(*r)==(*f)-1)
    {
       printf("overflow\n");
    }
    else if((*f)==-1)
    {
        (*f)=0;
        (*r)=0;
    
    }
    else
    {
        if((*f)==0)
        {
            (*f)=(*max)-1;
        }
        
        else
        {
            (*f)--;
        }
       
    }
     q[(*f)]=x;
}


int insertrear(int q[],int*f,int*r,int x,int*max)
{
    if(((*f)==0&&(*r)==(*max)-1)||(*r)==(*f)-1)
    {
       printf("overflow\n");
    }
    else if((*r)==-1)
    {
        (*f)=0;
        (*r)=0;
    
    }
    else
    {
        if((*r)==(*max)-1)
        {
            (*r)=0;
        }
        
        else
        {
            (*r)++;
        }
       
    }
     q[(*r)]=x;
}
int deletefront(int q[],int*f,int*r,int*max)
{
    if((*f)==-1)
    {
       printf("underflow\n");
    }
    else
    {   
        
        if((*f)==(*r))
        {
            (*r)=-1;
            (*f)=-1;
        }
        else if((*f)==(*max)-1)
        {
            (*f)=0;
        }
        else
        {
            (*f)++;
        }
    }
    
}

int deleterear(int q[],int*f,int*r,int*max)
{
    if((*r)==-1)
    {
       printf("underflow\n");
    }
    else
    {   
        
        if((*f)==(*r))
        {
            (*r)=-1;
            (*f)=-1;
        }
        else if((*r)==0)
        {
            (*r)=(*max)-1;
        }
        else
        {
            (*r)--;
        }
    }
    
}




void display(int q[], int *f, int *r, int *max) {
    if (*f == -1) 
    {
        printf("The queue is empty\n");
    } 
    else if (*r >= *f)
    {
        for (int i = *f; i <= *r; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    } 
    else 
    {
        for (int i = *f; i < *max; i++) 
        {
            printf("%d ", q[i]);
        }
        for (int i = 0; i <= *r; i++) 
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main()
{   
    int max=10;
    int q[max];
    int f=-1,r=-1;
    int a,b;
    printf("*****Menu*****\n");
    printf("press 1 to insertfront\n");
    printf("press 2 to insertrear\n");
    printf("press 3 to deletefront\n");
    printf("press 4 to deleterear\n");
    printf("press 5 to display\n");
    printf("press 6 to exit\n\n");
    
    while(a!=6)
    {   
        printf("enter the number:");
        scanf("%d",&a);
        switch (a)
        {
            case 1:
            printf("enter the number to insert:");
            scanf("%d",&b);
            insertfront(q,&f,&r,b,&max);
            break;
            case 2:
            printf("enter the number to insert:");
            scanf("%d",&b);
            insertrear(q,&f,&r,b,&max);
            break;
            case 3:
            deletefront(q,&f,&r,&max);
            break;
            case 4:
            deleterear(q,&f,&r,&max);
            break;
            case 5:
            display(q,&f,&r,&max);
            break;
            
            
        }
    
    }
    
  

}

