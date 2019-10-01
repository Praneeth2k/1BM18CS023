#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node* NODE;

NODE getnode(){
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
	    return p;
	else 
            printf("Memory could not be allocated");
}
NODE insert(int item,NODE head){
	NODE p,q;
        q=getnode();
	q->data=item;
	p=head;
	if(p==NULL)
	{
	   q->next=NULL;
           head=q;
           return head;
	}
	while(p->next!=NULL){
	    p=p->next;
	}
	p->next=q;
	q->next=NULL;
        return head;
}

NODE delete(NODE head){
    NODE p=head;
    if(p==NULL){
        printf("Queue underflow\n");
        return head;

    }
    printf("The deleted element is %d\n",p->data);
    head=head->next;
    free(p);
    return head;

}
void display(NODE head){
	NODE p=head;
        if(p==NULL){
            printf("Queue is empty\n");
            return;
        }
        while(p!=NULL){
            printf("%d ",p->data);
        p=p->next;

        }
  printf("\n");
}

int main()
{
  NODE head=NULL;
  int x,item,pos,y;
  do{
     printf("Press 1:Insert  2:delete  3:display 4:exit\n");
     scanf("%d",&x);
     
     switch(x){
       
        case 1:printf("Enter the item\n");
               scanf("%d",&item); 
               head=insert(item,head);
               break;
        case 2:head=delete(head);
               break;
        case 3:display(head);
               break;
        case 4:exit(0);

        default:printf("Invalid input\n");
        
      };

    }while(1);
     return 0;
  }

/*OUTPUT
Press 1:Insert  2:delete  3:display 4:exit
1
Enter the item
10
Press 1:Insert  2:delete  3:display 4:exit
1
Enter the item
20
Press 1:Insert  2:delete  3:display 4:exit
1
Enter the item
30
Press 1:Insert  2:delete  3:display 4:exit
3
10 20 30 
Press 1:Insert  2:delete  3:display 4:exit
2
The deleted element is 10
Press 1:Insert  2:delete  3:display 4:exit
3
20 30 
Press 1:Insert  2:delete  3:display 4:exit
2
The deleted element is 20
Press 1:Insert  2:delete  3:display 4:exit
2
The deleted element is 30
Press 1:Insert  2:delete  3:display 4:exit
2
Queue underflow
Press 1:Insert  2:delete  3:display 4:exit
3
Queue is empty
Press 1:Insert  2:delete  3:display 4:exit
*/
