#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> tree;
vector<int> dist;
vector<int> maxdist;
vector<int> istree;
void distfs(int node,int d){
    if(dist[node]==-1){
        dist[node]=d;
        for(auto& i:tree[node]){
            if(dist[i]==-1)distfs(i,d+1);
        }
    }
    return;
}
void find_path(int node){
    for(auto& i:tree[node]){
        if(dist[i]==dist[node]-1){
            maxdist.push_back(i);
            istree[i]=1;
            find_path(i);
        }
    }
}
int mxxx=-1;
void dfs(int node,int d){
    //cout<<node<<"x\n";
    dist[node]=d;
    if(mxxx<d)mxxx=d;
    for(auto& i:tree[node]){
        if(dist[i]==-1&&!istree[i]){
            dfs(i,d+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,i;
    cin>>n;
    tree.resize(n+1);
    dist.resize(n+1,-1);
    istree.resize(n+1,0);
    for(i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    distfs(1,0);
    int mx=-1,loc=0;
    for(i=1;i<=n;i++){
        if(mx<dist[i]){
            mx=dist[i];
            loc=i;
        }
    }
    //cout<<loc<<"loc\n";
    dist.clear();
    dist.resize(n+1,-1);
    distfs(loc,0);
    mx=-1;
    for(i=1;i<=n;i++){
        if(mx<dist[i]){
            mx=dist[i];
            loc=i;
        }
    }
    maxdist.push_back(loc);
    istree[loc]=1;
    find_path(loc);
    /*for(i=1;i<=n;i++)cout<<istree[i]<<" ";
    cout<<"y\n";*/
    dist.clear();
    dist.resize(n+1,-1);
    for(auto& i:maxdist){
        //cout<<i<<" ";
        dfs(i,0);
        //if(mxx<mxdist[i])mxx=mxdist[i];
    }
    /*cout<<"\n";
    for(auto& i:dist){
        cout<<i<<" ";
    }
    cout<<"\n";*/
    if(mxxx!=0)cout<<mx+mxxx+1;
    else cout<<"0";
}
