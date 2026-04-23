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
    for(i=0;i<n;i++){
        int t,a,b;
        cin>>t;
        while(cin>>a){
            if(a==-1)break;
            cin>>b;
            mp[t].push_back({a,b});
            mp[a].push_back({t,b});
        }
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