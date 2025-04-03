#include<stdio.h>
#include<stdbool.h>
#include<string.h>



void push(int *top,char stack[],char x,int*size);
char pop(int *top,char stack[]);
bool isempty(int *top);
bool isfull(int *top,int*size);
char peektop(int*top,char stack[]);
void display(int top,char stack[]);
bool prec(char a,char b);
bool isclosingp(char c);
bool isopenp(char c);
int isp(char c);
int icp(char c);



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
char peektop(int*top,char stack[])
{
    if(isempty(top))
    printf("stack is empty\n");
    
    else
    return(stack[(*top)]);

}
bool prec(char a,char b)
{
    if(isp(a)>icp(b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isclosingp(char c)
{
    if(c==')'||c=='}'||c==']')
        return true;
    else
        return false;

}
bool isopenp(char c)
{
    if(c=='('||c=='{'||c=='[')
        return true;
    else
        return false;

}

int isp(char c)
{
  if(c=='$')
      return 4;
  else if(c=='*'||c=='/')
      return 3;
  else if(c=='+'||c=='-')
      return 2;
  else if(c==')'||c=='}'||c==']')
      return 0;

}
int icp(char c)
{
  if(c=='$')
      return 5;
  else if(c=='*'||c=='/')
      return 3;
  else if(c=='+'||c=='-')
      return 2;
  else if(c==')'||c=='}'||c==']')
      return 5;
  else if(c=='('||c=='{'||c=='[')
      return 1;

}







int main()
{   int top=-1;
    int size=20;
    char stack[size];
    char res[30];
    char exp[20];
    char symb;
    printf("enter the expression:");
    scanf("%s",exp);
    int length = strlen(exp);
    int z=0;
    for(int i = length -1;i>=0;i--)
    {
        if((exp[i]>='a' && exp[i]<='z')|| (exp[i]>='A' && exp[i]<='Z'))
        {
           res[z]=exp[i];
           z++;

            
        }
        
        else
        {
            while(!isempty(&top) && prec(peektop(&top,stack),exp[i]) && !isclosingp(exp[i]))
            {
              symb = pop(&top,stack);
              res[z]=symb;
              z++;
            
            }
            if(!isopenp(exp[i]))
            {
                push(&top,stack,exp[i],&size);
            }
            else
            {
                symb = pop(&top,stack);
            }
            
        
        }
        
    
    }
    
    while(!isempty(&top))
    {
        symb = pop(&top,stack);
        res[z]=symb;
        z++;

   }
   int i=0;
    for(i=z;i>=0;i--)
    {
    printf("%c",res[i]);
    }
    
    }
    




