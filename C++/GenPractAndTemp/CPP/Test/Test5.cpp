#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int calDist(int currx, int curry, int nxtx, int nxty){
	return abs(nxtx-currx)+abs(nxty-curry);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, m, sx, sy, d;
		cin>>n>>m>>sx>>sy>>d;
		int val1=calDist(1, 1, sx, sy);
		int val2=sy-1, val3=n-sx, val4=m-sy, val5=sx-1;
		int val6=calDist(n, m, sx, sy);
		if(val1<=d||val6<=d){
			cout<<-1<<endl;
		} else if((val2>d&&val3>d)||(val4>d&&val5>d)){
			cout<<calDist(1, 1, n, m)<<endl;
		} else{
			cout<<-1<<endl;
		}
	}
}