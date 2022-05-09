// Maximum Matrix Sum
/*
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's 
elements using the operation mentioned above.

Constraints:

n == matrix.length == matrix[i].length
2 <= n <= 250
-10^5 <= matrix[i][j] <= 10^5
*/
/*
	If number of -ve numbers are even, it means you can ALWAYS shift -1 in a
	fashion that you can cancel out the negative signs and make the numbers positive.
	So in that case, total sum (absolute value of all elements) will be your answer
	
	If number of -ve numbers are odd, then you can cancel out the negative sign 
	of large numbers so that they contribute to our over all sum.
	And notice that at the end, you will be left with one negative number.
	*So, shift this negative sign to the smallest number
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        long long sum = 0;
        int negCount = 0;
        int smallestMin = INT_MAX;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                sum += abs(matrix[i][j]); //Add all the numbers
                
                if(matrix[i][j] < 0)
                    negCount++; //keep track of count of -ve numbers
                
				//keep track of the smallest number which can be negative
                smallestMin = min(smallestMin, abs(matrix[i][j]));
            }
        }
        
        return negCount%2 == 0 ? sum : sum-2*smallestMin;
		/*		
			Why (sum-2*smallestMin) ????
				In simple words : You had first added that number, 
				so you need to subtract that addition and also in the
				end, you need to reduce the sum with that number.
				That's why we have to substract 2 times.
				See with the example below :
				[1,   2, 3]
				[-1, -2,-3]
				[1,   2, 3]
			
			
				Over all Sum "S"(all elements with abs value) = 18
				Negative count = 3 which is odd
				Smallest number which can be negative is "Min"= 1

				so, 
				[1,   2, 3]
				[-1,  2, 3]
				[1,   2, 3]

				Now, final sum "F" = 1 + 2 + 3 + (-1) + 2 + 3 + 1 + 2 + 3 = 16

				So, final result "F" = "S" - 2*Min  (i.e. 18 - 2*1) = 16
		*/
    }
};