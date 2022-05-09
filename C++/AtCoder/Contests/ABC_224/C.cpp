#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);    
}

int countTriangles(pair<int, int> P[], int N)
{
	map<pair<int, int>, int> mp;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		mp.clear();
		for (int j = i + 1; j < N; j++)
		{
			int X = P[i].first - P[j].first;
			int Y = P[i].second - P[j].second;
			int g = gcd(X, Y);
			X /= g;
			Y /= g;
			mp[{X, Y}]++;
		}
		int num = N - (i + 1);
		ans += (num * (num - 1)) / 2;
		for (auto j : mp)
			ans -= (j.second * (j.second - 1)) / 2;
	}
	return ans;
}


int main(){
    int N;
    cin>>N;
    pair<int, int>P[N];
    for(int i=0; i<N; ++i){
        int x, y;
        cin>>x>>y;
        P[i]={x, y};
    }
    int ans=countTriangles(P, N);
    cout<<ans;
}