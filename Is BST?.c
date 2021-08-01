#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
int issubtreelesser(struct node *root,int value){
    if(root==NULL)
    return 1;
    if(root->data<=value&&issubtreelesser(root->left,value)&&issubtreelesser(root->right,value))
    return 1;
    else
    return 0;
}
int issubtreegreater(struct node *root,int value){
    if(root==NULL)
    return 1;
    if(root->data>value&&issubtreegreater(root->left,value)&&issubtreegreater(root->right,value))
    return 1;
    else
    return 0;

}
int isbinarysearchtree(struct node *root){
    if(root==NULL)
    return 1;
    if(issubtreelesser(root->left,root->data)&&issubtreegreater(root->right,root->data)&&isbinarysearchtree(root->left)&&isbinarysearchtree(root->right))
    return 1;
    else
    return 0;
}
struct node* newnode(int data){
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}
struct node* insert(struct node *root,int data){
    if(root==NULL)
    root=newnode(data);
    else if(data<=root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);
    return root;
}
int main(){
    struct node *root;
    root=NULL;
    root=insert(root,18);
    root=insert(root,12);
    root=insert(root,5);
    root=insert(root,17);
    root=insert(root,16);
    root=insert(root,20);
    root=insert(root,19);
    root=insert(root,25);
    struct node *root1;
    root1=newnode(12);
    root1->left=newnode(9);
    root1->right=newnode(17);
    root1->left->left=newnode(10);
    root1->left->right=newnode(11);
    root1->right->left=newnode(16);
    root1->right->right=newnode(19);
    int n;
    n=isbinarysearchtree(root);
    if(n==1)
    printf("BST");
    else
    printf("NOT BST");
    n=isbinarysearchtree(root1);
    if(n==1)
    printf("\nBST");
    else
    printf("\nNOT BST");
    return 0;
}
//another solution : inorder traversal should be sorted...
