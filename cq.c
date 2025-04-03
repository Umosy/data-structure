#include<stdio.h>

int isfull(int q[],int*f,int*r,int*max)
{
    if(((*f)==0&&(*r)==(*max)-1)||(*f)==(*r)+1)
        return 1;
    else
        return 0;
}

int isempty(int q[],int*f)
{
    if((*f)==-1)
        return 1;
    else
        return 0;

}


int enqueue(int q[],int*f,int*r,int x,int*max)
{
    if(isfull(q,f,r,max))
    {
       printf("the queue is full\n");
    }
    else
    {
        if((*r)==-1)
        {
            (*r)=0;
            (*f)=0;
        }
        else if((*r)==(*max)-1)
        {
            (*r)=0;
        }
        else
        {
            (*r)++;
        }
        q[(*r)]=x;
    }
    
}
int dequeue(int q[],int*f,int*r,int*max)
{
    if(isempty(q,f))
    {
       printf("the queue is empty\n");
    }
    else
    {   
        int val=q[(*f)];
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
        return val;
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
    printf("press 1 to enqueue\n");
    printf("press 2 to dequeue\n");
    printf("press 3 to display\n");
    printf("press 4 to exit\n\n");
    
    while(a!=4)
    {   
        printf("enter the number:");
        scanf("%d",&a);
        switch (a)
        {
            case 1:
            printf("enter the number to enqueue:");
            scanf("%d",&b);
            enqueue(q,&f,&r,b,&max);
            break;
            case 2:
            dequeue(q,&f,&r,&max);
            break;
            case 3:
            display(q,&f,&r,&max);
            break;
            
        }
    
    }
    
  

}

