#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int INF=1<<30;
int main(){
    int n,m;
    cin>>n>>m;
    int i;
    //vector<vector<pair<int,pair<int,int>>>> mp(n+1);
    vector<pair<int,pair<int,int>>> mp;
    for(i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mp.push_back({c,{a,b}});
        //mp.push_back({c,{b,a}});
        //mp[a].push_back({b,c});
        //mp[b].push_back({a,c});
    }
    vector<ll> dist(n+1,INF);
    dist[1]=0;
    for(i=1;i<n;i++){
        for(auto &j:mp){
            int cost=j.first;
            int a=j.second.first;
            int b=j.second.second;
            if(dist[a]==INF)continue;
            if(dist[b]>dist[a]+cost)dist[b]=dist[a]+cost;
        }
    }
    for(auto &j:mp){
        int cost=j.first;
        int a=j.second.first;
        int b=j.second.second;
        if(dist[a]==INF)continue;
        if(dist[b]>dist[a]+cost){
            cout<<"-1\n";
            exit(0);
        }
    }
    for(i=2;i<=n;i++){
        if(dist[i]==INF)cout<<"-1\n";
        else cout<<dist[i]<<"\n";
    }
}
