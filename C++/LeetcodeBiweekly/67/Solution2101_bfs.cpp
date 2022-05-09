using ll= long long;

class Solution {
public:

	bool isValid(ll x1, ll y1, ll x2, ll y2, ll r){
		return (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))<=r);
	}

    int maximumDetonation(vector<vector<int>>& bombs) {
    	const int sz=bombs.size();
		vector<vector<int>>gr(sz);
		for(int i=0; i<sz; ++i){
			ll r=(ll)bombs[i][2]*bombs[i][2];
			ll x1=bombs[i][0], y1=bombs[i][1];
			for(int j=0; j<sz; ++j){
				if(i!=j){
					ll x2=bombs[j][0], y2=bombs[j][1];
					if(isValid(x1, y1, x2, y2, r)){
						gr[i].push_back(j);
					}
				}
			}
		}
		int ans=1;
		for(int i=0; i<sz; ++i){
			vector<bool>seen(sz, false);
			int maxx=0;
			queue<int>q;
			q.push(i);
			while(!q.empty()){
				int len=q.size();
				while(len--){
					int curr=q.front();
					q.pop();
					seen[curr]=true;
					maxx++;
					for(auto &nei: gr[curr]){
						if(!seen[nei]){
							q.push(nei);
							seen[nei]=true;
						}
					}
				}
			}
			ans=max(maxx, ans);
		}
		return ans;
    }
};

