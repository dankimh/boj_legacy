#include<bits/stdc++.h>
constexpr int INF=1<<27;
using namespace std;
typedef pair<int,int> pii;
int main(){

    int n,m,k,i,j;

    scanf("%d %d %d",&n,&m,&k);
    vector<vector<pii>> mp(n+1);
    for(i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        mp[a].push_back({b,c});
    }
    vector<priority_queue<int>> dist(n+1);
    dist[1].push(0);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,1});
    while(!q.empty()){
        int d=q.top().first;
        int now=q.top().second;
        q.pop();
        for(auto &i:mp[now]){
            if(dist[i.first].size()<k){
                q.push({(d+i.second),i.first});
                dist[i.first].push(d+i.second);
            }
            else if(dist[i.first].top()>d+i.second){
                dist[i.first].pop();
                q.push({(d+i.second),i.first});
                dist[i.first].push(d+i.second);

            }
        }
    }

    for(i=1;i<=n;i++){
        if(dist[i].size()!=k)printf("-1\n");
        else printf("%d\n",dist[i].top());
    }
}