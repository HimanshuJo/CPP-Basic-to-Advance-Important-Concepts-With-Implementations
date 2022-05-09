#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        int N;
        cin >> N;
        multimap<int, int, greater <int>> mp;
        for (int i = 0; i < N; ++i) {
            int temp;
            cin >> temp;
            mp.insert(pair<int, int>(temp, i + 1));
        }
        int count = 0;
        int res = 0;
        for (auto &entry : mp) {
            count++;
            if (count == 2) {
                res = entry.second;
                break;
            }
        }
        cout << res << "\n";
    }
}