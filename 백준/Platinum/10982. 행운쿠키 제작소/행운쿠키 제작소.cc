#include<bits/stdc++.h>
using namespace std;
const int MAX=1<<20;
void solve(){
    int n,i,sum=0,sumb=0;
    cin>>n;
    vector<int> a,b;
    int dp[2][101010]={0,};
    for(i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        sum+=x;
        sumb+=y;
        a.push_back(x);
        b.push_back(y);
    }
    for(i=0;i<=sum;i++){
        dp[0][i]=0;
    }
    dp[1][0]=0;
    for(int j=1;j<=n;j++){
        int bef=(j+1)%2;
        int now=(j)%2;
        for(i=0;i<=sum;i++){
            if(i-a[j-1]<0)dp[now][i]=dp[bef][i];
            else dp[now][i]=max(dp[bef][i],dp[bef][i-a[j-1]]+b[j-1]);
        }
    }
    int mn=MAX;
    for(i=0;i<=sum;i++){
        mn=min(mn,max(i,sumb-dp[n%2][i]));
    }
    cout<<mn<<"\n";
    return;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--)solve();
}