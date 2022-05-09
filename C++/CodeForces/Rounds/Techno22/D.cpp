// D. Yet Another Sorting Problem
/*
Petya has an array of integers a1,a2,…,an. He only likes sorted arrays. Unfortunately, the given array could be arbitrary, so Petya wants to sort it.

Petya likes to challenge himself, so he wants to sort array using only 3-cycles. More formally, in one operation he can pick 3 pairwise 
distinct indices i, j, and k (1<=i,j,ky=n) and apply i→j→k→i cycle to the array a. It simultaneously places ai on position j, aj on position k, and ak on 
position i, without changing any other element.

For example, if a is [10,50,20,30,40,60] and he chooses i=2, j=1, k=5, then the array becomes [50_,40_,20,30,10_,60].

Petya can apply arbitrary number of 3-cycles (possibly, zero). You are to determine if Petya can sort his array a, i. e. make it non-decreasing.

Example
input
7
1
1
2
2 2
2
2 1
3
1 2 3
3
2 1 3
3
3 1 2
4
2 1 4 3
output
YES
YES
NO
YES
NO
YES
YES
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
using ll=long long;

ll cnt=0;

vector <int> merge(vector <int> l, vector <int> r)
{
    vector <int> ans;
    int i = 0; int j = 0;
    while (i < l.size() && j < r.size())
    {
        if (l[i] <= r[j])
        {
            ans.push_back(l[i++]);
        }
        else
        {
            ans.push_back(r[j++]);
            cnt += (long long)l.size() - i;
        }
    }
    while (i + j < l.size() + r.size())
    {
        if (i < l.size())
        {
            ans.push_back(l[i++]);
        }
        else
        {
            ans.push_back(r[j++]);
        }
    }
    return ans;
}

vector <int> mergeSort(vector <int> &v, int l, int r)
{
    if (l == r)
    {
        return { v[l] };
    }
    else
    {
        vector <int> lv = mergeSort(v, l, (l + r) / 2);
        vector <int> rv = mergeSort(v, (l + r) / 2 + 1, r);
        return merge(lv, rv);
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n; 
		cin>>n;
		vector<int>in(n);
		unordered_set<int>st;
		for(int i=0; i<n; ++i){
			cin>>in[i];
			st.insert(in[i]);
		}
		cnt=0;
		mergeSort(in, 0, n-1);
		if(cnt%2==0||st.size()<in.size()){
			cout<<"YES\n";
		} else{
			cout<<"NO\n";
		}
	}
}
