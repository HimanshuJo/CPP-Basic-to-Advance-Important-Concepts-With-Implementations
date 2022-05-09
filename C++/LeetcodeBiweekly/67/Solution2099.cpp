#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
  		int n=nums.size();
		vector<pair<int, int>>temp;
		for(int i=0; i<n; ++i){
			temp.push_back({nums[i], i});
		}
		sort(temp.begin(), temp.end());
		for(auto &vals: temp)
			cout<<vals.first<<" "<<vals.second<<" , ";
		cout<<endl;
		cout<<"-------\n";
		for(auto &vals: temp)
			cout<<vals.first<<" "<<vals.second<<" , ";
		cout<<endl;
		vector<int>ans;
		for(int i=n-1; i>=n-k; --i){
			ans.push_back(temp[i].second);
		}
		sort(ans.begin(), ans.end());
		for(int i=0; i<k; ++i){
			ans[i]=nums[ans[i]];
		}
		for(auto &vals: ans)
			cout<<vals<<" ";
		return ans;
    }
};

int main(){
	Solution obj;
	vector<int>nums{-1,-2,3,4};
	int k=3;
	obj.maxSubsequence(nums, k);
}
