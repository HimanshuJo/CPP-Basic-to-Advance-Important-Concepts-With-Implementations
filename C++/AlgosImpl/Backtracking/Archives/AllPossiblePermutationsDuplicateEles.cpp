#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void backtrack(vector<int> &nums,
               vector<int> &curr,
               vector<vector<int>> &ans,
               vector<bool> &visited)
{
    if ((int)curr.size() == (int)nums.size())
    {
        ans.push_back(curr);
    }
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (visited[i])
            continue;
        if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
            continue;
        visited[i] = true;
        curr.push_back(nums[i]);
        backtrack(nums, curr, ans, visited);
        visited[i] = false;
        curr.pop_back();
    }
}

vector<vector<int>> permuteDuplicates(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<bool> visited((int)nums.size(), false);
    vector<int> curr;
    backtrack(nums, curr, ans, visited);
    return ans;
}

void getDistinctPermutations(vector<int> nums)
{
    vector<vector<int>> ans = permuteDuplicates(nums);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    vector<int> nums = {1, 2, 2};
    getDistinctPermutations(nums);
    return 0;
}