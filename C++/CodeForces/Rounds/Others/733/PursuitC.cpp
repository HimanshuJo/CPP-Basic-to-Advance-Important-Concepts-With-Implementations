/*
You and your friend Ilya are participating in an individual programming contest 
consisting of multiple stages. A contestant can get between 0 and 100 points, inclusive, 
for each stage, independently of other contestants.

Points received by contestants in different stages are used for forming overall contest results. 
Suppose that k stages of the contest are completed. For each contestant, k−⌊k/4⌋ stages with 
the highest scores are selected, and these scores are added up. This sum is the overall result 
of the contestant. (Here ⌊t⌋ denotes rounding t down.)

For example, suppose 9 stages are completed, and your scores are 50,30,50,50,100,10,30,100,50. 
First, 7 stages with the highest scores are chosen — for example, all stages except for the 
2-nd and the 6-th can be chosen. Then your overall result is equal to 50+50+50+100+30+100+50=430.

As of now, n stages are completed, and you know the points you and Ilya got for 
these stages. However, it is unknown how many more stages will be held. 
You wonder what the smallest number of additional stages is, after which your result might become
 greater than or equal to Ilya's result, at least in theory. Find this number!
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<int> frA;
        priority_queue<int> frB;
        int count1 = 0;
        int count2 = 0;
        int x = n - (n / 4);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int in;
            cin >> in;
            frA.push(in);
        }
        for (int i = 0; i < n; ++i)
        {
            int in;
            cin >> in;
            frB.push(in);
        }
        deque<int> dA;
        deque<int> dB;
        for (int i = 0; i < x; ++i)
        {
            count1 += frA.top();
            dA.push_back(frA.top());
            frA.pop();
            count2 += frB.top();
            frB.pop();
        }
        while (!frB.empty())
        {
            dB.push_back(frB.top());
            frB.pop();
        }
        while (count1 < count2)
        {
            ans++;
            n++;
            if (n % 4 == 0)
            {
                if (!dA.empty())
                {
                    count1 += (100 - dA.back());
                    dA.pop_back();
                }
            }
            else
            {
                count1 += 100;
                if (!dB.empty())
                {
                    count2 += dB.front();
                    dB.pop_front();
                }
            }
        }
        cout << ans << "\n";
    }
}