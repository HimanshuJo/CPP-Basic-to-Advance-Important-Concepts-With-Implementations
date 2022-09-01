// A. Meximization
/*
You are given an integer n and an array a1,a2,…,an. You should reorder the elements of the array a in 
such way that the sum of MEX on prefixes (i-th prefix is a1,a2,…,ai) is maximized.

Formally, you should find an array b1,b2,…,bn, such that the sets of elements of arrays a and b are equal 
(it is equivalent to array b can be found as an array a with some reordering of its elements) and 
∑i=1nMEX(b1,b2,…,bi) is maximized.

MEX of a set of nonnegative integers is the minimal nonnegative integer such that it is not in the set.

For example, MEX({1,2,3})=0, MEX({0,1,2,4,5})=3.

Example
input
3
7
4 2 0 1 3 3 7
5
2 2 8 6 9
1
0

output
0 1 2 3 4 7 3 
2 6 8 9 2 
0

Note
In the first test case in the answer MEX for prefixes will be:

MEX({0})=1
MEX({0,1})=2
MEX({0,1,2})=3
MEX({0,1,2,3})=4
MEX({0,1,2,3,4})=5
MEX({0,1,2,3,4,7})=5
MEX({0,1,2,3,4,7,3})=5
The sum of MEX=1+2+3+4+5+5+5=25. It can be proven, that it is a maximum possible sum of MEX on prefixes.

*/

/*

MEX:

    For a set of given integers, MEX is the smallest non-negative integer which is not there

    For example, for MEX({1, 2, 3}) = 0, MEX({0, 1, 2, 4, 5}) = 3

/**/ 

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        vector<int> p1;
        vector<int> p2;
        map<int, int> map;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (map[a[i]] == 1) {
                p2.push_back(a[i]);
            } else {
                p1.push_back(a[i]);
                map[a[i]]++;
            }
        }
        sort(p1.begin(), p1.end());
        for (int i = 0; i < p1.size(); ++i)
            cout << p1[i] << " ";
        for (int i = 0; i < p2.size(); ++i)
            cout << p2[i] << " ";
        cout << endl;
    }
}