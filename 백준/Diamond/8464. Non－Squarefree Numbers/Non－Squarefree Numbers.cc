#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll MAX=1e6+1;
vector<ll> mob(MAX);
vector<ll> prime;
bool isp[MAX];
void mo(){
    fill(isp,isp+MAX,true);
    fill(mob.begin(),mob.end(),-1);
    mob[1]=1;
    for(ll i=2;i<=MAX;i++){
        if(isp[i])prime.push_back(i);
        for(ll p:prime){
            if(i*p>MAX)break;
            isp[i*p]=false;
            if(i%p==0){
                mob[i*p]=0;
                break;
            }
            mob[i*p]=mob[i]*mob[p];
        }
    }
}
ll f(ll n){
    ll ans=0,i;
    for(i=1;i*i<=n;i++){
        ans+=mob[i]*(n/(i*i));
    }
    return n-ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mo();
    ll a,i;
    cin>>a;
    ll st=1,en=a*4;
    while(st<en-1){
        ll mid=(st+en)/2;
        ll val=f(mid);
        if(val<a)st=mid;
        else en=mid;
    }
    cout<<en;
}
