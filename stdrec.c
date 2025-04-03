#include <stdio.h>
#include<string.h>
struct record{
        char name[80];
        int age;
        char gen;
        int mark[3];
        char grades[2];
};


void deletion(struct record student[80],int *no);
void insert(struct record student[80],int *no);
void show(struct record student[80],int *no);
void display(struct record student[80],int *no);


void display(struct record student[],int *no) {
    for(int i=0;i<(*no);i++)
    {
     printf("%s %d %c",student[i].name,student[i].age,student[i].gen);
        for(int j=0;j<3;j++)
        {
            printf("%d ",student[i].mark[j]);
        }
    }
}

void grade(struct record student[],int *no)
{
struct record fail[80];
       struct record pass[80];
       int avg[80];
       int sum;
       int y=0;
       int x;
       int flag=0;
       
        for(int i=0;i<(*no);i++)
        {
            sum=0;
        for(int j=0;j<3;j++)
        {
          sum = sum + student[i].mark[j];
        
        }
        
        avg[i]=sum/3;

       }
    
        for(int i=0;i<(*no);i++)
        {
        
            flag=0;
        for(int j=0;j<3;j++)
        {
            if(student[i].mark[j]<50 && flag!=1)
            {
                flag=1;
            }
            }
            if(flag==1)
            {
              strcpy(student[i].grades,"F");     
            }
            
            else 
            {
             if(avg[i]>=90)
             {
             strcpy(student[i].grades,"O");
             }
             else  if(avg[i]>=80)
             {
             strcpy(student[i].grades,"A+");
             }
            else  if(avg[i]>=70)
             {
             strcpy(student[i].grades,"A");
             }
             else if(avg[i]>=60)
             {
             strcpy(student[i].grades,"B+");
             }
             else if(avg[i]>=50)
             {
             strcpy(student[i].grades,"B");
             }
            
            }
            
        }
        
        
        }
        
void dis(struct record student[],int a)
{
     printf("%s %d %c %s",student[a].name,student[a].age,student[a].gen,student[a].grades);
     

}






 
void show(struct record student[],int *no) {
    int n=0;
    grade(student,no);
    while(n!=5)
    {
        printf("Enter the number:");
        scanf("%d",&n);
        switch(n){
            case 1:
            for(int i=0;i<(*no);i++)
            {
              if((strcmp(student[i].grades,"F"))==0)
              {
               dis(student,i);
            
            }
            }
            
            break;
            case 2:
             for(int i=0;i<(*no);i++)
            {
              if((strcmp(student[i].grades,"F"))!=0)
              {
               dis(student,i);   
              }          
            }
            
            break;
            case 3:
            int b;
            printf("enter the index:");
            scanf("%d",&b);
            dis(student,b);
            break;
            
            
            
            case 4:
            display(student,no);
            break;
            
            }
        }
    }
 
 
 
    
void insert(struct record student[],int *no)

{
        int pos;
        printf("enter the pos:");
        scanf("%d",&pos);
        for(int i=pos;i<(*no);i++)
        {
            
            student[i+1]=student[i];
            
        }
        (*no)++;
        
        scanf("%s %d %c",student[pos].name,&student[pos].age,&student[pos].gen);
        for(int i=0;i<3;i++)
        {
            scanf("%d",&student[pos].mark[i]);
        }
        display(student,no);
        grade(student,no);
}
void deletion(struct record student[],int *no)
        {
        int pos;
        printf("enter the pos:");
        scanf("%d",&pos);
        for(int i=pos;i<(*no);i++)
        {
            
            student[i]=student[i+1];
            
        }
        (*no)--;
        display(student,no);
        
        }

      



int main() {
    struct record student[80];
    int n;
    int no=0;
   
    printf("menu\n");
    printf("press 1 for insertion\n");
    while(n!=4){
    printf("Enter the number:");
    scanf("%d",&n);
    switch(n){
        case 1:
        insert(student,&no);
        break;
        case 2:
        deletion(student,&no);
        break;
        case 3:
        show(student,&no);
        break;
    }
    }

    return 0;
    
}
