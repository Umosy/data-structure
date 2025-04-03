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
void creation(int x,struct node**head)
{
     struct node*p;
     p=getnode();
     p->data=x;
     p->next=NULL;
     if(*head==NULL)
         *head=p;
     else
     {
         struct node*temp;
         temp=*head;
         while(temp->next!=NULL)
         {
             temp=temp->next;
         }
     temp->next=p;
     }

}
void traverse(struct node**head)
{
    struct node*temp;
    temp=*head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}
void search(struct node**head,int datas)
{
    struct node*temp;
    temp=*head;
    int found=0;
    while(temp!=NULL)
    {
        if(temp->data==datas)
        {
        found=1;
        }
    }
    if(found)
    {
        printf("element present");
    }
    else
    {
    printf("next present");
    }
} 

void insertatbeg(int ele,struct node**head)
{
    struct node*p;
    p=getnode();
    p->data=ele;
    p->next=*head;
    *head=p;
    
}
void insertatend(int ele,struct node**head)
{
    struct node*p;
    struct node*temp;
    p=getnode();
    p->data=ele;
    p->next=NULL;
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next=p;
    
}
void insertatmid(int ele,struct node**head,int loc)
{
    struct node*p;
    struct node*temp;
    p=getnode();
    p->data=ele;
    p->next=NULL;
    temp=*head;
    int i=1;
    while(i<loc)
    {
        temp=temp->next;
        i++;
    }
    p->next=temp->next;
    temp->next=p;
    
}
void deleteatbeg(struct node**head)
{
    if(head==NULL)
    {
        printf("not exist"); 
    }
    else
    {   struct node*temp;
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}
void deleteatend(struct node**head)
{
    if(*head==NULL)
    {
        printf("empty list");
    }
    else
    {   
        struct node*temp;
        struct node*p;
        temp=*head;
        while(temp->next!=NULL)
        {
            p=temp;
            temp=temp->next;
        
        }
        p->next=NULL;
        free(temp);
    
    }

}
void deleteatmid(struct node**head,int loc)
{
    if(*head==NULL)
    {
        printf("empty list");
    }
    else
    {   
        struct node*temp;
        struct node*q;
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

}
int main()
{
    struct node*head=NULL;
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
    
    
    while(x!=9)
    {
        printf("\nenter the number\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
        int elemen;
        printf("enter the element\n");
        scanf("%d",&elemen);
        creation(elemen,&head);\
        break;
        case 2:
        traverse(&head);
        break;
        case 3:
        int eleme;
        printf("enter the element\n");
        scanf("%d",&eleme);
        insertatbeg(eleme,&head);
        break;
        case 4:
        int ele;
        printf("enter the element\n");
        scanf("%d",&ele);
        int loc;
        printf("enter the loc\n");
        scanf("%d",&loc);
        insertatmid(ele,&head,loc);
        break;
        case 5:
        int elem;
        printf("enter the element\n");
        scanf("%d",&elem);
        insertatend(elem,&head);
        break;
        case 6:
        deleteatbeg(&head);
        break;
        case 7:
        int loca;
        printf("enter the loc\n");
        scanf("%d",&loca);
        deleteatmid(&head,loca);
        break;
        case 8:
        deleteatend(&head);
        break;
        
        
        
        }
            
    }



}

















