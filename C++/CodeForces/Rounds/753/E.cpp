#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		string s;
		cin>>s;
		int totX=0, totY=0;
		int xLeft=0, xRight=0;
		int yUp=0, yDown=0;
		for(char c: s){
			if(c=='L'){
				xLeft=min(xLeft, --totY);
			} else if(c=='R'){
				xRight=max(xRight, ++totY);
			} else if(c=='U'){
				yUp=min(yUp, --totX);
			} else{
				yDown=max(yDown, ++totX);
			}
			if(xRight-xLeft>=m){
				if(totY==xLeft){
					xLeft++;
				}
				break;
			}
			if(yDown-yUp>=n){
				if(totX==yUp){
					yUp++;
				}
				break;
			}
		}
		cout<<1-yUp<<" "<<1-xLeft<<"\n";
	}
}

