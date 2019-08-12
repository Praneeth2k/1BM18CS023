 //Marks using funtions and array of structures
 #include<stdio.h>
 #include<conio.h>
 struct student
 {
  int id,age,marks;
 };
 int validate(struct student s);
 int qualify(struct student s);
 void main()
 {
 int n,i;
 struct student s[100];
 clrscr();
 printf("Enter the number of students ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  {
   printf("Enter the id,age,marks of the student\n");
   scanf("%d%d%d",&s[i].id,&s[i].age,&s[i].marks);
   if(qualify(s[i])==1)
    printf("The student is eligible\n");
   else if(qualify(s[i])==0)
   printf("The student is not eligible go home and study\n");
   else
   printf("Data invalid\n");
  }
  getch();
 }
int qualify(struct student s)
{
 if(validate(s))
  {
   if(s.marks>65)
    return 1;
    else
    return 0;
   }
  else
  return -1;
}
int validate(struct student s)
{
 if((s.age>20)&&(s.marks>=0)&&(s.marks<=100))
  return 1;
 else
  return 0;
}