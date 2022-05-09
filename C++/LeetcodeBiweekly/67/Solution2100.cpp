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
