class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(begin(flowers), end(flowers), greater<int>());
        long long p1=0, sum=0, res=0, sz=flowers.size();
        for(; p1<sz; ++p1){
            if(target-flowers[p1]>newFlowers) break;
            newFlowers-=max(0, target-flowers[p1]);
        }
        if(p1==sz){
            return max(sz*full,
                      (sz-1)*full+(flowers.back()<target?(long long)(target-1)*partial:
                      full));
        }
        for(long long minF=flowers.back(), p2=flowers.size()-1; minF<target; ){
            while(p2>=p1&&flowers[p2]<=minF){
                sum+=flowers[p2--];
            }
           int needed=(sz-p2-1)*minF-sum;
           if(needed>newFlowers){
                if(--p1<0) break;
            newFlowers+=max(0, target-flowers[p1]);
           } else{
                res=max(p1*full+minF*partial, res);
                ++minF;
           }
        }
        return res;
    }
};