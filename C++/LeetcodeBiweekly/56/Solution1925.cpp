// Count Square Sum Triples

/*
 * A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

	Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

	Example 1:

	Input: n = 5
	Output: 2
	Explanation: The square triples are (3,4,5) and (4,3,5).

 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriples(int n)
    {
        vector<bool> squares(n * n + 1);
        for (int i = 1; i <= n; ++i)
        {
            squares[i * i] = true;
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; i * i + j * j <= n * n; ++j)
            {
                cout << squares[i * i + j * j] << " "
                     << "\n";
                res += squares[i * i + j * j] * 2;
            }
            cout << "-------"
                 << "\n";
        }
        return res;
    }
};

int main()
{
    Solution obj;
    int n = 5;
    obj.countTriples(n);
    return 0;
}