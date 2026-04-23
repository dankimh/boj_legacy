#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,i;
        cin>>n;
        int a[2][n+1];
        a[0][0]=a[1][0]=0;
        for(i=1;i<=n;i++)scanf("%d",&a[0][i]);
        for(i=1;i<=n;i++)scanf("%d",&a[1][i]);
        int dp[2][n+1];
        dp[0][0]=a[0][0];
        dp[1][0]=a[1][0];
        dp[0][1]=a[0][1];
        dp[1][1]=a[1][1];
        for(i=2;i<=n;i++){
            dp[0][i]=max(dp[1][i-1]+a[0][i],max(dp[1][i-2]+a[0][i],dp[0][i-2]+a[0][i]));
            dp[1][i]=max(dp[0][i-1]+a[1][i],max(dp[1][i-2]+a[1][i],dp[0][i-2]+a[1][i]));
        }
        printf("%d\n",max(dp[0][n],dp[1][n]));
    }
}