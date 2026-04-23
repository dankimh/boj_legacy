#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,m,i,j,t;
    vector<ll> ssa,ssb;
    scanf("%lld",&t);
    scanf("%lld",&n);
    vector<ll> a(n+1,0),sa(n+1,0);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)sa[i]=sa[i-1]+a[i];
    scanf("%lld",&m);
    vector<ll> b(m+1,0),sb(m+1,0);
    for(i=1;i<=m;i++)scanf("%lld",&b[i]);
    for(i=1;i<=m;i++)sb[i]=sb[i-1]+b[i];
    ll ca=0,cb=0;
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n;j++){
            ssa.push_back(sa[j]-sa[i]);
        }
    }
    for(i=0;i<=m;i++){
        for(j=i+1;j<=m;j++){
            ssb.push_back(sb[j]-sb[i]);
        }
    }
    sort(ssa.begin(),ssa.end());
    sort(ssb.begin(),ssb.end());
    /*for(auto &i:ssa)printf("%d ",i);
    printf("\n");
    for(auto &i:ssb)printf("%d ",i);
    printf("\n");*/
    ll ans=0;
    for(i=0;i<ssa.size();i++){
        ll fr=lower_bound(ssb.begin(),ssb.end(),t-ssa[i])-ssb.begin();
        ll re=upper_bound(ssb.begin(),ssb.end(),t-ssa[i])-ssb.begin();
        ans+=re-fr;
    }
    printf("%lld",ans);
}