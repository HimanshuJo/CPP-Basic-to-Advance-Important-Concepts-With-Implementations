// Check if a Binary Tree contains duplicate subtrees of size 2 or more
/*
Given a Binary Tree, check whether the Binary tree contains a duplicate sub-tree 
of size 2 or more. 
Note : Two same leaf nodes are not considered as subtree size of a leaf
       node is one.

Input :  Binary Tree 
               A
             /    \ 
           B        C
         /   \       \    
        D     E       B     
                     /  \    
                    D    E
Output : Yes
*/
/*
[ Method 1] 
A simple solution is that, we pick every node of tree and try to 
find is any sub-tree of given tree is present in tree which is 
identical with that sub-tree.

[Method 2 ]( Efficient solution ) 
An Efficient solution based on tree serialization and hashing. 
The idea is to serialize subtrees as strings and store the strings 
in hash table. Once we find a serialized tree (which is not a leaf) 
already existing in hash-table, we return true. 
*/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
const char MK='$';

struct Node{
    char key;
    struct Node *left, *right;
    //Node* left, *right;
};

struct Node* newNode(char key){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    //Node* node=new Node;
    node->key=key;
    node->left=node->right=NULL;
    return node;
}

unordered_set<string>subtrees;

string dupSubTreesUtil(Node* root){
    string s="";
    if (root==NULL){
        return s+MK;
    }
    string lStr=dupSubTreesUtil(root->left);
    if (lStr.compare(s)==0){
        return s;
    }
    string rStr=dupSubTreesUtil(root->right);
    if (rStr.compare(s)==0){
        return s;
    }
    s=s+root->key+lStr+rStr;
    if (s.length()>3&&subtrees.find(s)!=subtrees.end()){
        return "";
    }
    subtrees.insert(s);
    return s;
}

int main(){
    Node* root=newNode('A');
    root->left=newNode('B');
    root->right=newNode('C');
    root->left->left=newNode('D');
    root->left->right=newNode('E');
    root->right->right=newNode('B');
    root->right->right->right=newNode('E');
    root->right->right->left=newNode('D');
    string str=dupSubTreesUtil(root);
    (str.compare("")==0)?cout<<"Yes ":cout<<"No ";
    return 0;
}