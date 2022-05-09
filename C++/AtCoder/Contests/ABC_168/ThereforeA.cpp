#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, string> map;
        map.insert(pair<int, string>(2, "hon"));
        map.insert(pair<int, string>(4, "hon"));
        map.insert(pair<int, string>(5, "hon"));
        map.insert(pair<int, string>(7, "hon"));
        map.insert(pair<int, string>(9, "hon"));
        map.insert(pair<int, string>(0, "pon"));
        map.insert(pair<int, string>(1, "pon"));
        map.insert(pair<int, string>(6, "pon"));
        map.insert(pair<int, string>(8, "pon"));
        map.insert(pair<int, string>(3, "bon"));
        int toCheck = n % 10;
        cout << map[toCheck] << "\n";
    }
}