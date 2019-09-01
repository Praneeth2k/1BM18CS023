#include <stdio.h>

#define SIZE 20
void insert(int q[],int *r,int ele)
{
    if(*r==SIZE-1)
        printf("Queue overflow\n");
    else
    {
        *r=*r+1;
        q[*r]=ele;
    }
    return;
}
int delete(int q[],int *f,int *r)
{   
    int item;
    if(*f>*r)
    {
        printf("Queue underflow\n");
        return -9909;
    }
    item=q[*f];
    *f+=1;
    return item;
}
void display(int q[],int f,int r)
{   int i;
    if(f>r)
    {
        printf("The queue is empty");
        return;
    }
    printf("The contents of the queue are\n");
    for(i=f;i<=r;i++)
        printf("%d ",q[i]);
}


int main()
{
    int f=0,r=-1;
    int ele,x,del,y;
    int q[SIZE];


    do{
        printf("Enter 1 to insert,2 to delete and 3 to display ");
        scanf("%d",&x);

        switch(x){
            case 1:printf("Enter the element you want to insert ");
                   scanf("%d",&ele);
                   insert(q,&r,ele);
                   break;
            case 2:del=delete(q,&f,&r);
                   if(del!=-9909)
                   printf("The deleted element is %d\n",del);
                   break;
            case 3:display(q,f,r);
                   break;
            default:printf("Invalid input");
        }
        printf("Do you want to continue?(1/0)") ;
            scanf("%d",&y);
    }while(y==1);



}
