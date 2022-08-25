#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin>>n>>q;
	string s;
	cin>>s;
	map<pair<int, int>, int>memo;
	vector<int>ans(q);
	for(int i=0; i<q; ++i){
		int t, l, r;
		cin>>t>>l>>r;
		l--, r--;
		string curr=s.substr(l, (r-l)+1);
		int len=curr.length();
		stack<char>stk;
		int count=0;
		int left=0, right=len-1;
		bool flag=false;
		while(left<right){
			if(curr[left]=='('){
				stk.push(curr[left]);
			}
			if(curr[right]==')'&&left!=right-1){
				if(!stk.empty()){
					stk.pop();
					count++;
				}
			}
			left++, right--;
            int tmpl=l+left, tmpr=r-left;
			if(memo.find({tmpl, tmpr})!=memo.end()){
				count+=memo[{tmpl, tmpr}];
				ans[i]=count;
				memo[{l, r}]=count;
				flag=true;
				break;
			}
			if(flag) break;
		}
		if(!flag){
			while(!stk.empty()) stk.pop();
			for(int i_=l; i_<=r; ++i_){
				if(s[i_]=='('){
					stk.push(s[i_]);
				} else{
					if(!stk.empty()){
						stk.pop();
						count++;
					}
				}
			}
			ans[i]=count;
			memo[{l, r}]=count;
		}
	}
    for(auto &vals: ans)
        cout<<vals<<endl;
}

