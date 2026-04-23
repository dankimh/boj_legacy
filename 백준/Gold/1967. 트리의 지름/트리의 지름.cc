#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> mp;
vector<int> dist;
void dfs(int node,int d){
    if(dist[node]==-1){
        dist[node]=d;
        for(auto &i:mp[node]){
            if(dist[i.first]==-1)dfs(i.first,d+i.second);
        }
    }
    return;
}
int main(){
    int n,i;
    cin>>n;
    mp.resize(n+1);
    dist.resize(n+1,-1);
    for(i=0;i<n-1;i++){
        int t,a,b;
        cin>>a>>b>>t;
        mp[a].push_back({b,t});
        mp[b].push_back({a,t});
    }
    dfs(1,0);
    int mx=-1,loc=0;
    for(i=1;i<=n;i++){
        //cout<<i<<' '<<dist[i]<<"\n";
        if(mx<dist[i]){
            mx=dist[i];
            loc=i;
        }
    }
    dist.clear();
    dist.resize(n+1,-1);
    dfs(loc,0);
    mx=-1;
    for(i=1;i<=n;i++){
        //cout<<i<<' '<<dist[i]<<"\n";
        if(mx<dist[i]){
            mx=dist[i];
        }
    }
    cout<<mx;
}