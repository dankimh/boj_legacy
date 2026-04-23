#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll coin[21],dp[10101][21];
ll dpp(ll m,ll n){
    if(dp[m][n]!=-1)return dp[m][n];
    if(m==0)return 1;
    if(n==1){
        if(m%coin[n]==0)return 1;
        else return 0;
    }
    ll ans=0;
    for(ll i=0;;i++){
        if(m-i*coin[n]<0)break;
        ans+=dpp(m-i*coin[n],n-1);
    }
    return dp[m][n]=ans;
}
void solve(){
    ll n,m,i;
    cin>>n;
    for(i=1;i<=n;i++)cin>>coin[i];
    cin>>m;
    memset(dp,-1,sizeof(dp));
    cout<<dpp(m,n)<<"\n";;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--)solve();
}