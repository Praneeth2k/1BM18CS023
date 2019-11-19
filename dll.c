#include<stdio.h>
#include<stdlib.h>
struct node{
int d;
struct node* next;
struct node* prev;
};
typedef struct node* node;
node getnode()
{
    node p=(node)malloc(sizeof(struct node));
    return p;
}
node insertfront(node head,int e)
{
    node p=getnode();
    p->d=e;
    p->next=NULL;
    p->prev=NULL;
    if(head==NULL)
        return p;
    else
    {
        p->next=head;
        head->prev=p;
        p->prev=NULL;
        head=p;
        return head;
    }
}
node insertend(node head,int e)
{
    node p=getnode();
    p->d=e;
    p->prev=NULL;
    p->next=NULL;
    if(head==NULL)
        return p;
    else{
        node q=head;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
        p->prev=q;
        return head;
    }
}
node insertleft(node head,int item,node n)
{
    node newn=getnode();
    newn->d=item;

    if(n->prev==NULL)
    {
        n->prev=newn;
        newn->next=n;
        newn->prev=NULL;
        head=newn;
    }
    else
    {
      newn->next=n;
      newn->prev=n->prev;
      n->prev->next=newn;
      n->prev=newn;
    }
   return head;
     
}
void display(node head)
{
    if(head==NULL)
        printf("Empty LIst\n");
    else{
        node p=head;
        while(p!=NULL)
        {
            printf("%d ",p->d);
            p=p->next;
        }
    }
}

node delval(node head,int v)
{
    int f=0;
    if(head==NULL)
    {
        printf("Empty list\n");
        return NULL;
    }
   else if(head->d==v&&head->next==NULL)
    {
        printf("Deleted element is %d\n",head->d);
        free(head);
        return NULL;
    }
    else if(head->d==v)
    {
        node p=head;
        printf("Deleted element is %d\n",head->d);
        head=head->next;
        free(p);
        return head;
    }
    else{
        node p=head;
        while(p->next!=NULL)
        {
            if(p->d==v)
            {
                f=1;
                break;
            }
            p=p->next;
        }
        if(f==1){
        printf("Deleted element is %d\n",p->d);
        p->next->prev=p->prev;
        p->prev->next=p->next;
        }
        else if(p->d==v)
        {
            printf("Deleted element is %d\n",p->d);
            p->prev->next=NULL;
            free(p);
            return head;
        }
        else
            printf("Value not found\n");
    }
}

void main()
{
    node h=NULL;
    int ch,ch1,e,f=0;
    do
    {
        printf("\nEnter 1 to insert front\nEnter 2 to insert end\nEnter 3 to insert to the left of a node\nEnter 4 to delete a value\nEnter 5 to display list\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter element\n");
            scanf("%d",&e);
            h=insertfront(h,e);
        }
        else if(ch==2)
        {
            printf("Enter element\n");
            scanf("%d",&e);
            h=insertend(h,e);
        }
        else if(ch==3)
        {    
             int c=0; 
             node p=h;
             printf("Enter element\n");
             scanf("%d",&e);
             while(p!=NULL){
                 c++;
                 if(c==2){
                      h=insertleft(h,e,p);
                      break;
                 }
                 p=p->next;
            }           
        }

        
        else if(ch==4)
        {
            printf("Enter a value\n");
            scanf("%d",&e);
            h=delval(h,e);
        }
        
        else
            display(h);
        printf("Enter 1 to continue and 2 to exit\n");
        scanf("%d",&ch1);
    }while(ch1!=2);
}
 


