#include <bits/stdc++.h>
using namespace std;

string xoring(string a, string b, int n)
{
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        string nwA = bitset<8>(A).to_string();
        string nwB = bitset<8>(B).to_string();
        int n = nwA.length();
        string res = xoring(nwA, nwB, n);
        unsigned long ans = std::bitset<8>(res).to_ulong();
        cout << ans << "\n";
    }
}