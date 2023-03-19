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

struct Node* newNode(int dt){
  struct Node* node=(struct Node*)malloc(sizeof(struct Node));
  node->data=dt;
  node->left=node->right=NULL;
  return node;
};

/*
maxLevel has already increased a lot, when the first left recursive call start returning
therefore only print left side
*/
void leftViewUtil(struct Node* root, int level, int* maxLevel){
  if(root==NULL){
    return;
  }
  if(*maxLevel<level){
    cout<<root->data<<" ";
    *maxLevel=level;
  }
  leftViewUtil(root->left, level+1, maxLevel);
  leftViewUtil(root->right, level+1, maxLevel);
}

void leftView(struct Node* root){
  int maxLevel=0;
  leftViewUtil(root, 1, &maxLevel);
}

int main(){
  Node *root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->right=newNode(4);
  root->left->right->right=newNode(5);
  root->left->right->right->right=newNode(6);
  root->left->right->right->right->right=newNode(7);
  leftView(root);
  return 0;
}
