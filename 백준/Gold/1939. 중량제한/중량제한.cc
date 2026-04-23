#include<bits/stdc++.h>
#define ll long long
#define INF 1000000001
using namespace std;
int mi(int a,int b){
    return a<b?a:b;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<pair<int,int>>> bridge(n+1);
    vector<int> vis(n+1,0);
    vector<int> dist(n+1,-1);
    int i;
    for(i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        bridge[a].push_back({b,c});
        bridge[b].push_back({a,c});
    }
    int st,en;
    scanf("%d %d",&st,&en);
    priority_queue<pair<int,int>> q;
    q.push({INF,st});
    //dist[st]=INF;
    while(!q.empty()){
        int nowmax=q.top().first;
        int now=q.top().second;
        vis[now]=1;
        //_sleep(200);
        //printf("a%d %d\n",now,nowmax);
        if(now==en){
            break;
        }
        q.pop();
        if(dist[now]>nowmax)continue;
        for(int i=0;i<bridge[now].size();i++){
            int nextmax=bridge[now][i].second;
            int next=bridge[now][i].first;
            if(dist[next]<mi(nowmax,nextmax)&&vis[next]==0){
                dist[next]=mi(nowmax,nextmax);
                q.push({dist[next],next});
            }
        }
    }
    printf("%d",dist[en]);
}