#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
struct node *pre;

};
struct node* head=NULL;
struct node* tail=NULL;

struct node* getnode (){
  struct node *ptr;
  ptr=(struct node*)malloc(sizeof(struct node));
  return ptr;
}

void creation(int x,struct node **head,struct node **tail){
     struct node *p;
    p=getnode();
    p->data=x;
    p->next=NULL;
     p->pre = NULL;
    if (*head==NULL){
                *head=p;
                *tail=p;
                p->next=p;
                 p->pre = p;
    }
    else{
      /*  struct node *temp=*head;
        while(temp->next!=NULL)
             temp=temp->next;*/
        (*tail)->next=p;
        p->next=*head;
         p->pre = *tail;
         (*head)->pre = p;
        (*tail)=p;
        
        
       
       
       
       
     }
}
void traverse(struct node * head){
    if(head==NULL)
         printf("list is empty");
         return;
    else{
         struct node *temp=head;
         
        while(temp->next!=head){
          printf("[%d] ",temp->data);
          temp=temp->next;
       }
       printf("[%d]",temp->data);
       printf("\n");
    }
}
void search (struct node * head){
    struct node *temp=head;
    int data;
 
    if(head==NULL){
        printf("list is empty");
        return;
    }
   printf("enter the element to search:");
   scanf("%d",&data);
 
   do{
       if ( temp->data==data){
              printf("found");
              return;
       }
       temp=temp->next;
       
    }while(temp!=head);
 
    if (temp==head)
       printf("not found");

}
void insert_beg(int ele,struct node ** head,struct node **tail){
  struct node* p=getnode();
   p->data=ele;
   p->next=NULL;
   
      if (*head==NULL){
                *head=p;
                *tail=p;
                p->pre=*head;
                p->next=*head;
    }
    
    else{
       p->next=*head;
       (*head)->pre=p;
       (*tail)->next=p;
       p->pre=(*tail);
       *head=p;
    }
    
}
void insert_end(int ele,struct node **head,struct node **tail){
    struct node*p=getnode();
    p->data=ele;
    p->next=NULL;
    
    if (*head==NULL){
                *head=p;
                p->pre=*head;
                p->next=*head;
                
                *tail=p;
              
    }
    
    else{
        p->next=*head;
        p->pre=*tail;
        
        (*tail)->next=p;
        (*head)->pre=p;
        *tail=p;
    }
   
}
void insert_mid(int ele,int pos,struct node **head,struct node **tail){
        struct node *p=getnode();
        p->data=ele;
        int i=1;
        p->next=NULL;
        
        if (*head==NULL){
                *head=p;
                *tail=p;
                p->next=p;
                return ;
        }
        
        if (pos<=1){//
            p->next=*head;//
            *head=p;//
            (*tail)->next=*head;
            return;//
        }//
        
        struct node * temp=*head;
        
        while(i<pos-1 && temp->next!=*head){
           temp=temp->next;
           i++;
        }
        
        p->next=temp->next;
        temp->next=p;
        
        if(temp==*tail)
              *tail=p;
        
}
void delete_beg(struct node **head,struct node **tail){
    if(*head==NULL)
        printf("list is empty");
    
     
    else{
         struct node * temp=*head;
         (*head)->next->pre=(*tail);
         (*tail)->next=(*head)->next;
        (* head)=(*head)->next;
         free(temp);
    }
}
void delete_end(struct node ** head,struct node **tail){
    if(*head==NULL)
    printf("list is empty");
    
   
    
    else{
      struct node * temp=*tail;
     (*head)->pre=(*tail)->pre;
     (*tail)->pre->next=(*head);
     (*tail)=(*tail)->pre;
     free(temp);
     
}
}
void delete_mid(struct node **head,struct node **tail){
    if(*head==NULL)
          printf("list is empty");
      else if (*head==*tail){
          free(*head);
          *head=*tail=NULL;
      }
    else{
          int pos;
          printf("\nEnter the pos:");
                  scanf("%d",&pos);
          struct node * temp=*head;
          struct node *prev;
          int i=1;
               if (pos<=1){//
                  *head=temp->next;//
                  (*tail)->next=*head;
                   free(temp);//
                   return;//
               }//
            
          while(i<pos && temp->next!=*head){
            prev=temp;
            temp=temp->next;
            i++;
         }
         
         prev->next=temp->next;
         
         if(temp==*tail)
           *tail=prev;
           
        free(temp);
    }
    
}

int main(){
    int n,data,ele,pos,i=1,op;
    printf("\nenter the no. of nodes to create: ");
    scanf("%d",&n);
    while(i<=n){
       printf("\nEnter the data:");
       scanf("%d",&data);
       creation(data,&head,&tail);i++;
    }
    printf("1-insertBeg 2-insertMid 3-insertEnd \n4-deleteBeg 5-deleteMid 6-deleteEnd \n7-traverse  8-search \n9-exit");
    do{
         printf("\nEnter the operation to perform:");
         scanf("%d",&op);
         switch(op){
             case 1:
                  printf("\nEnter the data:");
                  scanf("%d",&ele);
                  insert_beg(ele,&head,&tail);
                  break;
               case 2:
                  printf("\nEnter the data and pos:");
                  scanf("%d%d",&ele,&pos);
                  insert_mid(ele,pos,&head,&tail);
                  break;
               case 3:
                  printf("\nEnter the data:");
                  scanf("%d",&ele);
                  insert_end(ele,&head,&tail);
                  break;
              case 4:
                  delete_beg(&head,&tail);
                  break;
              case 5:
                  delete_mid(&head,&tail);
                  break;
              case 6:
                  delete_end(&head,&tail);
                  break;
              case 7:
                   traverse(head);
                   break;
              case 8:
             
              search(head);
              break;
              case 9:
                   break;
              default:
                  printf("press valid option");
              
         }
    }while(op!=9);

}
