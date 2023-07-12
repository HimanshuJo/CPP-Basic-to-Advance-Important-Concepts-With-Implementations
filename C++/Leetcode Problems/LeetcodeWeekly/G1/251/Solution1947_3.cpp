// 1947. Maximum Compatibility Score Sum
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

Constraints:

m == students.length == mentors.length
n == students[i].length == mentors[j].length
1 <= m, n <= 8
students[i][k] is either 0 or 1.
mentors[j][k] is either 0 or 1.
*/
/*
The brute force solution is generating all the permuntations of the mentors and
calculate the score of this permutation and the students.

The permutation generation process with DFS takes O(M! * M) time and calculating the score takes O(N) time,
so the overall time complexity is O(M! * MN).

Since M and N are at most 8 and 8! * 8^2 = 2,580,480 ~= 2.6e6, such solution should be able to pass.
*/

class Solution
{
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors)
    {
        queue<vector<pair<int, int>>> q;
        int i = 0;
        int m = students.size();
        int n = students[0].size();
        int max_score = 0;
        for (int j = 0; j < m; j++)
        {
            vector<pair<int, int>> v(1);
            v[0] = {0, 0};

            v.push_back({i, j});

            for (int a = 0; a < n; a++)
            {
                v[0].first += students[i][a] == mentors[j][a];
            }

            q.push(v);
        }
        while (!q.empty())
        {
            vector<pair<int, int>> v_pair = q.front();
            q.pop();
            if (v_pair.size() == m + 1)
            {
                max_score = max(max_score, v_pair[0].first);
            }
            else
            {
                vector<bool> visited(m, false);
                for (int x = 1; x < v_pair.size(); x++)
                {
                    visited[v_pair[x].second] = true;
                }
                int last = v_pair.back().first;
                for (int x = 0; x < m; x++)
                {
                    if (visited[x] == false)
                    {
                        v_pair.push_back({last + 1, x});
                        int same = 0;
                        for (int a = 0; a < n; a++)
                        {
                            if (students[last + 1][a] == mentors[x][a])
                                same++;
                        }
                        v_pair[0].first += same;
                        q.push(v_pair);
                        v_pair.pop_back();
                        v_pair[0].first -= same;
                    }
                }
            }
        }
        return max_score;
    }
};