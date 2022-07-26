// 2055. Plates Between Candles
/*
There is a long table with a line of plates and candles arranged on top of it. 
You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' 
represents a plate and a '|' represents a candle.

You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] 
denotes the substring s[lefti...righti] (inclusive). 

For each query, you need to find the number of plates between candles that are in the substring. 
A plate is considered between candles if there is at least one candle to its left and at least 
one candle to its right in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". 

The number of plates between candles in this substring is 2, as each of the two plates has at 
least one candle in the substring to its left and right.

Return an integer array answer where answer[i] is the answer to the ith query.

Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]
Explanation:
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.

Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
Output: [9,0,0,0,0]
Explanation:
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.

Constraints:

3 <= s.length <= 10^5
s consists of '*' and '|' characters.
1 <= queries.length <= 10^5
queries[i].length == 2
0 <= lefti <= righti < s.length
*/

class Solution {
	public:
		int n;
		vector<int>tree;

		void build(vector<int>&arr){
			for(int i=0; i<n; i++)   
				tree[n+i]=arr[i];
			for(int i=n-1; i>0; --i)    
				tree[i]=tree[i<<1]+tree[i<<1|1];   
		}

		void updateTreeNode(int p, int value){
			tree[p+n]=value;
			p=p+n;
			for(int i=p; i>1; i>>=1)
				tree[i>>1]=tree[i]+tree[i^1];
		}

		int query(int l, int r){
			int res=0;
			for(l+=n, r+=n; l<r; l>>=1, r>>=1){
				if(l&1)
					res+=tree[l++];
				if(r&1)
					res+=tree[--r];
			}
			return res;
		}

		vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
            int N_=s.length();
            tree.resize(3e5+1);
            n=N_;
            vector<int>temp;
			vector<int>a(N_);
			for(int i=0; i<N_; ++i){
				if(s[i]=='*'){
					a[i]=1;
				} else{
                    temp.push_back(i);
                    a[i]=0;
                }
			}
			build(a);
			vector<int>res;
			for(auto &vals: queries){
				int bgn=vals[0];
                int end=vals[1];
                if(a[bgn]!=0){
                    auto it=lower_bound(temp.begin(), temp.end(), vals[0]);
                    if(it==temp.end()){
                        bgn=vals[1];
                    } else{
                        bgn=temp[lower_bound(temp.begin(), temp.end(), vals[0])-temp.begin()];   
                    }
                }
                if(a[end]!=0){
                    auto iter=std::lower_bound(temp.rbegin(), temp.rend(), vals[1], std::greater<int>());
                    if(iter == temp.rend()){
                        end=vals[0];
                    } else{
                        end=*iter;
                    }
                }
				res.push_back(query(bgn, end));
			}
			return res;
		}
};