#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> arr;
        vector<int> bArr;
        for (int i = 0; i < N; ++i)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        for (int i = 0; i < M; ++i)
        {
            int temp;
            cin >> temp;
            bArr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        sort(bArr.begin(), bArr.end());
        int mini = INT_MAX;
        for (int i = 0; i < N; ++i)
        {
            int curr = arr.at(i);
            vector<int>::iterator low, up;
            low = lower_bound(bArr.begin(), bArr.end(), curr);
            up = upper_bound(bArr.begin(), bArr.end(), curr);
            int lowIndex = low - bArr.begin();
            int upIndex = up - bArr.begin();
            if (upIndex > M - 1)
            {
                upIndex = M - 1;
            }
            if (lowIndex > M - 1)
            {
                lowIndex = M - 1;
            }
            if (lowIndex != 0 && bArr.at(lowIndex) != curr)
            {
                lowIndex--;
            }
            int temp1 = abs(curr - bArr.at(lowIndex));
            int temp2 = abs(curr - bArr.at(upIndex));
            int currMini = min(temp1, temp2);
            mini = min(mini, currMini);
        }
        cout << mini << "\n";
    }
}