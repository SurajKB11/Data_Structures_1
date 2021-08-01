#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
int findheight(struct node *root){
    if(root==NULL)
    return -1;//if root is null height of tree is 0 but in result we are incrementing l and r so it needs to be -1
    int l=findheight(root->left);
    int r=findheight(root->right);
    if(l>r)
    return l+1;
    else
    return r+1;
    
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
    root=NULL;
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,17);
    root=insert(root,25);
    root=insert(root,11);
    printf("%d",findheight(root));
    return 0;
}
