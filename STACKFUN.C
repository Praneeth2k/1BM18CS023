//stack operations using functions, by not using global variables and using switch statements
#include<stdio.h>
void push(int ele,int s[4],int *t);
int pop(int s[4],int *t);
void display(int s[4],int t);
int main()
{
 int e,x,element;
 int stack[4],top=-1;
do
{
 printf("Press 1 for pushing,2 for popping and 3 for displaying and 4 to exit\n");
 scanf("%d",&x);
 switch (x)
 {
  case 1:printf("Enter the element that you want to push\n");
         scanf("%d",&element);
         push(element,stack,&top);
         break;

  case 2:e=pop(stack,&top);
           if(e!=9090)
             printf("The popped element is %d\n",e);
             break;
  case 3:display(stack,top);
         break;
  };
 }while(x!=4);
  return 0;
}
void push(int ele,int s[4],int *t)
 {
  if(*t==3)
  {
  printf("Stack overflow\n");
  return;
  }
  *t=*t+1;
  s[*t]=ele;

  return;
 }

int pop(int s[4],int *t)
 {
  int ele;
  if(*t==-1)
  {
   printf("Stack underflow\n");
   return -9090;
  }
  ele=s[*t];
  *t=*t-1;
   return ele;
  }
void display(int stack[4],int t)
 {
  int i;
  if(t==-1)
  {
   printf("The stack is empty\n");
   return;
  }
   printf("The stack elements are\n");
   for(i=t;i>=0;i--)
    printf("%d\n",stack[i]);
    return;
  }
