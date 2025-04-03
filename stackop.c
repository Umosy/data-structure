#include<stdio.h>
#include<stdbool.h>
void push(int *top,int stack[],int x,int*size);
int pop(int *top,int stack[]);
bool isempty(int *top);
bool isfull(int *top,int*size);
int peektop(int*top,int stack[]);
void display(int top,int stack[]);

void push(int * top,int stack[],int x,int *size)
{
    if(isfull(top,size))
    {
       printf("the stack is full\n");
    }
  else
  {
      (*top)++;
      stack[(*top)]=x;
  }

}

int pop(int*top,int stack[])
{
    if(isempty(top))
    {
        printf("stack is empty\n");
    }
    else
    {   
        int temp=stack[(*top)];
        (*top)--;
        return(temp);
    
    }
}

bool isempty(int*top)
{
    if((*top)==-1)
    return true;

    else
    return false;
}

bool isfull(int*top,int*size)
{
    if((*top)==(*size)-1)
    return true;

    else
    return false;
}

int peektop(int*top,int stack[])
{
    if(isempty(top))
    printf("stack is empty\n");
    
    else
    return(stack[(*top)]);

}

void display(int top,int stack[])
{    
    for(int i=0;i<=top;i++)
    {
    printf("%d ",stack[i]);
    }

}




int main()
{ 
   int y;
   int top=-1;
   int size=10;
   int stack[size];
   printf("***********Menu************\n\n");
   printf("press 1 to push\n");
   printf("press 2 to pop\n");
   printf("press 3 to check the stack is full\n");
   printf("press 4 to check the stack is empty\n");
   printf("press 5 to peektop\n");
   printf("press 6 to display\n");
   while(y!=7)
   {
   printf("\nenter the number:");
   scanf("%d",&y);
   
   switch(y)
   {
       case 1:
       int x;
       printf("enter the number to push:");
       scanf("%d",&x);
       push(&top,stack,x,&size);
       display(top,stack);
       break;
       
       case 2:
       pop(&top,stack);
       display(top,stack);
       break;
       
       case 3:
       if(isfull(&top,&size))
       {
          printf("the stack is full\n");
       }
       else
       {
          printf("the stack is not full\n");
       }
       break;
       
       case 4:
       if(isempty(&top))
       {
          printf("the stack is empty\n");
       }
       else
       {
          printf("the stack is not empty\n");
       }
       break;
       
       
       case 5:
       printf("%d",peektop(&top,stack));
       break;
       
       case 6:
       display(top,stack);
       break;
  
   }
   
   
}

return 0;

}

