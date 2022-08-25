// 84. Largest Rectangle in Histogram
/*
Find the largest rectangular area possible in a given histogram where the 
largest rectangle can be made of a number of contiguous bars. 

For simplicity, assume that all bars have same width and the width is 1 unit. 
For example, consider the following histogram with 7 bars of heights {6, 2, 5, 4, 5, 1, 6}. 
The largest possible rectangle possible is 12

-------

Solution:

A simple solution is to one by one consider all bars as starting points and calculate area of all 
rectangles starting with every bar. Finally return maximum of all possible areas. 

Time complexity of this solution would be O(n^2).

We can use Divide and Conquer to solve this in O(nLogn) time. 
The idea is to find the minimum value in the given array. 
Once we have index of the minimum value, the max area is maximum of following three values. 

a) Maximum area in left side of minimum value (Not including the min value) 
b) Maximum area in right side of minimum value (Not including the min value) 
c) Number of bars multiplied by minimum value.

The areas in left and right of minimum value bar can be calculated recursively. 
If we use linear search to find the minimum value, 

then the worst case time complexity of this algorithm becomes O(n^2). 
In worst case, we always have (n-1) elements in one side and 0 elements in other side 
and if the finding minimum takes O(n) time, we get the recurrence similar to worst case of Quick Sort.

-------

How to find the minimum efficiently? 

Range Minimum Query using Segment Tree can be used for this. 
We build segment tree of the given histogram heights. 
Once the segment tree is built, all range minimum queries take O(Logn) time. 
So over all complexity of the algorithm becomes.

Overall Time = Time to build Segment Tree + Time to recursively find maximum area

Time to build segment tree is O(n). Let the time to recursively find max area be T(n). It can be written as following. 
T(n) = O(Logn) + T(n-1) 
The solution of above recurrence is O(nLogn). So overall time is O(n) + O(nLogn) which is O(nLogn)
*/

#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

int max(int x, int y, int z){
	return max(max(x, y), z);
}

int minVal(vector<int>&hist, int i, int j){
	if(i==-1) return j;
	if(j==-1) return i;
	return (hist[i]<hist[j])?i:j;
}

int getMid(int s, int e){
	return (s+(e-s)/2);
}

int RMQUtil(vector<int>&hist, vector<int>&st, int ss, int se, int qs, int qe, int sidx){
	if(se<qs||ss>qe) return -1;
	if(ss>=qs&&se<=qe) return st[sidx];
	int mid=getMid(ss, se);
	return (minVal(hist, RMQUtil(hist, st, ss, mid, qs, qe, sidx*2+1), 
		                 RMQUtil(hist, st, mid+1, se, qs, qe, sidx*2+2)));
}

int RMQ(vector<int>&hist, vector<int>&st, int n, int qs, int qe){
	if(qs<0||qe>n-1||qs>qe){
		cout<<"Invalid Input"<<endl;
		return -1;
	}
	int ss=0, se=n-1, sidx=0;
	return RMQUtil(hist, st, ss, se, qs, qe, sidx);
}

int constructStUtil(vector<int>&hist, vector<int>&st, int ss, int se, int sidx){
	if(ss==se){
		return (st[sidx]=ss);
	}
	int mid=getMid(ss, se);
	st[sidx]=minVal(hist, constructStUtil(hist, st, ss, mid, sidx*2+1),
		                  constructStUtil(hist, st, mid+1, se, sidx*2+2));
	return st[sidx];
}

vector<int> constructSt(vector<int>&hist, int n){
	int x=(int)(ceil(log2(n)));
	int maxSz=2*(int)pow(2, x)-1;
	vector<int>st(maxSz);
	int ss=0, se=n-1, sidx=0;
	constructStUtil(hist, st, ss, se, sidx);
	return st;
}

int getMaxAreaUtil(vector<int>&hist, vector<int>&st, int n, int l, int r){
	if(l>r) return INT_MIN;
	if(l==r) return hist[l];
	int minVal=RMQ(hist, st, n, l, r);
	return (max(getMaxAreaUtil(hist, st, n, l, minVal-1),
		        getMaxAreaUtil(hist, st, n, minVal+1, r),
		        (r-l+1)*hist[minVal]));
}

int getMaxArea(vector<int>&hist, int n){
	vector<int>st=constructSt(hist, n);
	int l=0, r=n-1;
	return getMaxAreaUtil(hist, st, n, l, r);
}

int main(){
	vector<int>hist{6, 1, 5, 4, 5, 2, 6};
	int n=hist.size();
	cout<<getMaxArea(hist, n);
	return 0;
}
