// 74. Search a 2D Matrix
/*
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rw=0, fnrw=matrix.size()-1, col=matrix[0].size()-1;
        while(rw<=fnrw){
            int currw=rw+(fnrw-rw)/2;
            if(target<matrix[currw][0]){
                fnrw=currw-1;
            } else if(target>matrix[currw][col]){
                rw=currw+1;
            } else{
                rw=currw;
                break;
            }
        }
        if(rw>fnrw) return false;
        int left=0, right=col;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(target>matrix[rw][mid]){
                left=mid+1;
            } else if(target<matrix[rw][mid]){
                right=mid-1;
            } else return true;
        }
        return false;
    }
};