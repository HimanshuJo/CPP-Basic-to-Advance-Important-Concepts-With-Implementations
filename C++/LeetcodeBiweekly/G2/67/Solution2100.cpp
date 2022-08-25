// 2100. Find Good Days to Rob the Bank
/*
You and a gang of thieves are planning on robbing a bank. 

You are given a 0-indexed integer array security, where security[i] is the 
number of guards on duty on the ith day. The days are numbered starting from 0. 

You are also given an integer time.

The ith day is a good day to rob the bank if:

There are at least time days before and after the ith day,
The number of guards at the bank for the time days before i are non-increasing, and
The number of guards at the bank for the time days after i are non-decreasing.

More formally, this means day i is a good day to rob the bank if and only if 

security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].

Return a list of all days (0-indexed) that are good days to rob the bank. 
The order that the days are returned in does not matter.


Example 1:

Input: security = [5,3,3,3,5,6,2], time = 2
Output: [2,3]
Explanation:
On day 2, we have security[0] >= security[1] >= security[2] <= security[3] <= security[4].
On day 3, we have security[1] >= security[2] >= security[3] <= security[4] <= security[5].
No other days satisfy this condition, so days 2 and 3 are the only good days to rob the bank.
Example 2:

Input: security = [1,1,1,1,1], time = 0
Output: [0,1,2,3,4]
Explanation:
Since time equals 0, every day is a good day to rob the bank, so return every day.
Example 3:

Input: security = [1,2,3,4,5,6], time = 2
Output: []
Explanation:
No day has 2 days before it that have a non-increasing number of guards.
Thus, no day is a good day to rob the bank, so return an empty list.
 

Constraints:

1 <= security.length <= 10^5
0 <= security[i], time <= 10^5
*/

/* TLE: 127 / 144

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
		vector<int>ans;
		for(int i=0; i<n; ++i){
			if(i-time>=0&&i+time<=n-1){
				int bgn=i-time;
				int end=i+time;
				int toChk=security[i];
				int curr=security[bgn];
				bool flag=false;
				for(int x=bgn; x<i; ++x){               
					if(security[x]<=curr&&security[x]>=toChk){
                        curr=security[x];
					} else{
                        flag=true;
						break;
                    }
				}
				if(!flag){
					int curr_=security[i+1];
					bool flag_=false;
					for(int x=i+1; x<=end; ++x){
						if(security[x]>=curr_&&security[x]>=toChk){
                            curr_=security[x];
						} else{
                            flag_=true;
							break;
                        }
					}
					if(!flag_){
						ans.push_back(i);
					}
				}
			}
		}
		return ans;
    }
};
*/
/*
Algo:

For every index we will find number of previous elements that follows this pattern 
security[i - time] >= security[i - time + 1] and it's easy to find you can see in the code and 
we store this info in prefix array.

For every index we will find number of elements that are ahead of current element which follows 
this pattern security[i + time - 1] <= security[i + time] and it's easy to find you can see in 
the code and we store this info in suffix array.

To find good days just traverse the array and check this condition pre[i]-1>=time && suf[i]-1>=time.

Note:- I am subtracting 1 in above line because i have included current element in cnt.

If you want, you can avoid to use prefix array and can calculate when you are calculating answer.

*/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int size=s.size(),cnt=1;
        vector<int>pre(size,0),suf(size,0);
        pre[0]=1;
        for(int i=1;i<size;i++){
            if(s[i]<=s[i-1])
                cnt++;
            else
                cnt=1;
             pre[i]=cnt;
        }
        suf[size-1]=1;cnt=1;
        for(int i=size-2;i>=0;i--){
            if(s[i]<=s[i+1])
                cnt++;
            else
                cnt=1;
            suf[i]=cnt; 
        }
        vector<int>ans;
        for(int i=0;i<size;i++)
            if(pre[i]-1>=time && suf[i]-1>=time)
                ans.push_back(i);
        return ans;
    }
};