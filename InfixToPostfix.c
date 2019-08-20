#include<stdio.h>
#include<ctype.h>
#include<string.h>
void push(char stack[30],int *t,char ele);
void pop(char s[30],int *t);
int precedence(char o);
void postfix(char infix[30],char pf[30],int *t1);
int main()
{
  int t=-1,t1=-1;
  char s[30]={'(','A','+','(','B','-','c',')','*','D',')'};
  char pstfix[30];
  
  postfix(s,pstfix,&t1);
  return 0;
}
void postfix(char infix[30],char pf[30],int *t1)
{
 int i,tops=-1;
 char stack[30];
 for(i=0;i<11;i++)
  {
   if(isalpha(infix[i]))
     {printf("%c",infix[i]);
     push(pf,t1,infix[i]);}
   else if((infix[i]=='+')||(infix[i]=='-')||(infix[i]=='*')||(infix[i]=='/'))
    {
     if((precedence(infix[i])>precedence(stack[tops]))||(stack[tops]=='(')||(tops==-1))
	push(stack,&tops,infix[i]);
     else
       {
       while(precedence(stack[tops])>=precedence(infix[i]))
	 pop(stack,&tops);
	 push(stack,&tops,infix[i]);
       }
    }
   if(infix[i]=='(')
     stack[++tops]='(';
   if(infix[i]==')')
     {
      while (stack[tops]!='(')
      {
       printf("%c",stack[tops]);
       pop(stack,*tops);
      }
      pop(stack,*tops);
      }
   }
    for(i=tops;i>=0;i--)
	  printf("%c",stack[i]);
   getch();
   }

void push(char stack[30],int *t,int ele)
{
   stack[++*t]=e;
   return;
}
void pop(int s[30],*t)
{
   *t=*t-1;
   return;
}
int precedence(char c)
{
 if((c=='^')
   return 3;
 else if((c=='*')||(c=='/'))
   return 2;
 else if((c=='+')||(c=='-'))
   return 1;
 else
   return 0;
}

