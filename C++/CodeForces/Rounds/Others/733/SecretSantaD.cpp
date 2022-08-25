/*
Every December, VK traditionally holds an event for its employees named "Secret Santa". 
Here's how it happens.

n employees numbered from 1 to n take part in the event. Each employee i is assigned a 
different employee bi, to which employee i has to make a new year gift. 
Each employee is assigned to exactly one other employee, and nobody is assigned to 
themselves (but two employees may be assigned to each other). 
Formally, all bi must be distinct integers between 1 and n, and for any i, bi≠i must hold.

The assignment is usually generated randomly. This year, as an experiment, 
all event participants have been asked who they wish to make a gift to. 
Each employee i has said that they wish to make a gift to employee ai.

Find a valid assignment b that maximizes the number of fulfilled wishes of the employees.
*/

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr;
        vector<ll> ans;
        unordered_set<ll> seen;
        stack<ll> extr;
        for (int i = 0; i < n; ++i)
        {
            ll in;
            cin >> in;
            arr.push_back(in);
        }
        for (int i = 0; i < n; ++i)
        {
            if (seen.find(arr.at(i)) == seen.end())
            {
                ans.push_back(arr.at(i));
                if (ans.at(i) == i + 1)
                {
                    ans.at(i) = -1;
                }
                seen.insert(ans.at(i));
            }
            else
            {
                ans.push_back(-1);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (seen.find(i + 1) == seen.end())
            {
                extr.push(i + 1);
            }
        }
        ll lastAdded = -1;
        int lastAddedIndex = -1;
        for (int i = 0; i < n; ++i)
        {
            if (ans.at(i) == -1)
            {
                ans.at(i) = extr.top();
                lastAdded = ans.at(i);
                lastAddedIndex = i;
                extr.pop();
                if (extr.empty() && lastAdded == i + 1)
                {
                    ans.at(i) = arr.at(i);
                    ll toCheck = ans.at(i);
                    for (int ii = 0; ii < n; ++ii)
                    {
                        if (ans.at(ii) == toCheck && ii != i)
                        {
                            ans.at(ii) = i + 1;
                        }
                    }
                }
                if (ans.at(i) == i + 1)
                {
                    if (extr.size() >= 1)
                    {
                        ans.at(i) = extr.top();
                        extr.pop();
                        extr.push(lastAdded);
                        lastAdded = ans.at(i);
                        lastAddedIndex = i;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr.at(i) == ans.at(i))
            {
                res++;
            }
        }
        cout << res << "\n";
        for (auto &num : ans)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
}