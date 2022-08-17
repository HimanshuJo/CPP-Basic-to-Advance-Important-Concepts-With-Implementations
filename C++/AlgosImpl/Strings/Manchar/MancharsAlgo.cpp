/*
*/

#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

/*
Algo:

	Let s="abcdcba"
	s=$abcdcba^
	res=[0, 0, 0, 0, 0, 0, 0, 0, 0]
	letB=1, rightB=1
	L1:

		res[1]=max(0, min(1-1, res[1+(1-1)]))
		      =max(0, min(0, 0))
			  =0

		while

			L1

				s[1-0]==s[1+0]
				res[1]++
				res[1]=1

			L2

				s[1-1]!=s[1+1]
				break

		if

			1+1>rightB(1)
				rightB=2, leftB=0

	L2:

		res[2]=max(0, min(2-2, res[0+res[2-2]]))
		      =max(0, min(0, 0))
			  =0

		while

			L1

				s[2-0]==s[2+0]
				res[2]++
				res[2]=1

			L2

				s[2-1]!=s[2+1]
				break

		if

			2+1>rightB(2)
				rightB=3, leftB=1

	...

	L4:

		res[4]=max(0, min(4-4, res[2+(4-4)]))
		      =max(0, min(0, 1))
			  =0

		while

			L1

				s[4-0]==s[4+0]
				res[4]=1

			L2

				s[4-1]==s[4+1]
				res[4]=2

			L3

				s[4-2]==s[4+2]
				res[4]=3

			L4

				s[4-3]==s[4+3]
				res[4]=4

			L5

				s[4-4]!=s[4+4]
				break

		if
			4+4>rightB(4)
			rightB=8, leftB=0
*/

vector<int> manacherOdd(string str){
	int sz=str.size();
	str="$"+str+"^";
	vector<int>res(sz+2);
	int leftB=1, rightB=1;
	for(int i=1; i<=sz; ++i){
		res[i]=max(0, min(rightB-i, res[leftB+(rightB-i)]));
		/*
			taking into account the current index as the center
			how much far in left and right I can stretch the current boundary
			such that the current substring is still a palindrome
		*/
		while(str[i-res[i]]==str[i+res[i]]){
			res[i]++;
		}
		if(i+res[i]>rightB){
			leftB=i-res[i], rightB=i+res[i];
		}
	}
	return res;
}

int main(){
	string str="abcdcba";
	vector<int>ans=manacherOdd(str);
	for(auto &vals: ans){
		cout<<vals<<" ";
	}
}