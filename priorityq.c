#include<stdio.h>


struct prior
{
    int data;
    int pr;

};


void enq(int d,int p,struct prior pq[],int *r,int *f,int max)
{
    if(*r==max-1)
    {
        printf("overflow");
    }
    else
    {
        if(*f==-1)
        {
            (*f)=0;
            (*r)=0;
        }
        else
        {
            (*r)++;
        
        }
        pq[(*r)].data=d;
        pq[(*r)].pr=p;
    }

}

int deq(struct prior pq[],int * f, int * r)
{   if((*f)==(*r))
        {
            printf("underflow");
        }
    else
    {
      int pos;
      pos=(*f);
      int max;
      int j;
      max=pq[(*f)].pr;
      int data=pq[(*f)].data;
      for(int i=(*f)+1;i<=(*r);i++)
      {
          if(pq[i].pr>=max)
              {
                  max=pq[i].pr;
                  data=pq[i].data;
                  pos=i;
                
              }
      
      }
      for(j =pos;j<(*r);j++)
      {
          pq[j]=pq[j+1];
      
      }
      (*r)--;
      return data;
    }
}


void display(int*f,int*r,struct prior pq[])
{
    for(int i=(*f);i<=(*r);i++)
    {
        printf("(%d,%d) ", pq[i].data,pq[i].pr);
    }

}

int main()
{    
    int max=10;
    int f=-1;
    int r=-1;
    struct prior pq[max];
    int x;
    printf("Menu\n");
    printf("1 to enqueue\n");
    printf("2 to dequeue\n");
    printf("3 to display\n");
    printf("4 to quit\n");
    
    while(x!=4)
    {
        printf("\nenter the number\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
        int a,b;
        printf("enter the data:");
        scanf("%d",&a);
        printf("enter the priority:");
        scanf("%d",&b);
        enq(a,b,pq,&r,&f,max);
        break;
        
        case 2:
        printf("%d",deq(pq,&f,&r));;
        break;
        
        case 3:
        display(&f,&r,pq);
        break;
        }
    
    }






return 0 ;
}











