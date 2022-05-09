#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        string res;
        res = (B == 0 && A > 0) ? "Gold" : (A == 0 && B > 0) ? "Silver"
                                                             : "Alloy";
        cout << res;
    }
}