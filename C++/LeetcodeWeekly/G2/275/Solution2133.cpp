// 2133. Check if Every Row and Column Contains All Numbers
/*
An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.

Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
1 <= matrix[i][j] <= n
*/

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        set<int>temp1; // col mat
        set<int>temp2;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                temp1.insert(matrix[i][j]);
                temp2.insert(matrix[j][i]);
            }
            for(int x=1; x<=n; ++x){
                auto it=temp1.find(x);
                if(it==temp1.end()) return false;
                auto it2=temp2.find(x);
                if(it2==temp2.end()) return false;
            }
            temp1.clear();
            temp2.clear();
        }
        return true;
    }
};