/*
	Randomly generate a set of m integers from an array of size n. Each element must have an equal probability of
	being chosen
*/
/*
	Algo:

		We can first pull a random set of size m from the first n-1 elements

		Then we just need to decide if vec[n] should be inserted into our subset(which would require pulling
		out a random element from it)

			We can pick a random number k from 0 through n

				If k<m then we will insert array[n] into subset[k]
				This will both "fairly"(i.e with proportional probability) insert array[n]
				into the subset and "fairly" removes a random element from the subset
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution1{
public:
	vector<int> dfs(vector<int>&original, int m, int i){
		if(i+1<m){
			return {0};
		} else if(i+1==m){
			// copying first m elements into the array
			vector<int>vec(m);
			for(int k=0; k<m; ++k){
				vec[k]=original[k];
			}
			return vec;
		} else{
			vector<int>vec=dfs(original, m, i-1);
			int randNum=rand()%(i+1);
			if(randNum<m){
				vec[randNum]=original[i];
			}
			return vec;
		}
	}

	vector<int> pickRandom(vector<int>&original, int m, int i){
		return dfs(original, m, i);
	}
};

// -------*******-------

class Solution2{
public:
	vector<int>pickRandom(vector<int>&original, int m){
		int sz=original.size();
		if(m>sz) return {0};
		vector<int>subset(m);
		for(int i=0; i<m; ++i){
			subset[i]=original[i];
		}
		for(int i=m; i<sz; ++i){
			int randNum=rand()%(i+1);
			if(randNum<m){
				subset[randNum]=original[i];
			}
		}
		return subset;
	}
};

int main(){
	Solution1 obj1;
	Solution2 obj2;
	vector<int>original{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15};
	int sz=original.size();
	vector<int>ans1=obj1.pickRandom(original, 4, sz);
	vector<int>ans2=obj2.pickRandom(original, 4);
	for(auto &vals: ans1){
		cout<<vals<<" ";
	}
	cout<<"\n-------\n";
	for(auto &vals: ans2){
		cout<<vals<<" ";
	}
}