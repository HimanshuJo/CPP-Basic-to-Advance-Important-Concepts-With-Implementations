// Maximum Compatibility Score Sum

// DFS
/*
There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).

The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. 
The answers of the students are represented by a 2D integer array students where students[i] is an integer array that 
contains the answers of the ith student (0-indexed). The answers of the mentors are represented by a 2D integer array 
mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).

Each student will be assigned to one mentor, and each mentor will have one student assigned to them. 
The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.

For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], then 
their compatibility score is 2 because only the second and the third answers are the same.
You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.

Given students and mentors, return the maximum compatibility score sum that can be achieved.

Example 1:

Input: students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]
Output: 8
Explanation: We assign students to mentors in the following way:
- student 0 to mentor 2 with a compatibility score of 3.
- student 1 to mentor 0 with a compatibility score of 2.
- student 2 to mentor 1 with a compatibility score of 3.
The compatibility score sum is 3 + 2 + 3 = 8.
*/
/*
The brute force solution is generating all the permuntations of the mentors and calculate the score of this permutation and the students.

The permutation generation process with DFS takes O(M! * M) time and calculating the score takes O(N) time, so the overall time complexity is O(M! * MN).

Since M and N are at most 8 and 8! * 8^2 = 2,580,480 ~= 2.6e6, such solution should be able to pass.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int used[9] = {}, ans = 0, m, n;
    void dfs(vector<vector<int>> &S, vector<vector<int>> &M, int i, int score)
    {
        if (i == m)
        {
            ans = max(ans, score);
            return;
        }
        for (int j = 0; j < m; ++j)
        {
            if (used[j])
                continue;
            used[j] = 1;
            int s = 0;
            for (int k = 0; k < n; ++k)
                s += S[i][k] == M[j][k]; // calculate the compatibility score of student `i` and mentor `j`.
            dfs(S, M, i + 1, score + s);
            used[j] = 0;
        }
    }

public:
    int maxCompatibilitySum(vector<vector<int>> &S, vector<vector<int>> &M)
    {
        m = S.size(), n = S[0].size();
        dfs(S, M, 0, 0);
        return ans;
    }
};