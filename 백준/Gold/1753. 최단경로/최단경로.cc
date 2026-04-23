#include<stdio.h>
#include<queue>
#include<string.h>
#include<utility>
#define INF 0xfffffff
using namespace std;
vector<vector<pair<int,int>>> map(20001);
int dis[20001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dist;
int main(){
    int v,e,i,j;
    scanf("%d %d",&v,&e);
    for(i=1;i<=v;i++)dis[i]=INF;
    int k;
    scanf("%d",&k);
    for(i=0;i<e;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        map[a].push_back({b,w});
    }
    dist.push({0,k});
    dis[k]=0;
    while(!dist.empty()){
        int now=dist.top().second;
        int until=dist.top().first;
        dist.pop();
        if(until>dis[now])continue;
        for(auto &i:map[now]){
            if(until+i.second<dis[i.first]){
                dis[i.first]=until+i.second;
                dist.push({until+i.second,i.first});
            }
        }
    }
    for(i=1;i<=v;i++){
        if(dis[i]<INF)printf("%d\n",dis[i]);
        else printf("INF\n");
    }
}