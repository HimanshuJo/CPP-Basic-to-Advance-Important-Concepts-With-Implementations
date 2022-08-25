// 2326. Spiral Matrix IV
/*
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in 
spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty 
spaces, fill them with -1.

Return the generated matrix.

Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.

Constraints:

1 <= m, n <= 10^5
1 <= m * n <= 10^5
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m, vector<int>(n, -1));
        bool flg1=true, flg2=false, flg3=false, flg4=false;
        int currw=0, curcol=0;
        while(head!=nullptr){
            mat[currw][curcol]=head->val;
            if(head->next==nullptr) break;
            if(flg1){
                if(curcol+1<=n-1){
                    head=head->next;
                    curcol++;
                    if(curcol==n-1){
                        flg1=false;
                        flg2=true;
                    }
                    if(mat[currw][curcol]!=-1){
                        curcol--;
                        currw++;
                        flg1=false;
                        flg2=true;
                    }
                } else{
                    flg1=false;
                    flg2=true;
                }
            }
            else if(flg2){
                if(currw+1<=m-1){
                    head=head->next;
                    currw++;
                    if(currw==m-1){
                        flg2=false;
                        flg3=true;
                    }
                    if(mat[currw][curcol]!=-1){
                        currw--;
                        curcol--;
                        flg2=false;
                        flg3=true;
                    }   
                } else{
                    flg2=false;
                    flg3=true;
                }
            }
            else if(flg3){
                if(curcol-1>=0){
                    head=head->next;
                    curcol--;
                    if(curcol==0){
                        flg3=false;
                        flg4=true;
                    }
                    if(mat[currw][curcol]!=-1){
                        curcol++;
                        currw--;
                        flg3=false;
                        flg4=true;
                    }   
                } else {
                    flg3=false;
                    flg4=true;
                }
            }
            else if(flg4){
                if(currw-1>=0){
                    head=head->next;
                    currw--;
                    if(currw==0){
                        flg4=false;
                        flg1=true;
                    }
                    if(mat[currw][curcol]!=-1){
                        currw++;
                        curcol++;
                        flg4=false;
                        flg1=true;
                    }   
                } else break;
            }
        } 
        vector<vector<int>>ans;
        for(int i=0; i<m; ++i){
            ans.push_back(mat[i]);
        }
        return ans;
    }
};