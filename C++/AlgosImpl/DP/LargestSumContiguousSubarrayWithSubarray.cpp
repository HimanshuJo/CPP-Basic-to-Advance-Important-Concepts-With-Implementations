// Largest Sum Contiguous Subarray
/*
Write an efficient program to find the sum of contiguous subarray within a 
one-dimensional array of numbers that has the largest sum. 
*/
/*
Kadane’s Algorithm:

Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far
*/

/*
Finding largest sum contigous subarray begin and last index

begin index:

	Since maxSumEndingHere is always updated to max(0, maxSumEndingHere+arr[idx])
	using a temp vector and pushing back indexes when it is >=0 and clearing it when not, will always
	place the best begin index in the vector(for let's say the ideal subarray A)

end index:

	we'll push back the maxSumSoFar in the vector as a second pair
	in the end the last entry of the vector will point to the largest subarray sum(for let's say the ideal subarray A)

	if in the last couple of entries in the vector the maxSumSoFar has remained same, adding those
	entries in the vector prvoides no benefit
	traverse from the end and reach to the entry which is the first one pointing to the largest maxSumSoFar
*/

#include<vector>
#include<iostream>
using namespace std;

vector<pair<int, int>>subarray;

int maxRunningSm(vector<int>&in, int sz){
	int maxSumEndingHere=0, maxSumSoFar=0, tempmaxsumending=0;
	for(int i=0; i<sz; ++i){
		tempmaxsumending=maxSumEndingHere;
		maxSumEndingHere=max(0, maxSumEndingHere+in[i]);
		maxSumSoFar=max(maxSumSoFar, maxSumEndingHere);
		if(tempmaxsumending+in[i]>=0) subarray.push_back({i, maxSumSoFar});
		else subarray.clear();
	}
	return maxSumSoFar;
}

pair<int, int> longestSumContiguousSubarray(vector<int>&in){
	int bgnIdx=0, endIdx=0, tochk=0;
	int sz_=subarray.size();
	int temp=subarray[sz_-1].second;
	int idx=sz_-1;
	while(subarray[idx].second==temp){
		idx--;
	}
	idx++;
	/*for(int i=0; i<=idx; ++i){
		cout<<subarray[i].first<<" "<<subarray[i].second<<endl;
		tochk+=in[subarray[i].first];
	}*/
	bgnIdx=subarray[0].first, endIdx=subarray[idx].first;
	return {bgnIdx, endIdx};
}

int main(){
	vector<int>in{-2, -3, -4, -1, -2, 1, 5, -3, 11, 23, -4, 
	               56, 11, -34, -7, -34, -9, -12};
	int sz=in.size();
	int ans=maxRunningSm(in, sz);
	cout<<ans<<endl;
	cout<<"-------\n";
	pair<int, int>res=longestSumContiguousSubarray(in);
	cout<<res.first<<" "<<res.second<<endl;
}