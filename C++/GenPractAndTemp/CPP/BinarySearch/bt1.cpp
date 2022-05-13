#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
#include<random>
using namespace std;

int binarySearch(vector<int>&in, int N, int val){
    sort(in.begin(), in.end());
    int left=0, right=N-1;
    int ans=0;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(in[mid]==val){
            ans=mid;
            break;
        } else if(in[mid]>val){
            right=mid-1;
        } else left=mid+1;
    }
    return ans;
}

int interpolationSearch(vector<int>&in, int N, int val){
    sort(in.begin(), in.end());
    int left=0, right=N-1;
    int ans=0;
    while(left<=right){
        int mid=left+((right-left)/(in[right]-in[left]))*(val-in[left]);
        if(in[mid]==val){
            ans=mid;
            break;
        } else if(in[mid]>val){
            right=mid-1;
        } else left=mid+1;
    }
    return ans;
}

int main(){
    clock_t t;
    vector<int>in{};
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(1,100);
    for(int i=0; i<=100; ++i){
        in.push_back(dist6(rng));
    }
    in.push_back(37);
    for(int i=0; i<=100; ++i){
        in.push_back(dist6(rng));
    }
    int sz=in.size();
    t=clock();
    int ans=binarySearch(in, sz, 37);
    
    for(int i=0; i<sz; ++i){
        cout<<i<<" : "<<in[i]<<endl;
    }
    cout<<"\n-------\n";
    
    cout<<ans<<endl;
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    cout<<"\n-------\n";
    t=clock();
    ans=interpolationSearch(in, sz, 37);
    cout<<ans<<endl;
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
}