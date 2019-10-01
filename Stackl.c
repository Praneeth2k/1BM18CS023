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
NODE push(int item,NODE head){
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}

NODE pop(NODE head){
    NODE p=head;
    if(p==NULL){
        printf("Stack underflow\n");
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
            printf("Stack is empty\n");
            return;
        }
        printf("The stack elements are\n");
        while(p!=NULL){
            printf("%d\n",p->data);
        p=p->next;

        }
  printf("\n");
}

int main()
{
  NODE head=NULL;
  int x,item,pos,y;
  do{
     printf("Press 1:push  2:pop  3:display 4:exit\n");
     scanf("%d",&x);
     
     switch(x){
       
        case 1:printf("Enter the item\n");
               scanf("%d",&item); 
               head=push(item,head);
               break;
        case 2:head=pop(head);
               break;
        case 3:display(head);
               break;
        case 4:exit(0);

        default:printf("Invalid input\n");
        
      };
     
    }while(1);
     return 0;
  }

/* OUTPUT
Press 1:push  2:pop  3:display 4:exit
1
Enter the item
10
Press 1:push  2:pop  3:display 4:exit
1
Enter the item
20
Press 1:push  2:pop  3:display 4:exit
1
Enter the item
30
Press 1:push  2:pop  3:display 4:exit
3
The stack elements are
30
20
10

Press 1:push  2:pop  3:display 4:exit
2
The deleted element is 30
Press 1:push  2:pop  3:display 4:exit
2
The deleted element is 20
Press 1:push  2:pop  3:display 4:exit
2
The deleted element is 10
Press 1:push  2:pop  3:display 4:exit
2
Stack underflow
Press 1:push  2:pop  3:display 4:exit
3
Stack is empty
Press 1:push  2:pop  3:display 4:exit
*/
