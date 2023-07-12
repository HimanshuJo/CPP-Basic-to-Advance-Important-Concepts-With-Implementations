/*
Given a 01 matrix M, find the longest line of consecutive one in the matrix. 

The line could be horizontal, vertical, diagonal or anti-diagonal.

    Example:
    
    Input:
    [[0,1,1,0],
     [0,1,1,0],
     [0,0,0,1]]
    
    Output: 3

-------

Solution:

	dp[i][j][k] represents the number of consecutive 1s in the kth case from the beginning of the
		numeration to the number nums[i][j]

	The value of k is 0, 1, 2, 3 which corresponds to the 
		horizontal, 
		vertical, 
		diagonal and
		inverse diagonal directions

		Update the dp array process

	If the number is 0, then we can skip that step directly, 

		then we can add the previous dp value in the horizontal direction

		then we can add the dp value of the above number in the vertical direction

		the diagonal direction is:
			simply adding the dp value of the upper right number

		the inverse diagonal direction is:
			the dp value of the upper left digit to the inverse diagonal

	Finally we can use each value to update the result

-------

Time Complexity:

	O(m*n)

Space Complexity:

	O(m*n)

*/

class Solution {

	public int longestLine(int[][] M) {
		int n = M.length, max = 0;
		int m = M[0].length;
		if (n == 0) return max;
		int[][][] dp = new int[n][m][4];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (M[i][j] == 0) continue;
				for (int k = 0; k < 4; ++k) {
					dp[i][j][k] = 1;
					if (j > 0) {
						dp[i][j][0] += dp[i][j - 1][0];  // horizontal line
					}
					if (j > 0 && i > 0) {
						dp[i][j][1] += dp[i - 1][j - 1][1];  // anti-diagonal line
					}
					if (i > 0) {
						dp[i][j][2] += dp[i - 1][j][2];  // vertical line
					}
					if (i > 0 && j < m - 1) {
						dp[i][j][3] += dp[i - 1][j + 1][3];  // diagonal line
					}
					max = Math.max(max, Math.max(dp[i][j][0], dp[i][j][1]));
					max = Math.max(max, Math.max(dp[i][j][2], dp[i][j][3]));
				}
			}
		}
		return max;
	}
}