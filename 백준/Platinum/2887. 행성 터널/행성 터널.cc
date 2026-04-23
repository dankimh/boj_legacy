#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> p;
ll f(ll u){
    if(u==p[u])return u;
    else return p[u]=f(p[u]);
}
void uni(ll u,ll v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    p[u]=v;
    return;
}
ll dist(ll a,ll b,ll c,ll d,ll e,ll f){
    return min(abs(c-f),min(abs(a=d),abs(b-e)));
}
int main(){
    ll n,m;
    cin>>n;
    ll i,j;
    p.resize(n);
    for(i=0;i<n;i++)p[i]=i;
    vector<pair<ll,pair<ll,ll>>> mp;
    vector<pair<ll,ll>> x(n),y(n),z(n);
    for(i=0;i<n;i++){
        cin>>x[i].first>>y[i].first>>z[i].first;
        x[i].second=y[i].second=z[i].second=i;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());
    //mp.push_back({dist(dot[i].first,dot[i].second.first,dot[i].second.second,dot[j].first,dot[j].second.first,dot[j].second.second),{i,j}});
    for(i=0;i<n-1;i++){
        mp.push_back({abs(x[i].first-x[i+1].first),{x[i].second,x[i+1].second}});
    }
    for(i=0;i<n-1;i++){
        mp.push_back({abs(y[i].first-y[i+1].first),{y[i].second,y[i+1].second}});
    }
    for(i=0;i<n-1;i++){
        mp.push_back({abs(z[i].first-z[i+1].first),{z[i].second,z[i+1].second}});
    }
    ll cnt=0;
    ll cc=0;
    sort(mp.begin(),mp.end());
    for(i=0;i<mp.size();i++){
        if(cnt==n-1)break;
        ll a=mp[i].second.first;
        ll b=mp[i].second.second;
        ll c=mp[i].first;
        //cout<<a<<' '<<b<<' '<<c;
        if(f(a)==f(b))continue;
        else{
                //cout<<"in";
            uni(a,b);
            cc+=c;
            cnt++;
        }
        //cout<<"\n";
    }
    cout<<cc;
}