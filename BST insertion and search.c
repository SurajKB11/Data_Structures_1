#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node* newnode(int data){
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}
struct node* insert(struct node *root,int data){
    if(root==NULL){
        root=newnode(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
int search(struct node *root, int data){
    if(root==NULL)return 0;
    else if(root->data==data)return 1;
    else if(data<=root->data)return search(root->left,data);
    else return search(root->right,data);
}
int main() {
    struct node *root;
    root=NULL;
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);
    int number;
    printf("enter a number to be searched : ");
    scanf("%d",&number);
    if(search(root,number)==1)
    printf("\nfound");
    else
    printf("\nnot found");
    return 0;
}
