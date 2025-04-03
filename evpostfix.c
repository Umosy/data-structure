#include<stdio.h>





void push(int * top,char stack[],char x,int *size)
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

char pop(int*top,char stack[])
{
    if(isempty(top))
    {
        printf("stack is empty\n");
    }
    else
    {   
        char temp=stack[(*top)];
        (*top)--;
        return(temp);
    
    }
}






































