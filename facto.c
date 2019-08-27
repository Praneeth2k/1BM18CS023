#include<stdio.h>

int fact(int n);
int main()
{
 int n,f;
 printf("Enter a number\n");
 scanf("%d",&n);

 f=fact(n);
 printf("The factorial of the number is %d\n",f);
 return 0;
}
int fact(int n)
{
  if(n==0)
    return 1;
  
  return (n*fact(n-1));
} 
