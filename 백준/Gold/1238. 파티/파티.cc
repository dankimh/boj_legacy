#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include<utility>
#define INF 0xfffffff

using namespace std;
vector<vector<pair<int,int>>> map(20001);
int main(){
    int v,e,i,j,x;
    scanf("%d %d %d",&v,&e,&x);

    int k;
    int tot[20001]={0,};
    for(i=0;i<e;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        map[a].push_back({b,w});
    }
    for(j=1;j<=v;j++){
        if(j==x){
            tot[j]+=0;
            continue;
        }

        int dis[20001];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dist;
        for(i=1;i<=v;i++)dis[i]=INF;
        dist.push({0,j});
        dis[j]=0;
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
        tot[j]+=dis[x];
    }
    int dis[20001];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dist;
    for(i=1;i<=v;i++)dis[i]=INF;
    dist.push({0,x});
    dis[x]=0;
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
    int max=-1;
    for(i=1;i<=v;i++){
        if(max<tot[i]+dis[i])max=tot[i]+dis[i];
    }
    printf("%d",max);
}