#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<int> vis,low;
vector<pair<int,int>> ans;
int num;
void dfs(int node,int p){
    vis[node]=num++;
    low[node]=num;
    for(auto &i:mp[node]){
        if(i==p)continue;
        if(vis[i]){
            low[node]=min(low[node],vis[i]);
            continue;
        }
        dfs(i,node);
        if(low[i]>vis[node]){
            ans.push_back({min(node,i),max(node,i)});
        }
        low[node]=min(low[node],low[i]);
    }
    return;
}
int main(){
    int v,e,i;
    cin>>v>>e;
    mp.resize(v+1);
    low.resize(v+1,0);
    vis.resize(v+1,0);
    for(i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(i=1;i<=v;i++){
        if(!vis[i])dfs(i,0);
    }
    cout<<ans.size()<<"\n";
    sort(ans.begin(),ans.end());
    for(auto &i:ans){
        cout<<i.first<<" "<<i.second<<"\n";
    }
}