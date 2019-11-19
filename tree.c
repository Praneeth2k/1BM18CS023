//tree traversals
#include<stdio.h>
#include<stdlib.h>
struct node
{

    int data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *NODE;

NODE getnode(int item)
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    p->data=item;
    p->lchild=NULL;
    p->rchild=NULL;
    return p;
}

NODE insert(NODE root,int item)
{
  if(root==NULL)
      return getnode(item);
  if(item<root->data)
      root->lchild=insert(root->lchild,item);
  else if(item>root->data)
      root->rchild=insert(root->rchild,item);
  return root;
}



void inorder(NODE root)
{
   if(root==NULL)
       return;
   inorder(root->lchild);
   printf("%d ",root->data);
   inorder(root->rchild);
}
void postorder(NODE root)
{
   if(root==NULL)
       return;
   postorder(root->lchild);
   postorder(root->rchild);
   printf("%d ",root->data);
}
void preorder(NODE root)
{
   
   if(root==NULL)
       return;
   printf("%d ",root->data);
   preorder(root->lchild);
   preorder(root->rchild);
}

int main(){
    int ch,ele;
    NODE root=NULL;
    do{
        printf("\nInsert into binary search tree:1\nInorder traversal:2\nPreorder traversal:3\nPostorder travelsal:4\nExit:5\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element you want to insert\n");
                   scanf("%d",&ele);
                   root=insert(root,ele);
                   break;
            case 2:inorder(root);
                    break;
            case 3:preorder(root);
                   break;
            case 4:postorder(root);
                   break;
            case 5:exit(0);
            default:printf("Wrong input\n");
       }  
    }while(1);
    return 0;
}
