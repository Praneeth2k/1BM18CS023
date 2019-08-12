//Using structure array
#include<stdio.h>
#include<conio.h>
void main()
{

 struct student
 {
  int id,age,marks,valid;
 };
 struct student s[10];
 int i;
 clrscr();
 for(i=0;i<10;i++)
 {
  printf("Enter the id,age and marks of the student\n");
  scanf("%d%d%d",&s[i].id,&s[i].age,&s[i].marks);
  if((s[i].age>20)&&(s[i].marks>0)&&(s[i].marks<100))
  {
   if(s[i].marks>65)
    printf("Student is eligible\n");
   else
    printf("Student is not eligible\n");
  }
  else
    printf("Data is invalid\n");
  }
  getch();
 }
