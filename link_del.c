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

int main(){
    NODE head=NULL;
    int x,value,y;
    do{
        printf("Do you want to delete the first element? 1\n Delete the specified element?2\n Delete the last element? 3");
        scanf("%d",&x);
        switch(x){
            case 1:head=delete_first(head);
            case 2:printf("Enter the value \n");
                   scanf("%d",&value);
                   head=delete_value(head,value);
            case 3:head=delete_rear(head);
            default:printf("Invalid input\n");
            printf("Do you wnat to continue?(1/0)");
            scanf("%d",&y);

        };

    }while(y=1);
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
    NODE curr,prev;
    curr=head;
    if(curr==NULL){
        printf("The list is empty");
        return head;
    }
    
    while(curr!=NULL && curr->data!=value){
        prev=curr;
        curr=curr->next;
    }
    if(curr->data=value){
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
    printf("The deleted element is %d",curr->data);
    prev->next=NULL;
    free(curr);
    return head;

}



