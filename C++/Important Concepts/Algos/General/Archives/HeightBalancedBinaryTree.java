/*
Height balanced binary tree:

    A tree where no leaf is much farther away from the root than any other leaf

    Different balancing schemes allow different definitions of “much farther” and different
        amounts of work to keep them balanced.

    Consider a height-balancing scheme where following conditions should be checked to determine
        if a binary tree is balanced

    An empty tree is height-balanced. A non-empty binary tree T is balanced if:

        1) Left subtree of T is balanced

        2) Right subtree of T is balanced

        3) The difference between heights of left subtree and right subtree is not more than 1

*/

/* A binary tree node has data, pointer to left child, and a pointer to right child */

class Node {
    int data;
    Node left;
    Node right;

    Node(int d) {
        data = d;
        left = null;
        right = null;
    }
}

class BinaryTree {
    Node root;

    /* Returns true if the binary tree with root is height-balanced */

    boolean isBalanced(Node node) {
        int left_tree_height;
        int right_tree_height;

        if (node == null) {
            return true;
        }

        // Get the height of the left and right sub-tree

        left_tree_height = height(node.left);
        right_tree_height = height(node.right);

        if (Math.abs(left_tree_height - right_tree_height) <= 1 && isBalanced(node.left) && isBalanced(node.right)) {

            return true;
        }

        return false;
    }

    /* Function to compute 'height' of a tree. Height of a tree is the number of nodes along the longest
        path from the root node down to the farthest leaf node */

    int height(Node node) {
        if (node == null) {
            return 0;
        }

        /* If the tree is not empty then height = 1 + max of left height and right heights */

        return 1 + Math.max(height(node.left), height(node.right));
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left =  new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.left.left.left = new Node(8);

        if (tree.isBalanced(tree.root)) {
            System.out.println("Tree is balanced");
        } else
            System.out.println("Not balanced");
    }
}
