//Stack operaetions
#include<stdio.h>
#include<conio.h>
int stack[100];
void push(int ele);
int pop();
void display();
int top=-1;
int main()
{
 int e;
 clrscr();
 push(3);
 push(1);
 push(0);
 display();
 e=pop();
 if(e!=9292)
 printf("The popped element is %d\n",e);
 display();
 getch();
 return 0;
}

void push(int ele)
 {
  if(top==99)
  {
   printf("The stack is full\n");
   return;
  }
  else
   stack[++top]=ele;
   return;
 }
int pop()
 {
   if(top==-1)
   {
   printf("The stack is empty\n");
   return -9292;
   }
   return stack[top--];
 }
void display()
{
  int i;
  if(top==-1)
  {
  printf("The stack is empty\n");
  return;
  }
  for(i=top;i>=0;i--)
  printf("%d\n",stack[i]);
  return;
}




