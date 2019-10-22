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

NODE insert_end(NODE head,int item){
	NODE newn=getnode();
        newn->data=item;
        newn->next=NULL;
        NODE p=head;
        if(p==NULL){
            head=newn;
            return head;
        }
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newn;
        return head;

}
void sort(NODE head){
    NODE p=head,q=NULL;
    if(p==NULL)
        return;
    while(p->next!=NULL){
        q=p->next;
         while(q!=NULL){
             if(p->data>q->data){
                 p->data=p->data+q->data;
                 q->data=p->data-q->data;
                 p->data=p->data-q->data;
             }
             q=q->next;
        }
        p=p->next;
    }
}

NODE reverse(NODE head){
    NODE curr=head,prev=NULL,nextn=NULL;
    if(curr==NULL){
        printf("The list is empty");
        return head;
    }
    if(head->next==NULL){
        return head;
     }
     while(curr!=NULL){
         nextn=curr->next;
         curr->next=prev;
         prev=curr;
         curr=nextn;
     }
     head=prev;
     return head;
}

NODE concatenate(NODE head1,NODE head2){
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
     NODE p=head1;
     while(p->next!=NULL){
         p=p->next;
     }
     p->next=head2;
     return head1;
}

void display(NODE head){
    NODE p=head;
    if(p==NULL){
        printf("List is empty\n");
        return;
     }
     printf("\n");
     while(p!=NULL){
         printf("%d ",p->data);
         p=p->next;
     }
     printf("\n");
}
int main(){
    NODE head1=NULL,head2=NULL;
    int item,ch;
    do{
    printf("Insert in LL1:1\nInsert in LL2:2\nReverse LL1:3\nReverse LL2:4\nSort LL1:5\nSort LL2:6\nConcatenate:7\nDisplay1:8\nDisplay2:9\nExit:10:");
    scanf("%d",&ch);
    
       switch(ch){
        case 1:printf("\nEnter the element:");
               scanf("%d",&item);
               head1=insert_end(head1,item);
               break;
        case 2:printf("\nEnter the element:");
               scanf("%d",&item);
               head2=insert_end(head2,item);
               break;
        case 3:head1=reverse(head1);
               break;
        case 4:head2=reverse(head2);
               break;
        case 5:sort(head1);
               break;
        case 6:sort(head2);
               break;
        case 7:head1=concatenate(head1,head2);
               break;
        case 8:display(head1);
               break;
        case 9:display(head2);
               break;
        case 10:exit(0);
        default:printf("\nWrong input");
     }
    }while(1);
    return 0;
}

