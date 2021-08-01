#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node* findmin(struct node *root){
    while(root->left!=NULL)
    root=root->left;
    return root;
}
struct node* deletenode(struct node *root,int data){
    if(root==NULL)
    return root;
    else if(data<root->data)
    root->left=deletenode(root->left,data);
    else if(data>root->data)
    root->right=deletenode(root->right,data);
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        else if(root->left==NULL){
            struct node *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL){
            struct node *temp=root;
            root=root->left;
            free(temp);
        }
        else{
            struct node *temp=findmin(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
    }
    return root;
}
struct node* newnode(int data){
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}
int search(struct node *root,int data){
    if(root==NULL)
    return 0;
    else if(data<root->data)
    return search(root->left,data);
    else if(data>root->data)
    return search(root->right,data);
    else
    return 1;
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

int main(){
    struct node *root;
    root=insert(root,12);
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,1);
    root=insert(root,9);
    root=insert(root,15);
    root=insert(root,13);
    root=insert(root,17);
    int n;
    n=search(root,15);
    if(n==1)
    printf("15 not deleted\n");
    else
    printf("15 not found\n");
    root=deletenode(root,15);
    n=search(root,15);
    if(n==1)
    printf("15 not deleted");
    else
    printf("15 deleted");
    return 0;
}
