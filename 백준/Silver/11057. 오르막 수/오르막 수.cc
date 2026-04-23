#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int dp[1001][110]={0,},i,j;
    for(i=0;i<10;i++)dp[1][i]=i+1;
    for(i=2;i<=n;i++){
        int sum=0;
        for(j=0;j<10;j++){
            sum+=dp[i-1][j];
            dp[i][j]+=sum;
            dp[i][j]%=10007;
        }
    }
    printf("%d",dp[n][9]%10007);
}