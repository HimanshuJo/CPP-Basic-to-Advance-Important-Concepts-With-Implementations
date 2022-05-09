// 378. Kth Smallest Element in a Sorted Matrix
/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-10^9 <= matrix[i][j] <= 10^9
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
*/

/*
We binary search to find the smallest ans in range [minOfMatrix ... maxOfMatrix] as long as countLessOrEqual(ans) >= k, 
where countLessOrEqual(x) is the number of elements less than or equal to x.

Algorithm

Start with left = minOfMatrix = matrix[0][0] and right = maxOfMatrix = matrix[n-1][n-1].
Find the mid of the left and the right. This middle number is NOT necessarily an element in the matrix.
If countLessOrEqual(mid) >= k, we keep current ans = mid and try to find smaller value by searching in the left side. 
Otherwise, we search in the right side.
Since ans is the smallest value which countLessOrEqual(ans) >= k, so it's the k th smallest element in the matrix.

How to count number of elements less or equal to x efficiently?

Since our matrix is sorted in ascending order by rows and columns.

We use two pointers, one points to the rightmost column c = n-1, and one points to the lowest row r = 0.

If matrix[r][c] <= x then the number of elements in row r less or equal to x is (c+1) (Because row[r] is sorted 
in ascending order, so if matrix[r][c] <= x then matrix[r][c-1] is also <= x). 
Then we go to next row to continue counting.

Else if matrix[r][c] > x, we decrease column c until matrix[r][c] <= x 
(Because column is sorted in ascending order, so if matrix[r][c] > x then matrix[r+1][c] is also > x).

Time complexity for counting: O(M+N).
*/

/*
Complexity

Time: O((M+N) * logD), where M <= 300 is the number of rows, N <= 300 is 
the number of columns, D <= 2*10^9 is the difference between the maximum element and the minimum element in the matrix.
Space: O(1).
*/

/*
Solution2:

Complexity:

Time: O(K * logK)
Space: O(K)

class Solution {
public:
    int rws, cols;
    
    int countValid(vector<vector<int>>&matrix, int mid){
        int cnt=0, col=cols-1;
        for(int rw=0; rw<rws; ++rw){
            while(col>=0&&matrix[rw][col]>mid){
                col--;
            }
            cnt+=(col+1);
        }
        return cnt;
    }
    
    void binarySearch(vector<vector<int>>&matrix, int left, int right, int k, int &ans){
        while(left<=right){
            int mid=left+((right-left)>>1);
            if(countValid(matrix, mid)>=k){
                ans=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        rws=matrix.size(), cols=matrix[0].size();
        int left=matrix[0][0], right=matrix[rws-1][cols-1], ans=-1;
        binarySearch(matrix, left, right, k, ans);
        return ans;
    }
};
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rws=matrix.size(), cols=matrix[0].size(), ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<>>minHeap;
        /*
            Since all the rows in the matrix are sorted in an ascending order,
            the kth min value in the matrix can't be farther away than min(rws, k)
        */
        for(int rw=0; rw<min(rws, k); ++rw){
            minHeap.push({matrix[rw][0], rw, 0});
        }
        /*
            For each of the possible inserted rows in the pq, keep on checking the next col until k times
            if for the same row, the next col element is the next smaller element, the same row will be
            inserted in the pq, with the next col
        */
        for(int i=1; i<=k; ++i){
            auto tp=minHeap.top();
            minHeap.pop();
            int rw=tp[1], col=tp[2];
            ans=tp[0];
            if(col+1<cols) minHeap.push({matrix[rw][col+1], rw, col+1});
        }
        return ans;
    }
};