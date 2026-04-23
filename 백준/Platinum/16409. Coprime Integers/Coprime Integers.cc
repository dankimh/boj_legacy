#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll sz=1e7+1;
vector<ll> mob(sz,-1);
bool isp[sz];
vector<ll> prime;
void mo(ll n){
    fill(isp,isp+n+1,true);
    mob[1]=1;
    for(ll i=2;i<=n;i++){
        if(isp[i])prime.push_back(i);
        for(auto p:prime){
            if(i*p>n)break;
            isp[i*p]=false;
            if(i%p==0){
                mob[i*p]=0;
                break;
            }
            mob[i*p]=mob[i]*mob[p];
        }
    }
    return;
}
ll f(ll n,ll m){
    ll i,ans=0;
    for(i=1;i<=min(n,m);i++){
        ans+=mob[i]*(n/i)*(m/i);
    }
    return ans;
}
int main(){
    ll a,b,c,d,i;
    cin>>a>>b>>c>>d;
    mo(min(b,d));
    ll aa=f(a-1,c-1),bb=f(b,d),cc=f(a-1,d),dd=f(b,c-1);
    //cout<<aa<<' '<<bb<<' '<<cc<<' '<<dd<<' ';
    cout<<bb-cc-dd+aa;
}