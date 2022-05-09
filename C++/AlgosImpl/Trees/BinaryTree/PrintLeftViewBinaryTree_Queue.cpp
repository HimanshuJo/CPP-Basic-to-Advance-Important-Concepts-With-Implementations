// Print Left View of a Binary Tree
/*
Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible when tree is 
visited from left side.

Examples: 

Input : 
                 1
               /   \
              2     3
             / \     \
            4   5     6             
Output : 1 2 4

Input :
        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Output :1 2 4 5 6
*/
/*
Method-1 (Using Recursion)
The left view contains all nodes that are first nodes in their levels. 
A simple solution is to do level order traversal and print the first node in every level.

The problem can also be solved using simple recursive traversal. We can keep 
track of the level of a node by passing a parameter to all recursive calls. 
The idea is to keep track of the maximum level also. Whenever we see a node 
whose level is more than maximum level so far, we print the node because 
this is the first node in its level (Note that we traverse the left subtree before 
right subtree). 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left, *right;
};

Node* newNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

void BTreeLeftSideView(Node* root){
    if (!root){
        return;
    }
    queue<struct Node*>q;
    q.push(root);
    while (!q.empty()){
        int sz=q.size();
        int counter=1;
        while (sz--){
            Node* tmp=q.front();
            q.pop();
            if (counter==1){
                cout<<tmp->data<<" ";
            }
            if (tmp->left!=NULL){
                q.push(tmp->left);
            }
            if (tmp->right!=NULL){
                q.push(tmp->right);
            }
            counter++;
        }
    }
}

int main(){
  Node *root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->right=newNode(4);
  root->left->right->right=newNode(5);
  root->left->right->right->right=newNode(6);
  root->left->right->right->right->right=newNode(7);
  BTreeLeftSideView(root);
  return 0;
}