#include<bits/stdc++.h>
using namespace std;

template <typename V>
void pop_front(V & v, int i)
{
    assert(!v.empty());
    v.erase(v.begin()+i);
}

template <typename V>
void popBack(V & v, int i)
{
    assert(!v.empty());
    v.erase(v.end()-i);
}

bool isPrime(int num){
    if(num == 1) return false;
    for(int i = 2; i<=sqrt(num); i++){
          if(num % i == 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>A(n);
        unordered_map<int, int>mp;
        for(int i=0; i<n; ++i){
            cin>>A[i];
            mp[A[i]]=i+1;
        }
        int sum=0;
        for(auto &nums: A){
            sum+=nums;
        }
        if(isPrime(sum)){
            for(int i=0; i<A.size(); ++i){
                if(A[i]%2!=0){
                    auto it=A.begin()+i;
                    A.erase(it);
                    break;
                }
            }
        }
        cout<<A.size()<<"\n";
        for(auto &nums: A){
            cout<<mp[nums]<<" ";
        }
        cout<<endl;
    }
}