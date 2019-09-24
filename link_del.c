#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node * NODE;
NODE delete_first(NODE head);
NODE delete_value(NODE head,int value);
NODE delete_rear(NODE head);
void Display(NODE head);

int main(){
    NODE head=NULL;
    NODE p,q,r;
    p=(NODE)malloc(sizeof(struct node));
    head=p;
    q=(NODE)malloc(sizeof(struct node));
    r=(NODE)malloc(sizeof(struct node));
    p->next=q;
    q->next=r;
    r->next=NULL;
    p->data=30;    
    q->data=40;
    r->data=50;
    

    
    int x,value,y;
    do{
        printf("Do you want to Delete the first element? 1\n               Delete the specified element?2\n               Delete the last element? 3\n               Display?4\n");
        scanf("%d",&x);
        switch(x){
            case 1:head=delete_first(head);
                   break;
            case 2:printf("Enter the value \n");
                   scanf("%d",&value);
                   head=delete_value(head,value);
                   break;
            case 3:head=delete_rear(head);
                   break;
            case 4:Display(head);
                   break;
            default:printf("Invalid input\n");
       };
                    
            printf("\nDo you want to continue?(1/0)\n");
            scanf("%d",&y);

   

    }while(y==1);
    return 0;

}
NODE delete_first(NODE head){
    NODE p=head;
    if(p==NULL){
        printf("The list is empty\n");
        return head;

    }
    printf("The deleted element is %d\n",p->data);
    head=head->next;
    free(p);
    return head;

}

NODE delete_value(NODE head,int value)
{
    NODE curr,prev=NULL;
    curr=head;
    if(curr==NULL){
        printf("The list is empty\n");
        return head;
    }
    if(curr->data==value){
         head=head->next;
          free(curr);
         return head;


    }
    
    while((curr->next!=NULL) && (curr->data!=value)){
        prev=curr;
        curr=curr->next;
    }
    if(curr->data==value){
    prev->next=curr->next;
    free(curr);
    
    }
    
    else{
        printf("The value is not present in the list\n");
    }
    return head;
    

} 
NODE delete_rear(NODE head){
    NODE curr,prev;
    curr=head;
    if(curr==NULL){
        printf("The list is empty\n");
        return head;
    }
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;

    }
    printf("The deleted element is %d\n",curr->data);
    prev->next=NULL;
    free(curr);
    return head;

}
void Display(NODE head){
    NODE p;
    p=head;
    if(p==NULL){
        printf("The list is empty\n");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}



