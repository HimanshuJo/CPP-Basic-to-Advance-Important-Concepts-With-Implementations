#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int K;
        cin >> n >> K;
        vector<ll> arr;
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        ll currMax = LONG_LONG_MIN;
        for (int i = 0; i < n; ++i)
        {
            int curr = i;
            for (int j = i + 1; j < n; ++j)
            {
                int nextNum = j;
                pair<int, int> par;
                par.first = curr;
                par.second = nextNum;
                ll left = par.first;
                ll right = par.second;
                ll leftHl = (left + 1) * (right + 1);
                ll rightHl = K * (arr.at(left) | arr.at(right));
                if (leftHl - rightHl > currMax)
                {
                    currMax = leftHl - rightHl;
                }
                // cout << "left: " << left << endl;
                // cout << "right: " << right << endl;
                // cout << "arr left: " << arr.at(left) << endl;
                // cout << "arr right: " << arr.at(right) << endl;
                // cout << "leftHl: " << leftHl << endl;
                // cout << "rightHl: " << rightHl << endl;
                // cout << "leftHl - rightHl: " << leftHl - rightHl << endl;
                // cout << "currMax: " << currMax << endl;
                // cout << "-------" << endl;
            }
        }
        cout << currMax << "\n";
    }
}