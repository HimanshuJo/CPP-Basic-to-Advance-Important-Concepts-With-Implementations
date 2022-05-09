/*

Aleksey has n friends. He is also on a vacation right now, so he has m days to play this new viral cooperative game! 
But since it's cooperative, Aleksey will need one teammate in each of these m days.

On each of these days some friends will be available for playing, and all others will not. 
On each day Aleksey must choose one of his available friends to offer him playing the game (and they, of course, always agree). 

However, if any of them happens to be chosen strictly more than ceil (m / 2) times, then all other friends are offended. 
Of course, Aleksey doesn't want to offend anyone.

Help him to choose teammates so that nobody is chosen strictly more than ceil (m / 2) times.

-------

Input

Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 10000). 

Description of the test cases follows.

The first line of each test case contains two integers n and m (1 ≤ n,m ≤ 100000) standing for the number of friends and 
the number of days to play, respectively.

The i-th of the following m lines contains an integer ki (1 ≤ ki ≤ n), followed by ki distinct integers 
fi1, ..., fiki (1 ≤ fij ≤ n), separated by spaces — indices of available friends on the day i


It is guaranteed that the sums of n and m over all test cases do not exceed 100000. 
It's guaranteed that the sum of all ki over all days of all test cases doesn't exceed 200000.

E.g.

4 6
1 1
2 1 2
3 1 2 3
4 1 2 3 4
2 2 3
1 3

Suppose here we have 6 days and 4 friends to choose for each day

Intution:

    We create an array of size m (number of days), and fill in the respective indexes, the suitable choice of the friend

        in the first day we have just 1 friend (friend 1) 

        in the second day we have 2 friends (friend 1 and friend 2)

        in the third day we have 3 friends (friend 1, friend 2 and friend 3)

        in the fourth day we have 4 friends (friend 1, friend 2, friend 3 and friend 4)

        in the fifth day we have 2 friends (friend 2, and friend 3)

        in the last day we have 2 friends (friend 1 and friend 3)

    -------

Algo:

    The approach we can follow is 'Greedy'

        Because if we don't fill the indexes, which have the limited availablity of friends

            then in future we might encounter a problem, that we reach to an index which have an availablity of a friend, but we have
                already used that friend in earlier places (since there is a limitation, for a particular friend, how many times we 
                can use him / her)

        so at those indexes, we will already fill the friends who are available

        then in the future if we have another choice of the same friend for some other place, we can suitably fill that
            or fill other friend in the day

        Using this approach, if at a certain point we arise at a day we cannot fill any friend, then we are sure
            that the answer is not possible

    -------

    For each day we can note down the frequency of friends in a list
        then we can sort them according to their sizes

        for example: let left side is 'Day' and the right side is 'No of available friends for that day'

            1 --> 1
            6 --> 1
            2 --> 2
            5 --> 2
            3 --> 3
            4 --> 3

/**/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main() {
    int t = 1;
    cin >> t;
    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        vector<int> a[m + 1]; // for the days
        vector<pair<int, int>> vv;  // for the frequencies
        int ans[m + 1] = {0};
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            for (int j = 0; j < x; ++j) {
                int tt;
                cin >> tt;
                a[i + 1].push_back(tt);
            }
            vv.push_back({x, i + 1});  // vector's first value is the frequency of friends, and the second is the day
        }
        sort(vv.begin(), vv.end());
        map<int, int> mm;  // for frequency count
        for (int i = 0; i < vv.size(); ++i) {
            for (int j = 0; j < a[vv[i].second].size(); ++j) {  // go into that day, take the first element on that day, check its frequency
                if (mm[a[vv[i].second][j]] < (m + 1) / 2) {
                    ans[vv[i].second] = a[vv[i].second][j];
                    mm[a[vv[i].second][j]]++;
                    break;  // for that day we have found our friend
                }
            }
        }
        int flag = 1;
        for (int i = 1; i <= m; ++i)  // if we haven't found any friend on any day
            if (ans[i] == 0) {
                flag = 0;
                break;
            }
        if (flag == 0) cout << 0 << " NO";
        else {
            cout << "YES" << endl;
            for (int i = 0; i <= m; ++i) {
                cout << ans[i] << " ";
            }
        }
        cout << endl;
    }
}