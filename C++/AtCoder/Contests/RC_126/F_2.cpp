#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N=1001;

template <int mod>
struct ModInt
{
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p)
    {
        if ((x += p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p)
    {
        if ((x += mod - p.x) >= mod)
            x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p)
    {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p)
    {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const
    {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0)
        {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const
    {
        ModInt ret(1), mul(x);
        while (n > 0)
        {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }

    friend istream &operator>>(istream &is, ModInt &a)
    {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

bool chmin(long long a, long long b)
{
    if (b < a)
    {
        return true;
    }
    return false;
}

constexpr int mod = 998244353;
using mint = ModInt<mod>;
using pii=pair<ll, ll>;
struct custComp{
    bool operator()(const pii &a, const pii &b){
        return (a.first*b.second)<(b.first*a.second);
    }
};

struct custComp2{
    bool operator()(const pair<pii, int>&a, const pair<pii, int>&b){
        return(a.first.first*b.first.second)<(b.first.first*a.first.second);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(15);
    int n;
    cin>>n;
    ll X[N];
    for(ll i=0; i<n; ++i){
        cin>>X[i];
    }
    ll mi=129, idx;
    for(ll i=0; i<n; ++i){
        if(chmin(mi, X[i])){
            idx=i;
        }
    }
    ll cX[N];
    for(int i=0; i<n; ++i){
        cX[i]=X[(i+idx)%n];
    }
    for(ll i=ll(n-1); i>=0; --i){
        cX[i]-=cX[0];
    }
    vector<pair<pii, int>>eV;
    for(ll i=0; i<n-1; ++i){
        ll d=cX[i+1]-cX[i];
        int nw=(d<0?0:1);
        vector<pii>li;
        if(cX[i]<0){
            li.emplace_back(0, 1);
        }
        for(ll j=1; j<abs(cX[i])+1; ++j){
            li.emplace_back(j, abs(cX[i]));
        }
        if(cX[i+1]<0){
            li.emplace_back(0, 1);
        }
        for(ll j=1; j<abs(cX[i+1])+1; ++j){
            li.emplace_back(j, abs(cX[i+1]));
        }
        for(ll j=1; j<abs(d)+1; ++j){
            li.emplace_back(j, abs(d));
        }
        if(nw){
            eV.push_back({{0, 1}, 1});
        }
        sort(eV.begin(), eV.end(), custComp());
        for(auto e: li){
            nw^=1;
            if(nw){
                eV.push_back({e, 1});
            } else{
                eV.push_back({e, -1});
            }
        }
    }
    eV.push_back({{1, 1}, -100});
    sort(eV.begin(), eV.end(), custComp2());
    mint ans=0;
    int cnt=0;
    for(ll i=0; i<eV.size(); ++i){
        auto[t, v]=eV[i];
        cnt+=v;
        if(cnt==n-1){
            auto[a, b]=eV[i].first;
            auto[c, d]=eV[i+1].first;
            ll dv=X[n-1]-X[0];
            mint dt=(mint)(c*b-(ll)a*d)/b*d;
            a*=dv;
            a+=abs(dv)*b;
            a%=b;
            a=b-a;
            if(dv<0&&a==b){
                a=0;
            }
            ans+=dt*a/b-dt*dt/2*dv;
        }
    }
    ans/=3;
    cout<<ans<<"\n";
}