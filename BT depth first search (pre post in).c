#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node* newnode(int data){
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}
void preordertraversal(struct node *root){
    if(root==NULL)
    return;
    printf("%d ",root->data);
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(struct node *root){
    if(root==NULL)
    return;
    postordertraversal(root->left);
    postordertraversal(root->right);
    printf("%d ",root->data);
}
void inordertraversal(struct node *root){
    if(root==NULL)
    return;
    inordertraversal(root->left);
    printf("%d ",root->data);
    inordertraversal(root->right);
}
int main() {
    struct node *root;
    root=newnode(20);
    root->left=newnode(45);
    root->right=newnode(90);
    root->left->left=newnode(34);
    root->left->right=newnode(9);
    root->right->left=newnode(4);
    root->right->right=newnode(65);
    root->left->left->right=newnode(80);
    printf("DEPTH FIRST SEARCH :\n\n");
    printf("PRE ORDER TRAVERSAL :\n");
    preordertraversal(root);
    printf("\nPOST ORDER TRAVERSAL :\n");
    postordertraversal(root);
    printf("\nINORDER TRAVERSAL :\n");
    inordertraversal(root);
    return 0;
}
