/*
Petya once wrote a sad love song and shared it to Vasya. 
The song is a string consisting of lowercase English letters. 
Vasya made up q questions about this song.
Each question is about a subsegment of the song starting from the l-th 
letter to the r-th letter. 

Vasya considers a substring made up from characters on this segment and repeats
each letter in the subsegment k times, where k is the index of the corresponding 
letter in the alphabet. 

For example, if the question is about the substring "abbcb", then Vasya repeats
letter 'a' once, each of the letters 'b' twice, letter 'c" three times, 
so that the resulting string is "abbbbcccbb", its length is 10. 

Vasya is interested about the length of the resulting string.

Help Petya find the length of each string obtained by Vasya.

Input

The first line contains two integers n and q (1≤n≤100000, 1≤q≤100000) — 
the length of the song and the number of questions.

The second line contains one string s — the song, consisting of n lowercase 
letters of English letters.

Vasya's questions are contained in the next q lines. 
Each line contains two integers l and r (1≤l≤r≤n) — the bounds of the question.

Output

Print q lines: for each question print the length of the string obtained by Vasya.

Examples
Input

7 3
abacaba
1 3
2 5
1 7

Output

4
7
11
*/

/*
We are not altering the original string, we are just taking a segment
    of the string between l and r (which is our sub-string to perform required
    operations) and after performing required operations we are generating our 
    final string and displaying it's length

* Main hint in the question:

    suppose we have our string as:
        abcaefab

        suppose our substring is "abc" so the final string in this case is:
            "abbccc"

            The contribution of 'a' in this final string is 1
            The contribution of 'b' in this final string is 2 and so on

        and it doesn't matter what is the position of 'b' and any other character 
            in the string it's contribution will always be the number where it
            stands in the alphabetical rankings (2 in this case)

    So what we can do in this case is to pre-compute this entire table

    -------

    Suppose our string is: "abcde"

    we will first create a dp array:

        In this array we'll store for a particular character, fixing the l
        and r is pointing to that character currently

        What entries to store in this array:
            * here our string is 1-based
            
            first our l=0 and r=0, so the entry corresponding to this is 0

            now our l=0 and r=1,
                in this particular example of string we'll have just 'a'
                the entry corresponding to this will be 1

            now our l=0 and r=2
                in this particular example of string we'll have now "ab"
                the entry corresponding to this will be 3
                (as the final string will be "abb")

            now our l=0 and r=3
                in this particular example of string we'll have now "abc"
                the entry corresponding to this will be 6
                (as the final string will be "abbccc") and so on

        -------

        Another example of creating our dp array:
            suppose our string is "aeb"

            so, initially our dp array will look like this:

                0 1 2 3
                0 0 0 0
            
            calculating for 'a' -> Alphabetical value of 'a' + value before
                = 1 + 0
                = 1

                0 1 2 3
                0 1 0 0

            calculating for 'e' -> Alphabetical value of 'e' + value before
                = 5 + 1
                = 6

                0 1 2 3
                0 1 6 0

            calculating for 'b' -> Alphabetical value of 'b' + value before
                = 2 + 6
                = 8

                0 1 2 3
                0 1 6 8

    -------

    How to answer queries:

        Suppose we got a query of: l=3 and r=5
            here the answer will be:
                (value at dp array at index5) - (value at ap array at index3 - 1)

        -------

    So this way of calculating the result will be valid for only the string
        which we have worked on (or have our dp array based upon), 
        the value is not generalized
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        ll dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + ((s[i - 1] - 'a' + 1));
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << dp[r] - dp[l - 1] << '\n';
        }
    }
}