#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<int> vis,ans;
int num,cnt;
int dfs(int node,int root){
    vis[node]=++num;
    int ret=vis[node],child=0;
    for(auto &i:mp[node]){
        if(vis[i]){
            ret=min(ret,vis[i]);
            continue;
        }
        child++;
        int next=dfs(i,0);
        if(!root&&next>=vis[node]){
            ans[node]=1;
        }
        ret=min(ret,next);
    }
    if(root){
        if(child>=2)ans[node]=1;
    }
    return ret;
}
int main(){
    int v,e,i;
    cin>>v>>e;
    mp.resize(v+1);
    vis.resize(v+1,0);
    ans.resize(v+1,0);
    for(i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(i=1;i<=v;i++){
        if(!vis[i])dfs(i,1);
    }
    for(i=1;i<=v;i++)if(ans[i])cnt++;
    cout<<cnt<<"\n";
    for(i=1;i<=v;i++){
        if(ans[i])cout<<i<<" ";
    }
}
