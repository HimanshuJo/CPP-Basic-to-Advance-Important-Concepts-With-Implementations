// Addition with bitwise operators

#include<iostream>
#include<vector>
using namespace std;

class Solution1{
	public:
	int addNums(int a, int b){
		while(b!=0){
			int sum=a^b;  // add without carry
			int carry=(a&b)<<1;  // carry but don't add;
			a=sum;
			b=carry;
		}
		return a;
	}
};

// -------*******-------

class Solution2{
public:

	int dfs(int a, int b){
		if(b==0) return a;
		int sum=a^b;
		int carry=(a&b)<<1;
		return dfs(sum, carry);
	}

	int addNums(int a, int b){
		return dfs(a, b);
	}
};

int main(){
	int a=14, b=15;
	Solution1 obj1;
	Solution2 obj2;
	int ans=obj1.addNums(a, b);
	int ans2=obj2.addNums(a, b);
	cout<<ans<<endl;
	cout<<ans2;
}
