#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
long long cnt = 0;

vector<int> merge(vector<int> l, vector<int> r)
{
    vector<int>ans;
    int i = 0; int j = 0;
    while (i < l.size() && j < r.size())
    {
        if (l[i] <= r[j])
        {
            ans.push_back(l[i++]);
        }
        else
        {
            ans.push_back(r[j++]);
            cnt += (long long)l.size() - i;
        }
    }
    while (i + j < l.size() + r.size())
    {
        if (i < l.size())
        {
            ans.push_back(l[i++]);
        }
        else
        {
            ans.push_back(r[j++]);
        }
    }
    return ans;
}

vector<int> mergeSort(vector <int> &v, int l, int r)
{
    if (l == r)
    {
        return { v[l] };
    }
    else
    {
        vector<int> lv = mergeSort(v, l, (l + r) / 2);
        vector<int> rv = mergeSort(v, (l + r) / 2 + 1, r);
        return merge(lv, rv);
    }
}

int main() {
    vector<int>nums{5, 7, 2, 1, 3, 9};
    vector<int>res = mergeSort(nums, 0, nums.size() - 1);
    for (auto &vals : res)
        cout << vals << " ";
}
