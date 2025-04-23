#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define SEATS 5



struct customer
{
    char userid[23];
    char name[50];
};
struct customer * seat[SEATS]={NULL};


int isfull(struct customer* q[],int*r)
{
    if((*r)==SEATS-1)
        return 1;
    else
        return 0;
}

int isempty(struct customer* q[],int*f)
{
    if((*f)==-1)
        return 1;
    else
        return 0;

}


void enqueue(struct customer* q[],int*f,int*r,struct customer* x)
{
    if(isfull(q,r))
    {
       printf("the waiting is full\n");
    }
    else
    {
        if((*r)==-1)
        {
            (*r)=0;
            (*f)=0;
        }
        else
        {
            (*r)++;
        }
        q[(*r)]=x;
    }
    
}
struct customer* dequeue(struct customer* q[],int*f,int*r)
{   
    struct customer*value;
    if(isempty(q,f))
    {
       printf("the waiting list is empty\n");
    }
    else
    {   
       
        (value)=(q[(*f)]);
        if((*f)==(*r))
        {
            (*r)=-1;
            (*f)=-1;
        }
        else
        {
            (*f)++;
        }
    }
    
    return value;
    
}
void booking(struct customer *x,int*f,int*r,struct customer *q[])
{
        int flag=0;
        for(int i=0;i<SEATS;i++)
        {
            if(seat[i]==NULL)
            {
                seat[i]=x;
                flag=1;
                printf("SEAT BOOKED SUCCESSFULLY\n");
                break;
            }
        }
        if(flag==0)
        {
            enqueue(q,f,r,x);
            printf("YOU ARE IN WAITING LIST:%d",(*r)-(*f)+1);
        }
       
}

void cancel(struct customer *x,int*f,int*r,struct customer* q[])
{
    for(int i =0;i<SEATS;i++)
    {
        if(seat[i]!=NULL&&strcmp(x->userid,(seat)[i]->userid)==0)
        {
        
            if(!isempty(q,f))
            {
                
                (seat[i])=dequeue(q,f,r);
            }    
            else
            {
                seat[i]=NULL;
            }      

        }
       
    }
    printf("THE SEAT CANCELLED SUCCESSFULLY");
}

void view(int*f,int*r,struct customer* q[])
{   
    struct customer *y = (struct customer *)malloc(sizeof(struct customer));
    printf("ENTER YOUR USER ID:");
    scanf("%s",y->userid);
    int flag=0;
    for(int i=0;i<SEATS;i++)
    {
        if(seat[i]!=NULL && strcmp(y->userid,seat[i]->userid)==0)
        {
            flag=1;
        }

    }
    if(!isempty(q,f))
    {
        for(int i=(*f);i<=(*r);i++)
        {
            if(q[i]!=NULL && strcmp(y->userid,q[i]->userid)==0)
            {
                flag=1;
            }
        }
    }


    
    if(flag!=0)
    {
        for(int i=0;i<SEATS;i++)
        {
            if(seat[i]==NULL)
            {
                printf("SEAT %d : EMPTY\n",i+1);
            }
            else
            {
                printf("SEAT %d : %s\n",i+1,(seat[i])->name);
            }
        }      
        if(isempty(q,f))
        {
            printf("waiting list is empty\n");
        }
        else
        {
            printf("WAITING LIST:%d\n",(*r)-(*f)+1);
        }
        if(!isempty(q,f))
        {
            for(int j=(*f);j<=(*r);j++)
            {
                if((strcmp(y->userid,q[j]->userid)==0))
                {
                    printf("you are in waiting list:%d",j-(*f)+1);
                }
            }
        }
        
    }
    else
    {
        printf("the userid does not exist,try again");
    }
    free(y);
        

}
int main()
{   
    
    int no=0,f=-1,r=-1;
    struct customer * q[30]={NULL};
    label2:
    printf("NELLAI EXPRESS TRAIN TICKET BOOKING\n");
    printf("1.BOOK TICKET\n");
    printf("2.CANCEL TICKET\n");
    printf("3.VIEW BOOKINGS\n");
    printf("4.EXIT\n");

    int y;
    while(y!=4)
    {
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&y);
        switch(y)
        {
            case 1:
            label1:
            int flag=0;
            struct customer *x = (struct customer *)malloc(sizeof(struct customer));
            printf("ENTER YOUR USER ID:");
            scanf("%s",x->userid);
            
            for(int i=0;i<SEATS;i++)
            {
                if(seat[i]!=NULL && strcmp(x->userid,seat[i]->userid)==0)
                {
                    flag=1;
                }

            }
            if(!isempty(q,&f))
            {
                for(int i=(f);i<=(r);i++)
                {
                    if(q[i]!=NULL && strcmp(x->userid,q[i]->userid)==0)
                    {
                        flag=1;
                    }
                }
            }
            if(flag==1)
            {
                printf("SORRY! THE USERID ALREADY EXIST!!! TRY AGAIN\n");
                free(x);
                goto label1;

            }
            printf("ENTER YOUR NAME:");
            scanf("%s",x->name);
            int c;
            printf("1.PAY 2000rs through wallet\n2.BACK\nENTER:");
            scanf("%d",&c);
            if(c==1)
            {
                booking(x,&f,&r,q);
            }
            else
            {
                goto label2;
            }    
            break;

            case 2:
            int flag1=0;
            struct customer *a = (struct customer *)malloc(sizeof(struct customer));
            printf("ENTER YOUR USER ID:");
            scanf("%s",a->userid);
            printf("ENTER YOUR NAME:");
            scanf("%s",a->name);
            for(int i=0;i<SEATS;i++)
            {
                if(seat[i]!=NULL && strcmp(a->userid,seat[i]->userid)==0)
                {
                    flag1=1;
                }

            }
            if(!isempty(q,&f))
            {
                for(int i=(f);i<=(r);i++)
                {
                    if(q[i]!=NULL && strcmp(a->userid,q[i]->userid)==0)
                    {
                        flag1=1;
                    }
                }
            }
            if(flag1!=0)
            {
                cancel(a,&f,&r,q);
            }   
            else
            {
                printf("userid not found");
            } 
            break;

            case 3:
            view(&f,&r,q);
            break;

            case 4:
            printf("THANK YOU!!!");
            break;

            default:
            printf("INVALID CHOICE");
            break;

        }
    }
}
