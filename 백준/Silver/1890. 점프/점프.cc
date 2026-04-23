#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,mp[101][101],dp[101][101]={0,},i,j;
    cin>>n;
    for(i=0;i<n;i++)for(j=0;j<n;j++){cin>>mp[i][j];dp[i][j]=0;}
    dp[0][0]=1;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mp[i][j]==0)continue;
            ll x=i+mp[i][j];
            ll y=j+mp[i][j];
            if(x<n)dp[x][j]+=dp[i][j];
            if(y<n)dp[i][y]+=dp[i][j];
        }
    }
    cout<<dp[n-1][n-1];
}