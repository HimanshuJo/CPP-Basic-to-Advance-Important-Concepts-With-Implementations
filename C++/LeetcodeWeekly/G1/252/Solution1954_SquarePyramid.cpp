#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Solution
{
public:
    long long minimumPerimeter(long long neededApples)
    {
        long long n = 0;
        while (2 * n * (n + 1) * (1 + 2 * n) < neededApples)
            ++n;
        cout << n * 8;
        return n * 8;
    }
};

int main()
{
    Solution obj;
    obj.minimumPerimeter(1000000000);
}