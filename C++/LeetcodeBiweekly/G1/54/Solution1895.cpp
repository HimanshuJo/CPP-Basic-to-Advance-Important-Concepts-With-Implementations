// 1895. Largest Magic Square
/*
A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum,
and both diagonal sums are all equal. The integers in the magic square do not have to be distinct.
Every 1 x 1 grid is trivially a magic square.

Given an m x n integer grid, return the size (i.e., the side length k) of the
largest magic square that can be found within this grid.

Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 50
    1 <= grid[i][j] <= 10^6
*/
/*
Algo:

We have to check all the possible squares, within the grid

Furthermore for each of the square we have to check, all the rows and all the columns
    also the left and the right diagonal, whether they have the same sum or not
    
A small improvement we can make here is:
    given a particular grid of any dimensions, when we check in any of our rows and columns
    we don't have to check the rows and the columns one-by-one
    
    We can already calculate a preSum of each row and each column
        so that we can check for each row in O(1) time
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<unordered_map<int, int>> rowPreSum;
        vector<unordered_map<int, int>> colPreSum;
        for (int i = 0; i < m; ++i)
        {
            /*
                actual preSum will be a list of dictionary, where
                index will represent each row and the value will be a 
                preSum dictionary
            */
            unordered_map<int, int> preSum;
            preSum[-1] = 0;
            for (int j = 0; j < n; ++j)
            {
                preSum[j] = preSum[j - 1] + grid[i][j];
            }
            rowPreSum.push_back(preSum);
        }
        for (int j = 0; j < n; ++j)
        {
            unordered_map<int, int> preSum;
            preSum[-1] = 0;
            for (int i = 0; i < m; ++i)
            {
                preSum[i] = preSum[i - 1] + grid[i][j];
            }
            colPreSum.push_back(preSum);
        }
        int ans = 1;
        for (auto &entry : rowPreSum)
        {
            for (auto &pair : entry)
            {
                std::cout << pair.first << ": " << pair.second;
            }
            cout << "\n";
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                /*
                    The case for square of length 1 is already handled
                    Now we have to find the possible squares which could be larger than 1
                    What could be the largest square possible
                    That will be of length: m-i, n-i
                */
                for (int x = 2; x < min(m - i, n - j) + 1; ++x)
                {
                    /*
                        For the sum of the first row, we have to find 2 indices as we already have the req preSums
                        The first index will be 'i', the second index will be 'j + x - 1'
                        We then have to subtract it with the preSum value at 'i, j - 1'
                        This sum can be served as a base checking condition for each row, column and the diagonal
                   */
                    int sum = rowPreSum[i][j + x - 1] - rowPreSum[i][j - 1];
                    int diagonal = 0, antiDiagonal = 0;
                    bool flag = true;
                    for (int l = 0; l < x; ++l)
                    {
                        int row = rowPreSum[i + l][j + x - 1] - rowPreSum[i + l][j - 1];
                        if (row != sum)
                        {
                            flag = false;
                            break;
                        }
                        int col = colPreSum[j + l][i + x - 1] - colPreSum[j + l][i - 1];
                        if (col != sum)
                        {
                            flag = false;
                            break;
                        }
                        diagonal += grid[i + l][j + l];
                        antiDiagonal += grid[i + l][j + x - l - 1];
                    }
                    if (diagonal == sum && antiDiagonal == sum && flag)
                    {
                        ans = max(ans, x);
                    }
                }
            }
        }
        cout << "ans: " << ans << "\n";
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> row1 = {7, 1, 4, 5, 6};
    vector<int> row2 = {2, 5, 1, 6, 4};
    vector<int> row3 = {1, 5, 4, 3, 2};
    vector<int> row4 = {1, 2, 7, 3, 4};
    vector<vector<int>> grid;
    grid.push_back(row1);
    grid.push_back(row2);
    grid.push_back(row3);
    grid.push_back(row4);
    obj.largestMagicSquare(grid);
}