#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> parent;
vector<ll> r;
vector<pair<ll,pair<ll,ll>>> co;
ll f(ll u){
    if(u==parent[u])return u;
    return parent[u]=f(parent[u]);
}
void uni(ll u,ll v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    if(r[u]>r[v])swap(u,v);
    parent[u]=v;
    if(r[u]==r[v])r[v]++;
    return;
}
int main(){
    ll v,e;
    scanf("%lld %lld",&v,&e);
    ll i;
    parent.resize(v+1);
    r.resize(v+1);
    for(i=1;i<=v;i++){
        parent[i]=i;
        r[i]=1;
    }
    for(i=0;i<e;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        co.push_back({c,{a,b}});
    }
    sort(co.begin(),co.end());
    //for(auto &i:co)printf("%lld %lld %lld\n",i.first,i.second.first,i.second.second);
    vector<ll> visit(v+1,0);
    ll cnt=0,sum=0;
    for(i=0;i<e;i++){
        if(cnt==v-1)break;
        ll a=co[i].second.first;
        ll b=co[i].second.second;
        ll c=co[i].first;
        if(f(a)==f(b))continue;
        else{
            uni(a,b);
            sum+=c;
            cnt++;
        }
    }
    printf("%lld",sum);
}
