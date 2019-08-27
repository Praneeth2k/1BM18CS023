#include<stdio.h>
#include<ctype.h>
#include<math.h>
double eval(char pf[40]);
void push(double stack[40],int *t,double ele);
void pop(int *t);
int main()
{

 double val;
 char pf[40];
 printf("Enter the postfix expression\n");
 scanf("%s",pf);
  
  val=eval(pf);
  printf("The value of this expression is %f",val);
  return 0;
}

double eval(char pf[40])
{ int i=0,top=-1;
  char ch;
  double stack[40],A,B,val;
  while(pf[i]!='\0')
  {
   ch=pf[i];
   if(isdigit(ch))
    {
      double a=ch-'0';
      push(stack,&top,a);
      
    }
   else
    {A=stack[top];
     pop(&top);
     B=stack[top];
     pop(&top);
     switch(ch)
	{
	   case '+':val=B+A;
		    break;
	   case '-':val=B-A;
		     break;
	   case '*':val=B*A;
		     break;
	   case '/':val=B/A;
		    break;
	   case '^':val=pow(B,A);
		    break;
	 };
	 push(stack,&top,val);
     }
	i++;
   }
   return stack[top];
}
void push(double s[40],int *t,double ele)
{ *t=*t+1;
  s[*t]=ele;
}
void pop(int *t)
{ *t=*t-1;

}

