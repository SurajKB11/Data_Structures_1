#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
int findmax(struct node *root){
    if(root==NULL)
    return -1;
    if(root->right==NULL)
    return root->data;
    return findmax(root->right);
}
struct node* newnode(int data){
    struct node *nn;
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}
struct node* insert(struct node *root, int data){
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
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,17);
    root=insert(root,25);
    int max;
    max=findmax(root);
    printf("MAX ELEMENT IN THE TREE : %d",max);
    return 0;
}
