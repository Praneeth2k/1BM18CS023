//stack operations using functions and by not using global variables
#include<stdio.h>
void push(int ele,int s[100],int *t);
int pop(int s[100],int *t);
void display(int s[100],int t);
int main()
{
 int e;
 int stack[100],top=-1;
 
 push(12,stack,&top);
 push(23,stack,&top);
 push(111,stack,&top);
 display(stack,top);
 e=pop(stack,&top);
 if(e!=9090)
  printf("The popped element is %d\n",e);
  display(stack,top);
  return 0;
}
void push(int ele,int s[100],int *t)
 {
  if(*t==99)
  {
  printf("Stack overflow\n");
  return;
  }
  *t=*t+1;
  s[*t]=ele;

  return;
 }

int pop(int s[100],int *t)
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
void display(int stack[100],int t)
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
