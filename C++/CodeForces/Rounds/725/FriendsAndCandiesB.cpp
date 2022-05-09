#include <bits/stdc++.h>
using namespace std;

/*
Polycarp has n friends, the i-th of his friends has ai candies. 
Polycarp's friends do not like when they have different numbers of candies. 
In other words they want all ai to be the same. To solve this, 
Polycarp performs the following set of actions exactly once:

    Polycarp chooses k(0≤k≤n) arbitrary friends (let's say he chooses friends with indices i1,i2,…,ik);

    Polycarp distributes their ai1+ai2+…+aik candies among all n friends. 
    
    During distribution for each of ai1+ai2+…+aik candies he chooses new owner. 
    
        That can be any of n friends. Note, that any candy can be given to the person, who has owned 
        that candy before the distribution process. 

    Note that the number k is not fixed in advance and can be arbitrary. Your task is to find the 
        minimum value of k

    For example, if n=4 and a=[4,5,2,5], then Polycarp could make the following distribution of the candies:

    Polycarp chooses k=2 friends with indices i=[2,4] and distributes a2+a4=10 candies to 
        make a=[4,4,4,4] (two candies go to person 3). 

    Note that in this example Polycarp cannot choose k=1 friend so that he can redistribute candies so that 
        in the end all ai are equal.

    For the data n and a, determine the minimum value k. With this value k, Polycarp should be 
        able to select k friends and redistribute their candies so that everyone will end up with the 
        same number of candies.
*/

/*
Let's denote for s the number of candies all friends have: s=∑i=1nai. 

    Note that at the end, each friend must have sn of candy. 
    
    If s is not completely divisible by n, then there is no answer.

    How to get the answer if it exists? If the i -th friend has more candies than s/n, 
        then he must be chosen by Polycarp (otherwise this friend will have more candies than the others). 
        
        If the i-th friend has no more than sn , then Polycarp may not choose it.

    Then, if the answer exists, it is equal to the number of ai>s/n.
*/

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
        int arr[n];
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum % n != 0)
        {
            cout << -1 << "\n";
            continue;
        }
        sum /= n;
        int res = 0;
        for (int num : arr)
        {
            if (num > sum)
            {
                res++;
            }
        }
        cout << res << "\n";
    }
}