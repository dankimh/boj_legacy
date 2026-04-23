#include<bits/stdc++.h>
using namespace std;
constexpr int INF=1<<27;
typedef pair<int,int> pii;
vector<vector<pii>> mp;
int n;
struct cmp{
    bool operator()(pii a,pii b){
        return a.second>b.second;
    }
};

int djik(int a,int b){
    vector<int> dist(n+1,INF);
    vector<int> ch(n+1,0);
    ch[a]=1;
    dist[a]=0;
    int i,j;
    priority_queue<pii,vector<pii>,cmp> q;
    q.push({a,0});
    while(!q.empty()){
        int now=q.top().first;
        int d=q.top().second;
        q.pop();
        if(d>dist[now])continue;
        for(auto &i:mp[now]){
            if(d+i.second<dist[i.first]){
                q.push({i.first,i.second+d});
                dist[i.first]=i.second+d;
            }
        }
    }
    return dist[b];
}
int main(){
    int e;
    scanf("%d %d",&n,&e);
    int i;
    mp.resize(n+1);
    for(i=0;i<e;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        mp[a].push_back({b,c});
        mp[b].push_back({a,c});
    }
    int v1,v2;
    scanf("%d %d",&v1,&v2);
    int f1=djik(1,v1);
    int f2=djik(v1,v2);
    int f3=djik(1,v2);
    int f4=djik(v1,n);
    int f5=djik(v2,n);
    //printf("%d %d %d %d %d\n",f1,f2,f3,f4,f5);
    int c1=f1+f2+f5;
    int c2=f3+f2+f4;
    int ans=min(c1,c2);
    if(ans>=INF)printf("-1");
    else printf("%d",ans);
}