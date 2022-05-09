/*
Suppose we have two string:

    String text1 = "abcdef"

    String text2 = "acmpf"

-------

To solve the big problem, we've to divide the problem into smaller sub-problems

    at any point in time, we'll probably be comparing two characters

        that is most of the time the case, with most of the 'DP' problems

-------

Suppose we start at the end of the String

    so in text1, we're currently at 'f'

    in text2, we're currently at 'f'

-------

Suppose the length of String text1 is n, and the length of String text2 is m

    If two letters at the end are same,
        then we can include them as a part of the longest common subsequence

    so LCS between String text1 and String text2 is (text1(n - 1), text2(m - 1))

        if text1.charAt(i) == text2.charAt(j)

            then the LCS is 1 + LCS(text1(n - 2), text2(m - 2))

                this is because if text1.charAt(i) == text2.charAt(j) are same then
                    that's one character we can add to our LCS

                    Now, all we need to figure out is that, what is the LCS between
                        the rest of the String in text1 and rest of the String in text2

        if text1.charAt(i) != text2.charAt(j) (e.g. last char in text1 is 'e' and last char in text2 is 'd')

            We know that at least one of them can't be a part of the subsequence
                either the 'e' or the 'd'

            here we've to consider two cases:

                Ist:

                    we can drop the 'e' in text1
                        in this case, we will be comparing the rest of the String text1 to the entire String text2

                IInd:

                    we can drop the 'd' in text2
                        in this case, we will be comparing the rest of the String text2 to the entire String text1

            so these are the two sub-problems that we're considering

                and what we want to do is search down both of these routes to see which one has better LCS

                LCS(text1(n - 1), text2(m - 2))
                LCS(text1(n - 2), text2(m - 1))


        Our base case is that when both of the sub-strings that we're comparing are empty

            so LCS will be 0 on this case

*/

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        int[][] dp = new int[n + 1][m + 1];  // extra index for the case when the substring is empty

        // our base case is set up by default, since java arrays are initialized with 0's
        // this is good because we want the 0th row and the 0th column of our matrix to be all 0's
        // since comparing an empty String to another String means that there is no common letters

        for (int i = 1; i < n + 1; i++) {  // we start at 1 because 0 represent an empty String in our matrix

        // the position [0][0] is comparing empty String to empty String
        // the position [1][1] is comparing the first letter of each String
        // because of that when we are filling a particular spot of our matrix, we've to subtract 1 to compensate
        // for it
            for (int j = 1; j < m + 1; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] =  1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] =  Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
}
