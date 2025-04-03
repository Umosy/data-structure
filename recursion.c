#include<stdio.h>

int factorial(int a)
{
    if(a==1||a==0)
    {
        return 1;
    }
    else
    {
        return (a*factorial(a-1));
    }
}
int sumofnno(int a)
{
   if(a==1)
   {
       return 1;
   }
   else
   {
       return (a+sumofnno(a-1));
   }
}
int expo(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    else
    {
        return(a*expo(a,b-1));
    }
}

int gcd(int a,int b,int z)
{
    if(a%z==0&&b%z==0)
    {
        return z;
    }
    else
    {
        return (gcd(a,b,z-1));
    }
}

int lcm(int a,int b,int z)
{
    if(z%a==0&&z%b==0)
    {
        return z;
    }
    else
    {
        return (lcm(a,b,z+1));
    }

}
void bina(int a)
{
    
    if(a==0)
        return;
    else
    {   
       
        bina(a/2);
         printf("%d",a%2);
    }

}

int main()
{
    int x;
    printf("Menu\n");
    printf("press 1 to fact\n");
    printf("press 2 to get sum of nat num\n");
    printf("press 3 to get expo\n");
    printf("press 4 to get gcd\n");
    printf("press 5 to get lcm\n");
    printf("press 6 to get binary\n");
    
    while(x!=7)
    {
        printf("enter the number:\n");
        scanf("%d",&x);
        
        switch(x)
        {
        case 1:
        int a;
        printf("enter the number:");
        scanf("%d",&a);
        printf("%d",factorial(a));
        break;
        
        case 2:
        int b;
        printf("enter the number:");
        scanf("%d",&b);
        printf("%d",sumofnno(b));
        break;
        
        case 3:
        int c;
        printf("enter the number 1:\n");
        scanf("%d",&c);
        int d;
        printf("enter the number2:");
        scanf("%d",&d);
        printf("%d",expo(c,d));
        break;
        case 4:
        int e;
        printf("enter the number 1:\n");
        scanf("%d",&e);
        int f;
        printf("enter the number2:");
        scanf("%d",&f);
        int g;
        g=(e<f)?e:f;
        printf("%d",gcd(e,f,g));
        break;
        case 5:
        int h;
        printf("enter the number 1:\n");
        scanf("%d",&h);
        int i;
        printf("enter the number2:");
        scanf("%d",&i);
        int j;
        j=(h<i)?i:h;
        printf("%d",lcm(h,i,j));
        break;
        case 6:
        int k;
        printf("enter the number:\n");
        scanf("%d",&k);
        bina(k);
        break;
              
        }
        
    
    }
}








