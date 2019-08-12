//Using single structure
#include<stdio.h>
#include<conio.h>
void main()
{
  int valid;
 struct student
 {

  int id,age,marks;
 }s1;
 clrscr();
 printf("Enter the id,age and marks of the student\n");
 scanf("%d%d%d",&s1.id,&s1.age,&s1.marks);
 if((s1.age>20)&&(s1.marks>0)&&(s1.marks<100))
  {
  if(s1.marks>65)
    printf("The student is eligible for admission\n");
  else
   printf("The student is not eligible for admission");
  }
 else
   printf("The data entered is invalid");
 getch();
 }



