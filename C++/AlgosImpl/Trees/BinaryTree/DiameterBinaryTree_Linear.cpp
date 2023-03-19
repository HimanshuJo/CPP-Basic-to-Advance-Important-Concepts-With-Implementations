// Diameter of a Binary Tree
/*
The diameter of a tree (sometimes called the width) is 
the number of nodes on the longest path between two end nodes. 
The diagram below shows two trees each with diameter nine, 
the leaves that form the ends of the longest path are shaded 
(note that there is more than one path in each tree of length nine,
but no path longer than nine nodes).

                    A
                   /  \
                  B    C
                / \      \
               D   E      F
                  / \      \
                 G   'H'    I
                           / \
                          J   K
                           \
                            'L'

Diameter 9 nodes through root

*/
/*
The diameter of a tree T is the largest of the following quantities:

the diameter of T’s left subtree.
the diameter of T’s right subtree.
the longest path between leaves that goes through the root of T 
(this can be computed from the heights of the subtrees of T)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
};

int diameter(struct Node* root, int *height){
    int lH=0, rH=0;
    int lDiameter=0, rDiameter=0;
    if(root==NULL){
        *height=0;
        return 0;
    }
    lDiameter=diameter(root->left, &lH);
    rDiameter=diameter(root->right, &rH);
    *height=max(lH, rH)+1;
    return max(lH+rH+1, max(lDiameter, rDiameter));
}

int main(){
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    struct Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    cout<<diameter(root, 0);
    return 0;
}
