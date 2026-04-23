#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<double,ll> a,pair<double,ll> b){
    if(a.first==b.first)return a.second>b.second;
    return a.first>b.first;
}
int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> w(n),v(n);
    vector<pair<double,ll>> sugar(n);
    ll i;
    for(i=0;i<n;i++){
        cin>>w[i]>>v[i];
        sugar[i]={(double)v[i]/(double)w[i],i};
    }
    sort(sugar.begin(),sugar.end(),cmp);
    //for(i=0;i<n;i++)cout<<sugar[i].first<<" "<<sugar[i].second<<"\n";
    ll x=0,a=0,b=1;
    for(i=0;i<n;i++){
        if(m<w[sugar[i].second]){
            b=w[sugar[i].second];
            a=v[sugar[i].second]*m;
            break;
        }
        x+=v[sugar[i].second];
        m-=w[sugar[i].second];
    }
    ll g=__gcd(a,b);
    if(g!=0){
        a/=g;
        b/=g;
    }
    //cout<<a<<" "<<b<<" "<<x<<"\n";
    cout<<a+b*x<<"/"<<b;
}