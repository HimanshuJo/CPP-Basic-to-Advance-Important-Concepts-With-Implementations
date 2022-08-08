// 1896. Minimum Cost to Change the Final Value of Expression
/*
You are given a valid boolean expression as a string expression consisting of the 
characters '1','0','&' (bitwise AND operator),'|' (bitwise OR operator),'(', and ')'.

    For example, "()1|1" and "(1)&()" are not valid while "1", "(((1))|(0))", and "1|(0&(1))" 
    are valid expressions.

Return the minimum cost to change the final value of the expression.

    For example, if expression = "1|1|(0&0)&1", its value is 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1. 
    We want to apply operations so that the new expression evaluates to 0.

The cost of changing the final value of an expression is the number of operations performed on the expression. 
The types of operations are described as follows:

    Turn a '1' into a '0'.
    Turn a '0' into a '1'.
    Turn a '&' into a '|'.
    Turn a '|' into a '&'.

Note: '&' does not take precedence over '|' in the order of calculation. Evaluate parentheses first, 
then in left-to-right order.

Example 1:

Input: expression = "1&(0|1)"
Output: 1
Explanation: We can turn "1&(0|1)" into "1&(0&1)" by changing the '|' to a '&' using 1 operation.
The new expression evaluates to 0. 

Example 2:

Input: expression = "(0&0)&(0&0&0)"
Output: 3
Explanation: We can turn "(0&0)&(0&0&0)" into "(0|1)|(0&0&0)" using 3 operations.
The new expression evaluates to 1.

Example 3:

Input: expression = "(0|(1|0&1))"
Output: 1
Explanation: We can turn "(0|(1|0&1))" into "(0|(0|0&1))" using 1 operation.
The new expression evaluates to 0.

 

Constraints:

    1 <= expression.length <= 10^5
    expression only contains '1','0','&','|','(', and ')'
    All parentheses are properly matched.
    There will be no empty parentheses (i.e: "()" is not a substring of expression).
*/

class Solution {
public:
    
    struct Node{
      char op;
        int value;
        Node *left, *right;
    
        Node(char op, int value, Node *left, Node *right){
            this->op=op;
            this->value=value;
            this->left=left;
            this->right=right;
        }
    };
    
    Node* parse(string &expression, int start, int &len){
        Node *left;
        int i=start;
        if(expression[i]=='0'||expression[i]=='1'){
            left=new Node(expression[i], expression[i]-'0', nullptr, nullptr);
        } else if(expression[i]=='('){
            left=parse(expression, i+1, len);
            i+=len+1;
        }
        i+=1;
        while(i<expression.size()&&expression[i]!=')'){
            char op=expression[i++];
            Node *right;
            if(expression[i]=='0'||expression[i]=='1'){
                right=new Node(expression[i], expression[i]-'0', nullptr, nullptr);
            } else if(expression[i]=='('){
                right=parse(expression, i+1, len);
                i+=len+1;
            }
            int value=(op=='&'?(left->value&right->value):(left->value|right->value));
            i+=1;
            left=new Node(op, value, left, right);
        }
        len=i-start;
        return left;
    }
    
    int get_min_cost(Node *root){
        if(root->op=='1'||root->op=='0') return 1;
        int left_cost=get_min_cost(root->left);
        int right_cost=get_min_cost(root->right);
        int desired=root->value==1?0:1;
        if(root->op=='&'&&desired==1||root->op=='|'&&desired==0){
            int no_change_op=(root->left->value!=desired?left_cost:0)+(root->right->value!=desired?right_cost:0);
            int change_op=1+min((root->left->value!=desired?left_cost:0), (root->right->value!=desired?right_cost:0));
            return min(no_change_op, change_op);
        }
        return min((root->left->value!=desired?left_cost:0), (root->right->value!=desired?right_cost:0));
    }
    
    int minOperationsToFlip(string expression) {
        int len=expression.size();
        Node *root=parse(expression, 0, len);
        return get_min_cost(root);
    }
};