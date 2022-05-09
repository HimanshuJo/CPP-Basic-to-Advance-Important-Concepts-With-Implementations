#include <bits/stdc++.h>
using namespace std;

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