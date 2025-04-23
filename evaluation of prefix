#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
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
void push(int * top,int stack[],int x,int *size)
{
    if(isfull(top,size))
    {
       printf("the stack is full\n");
    }
  else
  {
      (*top)++;
      stack[*top]=x;
  }

}

int pop(int*top,int stack[])
{   
    int temp=stack[(*top)];
    (*top)--;
    return(temp);

}
bool isoperand(char a)
{

    if(a!='+' && a!='-' && a!='*'&& a!='/'&& a!='$'&& a!='%'&& a!='^')
    {
        return true;

    }
    else
    {
        return false;
    }
}

int convert(char a)
{
    int b = a-48;
    return b;

}
int value(int ope1,int ope2,char op)
{
    if(op=='+')
    {
        return (ope1 + ope2);
    }
    else if(op=='-')
    {
        return (ope1 - ope2);
    }
    else if(op=='*')
    {
        return (ope1 * ope2);
    }
    else if(op=='/')
    {
        return (ope1 / ope2);
    }
    else if(op=='$'||op=='^')
    {
        return (pow(ope1,ope2));
    }

}

int main()
{
    int opstack[100];
    char exp[100];
    printf("enter the expression:");
    scanf("%s",exp);
    int top=-1;
    int size=100;
    for(int i =strlen(exp)-1; i>=0;i--)
    {
        if(isoperand(exp[i]))
        {
            int symb=convert(exp[i]);
            push(&top,opstack,symb,&size);
        }
        else
        {
            int ope2=pop(&top,opstack);
            int ope1=pop(&top,opstack);
            push(&top,opstack,value(ope1,ope2,exp[i]),&size);
        }

    }
    printf("the value is %d",pop(&top,opstack));
}
    
    
