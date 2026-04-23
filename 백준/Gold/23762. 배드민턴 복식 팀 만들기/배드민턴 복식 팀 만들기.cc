#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,i;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    vector<pair<int,vector<int>>> dp(n);
    //dp[0].s.push_back(0);
    for(i=0;i<3;i++){
        dp[i].f=0;
        if(i>0)dp[i].s=dp[i-1].s;
        dp[i].s.push_back(a[i].s);
    }
    dp[3].f=a[3].f-a[0].f;
    for(i=4;i<n;i++){
        if((i+1)%4==0){
            dp[i].f=dp[i-4].f+(a[i].f-a[i-3].f);
        }
        else{
            int x=dp[i-1].f;
            int y=dp[i-4].f+(a[i].f-a[i-3].f);
            if(x>y){
                dp[i].f=y;
                dp[i].s=dp[i-4].s;
            }
            else{
                dp[i].f=x;
                dp[i].s=dp[i-1].s;
                dp[i].s.push_back(a[i].s);
            }
        }
    }
    cout<<dp[n-1].f<<"\n";
    sort(dp[n-1].s.begin(),dp[n-1].s.end());
    for(auto &i:dp[n-1].s){
        cout<<i<<"\n";
    }
}