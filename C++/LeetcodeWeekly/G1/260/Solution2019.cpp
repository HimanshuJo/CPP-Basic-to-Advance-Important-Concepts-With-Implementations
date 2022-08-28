// 2019. The Score of Students Solving Math Expression
/*
You are given a string s that contains digits 0-9, addition symbols '+', and multiplication symbols '*'
only, representing a valid math expression of single digit numbers (e.g., 3+5*2).

This expression was given to n elementary school students. The students were instructed to get
the answer of the expression by following this order of operations:

Compute multiplication, reading from left to right; Then,
Compute addition, reading from left to right.
You are given an integer array answers of length n, which are the submitted answers of the students in no
particular order. You are asked to grade the answers, by following these rules:

If an answer equals the correct answer of the expression, this student will be rewarded 5 points;
Otherwise, if the answer could be interpreted as if the student applied the operators in the wrong order but
had correct arithmetic, this student will be rewarded 2 points;
Otherwise, this student will be rewarded 0 points.
Return the sum of the points of the students.

Input: s = "7+3*1*2", answers = [20,13,42]
Output: 7
Explanation: As illustrated above, the correct answer of the expression is 13, therefore one student is rewarded 5
points: [20,13,42]
A student might have applied the operators in this wrong order: ((7+3)*1)*2 = 20. Therefore one student is
rewarded 2 points: [20,13,42]
The points for the students are: [2,5,0]. The sum of the points is 2+5+0=7.
Example 2:

Input: s = "3+5*2", answers = [13,0,10,13,13,16,16]
Output: 19
Explanation: The correct answer of the expression is 13, therefore three students are rewarded 5 points each:
[13,0,10,13,13,16,16]
A student might have applied the operators in this wrong order: ((3+5)*2 = 16. Therefore two students are
rewarded 2 points: [13,0,10,13,13,16,16]
The points for the students are: [5,0,0,5,5,2,2]. The sum of the points is 5+0+0+5+5+2+2=19.
Example 3:

Input: s = "6+0*1", answers = [12,9,6,4,8,6]
Output: 10
Explanation: The correct answer of the expression is 6.
If a student had incorrectly done (6+0)*1, the answer would also be 6.
By the rules of grading, the students will still be rewarded 5 points (as they got the correct answer), not 2 points.
The points for the students are: [0,0,5,0,0,5]. The sum of the points is 10.


Constraints:

3 <= s.length <= 31
s represents a valid expression that contains only digits 0-9, '+', and '*' only.
All the integer operands in the expression are in the inclusive range [0, 9].
1 <= The count of all operators ('+' and '*') in the math expression <= 15
Test data are generated such that the correct answer of the expression is in the range of [0, 1000].
n == answers.length
1 <= n <= 104
0 <= answers[i] <= 1000
*/

class Solution
{
public:
    unordered_set<int> memo[32][32];
    void dfs(string &s, int st, int fin)
    {
        if (memo[st][fin].empty())
        {
            if (fin - st == 1)
                memo[st][fin].insert(s[st] - '0');
            for (int i = st + 1; i < fin; i += 2)
            {
                dfs(s, st, i);
                dfs(s, i + 1, fin);
                for (int n1 : memo[st][i])
                {
                    for (int n2 : memo[i + 1][fin])
                    {
                        int n = s[i] == '*' ? n1 * n2 : n1 + n2;
                        if (n <= 1000)
                            memo[st][fin].insert(n);
                    }
                }
            }
        }
    }

    int scoreOfStudents(string s, vector<int> &answers)
    {
        int correct = 0;
        for (int i = 1, j = 0; i <= s.size(); i += 2)
            if (i == s.size() || s[i] == '+')
            {
                int mul = 1;
                for (; j < i; j += 2)
                    mul *= s[j] - '0';
                correct += mul;
            }
        dfs(s, 0, s.size());
        return accumulate(begin(answers), end(answers), 0, [&](int sum, int ans)
        {   return sum + (ans == correct ? 5 : memo[0][s.size()].count(ans) ? 2
                          : 0);
        });
    }
};

// -------*******-------

class Solution
{
public:
    int scoreOfStudents(string s, vector<int> &answers)
    {
        int n = s.length() / 2 + 1;
        unordered_map<int, int>mp;
        unordered_set<int>st[n][n];
        int res1 = 0;
        stack<int> st1;
        for (int i = 0; i < s.length(); ++i)
        {
            if (isdigit(s[i]))
            {
                st1.push(s[i] - '0');
            }
            else
            {
                char sgn = s[i];
                if (sgn == '*')
                {
                    int curr = st1.top();
                    st1.pop();
                    while (true)
                    {
                        if (isdigit(s[i + 1]))
                        {
                            ++i;
                            break;
                        }
                        else
                        {
                            ++i;
                            if (i == s.length() - 1)
                            {
                                break;
                            }
                        }
                    }
                    curr *= s[i] - '0';
                    st1.push(curr);
                }
            }
        }
        while (!st1.empty())
        {
            res1 += st1.top();
            st1.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            st[i][i].insert(s[i << 1] - '0');
            for (int j = i + 1; j < n; ++j) {
                for (int k = i; k < j; ++k) {
                    for (auto& lf : st[i][k]) {
                        for (auto& rght : st[k + 1][j]) {
                            int ans = s[(k << 1) | 1] == '*' ? lf * rght : lf + rght;
                            if (ans <= 1000) {
                                st[i][j].insert(ans);
                            }
                        }
                    }
                }
            }
        }
        mp[res1] = 5;
        int fnres = 0;
        for (auto &nums : answers) {
            auto it = mp.find(nums);
            if (it != mp.end()) {
                fnres += mp[nums];
            } else {
                if (st[0][n - 1].count(nums)) {
                    fnres += 2;
                }
            }
        }
        return fnres;
    }
};