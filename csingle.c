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
void creation(int x,struct node**head,struct node **tail)
{
     struct node*p;
     p=getnode();
     p->data=x;
     p->next=NULL;
     if(*head==NULL)
     {
         *head=p;
         *tail=p;
          (*tail)->next=*head;
      }
     else
     {
        (*tail)->next=p;
        *tail=p;
        (*tail)->next=*head;
        (*tail)->data=x;
         
     }

}
void traverse(struct node**head,struct node**tail)
{
    struct node*temp;
    temp=*head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=*head);

}
void search(struct node**head,struct node**tail,int datas)
{
    struct node*temp;
    temp=(*head);
    int found=0;
    do
    {
        if(temp->data==datas)
        {
        found=1;
        
        }
        temp=temp->next;
    }while(temp!=*tail);
    if(found)
    {
        printf("element present");
    }
    else
    {
    printf("not present");
    }
} 

void insertatbeg(int ele,struct node**head,struct node**tail)
{
    struct node*p;
    p=getnode();
    if(*head==NULL)
    {
        *head=p;
        *tail=p;
        (*tail)->next=*head;
    }
    else
    {
        p->next=*head;
        *head=p;
    }
    (*tail)->next=*head;
    (*head)->data=ele;
      
}
void insertatend(int ele,struct node**head,struct node**tail)
{   struct node*p;
    p=getnode();
    if(*tail==NULL)
    {
        *head=p;
        *tail=p;
        (*tail)->next=*head;
    }
    else
    {
    (*tail)->next=p;
    *tail=p;
    }
    (*tail)->data=ele;
    (*tail)->next=*head;
    
}
void insertatmid(int ele,struct node**head,struct node**tail,int loc)
{
    struct node*p;
    struct node*temp;
    p=getnode();
    temp=*head;
    int i=1;
    while(i<loc)
    {
        temp=temp->next;
        i++;
    }
    p->next=temp->next;
    temp->next=p;
    p->data=ele;
    
}
void deleteatbeg(struct node**head,struct node**tail)
{
    if(head==NULL)
    {
        printf("not exist"); 
    }
    else
    {   
    if(*head==*tail)
        {
            *head=NULL;
            *tail=NULL;
        }
        else
        {
        struct node*temp;
        temp=*head;
        *head=temp->next;
        (*tail)->next=*head;
        free(temp);
        }
    }
}
void deleteatend(struct node**head,struct node**tail)
{
    if(*head==NULL)
    {
        printf("empty list");
    }
    else
    {   if(*head==*tail)
        {
            *head=NULL;
            *tail=NULL;
        }
        else
        {
        struct node*temp;
        temp=(*head);
        while(temp->next!=*tail)
        {
            temp=temp->next;
        
        }
        (*tail)=temp;
        temp=temp->next;
        (*tail)->next=*head;
        free(temp);
        }
    }

}
void deleteatmid(struct node**head,struct node**tail,int loc)
{
    struct node*q;
    struct node*temp;
    temp=*head;
    int i=0;
    while(i<loc)
    {
        q=temp;
        temp=temp->next;
        i++;
    }
    q->next=temp->next;
    free(temp);
    
}
    
    


int main()
{
    struct node*head=NULL;
    struct node*tail=NULL;
    int x;
    printf("Menu\n");
    printf("press 1 to create node\n");
    printf("press 2 to display\n");
    printf("press 3 to insert at beg\n");
    printf("press 4 to insert at mid\n");
    printf("press 5 to insert at end\n");
    printf("press 6 to delete at beg\n");
    printf("press 7 to delete at mid\n");
    printf("press 8 to delete at end\n");
    printf("press 9 to  search\n");
    printf("press 10 to quit\n");
    
    
    while(x!=10)
    {
        printf("\nenter the number\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
        int elemen;
        printf("enter the element\n");
        scanf("%d",&elemen);
        creation(elemen,&head,&tail);
        break;
        case 2:
        traverse(&head,&tail);
        break;
        case 3:
        int eleme;
        printf("enter the element\n");
        scanf("%d",&eleme);
        insertatbeg(eleme,&head,&tail);
        break;
        case 4:
        int ele;
        printf("enter the element\n");
        scanf("%d",&ele);
        int loc;
        printf("enter the loc\n");
        scanf("%d",&loc);
        insertatmid(ele,&head,&tail,loc);
        break;
        case 5:
        int elem;
        printf("enter the element\n");
        scanf("%d",&elem);
        insertatend(elem,&head,&tail);
        break;
        case 6:
        deleteatbeg(&head,&tail);
        break;
        case 7:
        int loca;
        printf("enter the loc\n");
        scanf("%d",&loca);
        deleteatmid(&head,&tail,loca);
        break;
        case 8:
        deleteatend(&head,&tail);
        break;      
        case 9:
        int el;
        printf("enter the element\n");
        scanf("%d",&el);      
        search(&head,&tail,el);
        break;
        
    }
}
}

