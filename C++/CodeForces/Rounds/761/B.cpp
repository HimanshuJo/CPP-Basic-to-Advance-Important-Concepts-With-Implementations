#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

vector<int> prime;

void simpleSieve(int limit, vector<int> &prime)
{ 
    vector<bool> mark(limit + 1, true);
    for (int p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p); 
        }
    }
}

void segmentedSieve(int n)
{
    int limit = floor(sqrt(n))+1;
    prime.reserve(limit);
    simpleSieve(limit, prime);
    int low = limit;
    int high = 2*limit;
    while (low < n)
    {
        if (high >= n)
           high = n;
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
        for (int i = 0; i < prime.size(); i++)
        {
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        } 
        low = low + limit;
        high = high + limit;
    }
}
 

int binarySearch(int left,int right,int n)
{
	if (left<=right)
	{
		int mid = (left + right)/2;
		if (mid == 0 || mid == prime.size()-1)
			return prime[mid];
		if (prime[mid] == n)
			return prime[mid-1];
		if (prime[mid] < n && prime[mid+1] > n)
			return prime[mid];
		if (n < prime[mid])
			return binarySearch(left, mid-1, n);
		else
			return binarySearch(mid+1, right, n);
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	segmentedSieve(1e9);
	while(t--){
		int n;
		cin>>n;
		int a, b, c;
		a=binarySearch(0, prime.size()-1, n);
		if(a==n-1){
			a=binarySearch(0, prime.size()-1, a);
		}
		int diff=n-a;
		b=diff-1;
		while(b==1){
			a=binarySearch(0, prime.size()-1, a);
			diff=n-a;
			b=diff-1;
		}
		while(a==b){
			a=binarySearch(0, prime.size()-1, a);
			diff=n-a;
			b=diff-1;
		}
		c=1;
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}
}
