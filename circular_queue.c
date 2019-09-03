//circular queue
#include<stdio.h>
#define size 3
void insert(int item,int *r,int q[],int *f)
{
	if((*f==*r+1)||(*f==0 && *r==size-1))
	{
	printf("Queue Overflow.Cannot insert\n");
		return;
	}
	if(*f==-1)
	*f=0;
	*r=(*r+1)%size;
	q[*r]=item;
}
int delete(int q[],int *f,int *r)
{
	int item;
	if(*f==-1)
	{
	printf("Queue Underflow.\n");
	return -9909;
	}
	item=q[*f];
	if(*f==*r)
	{
		*f=-1;
		*r=-1;
	}
	else
		*f=(*f+1)%size;
	return item;
	
}
void display(int q[],int f,int r)
{
	int i;
	if(f==-1)
	{
	printf("Queue is Empty.\n");
	return;
	}
	printf("Contents of Queue are:\n");
	for(i=f;i!=r;i=(i+1)%size)
	printf("%d\n",q[i]);
	printf("%d",q[i]);
}
int main()
{
    int f=-1,r=-1;
    int ele,x,del,y;
    int q[size];


    do{
        printf("Enter 1 to insert,2 to delete and 3 to display ");
        scanf("%d",&x);

        switch(x){
            case 1:printf("Enter the element you want to insert ");
                   scanf("%d",&ele);
                   insert(ele,&r,q,&f);
                   break;
            case 2:del=delete(q,&f,&r);
                   if(del!=-9909)
                   printf("The deleted element is %d\n",del);
                   break;
            case 3:display(q,f,r);
                   break;
            default:printf("Invalid input");
        };
        printf("\nDo you want to continue?(1/0) ") ;
            scanf("%d",&y);
    }while(y==1);



}
