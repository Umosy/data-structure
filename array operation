#include<stdio.h>
void traverse(int arr[],int *n)
{
   for(int i=0;i<(*n);i++)
   printf("%d ",arr[i]);
}

int insertion(int arr[],int * n)
{
   int pos;
   int data;
   printf("enter the position:");
   scanf("%d",&pos);
   printf("enter the data:");
   scanf("%d",&data);
   int i;
   for(i=(*n);i>=pos;i--)
     arr[i+1]=arr[i];
     
     arr[pos]= data;
   (*n)++;
   traverse(arr,n);
}
int deletion(int arr[],int* n)
{
   int i;
   int pos;
   printf("enter the position:");
   scanf("%d",&pos);
    
  arr[pos]=0;
   
   for(i=pos;i<=(*n);i++)
   arr[i]=arr[i+1];
   
   (*n)--;
   traverse(arr,n);
}

int search(int arr[],int* n)
{
    int a;
    printf("enter the number:");
    scanf("%d",&a);
    int i;
    int flag=0;
    for(i=0;i<(*n);i++)
    {
       if(a==arr[i])
       {
          printf("%d is the pos of the number\n",i);
          flag=1;
       
       }   
    }
    if(flag==0)
    {
    printf("the no is not present");
    }

}
int main()
{
  int arr[80]={10,20,30,40};
  int n=4;
  int a=0;
  printf("      Menu      \n\n");
  printf("for insertion press 1\n");
  printf("for deletion press 2\n");
  printf("for search press 3\n");
  printf("for traverse press 4\n");
  printf("for exit press any other key\n\n");
  while(a<5)
  {
  printf("\n\nenter the number:");
  scanf("%d",&a);
  
  switch(a)
  {
  case 1:
  insertion(arr,&n);
  break;
   case 2:
  deletion(arr,&n);
  break;
   case 3:
  search(arr,&n);
  break;
   case 4:
  traverse(arr,&n);
  break;
  default:
  break;
  
  
  
  }
  
  
  
  
  
  
  }
  
  
  return 0;


}
   








