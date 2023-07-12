// 1970. Last Day Where You Can Still Cross
/*
There is a 1-based binary matrix where 0 represents land and 1 represents water.
You are given integers row and col representing the number of rows and columns in the matrix,
respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes
flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci]
represents that on the ith day, the cell on the rith row and cith column (1-based coordinates)
will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom
by only walking on land cells. You can start from any cell in the top row and end at
any cell in the bottom row. You can only travel in the four cardinal directions
(left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by
only walking on land cells.

Example:
Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.

Constraints:

2 <= row, col <= 2 * 10^4
4 <= row * col <= 2 * 10^4
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.
*/

class Solution
{
public:
    vector<int> x = {0, 1, -1, 0};
    vector<int> y = {1, 0, 0, -1};

    bool check(vector<vector<int>> &A, int i, int j)
    {
        return (i >= 0 && j >= 0 && i < A.size() && j < A[0].size() && A[i][j] == 0);
    }

    bool dfs(vector<vector<int>> &A, int i, int j)
    {
        if (i == A.size() - 1)
            return true;
        A[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int u = i + x[k];
            int v = j + y[k];
            if (check(A, u, v))
            {
                if (dfs(A, u, v))
                    return true;
            }
        }
        return false;
    }

    bool check(vector<vector<int>> &A, int mid)
    {
        if (mid < A[0].size()) //There will always be way to reach bottom in this case
            return true;       //Worst case : all boxes in 1st row gets filled one by one.
        for (int i = 0; i < A[0].size(); i++)
        {
            if (A[0][i] == 0)
            {
                if (dfs(A, 0, i))
                    return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &B)
    {

        int start = 0;
        int end = B.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            vector<vector<int>> A(row, vector<int>(col, 0));
            for (int i = 0; i < mid; i++)
            {
                int u = B[i][0] - 1;
                int v = B[i][1] - 1;
                A[u][v] = 1;
            }
            if (check(A, mid))
                start = mid + 1;
            else
                end = mid - 1;
        }
        return end;
    }
};