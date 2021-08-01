#include <iostream>
#include <queue>
using namespace std;

// node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;    
};

// Utility function to create new node to binary tree 

Node* newNode(int data)
{
    Node* temp = new Node;
    temp-> data =  data;
    temp-> left =  NULL;
    temp-> right=  NULL;
    return temp;
}

// LevelOrder using single Queue

void LevelOrderQ( Node* root)
{
    if(root == NULL)  return; 
    
    queue< Node * > q;              //create empty Queue
    
    q.push(root);                   //enqueue root
    
    while(q.empty() == false)
    {
        // Print front of queue and remove it from queue
        
        Node* current = q.front();
        cout<< current->data << " ";
        q.pop();
        
        //enqueue Left child
        
        if(current->left != NULL)
            q.push(current->left);
        
        //enqueue right child
        
        if(current->right != NULL)
            q.push(current->right);
    }
}

//driver function

int main() {
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    LevelOrderQ(root); 
    return 0; 
}
