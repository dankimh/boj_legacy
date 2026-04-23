#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> val;
vector<vector<int>> mp,tree;
vector<int> vis;
vector<int> dp[2];
void solve(){

}
void mktree(int node){
    vis[node]=1;
    for(auto &i:mp[node]){
        if(!vis[i]){
            mktree(i);
            tree[node].push_back(i);
        }
    }
}
int dfs(int node,int include){
    if(dp[include][node]!=-1)return dp[include][node];
    if(include){
        int ans=0;
        for(auto &i:tree[node]){
            //if(!vis[i]){
                ans+=dfs(i,0);
            //}
        }
        //cout<<node<<" 1 "<<ans+val[node]<<"\n";
        return dp[include][node]=ans+val[node];
    }
    else{
        int ans=0;
        for(auto &i:tree[node]){
            //if(!vis[i]){
                int t1=dfs(i,0);
                int t2=dfs(i,1);
                ans+=max(t1,t2);
            //}
        }
        //cout<<node<<" 2 "<<ans<<"\n";
        return dp[include][node]=ans;
    }
}
int main(){
    /*int tt;
    cin>>tt;
    while(tt--)solve();*/
    int n,i;
    cin>>n;
    mp.resize(n+1);
    tree.resize(n+1);
    vis.resize(n+1,0);
    dp[0].resize(n+1,-1);
    dp[1].resize(n+1,-1);
    val.push_back(0);
    for(i=0;i<n;i++){
        int a;
        cin>>a;
        val.push_back(a);
    }
    for(i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    mktree(1);
    int t1=dfs(1,0);
    int t2=dfs(1,1);
    cout<<max(t1,t2);
}
