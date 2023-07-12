/*
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of
    left and right sub-trees cannot be more than one for all nodes.

-------

Why AVL Trees?

    Most of the BST operations (e.g., search, max, min, insert, delete.. etc)
        take O(h) time where h is the height of the BST

    The cost of these operations may become O(n) for a skewed Binary tree.

        If we make sure that height of the tree remains O(Log N) after every insertion and deletion,
            then we can guarantee an upper bound of O(Log N) for all these operations

    ** The height of an AVL tree is always O(Log N) where n is the number of nodes in the tree

-------

Insertion

    To make sure that the given tree remains AVL after every insertion,
        we must augment the standard BST insert operation to perform some re-balancing.

        Following are two basic operations that can be performed to re-balance a BST without
            violating the BST property (keys(left) < key(root) < keys(right)).

                1) Left Rotation
                2) Right Rotation

    -------

    T1, T2 and T3 are subtrees of the tree rooted with y (on the left side) or
        x (on the right side)

         y                               x
        / \     Right Rotation          /  \
       x   T3   - - - - - - - >        T1   y
      / \       < - - - - - - -            / \
     T1  T2     Left Rotation            T2  T3

    Keys in both of the above trees follow the following order

        keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)

            So BST property is not violated anywhere.

-------

Steps to follow for insertion

    Let the newly inserted node be w

        1) Perform standard BST insert for w.

        2) Starting from w, travel up and find the first unbalanced node.
            Let z be the first unbalanced node,
                y be the child of z that comes on the path from w to z and
                x be the grandchild of z that comes on the path from w to z.

        3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z.
            There can be 4 possible cases that needs to be handled as x, y and z can be arranged in 4 ways.

            Following are the possible 4 arrangements:

                a) y is left child of z and x is left child of y (Left Left Case)

                b) y is left child of z and x is right child of y (Left Right Case)

                c) y is right child of z and x is right child of y (Right Right Case)

                d) y is right child of z and x is left child of y (Right Left Case)

-------

a) Left Left Case

        T1, T2, T3 and T4 are subtrees.
                 z                                      y
                / \                                   /   \
               y   T4      Right Rotate (z)          x      z
              / \          - - - - - - - - ->      /  \    /  \
             x   T3                               T1  T2  T3  T4
            / \
          T1   T2

b) Left Right Case

             z                               z                           x
            / \                            /   \                        /  \
           y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
          / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
        T1   x                          y    T3                    T1  T2 T3  T4
            / \                        / \
          T2   T3                    T1   T2

c) Right Right Case

          z                                y
         /  \                            /   \
        T1   y     Left Rotate(z)       z      x
            /  \   - - - - - - - ->    / \    / \
           T2   x                     T1  T2 T3  T4
               / \
             T3  T4

d) Right Left Case

           z                            z                            x
          / \                          / \                          /  \
        T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
            / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
           x   T4                      T2   y                  T1  T2  T3  T4
          / \                              /  \
        T2   T3                           T3   T4

-------

Implementation:

    Following is the implementation for AVL Tree Insertion.

        The following implementation uses the recursive BST insert to insert a new node.

        In the recursive BST insert, after insertion, we get pointers to all ancestors one by one
            in a bottom-up manner.

            So we don’t need parent pointer to travel up.

            The recursive code itself travels up and visits all the ancestors of the newly inserted node.

    -------

    1. Perform the normal BST insertion

    2. The current node must be one of the ancestors of the newly inserted node.

        Update the height of the current node

    3) Get the balance factor (left subtree height – right subtree height) of the current node.

    4) If balance factor is greater than 1, then the current node is unbalanced and we are
        either in 'Left Left case' or 'left Right case'.

        To check whether it is left left case or not, compare the newly inserted key with
            the key in left subtree root.

    5) If balance factor is less than -1, then the current node is unbalanced and we are
        either in 'Right Right' case or 'Right-Left case'.

        To check whether it is Right Right case or not, compare the newly inserted key with the
            key in right subtree root.
*/
/*
class Node {

    int key, height;
    Node left, right;

    Node(int d) {
        key = d;
        height = 1;
    }
}

class AVLTree {

    Node root;

    int height(Node N) {

        if (N == null)
            return 0;

        return N.height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // A utility function to right rotate subtree with y
    Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        // Perform rotation
        x.right = y;
        y.left = T2;

        // Update heights
        y.height = max(height(y.left), height(y.right)) + 1;
        x.height = max(height(x.left), height(x.right)) + 1;

        return x;
    }

    // A utility function to left rotate subtree rooted with x

    Node leftRotate(Node x) {
        // For node x I will be holding first it's right and
        // then it's right's left
        Node y = x.right;
        Node T2 = y.left;

        // Perform rotation
        y.left = x;
        x.right = T2;

        //  Update heights
        x.height = max(height(x.left), height(x.right)) + 1;
        y.height = max(height(y.left), height(y.right)) + 1;

        // Return new root
        return y;
    }

    // Get Balance factor of node N
    int getBalance(Node N) {
        if (N == null)
            return 0;

        return height(N.left) - height(N.right);
    }

    Node insert(Node node, int key) {

        // 1. Perform the normal BST insertion
        if (node == null)
            return (new Node(key));

        if (key < node.key)
            node.left = insert(node.left, key);

        else if (key > node.key)
            node.right = insert(node.right, key);

        else // Duplicate keys not allowed
            return node;

        // 2. Update height of this ancestor node
        node.height = 1 + max(height(node.left), height(node.right));

        // 3. Get the balance factor of this ancestor
        //    node to check whether this node became
        //    unbalanced

        int balance = getBalance(node);

        // If this node becomes unbalanced, then there

        // are 4 cases Left Left Case
        if (balance > 1 && key < node.left.key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node.right.key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node.left.key) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node.right.key) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        // return the (unchanged) node pointer
        return node;
    }

    // A utility function to print preorder traversal
    // of the tree.
    // The function also prints height of every node

    void preOrder(Node node) {
        if (node != null) {
            System.out.print(node.key + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    public static void main(String[] args) {
        AVLTree tree = new AVLTree();

        // Constructing tree given in the above figure
        tree.root = tree.insert(tree.root, 10);
        tree.root = tree.insert(tree.root, 20);
        tree.root = tree.insert(tree.root, 30);
        tree.root = tree.insert(tree.root, 40);
        tree.root = tree.insert(tree.root, 50);
        tree.root = tree.insert(tree.root, 25);

        The constructed AVL Tree would be
             30
            /  \
          20   40
         /  \     \
        10  25    50

        System.out.println("Preorder traversal" +  " of constructed tree is : ");
        tree.preOrder(tree.root);
    }
}

Output:

  Preorder traversal of the constructed AVL tree is
  30 20 10 25 40 50

Time:

    The rotation operations (left and right rotate) takes constant time as only a few pointers are
        being changed there

    Updating the height and getting the balancing factor also takes constant time

    So the time complexity of the AVL insert remains same as BST insert which is O(h)
        where 'h' is the height of the tree

    Therefore AVL tree is height balanced -> O(log n)

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return N->height;
}

/*
    A helper function that allocates a new node with the given key and
        null left and right pointers
*/
Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    // new node is initially added at the leaf
    node->height = 1;
    return node;
}

/*
    A utility function to right rotate subtree rooted with y
*/
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/*
    A utility function to left rotate subtree rooted with x
*/
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
}

// Getting the balance factor of N
int getBalance(Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return height(N->left) - height(N->right);
}

/*
    Recursive function to insert a key in the subtree rooted with node
    and returns the new root of the subtree
*/
Node *insert(Node *node, int key)
{
    // 1. Perform the normal BST insertion
    if (node == NULL)
    {
        return (newNode(key));
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
        return node;

    // Updating the height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Getting the balance factor of this ancestor node to check
    // whether this node became unbalanced
    int balance = getBalance(node);

    // If the node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
}

// Printing pre-order
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "PreOrder traversal of the constructed AVL tree is \n";
    preOrder(root);
    return 0;
}

/*
Output :

    Preorder traversal of the constructed AVL tree is 30 20 10 25 40 50
*/