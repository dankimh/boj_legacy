#include<bits/stdc++.h>
#include<fstream>
#include<numeric>
#define DEBUG ifstream ifs;ofstream ofs;ifs.open("./dduk/10.in");ofs.open("output.txt");
#ifdef DEBUG
#define in ifs
#define out ofs
#else
#define in cin
#define out cout
#endif // DEBUG

#define print(x) for(const auto& vectorvalue:x){cout<<vectorvalue<<" ";}cout<<"\n";
#define arrin(x,n) for(ll qwer=0;qwer<n;qwer++)cin>>x[qwer];
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll INF=1e18;
constexpr ll mod=1e9+7;
ll d[5]= {1,0,-1,0,1};
ll f(ll n){
    ll ret=1;
    for(ll i=1;i<=n;i++){
        ret*=i;
        ret%=mod;
    }
    return ret;
}
ll p(ll b,ll e){ // b^e
    ll ret=1;
    while(e>0){
        if(e%2){
            ret*=b;
            ret%=mod;
        }
        b*=b;
        b%=mod;
        e/=2;
    }
    return ret%mod;
}
ll ncr(ll n,ll r){
    ll A=f(n),B=(f(r)*f(n-r))%mod;
    ll ex=mod-2;
    ll re=p(B,mod-2);
    return (re*A)%mod;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    ll i,r=0;
    for(i=0;i<n;i++){
        ll x;
        cin>>x;
        a[i]=m-x;
        r+=a[i];
    }
    if(m<r){
        cout<<"0";
        return;
    }
    ll ans=ncr(m,r);
    ans*=f(r);
    ans%=mod;
    for(i=0;i<n;i++){
        if(a[i]==0)continue;
        ans*=p(f(a[i])%mod,mod-2);
        ans%=mod;
    }
    cout<<ans%mod;
}
int main(){
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    ll t=1;
    //cin>>t;
    while(t--)solve();
}
