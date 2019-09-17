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
NODE insert_first(int item,NODE head){
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
	
void insert_end(int item,NODE head){
	NODE p,q;
        q=getnode();
	q->data=item;
	p=head;
	if(p==NULL)
	{
	   q->next=NULL;
           return;
	}
	while(p->next!=NULL){
	    p=p->next;
	}
	p->next=q;
	q->next=NULL;
        
}

NODE insert_pos(int item,NODE head,int pos){
	NODE curr,prev=NULL,newn;
	int count=1;
	newn=getnode();
	newn->data=item;

	if(head==NULL){
	    if(pos==1){
	       newn->next=NULL;
	       return newn;
	    }
            
            else{
               printf("Invalid position\n");
               return head;
            }
         }

        if(pos==1){
	    newn->next=head;
            head=newn;
            return head;
        }
               
	curr=head;
	while(curr!=NULL&&count!=pos){
	    prev=curr;
            curr=curr->next;
            count++;
        }
        if(count==pos){
            prev->next=newn;
            newn->next=curr;
            return head;
        }
        else
           printf("Invalid position\n");
             return head;
}

void display(NODE head){
	NODE p=head;
        if(p==NULL){
            printf("The list is empty\n");
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
     printf("Press 1:insert_front  2:insert_end  3:insert at psition  4:display\n");
     scanf("%d",&x);
     
     switch(x){
       
        case 1:printf("Enter the item\n");
               scanf("%d",&item); 
               head=insert_first(item,head);
               break;
        case 2:printf("Enter the item\n");
               scanf("%d",&item);
               insert_end(item,head);
               break;
        case 3:printf("Enter the item and postition\n");
               scanf("%d%d",&item,&pos);
               head=insert_pos(item,head,pos);
               break;
        case 4:printf("The list elements are\n");
               display(head);
               break;
        default:printf("Invalid input\n");
        
      };
     printf("Do you want to continue?(0/1)\n");
      scanf("%d",&y);
    }while(y!=0);
     return 0;
  }               



