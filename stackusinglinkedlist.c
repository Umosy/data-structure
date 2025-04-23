#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node *getnode()
{
    struct node * ptr=(struct node*) malloc (sizeof(struct node));
}
void push(int datas,struct node**top)
{
    struct node*p;
    p=getnode();
    p->data=datas;
     p->next=*top;
    if(*top==NULL)
    {
        *top=p;
    }
    else
    {  
      *top=p;
    }
}
void pop(struct node**top)
{
    if(*top==NULL)
    {
        printf("empty stack");
    }
    else
    {
        struct node*p;
        p=(*top);
        (*top)=(*top)->next;
        free(p);
    }

}
int peektop(struct node**top)
{
    if(*top==NULL)
    {
        printf("empty");
    }
    else
    {
        return((*top)->data);
    }
}
void display(struct node**top)
{   
    if(*top==NULL)
    {
        printf("empty");
    }
    else
    {
    struct node*temp;
    temp=(*top);
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    
    }
    }
}
int main()
{  
   struct node*top=NULL;
   printf("***********Menu************\n\n");
   printf("press 1 to push\n");
   printf("press 2 to pop\n");
   printf("press 3 to peektop\n");
   printf("press 4 to display\n");
   printf("press 5 to quit\n");
   int x;
   while(x!=5)
   {
   printf("\nenter the number:");
   scanf("%d",&x);
   
   switch(x)
   {
       case 1:
       int y;
       printf("enter the number to push:");
       scanf("%d",&y);
       push(y,&top);
       break;
       
       case 2:
       pop(&top);
       break;
       
       case 3:
       printf("%d",peektop(&top));
       break;
       
       case 4:
       display(&top);
       break;
   
   
   }



}
}
