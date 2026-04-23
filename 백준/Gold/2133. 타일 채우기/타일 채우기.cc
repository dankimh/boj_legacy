#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[31];
    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    dp[3]=0;
    for(int i=4;i<=n;i++){
        dp[i]=3*dp[i-2];
        int j=4;
        while(i-j>=0){
            dp[i]+=2*dp[i-j];
            j+=2;
        }
    }
    cout<<dp[n];
}