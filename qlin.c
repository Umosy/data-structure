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
void enqueue(struct node**front,struct node**rear,int datas)
{
    if(*front==NULL)
    {
        struct node*p;
        p=getnode();
        p->data=datas;
        p->next=NULL;
        *front=p;
        *rear=p;
    }
    else
    {   
        struct node*p;
        p=getnode();
        p->data=datas;
        p->next=NULL;
        (*rear)->next=p;
        (*rear)=p;
    }
}
void dequeue(struct node**front,struct node**rear)
{
    if(*front==NULL)
    {
        printf("empty");
    }
    else
    {
        if(*front==*rear)
        {
            *front=NULL;
            *rear=NULL;
        }
        else
        {
            struct node*temp;
            temp=*front;
            *front=(*front)->next;
            free(temp);
         }
        
    }

}

void display(struct node**front)
{   
    if(*front==NULL)
    {
        printf("empty");
    }
    else
    {
    struct node*temp;
    temp=(*front);
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    
    }
    }
}



int main()
{    
    int a;
    struct node*front=NULL;
    struct node*rear=NULL;

     printf("*****Menu*****\n");
    printf("press 1 to enqueue\n");
    printf("press 2 to dequeue\n");
    printf("press 3 to display\n");
    printf("press 4 to exit\n\n");\
    
    while(a!=4)
    {   
        printf("enter the number:");
        scanf("%d",&a);
        switch (a)
        {
            case 1:
            int b;
            printf("enter the number to enqueue:");
            scanf("%d",&b);
            enqueue(&front,&rear,b);
            break;
            case 2:
            dequeue(&front,&rear);
            break;
            case 3:
            display(&front);
            break;
            
        }
    
    }


}

