#include<bits/stdc++.h>
using namespace std;
int dp[1<<20],a[21][21],n;
int f(int now,int vis){
    if(dp[vis])return dp[vis];
    //cout<<vis<<"\n";
    if(vis==(1<<n)-1)return 0;
    int mn=1<<30;
    for(int i=0;i<n;i++){
        int x=-1;
        //cout<<hex<<(vis&(1<<i))<<"x\n";
        if(!(vis&(1<<i))){
            //cout<<"in\n";
            x=f(now+1,vis|(1<<i))+a[now][i];
        }
        if(mn>x&&x>=0){
            mn=x;
        }
    }
    //cout<<now<<" "<<work<<" "<<a[now][work]<<"x\n";
    return dp[vis]=mn;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)cin>>a[i][j];
    }

    /*for(i=0;i<n;i++){
        for(j=0;j<(1<<n);j++)cout<<dp[i][j]<<" ";
        cout<<"\n";
    }*/
    cout<<f(0,0);
}