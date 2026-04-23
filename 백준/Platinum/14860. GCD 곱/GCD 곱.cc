#include<bits/stdc++.h>
typedef long long ll;
constexpr ll mod=1e9+7;
constexpr ll MAX=15000002;
using namespace std;
vector<ll> prime;
bool isp[MAX];
ll pw(ll a,ll b){
    ll ex=(ll)b;
    ll base=(ll)a;
    ll ans=1;
    while(ex){
        if(ex%2){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        ex/=2;
    }
    return ans%mod;
}
/*void mo(ll n){

}
ll f(ll n,ll m,ll p){
    ll ret=0;
    while(n/p>0&&m/p>0){
        ret+=(((n/p))*((m/p)));
        ret%=mod;
        p=p*p;
    }
    return ret%mod;
}*/
int main(){
    ll n,m,j,ans=1;

    cin>>n>>m;
    fill(isp,isp+n+1,true);
    for(ll i=2;i<=n;i++){
        if(isp[i]){
            ll t=0;
            prime.push_back(i);
            for(j=i;j<=n;j*=i){
                t+=(n/j)*(m/j);
            }
            ans=ans*pw(i,t)%mod;
        }
        for(ll p:prime){
            if(i*p>n)break;
            isp[i*p]=false;
            if(i%p==0){
                break;
            }
        }
    }
    if(n==1||m==1){
        cout<<"1";
        exit(0);
    }
    /*cout<<prime.back()<<"\n";
    for(auto p:prime){
        //if(p>min(n,m))break;
        //cout<<p<<"\n";
        ll ex=f(n,m,p);
        ans=ans*pw(p,ex)%mod;
    }*/
    cout<<ans%mod;
}