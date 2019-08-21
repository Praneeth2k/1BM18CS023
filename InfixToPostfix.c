#include<stdio.h>
#include<ctype.h>
void push(char stack[30],int *t,char ele);
void pop(char s[30],int *t);
int precedence(char o);
void postfix(char infix[30]);
int main()
{
  int t=-1,i=-1;
  char s[30];
  printf("Enter the string\n");
  scanf("%[^\n]%*c",s);
  postfix(s);
  return 0;
}
void postfix(char infix[30])
{
 int i=0,tops=-1;
 char stack[30];
 while(infix[i]!='\n')
  {
   if(isalpha(infix[i]))
     printf("%c",infix[i]);
     
   else if((infix[i]=='+')||(infix[i]=='-')||(infix[i]=='*')||(infix[i]=='/')||(infix[i]=='^'))
    {
     if((precedence(infix[i])>precedence(stack[tops]))||(stack[tops]=='(')||(tops==-1))
	push(stack,&tops,infix[i]);
     else
       {
       while(precedence(stack[tops])>=precedence(infix[i]))
	    {printf("%c",stack[tops]);
	     pop(stack,&tops);}
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
       
       pop(stack,&tops);
      }
      pop(stack,&tops);
      }
  
      i++;
  }
    for(i=tops;i>=0;i--)
	  printf("%c",stack[i]);
	  printf(" is the corresponding postfix expression");
    
}
   

void push(char stack[30],int *t,char ele)
{  
    *t=*t+1; 
   stack[*t]=ele;
   return;
}
void pop(char s[30],int *t)
{
   *t=*t-1;
   return;
}
int precedence(char c)
{
 if(c=='^')
   {return 3;}
 else if((c=='*')||(c=='/'))
   {return 2;}
 else if((c=='+')||(c=='-'))
   {return 1;}
 else
   {return 0;}
}

