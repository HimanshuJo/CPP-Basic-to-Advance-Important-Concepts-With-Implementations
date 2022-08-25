/*
This is an interactive problem.

Note: the XOR-sum of an array a1,a2,…,an (1≤ai≤109) is defined as a1⊕a2⊕…⊕an, 
    where ⊕ denotes the bitwise XOR operation.

Little Dormi received an array of n integers a1,a2,…,an for Christmas. 
However, while playing with it over the winter break, he accidentally 
dropped it into his XOR machine, and the array got lost.

The XOR machine is currently configured with a query size of k
(which you cannot change), and allows you to perform the following type of query: 
by giving the machine k distinct indices x1,x2,…,xk, 
it will output ax1⊕ax2⊕…⊕axk

As Little Dormi's older brother, you would like to help him recover the 
XOR-sum of his array a1,a2,…,an by querying the XOR machine.

Little Dormi isn't very patient, so to be as fast as possible, 
you must query the XOR machine the minimum number of times to find 
the XOR-sum of his array. Formally, let d
be the minimum number of queries needed to find the XOR-sum of any 
array of length n with a query size of k. 

Your program will be accepted if you find the correct XOR-sum in at 
most d queries.

Lastly, you also noticed that with certain configurations of the machine k
and values of n, it may not be possible to recover the XOR-sum of Little Dormi's 
lost array. 

If that is the case, you should report it as well.

The array a1,a2,…,an is fixed before you start querying the XOR machine 
and does not change with the queries.

Input

The only line of input contains the integers n and k (1≤n≤500, 1≤k≤n), 
the length of the lost array and the configured query size of the XOR machine.

Elements of the original array satisfy 1≤ai≤10^9

It can be proven that that if it is possible to recover the XOR sum 
under the given constraints, it can be done in at most 500
queries. That is, d≤500

After taking n and k, begin interaction.

Output

If it is impossible to recover the XOR-sum of the array, output −1
immediately after taking n and k

Do not begin interaction.

Otherwise, when your program finds the XOR-sum of the lost array a1,a2,…,an
, report the answer in the following format: "! x", 
where x is the XOR sum of the array a1,a2,…,an, and terminate your program 
normally immediately after flushing 
the output stream.

Note that answering does not count as a query.
Interaction

Each query is made in the format "? b", where b
is an array of exactly k distinct integers from 1 to n
denoting the indices of the elements in the lost array that you want to 
query the XOR sum of.

You will then receive an integer x
, the XOR sum of the queried elements. 

It can be proven that 0≤x≤2⋅10^9 will always be true.

After printing a query do not forget to output end of line and flush the output.

Otherwise, you will get Idleness limit exceeded. To do this, use:

    fflush(stdout) or cout.flush() in C++;
    System.out.flush() in Java;
    flush(output) in Pascal;
    stdout.flush() in Python;
    see documentation for other languages.

If at any point you make an invalid query or try to make more than 500
queries (which is the hard limit), the interaction will terminate 
immediately and give you a Wrong Answer verdict. 

Note that if you exceed d queries, the interaction will continue
normally unless you also exceed the 500 query hard limit, though you will 
still receive a Wrong Answer verdict either way.

Hacks

To hack a solution, use the following format.

The first line contains the integers n
and k (1≤n≤500, 1≤k≤n).

The second line contains the the array a1,a2,…,an (1≤ai≤10^9).
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f;

const int MN = 2001;
int N, K, dis[MN], par[MN];

int main()
{
    cin >> N >> K;
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    dis[0] = 0;
    par[0] = -1;
    q.push(0);
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for (auto i = 0; i <= K; i++)
        {
            if (i <= N - c && K - i <= c)
            {
                int to = c + i - (K - i);
                if (dis[to] == INF)
                {
                    dis[to] = dis[c] + 1;
                    par[to] = c;
                    q.push(to);
                }
            }
        }
    }
    if (dis[N] == INF)
        cout << "-1\n";
    else
    {
        vector<int> sel, nosel(N);
        iota(nosel.begin(), nosel.end(), 1);

        // get ans
        vector<int> path;
        for (auto c = N; c != -1; c = par[c])
            path.push_back(c);
        reverse(path.begin(), path.end());
        int sz = path.size(), ans = 0;
        for (auto i = 0; i < sz - 1; i++)
        {
            int a = path[i], b = path[i + 1], d = b - a, nsel = (d + K) / 2, nnosel = K - nsel;
            assert((d + K) % 2 == 0);
            vector<int> cnosel, csel;
            for (auto j = 0; j < nsel; j++)
            {
                csel.push_back(nosel.back());
                nosel.pop_back();
            }
            for (auto j = 0; j < nnosel; j++)
            {
                cnosel.push_back(sel.back());
                sel.pop_back();
            }
            cout << "? ";
            for (auto x : csel)
                cout << x << ' ';
            for (auto x : cnosel)
                cout << x << ' ';
            cout << '\n';
            cout.flush();
            nosel.insert(nosel.end(), cnosel.begin(), cnosel.end());
            sel.insert(sel.end(), csel.begin(), csel.end());
            int res;
            cin >> res;
            ans ^= res;
        }
        assert(nosel.empty());
        cout << "! " << ans << '\n';
        cout.flush();
    }
}