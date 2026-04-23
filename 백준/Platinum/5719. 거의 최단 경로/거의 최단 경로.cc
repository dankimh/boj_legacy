#include<bits/stdc++.h>
#define pv pair<pii,vector<int>>
constexpr int INF=1<<27;
using namespace std;
typedef pair<int,int> pii;
struct cmp{
    bool operator()(pv a,pv b){
        return a.first>b.first;
    }
};
//ifstream in;
//ofstream out;
void solve(int n,int m){
    int s,d,i,j;
    cin>>s>>d;
    vector<vector<int>> mp2(n,vector<int> (n,INF));
    vector<vector<pii>> mp(n);
    for(i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back({b,c});
        mp2[a][b]=c;
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<set<pii>> del(n);
    vector<int> dist(n,INF);
    q.push({0,s});
    dist[s]=0;
    while(!q.empty()){
        int now=q.top().second;
        int dst=q.top().first;
        /*printf("x-%d %d\n",now,dst);
        for(i=0;i<path.size();i++)printf("%d ",path[i]);
        printf("\n");*/
        q.pop();
        if(dst>dist[now])continue;
        if(now==d){
            /*for(i=0;i<path.size();i++)printf("%d ",path[i]);
        printf("\n");*/
            continue;
        }
        for(auto &i:mp[now]){
            int nd=i.second+dst;
            int nn=i.first;
            if(nd>dist[nn])continue;
            else if(nd==dist[nn]){
                for(auto &j:del[now]){
                    del[nn].insert(j);
                }
                del[nn].insert({now,nn});
            }
            else{
                del[nn].clear();
                for(auto &j:del[now]){
                    del[nn].insert(j);
                }
                del[nn].insert({now,nn});
                q.push({nd,nn});
                dist[nn]=nd;
            }
        }
    }
    /*for(i=0;i<n;i++)printf("%d ",dist[i]);
    printf("\n");*/
    //printf("aaa\n");
    /*for(auto &i:del){
        for(auto &j:i)printf("(%d %d) ",j.first,j.second);
        printf("\n");
    }*/
    for(auto &i:del[d]){
        mp2[i.first][i.second]=INF;
    }
    vector<vector<pii>> mp3(n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            //printf("%d ",mp2[i][j]);
            if(mp2[i][j]!=INF)mp3[i].push_back({j,mp2[i][j]});
        }
        //printf("\n");
    }
    priority_queue<pii,vector<pii>,greater<pii>> qq;
    qq.push({0,s});
    vector<int> distt(n,INF);
    while(!qq.empty()){
        int now=qq.top().second;
        int dst=qq.top().first;
        qq.pop();
        if(dst>distt[now])continue;
        for(auto &i:mp3[now]){
            int nd=i.second+dst;
            int nn=i.first;
            if(nd<distt[nn]){
                qq.push({nd,nn});
                distt[nn]=nd;
            }
        }
    }
    if(distt[d]==INF)cout<<"-1\n";
    else cout<<distt[d]<<"\n";
}
int main(){
    int n,m;
    //in.open("in.txt");
    //out.open("out.txt");
    while(cin>>n>>m){
        if(n==0&&m==0)break;
        solve(n,m);
    }
}